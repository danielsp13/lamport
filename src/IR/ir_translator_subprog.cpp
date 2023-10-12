/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_subprog.hpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del constructor de codigo intermedio Lineal para SUBPROGRAMAS (IR)
 */

#include "IR/ir_translator_subprog.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Subprogram] -----

void IR_Translator_Subprogram::translate_subprogram_to_ir_instructions(struct subprogram * subprog){
    // -- 1. Obtener nombre de subprograma
    std::string subprog_name = std::string(subprog->name_subprogram);

    // -- 2. Registrar subprograma como una variable (de scope global)
    int id_subprog_in_table = tables.add_entry_variable(IR_VAR_GLOBAL,subprog_name,IR_VAR_TYPE_SUBPROGRAM);

    // -- 3. Generar etiqueta de entrada de subprograma
    std::string start_label_subprog = std::string("start_subprog_") + subprog_name;
    const int start_subprog_addr = instructions.size()+1;

    // -- 3.1.1 Insertar nueva etiqueta
    int id_label_in_table = tables.add_entry_label(start_label_subprog,start_subprog_addr);

    // -- 4. Emitir instruccion de punto de salida de subprograma
    IR_operand op_label = instructions.emit_operand_label(id_label_in_table);
    instructions.emit_instruction(IR_LABEL,op_label);

    ///////////////////////////////////////////////////////////////////////////////////////

    // --- 5.A Comprobar si el subprograma tiene parametros
    if(subprog->parameters){
        // --- 5.A.1 Generar instrucciones IR para los parametros
        this->translate_list_parameters_to_ir_instructions(subprog->parameters);
    }

    // --- 5.B Comprobar si el subprograma tiene declaraciones
    if(subprog->declarations){
        // --- 5.B.1 Generar instrucciones IR para las variables locales
        decl_translator.translate(subprog->declarations,true);
    }

    // --- 5.C Generar instrucciones IR para el cuerpo del subprograma
    if(subprog->statements){
        stmt_translator.translate(subprog->statements,true);
    }

    // --- 5.D Emitir instruccion de retorno
    // ---- 5.D.1 Comprobar si el subprograma es una funcion o procedimiento
    if(subprog->kind == SUBPROGRAM_FUNCTION){
        // TODO
    }
    else{
        // ---- 5.D.1.2 Emitir instruccion de retorno
        instructions.emit_instruction(IR_OP_RET);
    }

    ///////////////////////////////////////////////////////////////////////////////////////

    // -- . Generar etiqueta de fin de subprograma
    id_label_in_table = tables.add_entry_label(std::string("end_subprog_") + subprog_name,instructions.size()+1);

    // -- . Emitir instruccion de punto de salida de subprograma
    op_label = instructions.emit_operand_label(id_label_in_table);
    instructions.emit_instruction(IR_LABEL,op_label);

    // -- Limpiar registro de variables locales de subprograma
    assistant_translator.clear_locals_subprog();
    // -- Resetear registros de subprograma
    reg_manager.reset_subprog_register_counter();
}

void IR_Translator_Subprogram::translate_list_subprograms_to_ir_instructions(struct subprogram * list_subprog){
    struct subprogram *current_subprog = list_subprog;
    while(current_subprog != NULL){
        // -- Traducir declaracion
        this->translate_subprogram_to_ir_instructions(current_subprog);
        // -- Ir a siguiente declaracion
        current_subprog = current_subprog->next;
    }
}

void IR_Translator_Subprogram::translate_list_parameters_to_ir_instructions(struct parameter * list_param){
    // -- 1. Generar instrucciones IR para cada parametro
    struct parameter * current_parameter = list_param;

    // ---- Instrumentacion necesaria
    // ------ Registro donde se encuentra el parametro
    int addr_reg_param;
    // ------ Operando de registro donde se encontrara el valor del parametro
    IR_operand op_reg_param;

    std::stack<struct parameter*> stack_parameters;
    while(current_parameter){
        stack_parameters.push(current_parameter);

        // --- Ir al siguiente parametro
        current_parameter = current_parameter->next;
    }

    std::string name_parameter;
    while(!stack_parameters.empty()){
        current_parameter = stack_parameters.top();

        // ---- 2.0 Obtener nombre de parametro
        name_parameter = std::string(current_parameter->name_parameter);

        // ---- 2.A Obtener registros para pasar parametros
        addr_reg_param = reg_manager.get_next_subprog_register();

        // ---- 2.B Definir operando de registro
        op_reg_param = instructions.emit_operand_register(addr_reg_param);

        // ---- 2.C Emitir instruccion de pop de registro
        instructions.emit_instruction(IR_OP_POP,op_reg_param);

        // ---- 2.D Registrar parametro como una variable local de subprograma
        assistant_translator.insert_var_local_subprog(name_parameter,addr_reg_param);

        stack_parameters.pop();
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_Translator_Subprogram] -----

IR_Translator_Subprogram& IR_Translator_Subprogram::get_instance(){
    static IR_Translator_Subprogram instance;
    return instance;
}

void IR_Translator_Subprogram::translate(struct subprogram * list_subprog){
    this->translate_list_subprograms_to_ir_instructions(list_subprog);
}