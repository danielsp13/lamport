/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file stack_block.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de bloque de pila para la maquina virtual de lamport
 */

#include "LVM/stack_block.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [STACK BLOCK] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [STACK BLOCK] -----

std::string LVM_Stack_Block::get_type_of_alloc_str() const{
    std::string allocates_type_str;

    auto it = LVM_Stack_Block_type_t_str.find(this->allocates_type);
    if(it != LVM_Stack_Block_type_t_str.end())
        allocates_type_str = it->second;

    return allocates_type_str;
}

std::string LVM_Stack_Block::get_value_str() const{
    std::string value_allocated_str;
    switch (this->allocates_type)
    {
    case STACK_BLOCK_EMPTY:
    {
        value_allocated_str = std::string("NULL");
        break;
    }
    case STACK_BLOCK_INTEGER:
    {
        value_allocated_str = std::to_string(std::get<int>(value_allocated));
        break;
    }
    case STACK_BLOCK_REAL:
    {
        value_allocated_str = std::to_string(std::get<float>(value_allocated));
        break;
    }
    case STACK_BLOCK_CHAR:
    {
        char ch = std::get<char>(value_allocated);
    
        switch(ch) {
            case '\n': 
            {
                value_allocated_str = "'\\n'"; 
                break;
            }
            case '\t':
            {
                value_allocated_str = "'\\t'";
                break;
            }
            case '\r':
            {
                value_allocated_str = "'\\r'";
                break;
            }
            case '\0':
            {
                value_allocated_str = "\'\'";
                break;
            }
            
            default:
            {
                if(std::isprint(ch)) { // Si es un caracter imprimible
                    value_allocated_str = "'" + std::string(1, ch) + "'";
                } else { 
                    // Convertir caracteres no imprimibles a su representación hexadecimal
                    std::ostringstream oss;
                    oss << "'\\x" << std::setfill('0') << std::setw(2) << std::hex << (int)ch << "'";
                    value_allocated_str = oss.str();
                }
                break;
            }
                
        }
        
        break;
    }
    case STACK_BLOCK_STRING:
    {
        value_allocated_str = std::get<std::string>(value_allocated);
        
        if(value_allocated_str == std::string("\n"))
            value_allocated_str = std::string("\"\\n\"");
        else
            value_allocated_str = "\"" + value_allocated_str + "\"";

        break;
    }
    case STACK_BLOCK_BOOL:
    {
        value_allocated_str = std::get<bool>(value_allocated) ? std::string("true") : std::string("false");
        break;
    }
    case STACK_BLOCK_ADDRESS_INSTR:
    {
        // Usar un ostringstream para formatear el número
        std::ostringstream instr_int;
        instr_int << "0i" << std::setfill('0') << std::setw(4) << std::to_string(std::get<long>(value_allocated));

        value_allocated_str = instr_int.str();
        break;
    }
    
    default:
        value_allocated_str = std::string("UNDEFINED");
        break;
    }

    return value_allocated_str;
}