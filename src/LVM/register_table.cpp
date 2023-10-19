/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file register_table.cpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de tabla de registros para la maquina virtual de lamport
 */

#include "LVM/register_table.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [REGISTER TABLE] -----

void LVM_Register_Table::resize_register_table(){
    const int N_REGISTERS_INCREMENT = 101;

    if(this->RESIZE_AVAIABLE){
        this->register_table.resize(N_REGISTERS_INCREMENT);
    }
    else
        throw std::out_of_range("REGISTRO FUERA DE RANGO.");
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [REGISTER TABLE] -----

LVM_Register_Table& LVM_Register_Table::get_instance(){
    static LVM_Register_Table instance;
    return instance;
}

void LVM_Register_Table::operator()(int i, const LVM_Memory_Block& mem_block){
    // -- Si el registro esta fuera de rango, redimensionar
    if(i >= this->register_table.size())
        this->resize_register_table();

    // -- Obtener tipo de dato que contiene mem_block
    LVM_Memory_Block_type_t allocates_type = mem_block.get_type_of_alloc();

    // -- Crear registro para insertar
    LVM_Register reg;

    // -- Comprobar
    switch (allocates_type)
    {
    case MEM_BLOCK_INTEGER:
    {   
        reg.allocate_value<int>(mem_block.get_value<int>());
        break;
    }
    case MEM_BLOCK_REAL:
    {   
        reg.allocate_value<float>(mem_block.get_value<float>());
        break;
    }
    case MEM_BLOCK_CHAR:
    {   
        reg.allocate_value<char>(mem_block.get_value<char>());
        break;
    }
    case MEM_BLOCK_STRING:
    {   
        reg.allocate_value<std::string>(mem_block.get_value<std::string>());
        break;
    }
    case MEM_BLOCK_BOOL:
    {   
        reg.allocate_value<bool>(mem_block.get_value<bool>());
        break;
    }
    default:
        throw std::invalid_argument("ALMACENAMIENTO A REGISTRO DE UN BLOQUE DE MEMORIA INVALIDO.");
        break;
    }

    // -- Insertar registro en tabla
    this->register_table[i] = reg;
}

const LVM_Register& LVM_Register_Table::operator()(int i) const{
    if(i >= this->register_table.size())
        throw std::out_of_range("INDICE DE REGISTRO FUERA DE RANGO.");

    return this->register_table[i];
}

LVM_Register& LVM_Register_Table::operator[](int i){
    return this->register_table[i];
}

const LVM_Register& LVM_Register_Table::operator[](int i) const{
    if(i >= this->register_table.size())
        throw std::out_of_range("INDICE DE REGISTRO FUERA DE RANGO.");

    return this->register_table[i];
}

void LVM_Register_Table::restore_registers(std::vector<LVM_Register> regs){
    this->register_table = regs;
}

void LVM_Register_Table::print_register_table(std::ostream & os){
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
        reg = register_table[i];

        // -- Imprimir contenido
        os << std::left << std::setw(gap) << i << std::setw(gap) << reg.get_type_of_alloc_str() << std::setw(gap) << reg.get_value_str() << std::endl;
    }
   
}