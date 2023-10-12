/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_proc.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del constructor de codigo intermedio Lineal para PROCESOS (IR)
 */

#include "IR/ir_translator_proc.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Process] -----

void IR_Translator_Process::translate_process_to_ir_instructions(struct process * proc){
    // 1. Obtener nombre de proceso
    std::string id_label_block = instructions.get_next_label_id();
    std::string proc_name = std::string(proc->name_process);

    // 2. Registrar proceso como una variable (de scope global)
    int id_process_in_table = tables.add_entry_variable(IR_VAR_GLOBAL,proc_name,IR_VAR_TYPE_PROCESS);

    // 3. Generar etiqueta de entrada de proceso
    int id_label_in_table = tables.add_entry_label(std::string("start_proc_") + proc_name + "(" + id_label_block + ")",instructions.size()+1);

    // 4. Emitir instruccion de punto de entrada de proceso
    IR_operand op_label = instructions.emit_operand_label(id_label_in_table);

    instructions.emit_instruction(IR_LABEL,op_label);

    // 5. Traducir declaraciones de proceso
    if(proc->declarations)
        decl_translator.translate(proc->declarations);

    // 6. Traducir sentencias de proceso
    // TODO .. COMPROBAR SI EL BLOQUE DE SENTENCIAS ES COBEGIN
    if(proc->statements)
        stmt_translator.translate(proc->statements);

    // 7. Generar etiqueta de fin de proceso
    id_label_in_table = tables.add_entry_label(std::string("end_proc_") + proc_name + "(" + id_label_block + ")",instructions.size()+1);

    // 4. Emitir instruccion de punto de entrada de proceso
    op_label = instructions.emit_operand_label(id_label_in_table);

    instructions.emit_instruction(IR_LABEL,op_label);
}

void IR_Translator_Process::translate_process_vector_to_ir_instructions(struct process * proc){
    // -- 0. Obtener indice de inicio/fin
    const int start_index = proc->index_start->expr.expression_literal.value.integer_literal;
    const int end_index = proc->index_end->expr.expression_literal.value.integer_literal;

    // -- 0.A Generar literal para inicio de proceso
    int id_literal_in_table = tables.add_entry_literal(start_index);
    IR_operand op_start_index = instructions.emit_operand_literal(id_literal_in_table);

    // ---- 0.A.2 Obtener registro para cargar valor inicial de variable
    const int reg_index_init = reg_manager.get_next_general_purpose_register();
    IR_operand op_index_reg = instructions.emit_operand_register(reg_index_init);

    // ---- 0.A.3 Realizar operacion de carga de valor en registro
    instructions.emit_instruction(IR_OP_LOAD,op_index_reg,op_start_index);

    // -- 0.B Obtener identificador de indice
    std::string index_name = std::string(proc->index_identifier);

    // -- 0.B.1 Generar variable global para el indice
    int id_variable_in_table = tables.add_entry_variable(IR_VAR_GLOBAL,index_name,IR_VAR_TYPE_INT);

    // ---- 0.B.2 Emitir instruccion de carga de valor en variable
    IR_operand op_index_dest = instructions.emit_operand_variable(id_variable_in_table);
    instructions.emit_instruction(IR_OP_STORE,op_index_dest,op_index_reg);

    // -- 1. Realizar bucle para cada proceso
    for(int i=start_index; i<=end_index; i++){
        // 8. Emitir instruccion de fin de proceso
        instructions.emit_instruction(IR_START_PROCESS);
        
        // --- 2. Traducir proceso
        translate_process_to_ir_instructions(proc);

        // --- 2.1 Incrementar indice
        // ------- Generar operacion de carga de incremento
        id_literal_in_table = tables.add_entry_literal(static_cast<int>(1));
        IR_operand op_index_inc = instructions.emit_operand_literal(id_literal_in_table);
        const int reg_assigned = this->reg_manager.get_next_general_purpose_register();
        IR_operand op_reg_index_inc = instructions.emit_operand_register(reg_assigned);
        instructions.emit_instruction(IR_OP_LOAD,op_reg_index_inc,op_index_inc);

        instructions.emit_instruction(IR_OP_ADD,op_index_reg,op_index_reg,op_reg_index_inc);
        instructions.emit_instruction(IR_OP_STORE,op_index_dest,op_index_reg);


        // 8. Emitir instruccion de fin de proceso
        instructions.emit_instruction(IR_END_PROCESS);
    }
}

void IR_Translator_Process::translate_list_process_to_ir_instructions(struct process * list_proc){
    struct process *current_proc = list_proc;
    while(current_proc != NULL){
        // -- Traducir declaracion
        if(current_proc->index_identifier){
            this->translate_process_vector_to_ir_instructions(current_proc);
        }
            
        else{
            // 8. Emitir instruccion de fin de proceso
            instructions.emit_instruction(IR_START_PROCESS);
            this->translate_process_to_ir_instructions(current_proc);
            // 8. Emitir instruccion de fin de proceso
            instructions.emit_instruction(IR_END_PROCESS);
        }
        // -- Ir a siguiente declaracion
        current_proc = current_proc->next;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_Translator_Process] -----

IR_Translator_Process& IR_Translator_Process::get_instance(){
    static IR_Translator_Process instance;
    return instance;
}

void IR_Translator_Process::translate(struct process * list_proc){
    this->translate_list_process_to_ir_instructions(list_proc);
}