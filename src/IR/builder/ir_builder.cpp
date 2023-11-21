/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_builder.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del constructor de codigo intermedio Lineal (IR)
 */

#include "IR/builder/ir_builder.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_BUILDER] -----

void IR_Builder::instructions_to_str(){
    for(int i=0; i<instructions.size(); i++){
        printer.add_ir_instruction_to_printer(instructions[i]);
    }
}

void IR_Builder::reparse_dynamic_process(){
    // -- ID de proceso estatico
    int id_static_proc;
    // -- ID de proceso dinamico
    int id_dynamic_proc;
    // -- Direccion de salto directo
    IR_operand jmp_addr;
    // -- Operando de id
    IR_operand id_op;

    // -- Flags de comprobacion
    bool pc_found = false;


    for(int i=0; i<instructions.size(); i++){
        // -- Obtener instruccion
        pc_found = false;
        IR_instruction instr = instructions[i];
        // -- Comprobar si el codigo de instruccion es START_PROCESS
        if(instr.get_code_instr() == IR_START_PROCESS){
            id_static_proc = instr.get_operand_1().value().get_address();
            continue;
        }

        // -- Comprobar si el codigo de instruccion es WAIT_PROCESS
        if(instr.get_code_instr() == IR_WAIT_PROCESS){
            // -- Obtener operando de id
            id_op = instructions.emit_operand_id_thread(id_static_proc);

            instructions[i] = IR_instruction(IR_WAIT_PROCESS,id_op);

            continue;
        }

        // -- Comprobar si el codigo de instruccion es START_DYNAMIC_PROCESS
        if(instr.get_code_instr() != IR_START_DPROCESS)
            continue;
        
        // -- Definir nuevo id para thread
        id_dynamic_proc = id_thread_manager.get_id();
        id_op = instructions.emit_operand_id_thread(id_dynamic_proc);

        for(int j=i+1; j<instructions.size(); j++){
            IR_instruction fwrd_instr = instructions[j];
            // -- Buscar otro START_DYNAMIC_PROCESS
            if(fwrd_instr.get_code_instr() == IR_START_DPROCESS){
                // -- Modificar instruccion START_DYNAMIC_PROCESS
                jmp_addr = instructions.emit_operand_direct_jmp(j);

                instructions[i] = IR_instruction(IR_START_DPROCESS,jmp_addr,id_op,instr.get_operand_2().value());
                pc_found = true;
                break;
            }

            // -- Buscar su correspondiente END_PROCESS
            if(fwrd_instr.get_code_instr() == IR_END_PROCESS){
                if(!fwrd_instr.get_operand_1().has_value()){
                    // -- Modificar instruccion END_PROCESS
                    instructions[j] = IR_instruction(IR_END_PROCESS,id_op);

                    // -- Modificar instruccion START_DYNAMIC_PROCESS
                    jmp_addr = instructions.emit_operand_direct_jmp(j+1);

                    instructions[i] = IR_instruction(IR_START_DPROCESS,jmp_addr,id_op);
                    pc_found = true;
                }
                break;
            }
        }

        if(!pc_found){
            // -- Modificar instruccion START_DYNAMIC_PROCESS
            jmp_addr = instructions.emit_operand_direct_jmp(i+1);
            instructions[i] = IR_instruction(IR_START_DPROCESS,jmp_addr,id_op,instr.get_operand_2().value());
        }
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_BUILDER] -----

IR_Builder& IR_Builder::get_instance(){
    static IR_Builder instance;
    return instance;
}

int IR_Builder::build(bool verbose_avaiable){
    // -- Generar traduccion a IR de programa
    prog_translator.translate();
    // -- Repasar
    reparse_dynamic_process();
    // -- Pasar lista de instrucciones IR a formato string
    instructions_to_str();

    if(verbose_avaiable){
        // -- Imprimir tablas
        tables.print_literals_table(); std::cout << std::endl;
        tables.print_variables_table(); std::cout << std::endl;
        tables.print_labels_table(); std::cout << std::endl;

        // -- Imprimir instrucciones IR
        printer.print_ir_instructions();
    }

    return 0;
}