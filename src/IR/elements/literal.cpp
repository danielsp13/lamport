/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file literal.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para generacion
 * de codigo intermedio  (Literales de IR Lineal)
 */

#include "IR/elements/literal.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [LITERAL] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [LITERAL] -----

std::string IR_literal::to_string() const{
    std::string lit_str;
    switch (kind)
    {
    case IR_LIT_INTEGER:
    {
        lit_str = std::to_string(std::get<int>(lit));
        break;
    }
    case IR_LIT_REAL:
    {
        lit_str = std::to_string(std::get<float>(lit));
        break;
    }
    case IR_LIT_CHAR:
    {
        lit_str = "\'" + std::string(1, std::get<char>(lit)) + "\'";
        break;
    }
    case IR_LIT_STRING:
    {
        lit_str = std::get<std::string>(lit);
        
        if(lit_str == std::string("\n"))
            lit_str = std::string("\"\\n\"");

        break;
    }
    case IR_LIT_BOOLEAN:
    {
        lit_str = std::get<bool>(lit) ? "true" : "false";
        break;
    }
    
    default:
        break;
    }

    return lit_str;
}

std::string IR_literal::get_kind_str() const{
    std::string kind_str;

    auto it = IR_literal_t_str.find(kind);
    if(it != IR_literal_t_str.end())
        kind_str = it->second;

    return kind_str;
};