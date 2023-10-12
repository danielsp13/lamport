/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_builder.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del constructor de codigo intermedio Lineal (IR)
 */

#include "IR/ir_builder.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_BUILDER] -----

void IR_Builder::translate_program_to_ir_instructions(struct program * prog){
    // 1. Obtener nombre de programa
    std::string prog_name = std::string(prog->name_program);

    // 3. Generar etiqueta de entrada de programa
    int id_label_in_table = tables.add_entry_label(std::string("prog_") + prog_name,instructions.size()+1);

    // 4. Emitir instruccion de punto de entrada de proceso
    IR_operand op_label = instructions.emit_operand_label(id_label_in_table);

    instructions.emit_instruction(IR_LABEL,op_label);

    // 0. Emitir instruccion de inicio de programa
    instructions.emit_instruction(IR_START_PROGRAM);

    // -- Comprobar los subprogramas del programa
    if(prog->subprograms){
        instructions.emit_instruction(NOT_IR_START_SUBPROGRAM_INSTR);
        // -- Traducir lista de subprogramas
        subprog_translator.translate(prog->subprograms);
        instructions.emit_instruction(NOT_IR_END_SUBPROGRAM_INSTR);
    }

    // -- Comprobar las declaraciones globales del programa
    if(prog->declarations){
        // -- Traducir lista de declaraciones
        decl_translator.translate(prog->declarations);
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

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_BUILDER] -----

IR_Builder& IR_Builder::get_instance(){
    static IR_Builder instance;
    return instance;
}

int IR_Builder::build(bool verbose_avaiable){
    // -- Generar traduccion a IR de programa
    this->translate_program_to_ir_instructions(AST_program);

    if(verbose_avaiable){
        // -- Imprimir tablas
        tables.print_literals_table(); std::cout << std::endl;
        tables.print_variables_table(); std::cout << std::endl;
        tables.print_labels_table(); std::cout << std::endl;

        // -- Imprimir instrucciones IR
        IR_Printer::get_instance().print_ir_instructions();
    }

    return 0;
}