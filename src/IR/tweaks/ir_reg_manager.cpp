/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_reg_manager.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del asignador de registros virtuales para representacion intermedia
 */

#include "IR/tweaks/ir_reg_manager.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_MANAGER] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_MANAGER] -----

IR_Reg_Manager& IR_Reg_Manager::get_instance(){
    static IR_Reg_Manager instance;
    return instance;
}

int IR_Reg_Manager::get_next_general_purpose_register(){
    return this->reg_general_purpose_id++;
}

void IR_Reg_Manager::reset_general_purpose_register_counter(){
    if(!RESET_REGISTERS_AVARIABLE)
        return;

    this->reg_general_purpose_id = STARTING_REG_GENERAL_PURPOSE;
}

int IR_Reg_Manager::get_next_subprog_register(){
    // -- Comprobar que hay registros disponibles
    if(this->reg_subprogram_vars_id > ENDING_REG_SUBPROGRAM_VARS){
        std::string MSG = "subprograma tiene demasiadas variables locales y parámetros para ser gestionado por la máquina virtual. Máximo permitido: ";
        MSG += std::to_string(ENDING_REG_SUBPROGRAM_VARS);

        throw std::runtime_error(MSG);
    }

    return this->reg_subprogram_vars_id++;
}

int IR_Reg_Manager::get_return_subprog_register(){
    return this->RETURN_REG_SUBPROGRAM_FUNCTION;
}

void IR_Reg_Manager::reset_subprog_register_counter(){
    this->reg_subprogram_vars_id = STARTING_REG_SUBPROGRAM_VARS;
}