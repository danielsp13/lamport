/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file variable.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para generacion
 * de codigo intermedio  (Variables de IR Lineal)
 */

#include "IR/variable.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_VARIABLE_TYPE] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_VARIABLE_TYPE] -----

std::string IR_variable_type::get_type_str(){
    std::string type_str;

    auto it = IR_variable_type_t_str.find(type);
    if(it != IR_variable_type_t_str.end())
        type_str = it->second;

    if(is_array()){
        it = IR_variable_type_t_str.find(array_subtype);
        if(it != IR_variable_type_t_str.end())
            type_str += " [" + it->second + "]";
    }

    // Retornar tipo
    return type_str;
};

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_VARIABLE] -----

void IR_variable::initialize_variable(){
    const IR_variable_type_t kind = this->is_array() ? get_array_type() : get_type();
    switch (kind)
    {
    case IR_VAR_TYPE_INT:
    {   
        value = static_cast<int>(0);
        break;
    }
    case IR_VAR_TYPE_REAL:
    {
        value = static_cast<float>(0.0);
        break;
    }
    case IR_VAR_TYPE_CHAR:
    {
        value = '\0';
        break;
    }
    case IR_VAR_TYPE_STR:
    {
        value = std::string("");
        break;
    }
    case IR_VAR_TYPE_BOOL:
    {
        value = false;
        break;
    }
    
    default:
        break;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_VARIABLE] -----

std::string IR_variable::get_kind_str(){
    std::string kind_str;

    auto it = IR_variable_t_str.find(kind);
    if(it != IR_variable_t_str.end())
        kind_str = it->second;

    return kind_str;
};

std::string IR_variable::get_initial_value_str() const{
    IR_variable_type_t var_type = get_type();
    if(var_type == IR_VAR_TYPE_ARRAY || var_type == IR_VAR_TYPE_PROCESS || var_type == IR_VAR_TYPE_SUBPROGRAM)
        return "------";
    
    return std::visit([](auto&& arg) -> std::string {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::string>) {
            return "\"" + arg + "\"";
        } else if constexpr (std::is_same_v<T, char>) {
            if(arg == '\0')
                return std::string("\'\'");
            return "\'" + std::string(1, arg) + "\'"; // Convertir char a std::string
        } else {
            return std::to_string(arg);
        }
    }, value);
}