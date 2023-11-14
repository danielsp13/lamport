/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_decl.cpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para DECLARACIONES (IR)
 */

#include "IR/translators/ir_translator_decl.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Declaration] -----

IR_variable_t IR_Translator_Declaration::get_variable_scope(std::string var_name,const symbol_t & kind){
    auto var_scope = AST_symbol_IR_var_t.find(kind);
    // ------ Comprobar que se encontro scope
    if(var_scope == AST_symbol_IR_var_t.end()){
        // ------ Excepcion
        std::string MSG = "[IR_Translation] No se pudo encontrar el scope de variable: ";
        MSG += var_name;
        throw std::runtime_error(MSG);
    }

    return var_scope->second;
}

IR_variable_type_t IR_Translator_Declaration::get_type_variable(std::string var_name,type_t & kind){
    auto var_type = AST_type_IR_type.find(kind);
    // ------ Comprobar que se encontro tipo de dato
    if(var_type == AST_type_IR_type.end()){
        // ------ Excepcion
        std::string MSG = "[IR_Translation] No se pudo encontrar el tipo de dato de variable: ";
        MSG += var_name;
        throw std::runtime_error(MSG);
    }

    return var_type->second;
}

int IR_Translator_Declaration::initialize_variable_local_subprogram(std::string var_name, IR_variable_type_t var_type){
    // --- 4.B.1.A.1 Obtener nuevo registro
    int id_register_subprog_variable = reg_manager.get_next_subprog_register();

    // --- 4.B.1.A.2 Obtener operando de variable local
    IR_operand op_reg_var_local = instructions.emit_operand_register(id_register_subprog_variable);

    // --- 4.B.1.A.3 Obtener variable para valor de inicializacion
    IR_variable var_local(IR_VAR_LOCAL,var_name.c_str(),var_type);
    var_local.set_precedence(this->precedence);

    int id_literal_in_table;
    switch (var_local.get_type())
    {
    case IR_VAR_TYPE_INT:
    {
        id_literal_in_table = tables.add_entry_literal(var_local.get_initial_value<int>());
        break;
    }
    case IR_VAR_TYPE_REAL:
    {
        id_literal_in_table = tables.add_entry_literal(var_local.get_initial_value<float>());
        break;
    }
    case IR_VAR_TYPE_CHAR:
    {
        id_literal_in_table = tables.add_entry_literal(var_local.get_initial_value<char>());
        break;
    }
    case IR_VAR_TYPE_STR:
    {
        id_literal_in_table = tables.add_entry_literal(var_local.get_initial_value<std::string>());
        break;
    }
    case IR_VAR_TYPE_BOOL:
    {
        id_literal_in_table = tables.add_entry_literal(var_local.get_initial_value<bool>());
        break;
    }
    default:
        break;
    }
    IR_operand op_var_init_v = instructions.emit_operand_literal(id_literal_in_table);

    // --- 4.B.1.A.4 Emitir instruccion de inicializacion de variable local de subprograma
    instructions.emit_instruction(IR_OP_STORE,op_reg_var_local,op_var_init_v);

    // --- 4.B.1.A.5 Registrar declaracion de variable local
    assistant_translator.insert_var_local_subprog(var_name,id_register_subprog_variable);

    // --- Retornar registro asociado a variable
    return id_register_subprog_variable;
}

