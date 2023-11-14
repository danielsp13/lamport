/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_prog.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del constructor de codigo intermedio Lineal para PROGRAMAS (IR)
 */

#include "IR/translators/ir_translator_prog.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Program] -----

void IR_Translator_Program::translate_program_to_ir_instructions(struct program * prog){
    // 1. Obtener nombre de programa
    std::string prog_name = std::string(prog->name_program);

    // 3. Generar etiqueta de entrada de programa
    int id_label_in_table = tables.add_entry_label(std::string("prog_") + prog_name,instructions.size()+1);

    // 4. Emitir instruccion de punto de entrada de proceso
    IR_operand op_label = instructions.emit_operand_label(id_label_in_table);

    instructions.emit_instruction(IR_LABEL,op_label);

    // 0. Emitir instruccion de inicio de programa
    instructions.emit_instruction(IR_START_PROGRAM);
    
    // -- Comprobar las declaraciones globales del programa
    if(prog->declarations){
        instructions.emit_instruction(IR_INITIALIZE_GLOBAL_VAR);
        // -- Traducir lista de declaraciones
        decl_translator.translate(prog->declarations);
        instructions.emit_instruction(IR_END_INITIALIZE_GLOBAL_VAR);
    }

    // -- Comprobar los subprogramas del programa
    if(prog->subprograms){
        // -- Traducir lista de subprogramas
        subprog_translator.translate(prog->subprograms);
    }

    // -- Comprobar los procesos del programa
    if(prog->process){
        // -- Traducir lista de procesos
        proc_translator.translate(prog->process);
    }

    // 8. Emitir instruccion de fin de programa
    instructions.emit_instruction(IR_END_PROGRAM);
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_Translator_Program] -----

IR_Translator_Program& IR_Translator_Program::get_instance(){
    static IR_Translator_Program instance;
    return instance;
}

void IR_Translator_Program::translate(){
    translate_program_to_ir_instructions(AST_program);
}