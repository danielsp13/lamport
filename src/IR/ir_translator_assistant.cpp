/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_assistant.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del asistente de traduccion de codigo intermedio Lineal (IR)
 */

#include "IR/ir_translator_assistant.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Assistant] -----

int IR_Translator_Assistant::get_index_var_local_subprog(std::string local_name){
    for(int i=0; i<locals_subprog.size(); i++){
        if(locals_subprog[i].first == local_name)
            return i;
    }
    
    // ----- Excepcion
    /*std::string MSG = "[IR_Translation_Assistant] El asistente no pudo encontrar informacion de variable local de subprograma: ";
    MSG += local_name;

    throw std::runtime_error(MSG);*/
    return -1;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_Translator_Assistant] -----

void IR_Translator_Assistant::insert_var_local_subprog(std::string local_name, int reg_addr){
    std::pair<std::string,int> var_local_info;
    var_local_info.first = local_name;
    var_local_info.second = reg_addr;

    locals_subprog.push_back(var_local_info);
    
}

int IR_Translator_Assistant::get_reg_from_var_local_subprog(std::string local_name){
    int index = get_index_var_local_subprog(local_name);

    if(index == -1)
        return -1;
    
    // -- Retornar registro
    return locals_subprog[index].second;
}

int IR_Translator_Assistant::get_reg_from_var_local_subprog(std::string local_name, int offset){
    int index = get_index_var_local_subprog(local_name);

    if(index+offset >= locals_subprog.size()){
        // ----- Excepcion
        std::string MSG = "[IR_Translation_Assistant] El asistente no pudo obtener el registro de variable local (array) de subprograma: ";
        MSG += local_name;

        throw std::runtime_error(MSG);
    }

    return locals_subprog[index+offset].second;
}

bool IR_Translator_Assistant::is_var_local_subprog(std::string var_name){
    for(int i=0; i<locals_subprog.size(); i++){
        if(locals_subprog[i].first == var_name)
            return true;
    }

    return false;
}

IR_Translator_Assistant& IR_Translator_Assistant::get_instance(){
    static IR_Translator_Assistant instance;
    return instance;
}

