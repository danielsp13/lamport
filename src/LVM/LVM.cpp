/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file LVM.cpp
 * @author Daniel Perez Ruiz
 * @brief Maquina Virtual de Lamport
 */

#include "LVM/LVM.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [LVM] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [LVM] -----

LVM& LVM::get_instance(){
    static LVM instance;
    return instance;
}

LVM::~LVM(){
    if(this->state != LVM_STATE_DEAD)
        this->state = LVM_STATE_SHUTDOWN;
}

void LVM::print_segment_table(std::ostream& os){
    if(this->state == LVM_STATE_BORN)
        return;

    LVM_Segment_Table::get_instance().print_segment_table(os);
}

void LVM::print_memory(std::ostream& os){
    if(this->state == LVM_STATE_BORN)
        return;

    LVM_Memory::get_instance().print_memory(os);
}

bool LVM::preload_lvm(bool verbose_avaiable){
    if(this->state == LVM_STATE_BORN){
        // -- Cambiar estado a prepared
        this->state = LVM_STATE_PREPARED;

        // -- Volcar contenido a memoria
        this->initializer.dump_to_memory();

        // -- Crear hebras iniciales
        this->initializer.create_threads();

        // -- Imprimir contenido (si esta habilitado)
        if(verbose_avaiable){
            // -- Imprimir tabla de paginas
            this->print_segment_table();

            // -- Imprimir memoria
            this->print_memory();
        }

        return true;
    }
    
    return false;
}

bool LVM::run(){
    if(this->state == LVM_STATE_PREPARED){
        // -- Cambiar estado a ejecutandose
        this->state == LVM_STATE_RUNNING;

        // -- Preinicializar el programa
        cpu.pre_start();
        
        // -- Ejecucion de listado de instrucciones
        while(cpu.get_program_counter() < cpu.get_total_instructions()){
            cpu.execute_next_instruction();
        }

        return true;
    }
    
    return false;
}