/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_assistant.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del asistente de traduccion de codigo intermedio Lineal (IR)
 */

#include "IR/ir_translator_assistant.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Assistant] -----

void IR_Translator_Assistant::insert_var_local_subprog(std::string var_local_name, int reg_addr){
    std::pair<std::string,int> var_local_info;
    var_local_info.first = var_local_name;
    var_local_info.second = reg_addr;

    var_local_subprog.push_back(var_local_info);
}

int IR_Translator_Assistant::get_reg_from_var_local_name_subprog(std::string var_local_name){
    for(int i=0; i<var_local_subprog.size(); i++){
        if(var_local_subprog[i].first == var_local_name)
            return var_local_subprog[i].second;
    }

    return -1;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_Translator_Assistant] -----

IR_Translator_Assistant& IR_Translator_Assistant::get_instance(){
    static IR_Translator_Assistant instance;
    return instance;
}

