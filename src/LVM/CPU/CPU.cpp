/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file CPU.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de CPU para la maquina virtual de lamport
 */

#include "LVM/CPU/CPU.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [CPU] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [CPU] -----

LVM_CPU& LVM_CPU::get_instance(){
    static LVM_CPU instance;
    return instance;
}


void LVM_CPU::execute_next_instruction(LVM_Thread * current_thread){
    // -- Indicar contador de programa a CPU
    registers.set_pc(current_thread->get_pc());
    // -- Colocar registros
    registers.set_registers(current_thread->get_registers());

    // -- Indicar segmento de direcciones de hebra
    CU.set_segment_thread(current_thread->get_segment());

    // -- Captar siguiente instruccion
    CU.fetch();

    if(current_thread){
        // -- Actualizar pc de hebra
        current_thread->set_pc(registers.get_pc());
        // -- Actualizar registros de hebra
        current_thread->set_registers(registers.get_registers());

        // -- Notificar que la hebra ha ejecutado la instruccion
        current_thread->instruction_executed();
    }
    

    // -- Actualizar nuevo ciclo de CPU
    cycle_counter++;
}