/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_decl.cpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para DECLARACIONES (IR)
 */

#include "IR/ir_translator_decl.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Declaration] -----

void IR_Translator_Declaration::translate_declaration_to_ir_instruction(struct declaration * decl, bool from_subprogram){
    // --- 1. Obtener nombre de variable
    std::string var_name = std::string(decl->name);

    // --- 2. Obtener scope de variable
    auto var_scope = AST_symbol_IR_var_t.find(decl->symb->kind);
    // ------ Comprobar que se encontro scope
    if(var_scope == AST_symbol_IR_var_t.end())
        return;

    // --- 3. Obtener tipo de dato de variable
    auto var_type = AST_type_IR_type.find(decl->type->kind);
    // ------ Comprobar que se encontro tipo de dato
    if(var_type == AST_type_IR_type.end())
        return;

    // --- 5. Comprobar si la variable es de tipo array
    // ---- Identificador de registro de variable
    int id_variable_in_table = 0; int id_register_subprog_variable = 0;
    if(var_type->second == IR_VAR_TYPE_ARRAY){
        var_type = AST_type_IR_type.find(decl->type->subtype->kind);
        if(var_type == AST_type_IR_type.end())
            return;

        // --- 5.1 Obtener longitud de array
        // ---- FUTURE (por ahora se sabe que si paso el typechecking es porque es un literal puro integer)
        size_t var_size = decl->type->size->expr.expression_literal.value.integer_literal; 

        ///////////////////////////////////////////////////////////////////////////////////////

        /// ---- Comprobar si es una declaracion de un subprograma
        if(from_subprogram){
            // -- 4.2 
            /// TODO
        }
        else{
            // -- 4.2 Registrar variable
            id_variable_in_table = tables.add_entry_variable(var_scope->second,var_name,var_type->second,var_size);
        }

        ///////////////////////////////////////////////////////////////////////////////////////
    }
    else{

        ///////////////////////////////////////////////////////////////////////////////////////

        /// ---- Comprobar si es una declaracion de un subprograma
        if(from_subprogram){
            // -- Obtener nuevo registro
            id_register_subprog_variable = reg_manager.get_next_register();

            // -- Incluir en el registro de variables locales
            assistant_translator.insert_var_local_subprog(var_name,id_register_subprog_variable);

            // -- Obtener operando de variable local
            IR_operand op_var_local = instructions.emit_operand_register(id_register_subprog_variable);

            // -- Obtener variable para valor de inicializacion
            IR_variable var_local(IR_VAR_LOCAL,var_name.c_str(),var_type->second);

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

            // -- Emitir instruccion de inicializacion de variable local de subprograma
            instructions.emit_instruction(IR_OP_STORE,op_var_local,op_var_init_v);

            // -- Emitir instruccion de push local
            instructions.emit_instruction(IR_OP_PUSH_LOCAL, op_var_local);
        }
        else{
            // -- 5. Registrar variable
            id_variable_in_table = tables.add_entry_variable(var_scope->second,var_name,var_type->second);
        }

        ///////////////////////////////////////////////////////////////////////////////////////
    }
    
    // --- 4. Evaluar valor de variable
    if(decl->value){
        // --- 4.1 Traducir expresion de asignacion a instruccion IR
        const int id_reg_value = expr_translator.translate(decl->value,from_subprogram);
        if(id_reg_value == -1){
            // -- Manejar error en traduccion //FUTURE
            return;
        }

        ///////////////////////////////////////////////////////////////////////////////////////

        IR_operand op_dest, op_1;

        // --- Comprobar si la declaracion es de un subprograma
        if(from_subprogram){
            // --- 4.3 Emitir instruccion de almacenamiento de valor en variable
            // ---- Operando de destino
            op_dest = instructions.emit_operand_register(id_register_subprog_variable);
            // ---- Operando de carga
            op_1 = instructions.emit_operand_register(id_reg_value);

            instructions.emit_instruction(IR_OP_STORE,op_dest,op_1);
        }
        else{
            // --- 4.3 Emitir instruccion de almacenamiento de valor en variable
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
        // -- Traducir declaracion
        this->translate_declaration_to_ir_instruction(current_decl,from_subprogram);

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