/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file thread_stack.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de pila de hebra lamport
 */

#include "LVM/SO/thread_stack.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS -----

void LVM_Thread_Stack::push(const LVM_Register& reg){
    // -- Generar bloque de pila e insertar
    LVM_Block stack_block;

    switch (reg.get_type_of_alloc())
    {
    case REG_CONTAINS_INTEGER:
    {
        stack_block.allocate_value<int>(reg.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        stack_block.allocate_value<float>(reg.get_value<float>());
        break;
    }
    case REG_CONTAINS_CHAR:
    {
        stack_block.allocate_value<char>(reg.get_value<char>());
        break;
    }
    case REG_CONTAINS_STRING:
    {
        stack_block.allocate_value<std::string>(reg.get_value<std::string>());
        break;
    }
    case REG_CONTAINS_BOOL:
    {
        stack_block.allocate_value<bool>(reg.get_value<bool>());
        break;
    }
    default:
        throw std::invalid_argument("NO SE PUDO ALOJAR UN BLOQUE DE PILA CORRECTAMENTE.");
        break;
    }

    // -- Insertar en pila
    stack.push_back(stack_block);
    // -- Aumentar puntero de pila
    top_pointer = stack.size()-1;
}

void LVM_Thread_Stack::push_ret_dir(long ret_dir){
    LVM_Block block; block.allocate_value<long>(ret_dir);
    stack.insert(stack.begin(),block);
    top_pointer = stack.size()-1;
}


LVM_Block LVM_Thread_Stack::top_and_pop(){
    LVM_Block block = stack[top_pointer];
    stack.pop_back();
    top_pointer = stack.size()-1;

    return block;
}

LVM_Register LVM_Thread_Stack::top_and_pop_reg(){
    LVM_Block stack_block = top_and_pop();
    LVM_Register reg;

    switch (stack_block.get_type_of_alloc())
    {
    case BLOCK_INTEGER:
    {
        reg.allocate_value<int>(stack_block.get_value<int>());
        break;
    }
    case BLOCK_REAL:
    {
        reg.allocate_value<float>(stack_block.get_value<float>());
        break;
    }
    case BLOCK_CHAR:
    {
        reg.allocate_value<char>(stack_block.get_value<char>());
        break;
    }
    case BLOCK_STRING:
    {
        reg.allocate_value<std::string>(stack_block.get_value<std::string>());
        break;
    }
    case BLOCK_BOOL:
    {
        reg.allocate_value<bool>(stack_block.get_value<bool>());
        break;
    }
    default:
        throw std::invalid_argument("NO SE PUDO ALOJAR UN BLOQUE DE PILA CORRECTAMENTE.");
        break;
    }

    return reg;
}