/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_thread_id_manager.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del asignador de registros virtuales para representacion intermedia
 */

#include "IR/tweaks/ir_thread_id_manager.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_MANAGER] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_MANAGER] -----
int IR_Thread_Id_Manager::get_id(){ 
    last_id_thread = id_thread;
    return id_thread++; 
};

int IR_Thread_Id_Manager::get_last_id(){
    return last_id_thread;
}

IR_Thread_Id_Manager& IR_Thread_Id_Manager::get_instance(){
    static IR_Thread_Id_Manager instance;
    return instance;
}