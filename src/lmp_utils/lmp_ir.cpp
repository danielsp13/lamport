/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_ir.cpp
 * @author Daniel Perez Ruiz
 * @brief Gestor de codigo intermedio de interprete lamport
 */

#include "lmp_utils/lmp_ir.hpp"


// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR MANAGER] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR MANAGER] -----

LMP_IR_Manager& LMP_IR_Manager::get_instance(){
    static LMP_IR_Manager instance;
    return instance;
}

int LMP_IR_Manager::start(bool verbose_avaiable){
    tasker.task_translate_to_ir();
    tasker.task_ok();
    ir_builder.build(verbose_avaiable);
    
    return EXIT_SUCCESS;
}