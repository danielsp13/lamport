/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file registers.cpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de tabla de registros para la maquina virtual de lamport
 */

#include "LVM/CPU/registers.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [REGISTER TABLE] -----

LVM_CPU_Registers& LVM_CPU_Registers::get_instance(){
    static LVM_CPU_Registers instance;
    return instance;
}

void LVM_CPU_Registers::operator()(int i, const LVM_Memory_Block& mem_block){

    // -- Obtener tipo de dato que contiene mem_block
    LVM_Block_type_t allocates_type = mem_block.get_type_of_alloc();

    // -- Crear registro para insertar
    LVM_Register reg;

    // -- Comprobar
    switch (allocates_type)
    {
    case BLOCK_INTEGER:
    {   
        reg.allocate_value<int>(mem_block.get_value<int>());
        break;
    }
    case BLOCK_REAL:
    {   
        reg.allocate_value<float>(mem_block.get_value<float>());
        break;
    }
    case BLOCK_CHAR:
    {   
        reg.allocate_value<char>(mem_block.get_value<char>());
        break;
    }
    case BLOCK_STRING:
    {   
        reg.allocate_value<std::string>(mem_block.get_value<std::string>());
        break;
    }
    case BLOCK_BOOL:
    {   
        reg.allocate_value<bool>(mem_block.get_value<bool>());
        break;
    }
    default:
        throw std::invalid_argument("ALMACENAMIENTO A REGISTRO DE UN BLOQUE DE MEMORIA INVALIDO.");
        break;
    }

    // -- Insertar registro en tabla
    this->registers[i] = reg;
}

const LVM_Register& LVM_CPU_Registers::operator()(int i) const{
    if(i >= this->registers.size())
        throw std::out_of_range("INDICE DE REGISTRO FUERA DE RANGO.");

    return this->registers[i];
}

LVM_Register& LVM_CPU_Registers::operator[](int i){
    return this->registers[i];
}

const LVM_Register& LVM_CPU_Registers::operator[](int i) const{
    if(i >= this->registers.size())
        throw std::out_of_range("INDICE DE REGISTRO FUERA DE RANGO.");

    return this->registers[i];
}

void LVM_CPU_Registers::restore_registers(std::vector<LVM_Register> regs){
    this->registers = regs;
}

void LVM_CPU_Registers::print_registers(std::ostream & os){
    const std::string TABLE_SEPARATOR = "===================================================================";
    const int gap = 16;

    const int MAX_REGS_TO_PRINT = 100;

    os << TABLE_SEPARATOR << std::endl;
    os << std::left << "TABLA DE REGISTROS" << std::endl;
    os << TABLE_SEPARATOR << std::endl;
    os << std::left << std::setw(gap) << "Numero" << std::setw(gap) << "Tipo de Alloc." << std::setw(gap) << "Valor" << std::endl;
    os << TABLE_SEPARATOR << std::endl;

    LVM_Register reg;
    for(unsigned i=0; i<MAX_REGS_TO_PRINT; i++){
        // -- Obtener literal
        reg = registers[i];

        // -- Imprimir contenido
        os << std::left << std::setw(gap) << i << std::setw(gap) << reg.get_type_of_alloc_str() << std::setw(gap) << reg.get_value_str() << std::endl;
    }
   
}