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

void LVM::print_pages_table(std::ostream& os){
    if(this->state == LVM_STATE_BORN)
        return;

    LVM_Page_Table::get_instance().print_page_table(os);
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

        // -- Imprimir contenido (si esta habilitado)
        if(verbose_avaiable){
            // -- Imprimir tabla de paginas
            this->print_pages_table();

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
        
        // -- Ejecucion de listado de instrucciones
        cpu.execute_instructions();

        return true;
    }
    
    return false;
}