/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_reg_manager.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del asignador de registros virtuales para representacion intermedia
 */

#include "IR/ir_reg_manager.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_MANAGER] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_MANAGER] -----

IR_Reg_Manager& IR_Reg_Manager::get_instance(){
    static IR_Reg_Manager instance;
    return instance;
}