void IR_Translator_Declaration::translate_declaration_to_ir_instruction(struct declaration * decl, bool from_subprogram){
    // --- 1. Obtener nombre de variable
    std::string var_name = std::string(decl->name);

    // --- 2. Obtener scope de variable
    IR_variable_t var_scope = get_variable_scope(var_name,decl->symb->kind);

    // --- 3. Obtener tipo de dato de variable
    IR_variable_type_t var_type = get_type_variable(var_name,decl->type->kind);

    // --- 4. Comprobar si la variable es de tipo array
    // ---- Identificador de registro de variable
    int id_variable_in_table = 0; int id_register_subprog_variable = 0;
    if(var_type == IR_VAR_TYPE_ARRAY){
        // --- 4.A.1 Obtener subtipo de dato
        var_type = get_type_variable(var_name,decl->type->subtype->kind);

        // --- 4.A.2 Obtener longitud de array
        // ---- FUTURE (por ahora se sabe que si paso el typechecking es porque es un literal puro integer)
        size_t var_size = decl->type->size->expr.expression_literal.value.integer_literal; 

        ///////////////////////////////////////////////////////////////////////////////////////

        /// --- 4.A.3 Comprobar si es una declaracion de un subprograma
        if(from_subprogram){ 
            for(int i=0; i<var_size; i++)
                initialize_variable_local_subprogram(var_name,var_type);
        }
        else{
            if(var_scope == IR_VAR_GLOBAL){
                // -- 4.A.3.A Registrar variable
                id_variable_in_table = tables.add_entry_variable(var_scope,var_name,var_type,var_size);
            }
            else{
                // -- 4.A.3.A Registrar variable
                id_variable_in_table = tables.add_entry_variable(var_scope,var_name,precedence,var_type,var_size);
            }
            
        }

        ///////////////////////////////////////////////////////////////////////////////////////
    }
    else{

        ///////////////////////////////////////////////////////////////////////////////////////

        // --- 4.B.1 Comprobar si es una declaracion de un subprograma
        if(from_subprogram){
            id_register_subprog_variable = initialize_variable_local_subprogram(var_name,var_type);
        }
        else{
            if(var_scope == IR_VAR_GLOBAL){
                // --- 4.B.1.B.1 Registrar variable
                id_variable_in_table = tables.add_entry_variable(var_scope,var_name,var_type);
            }
            else{
                // --- 4.B.1.B.1 Registrar variable
                id_variable_in_table = tables.add_entry_variable(var_scope,var_name,precedence,var_type);
            }
            
        }

        ///////////////////////////////////////////////////////////////////////////////////////
    }
    
    // --- 5. Evaluar valor de variable
    if(decl->value){
        // --- 5.0 Optimizar expresion
        decl->value = expr_translator.optimize(decl->value);
        // --- 5.1 Traducir expresion de asignacion a instruccion IR
        const int id_reg_value = expr_translator.translate(decl->value,from_subprogram);
        if(id_reg_value == -1){
            // ----- Exception
            std::string MSG = "[IR_Translation] No se pudo traducir expresion de inicio para variable: ";
            MSG += var_name;
            
            throw std::runtime_error(MSG);
        }

        ///////////////////////////////////////////////////////////////////////////////////////

        IR_operand op_dest, op_1;

        // --- 5.2 Comprobar si la declaracion es de un subprograma
        if(from_subprogram){
            // --- 5.2.A.1 Emitir instruccion de almacenamiento de valor en variable
            // ---- Operando de destino
            op_dest = instructions.emit_operand_register(id_register_subprog_variable);
            // ---- Operando de carga
            op_1 = instructions.emit_operand_register(id_reg_value);

            instructions.emit_instruction(IR_OP_STORE,op_dest,op_1);
        }
        else{
            // --- 5.2.B.1 Emitir instruccion de almacenamiento de valor en variable
            // ---- Operando de destino
            op_dest = instructions.emit_operand_variable(id_variable_in_table);
            // ---- Operando de carga
            op_1 = instructions.emit_operand_register(id_reg_value);

            instructions.emit_instruction(IR_OP_STORE,op_dest,op_1);
        }

        ///////////////////////////////////////////////////////////////////////////////////////
    }
}

void IR_Translator_Declaration::translate_list_declarations_to_ir_instructions(struct declaration * list_decl, bool from_subprogram){
    struct declaration *current_decl = list_decl;
    while(current_decl != NULL){
        expr_translator.set_precedence(precedence);

        // -- Traducir declaracion
        this->translate_declaration_to_ir_instruction(current_decl,from_subprogram);

        expr_translator.reset_precedence();

        // -- Ir a siguiente declaracion
        current_decl = current_decl->next;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_Translator_Declaration] -----

IR_Translator_Declaration& IR_Translator_Declaration::get_instance(){
    static IR_Translator_Declaration instance;
    return instance;
}

void IR_Translator_Declaration::translate(struct declaration * list_decl, bool from_subprogam){
    this->translate_list_declarations_to_ir_instructions(list_decl,from_subprogam);
}