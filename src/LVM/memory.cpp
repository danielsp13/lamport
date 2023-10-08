/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file memory.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de memoria para la maquina virtual de lamport
 */

#include "LVM/memory.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [MEMORY] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [MEMORY] -----

LVM_Memory& LVM_Memory::get_instance(){
    static LVM_Memory instance;
    return instance;
}

LVM_Memory_Block& LVM_Memory::operator[](int i){
    return this->mem[i];
}

const LVM_Memory_Block& LVM_Memory::operator[](int i) const{
    // -- Buscar direccion de memoria
    auto it = this->mem.find(i);
    // -- EXCEPCION: Direccion de memoria no valida
    if(it == this->mem.end()){
        //TODO BETTER
        throw std::out_of_range("DIRECCIÓN DE MEMORIA NO ENCONTRADA.");
    }

    // -- Retornar bloque de memoria
    return it->second;
}

void LVM_Memory::print_memory(std::ostream& os){
    const std::string LINE = "==========================================================";
    const std::string TITLE = "MEMORIA DE LA MÁQUINA VIRTUAL";
    const unsigned int gap = 22;

    os << LINE << std::endl << TITLE << std::endl << LINE << std::endl;
    os << std::left << std::setw(gap) << "Dirección" << std::setw(gap) << "Tipo de bloque" << std::setw(gap) << "Contenido" << std::endl;
    os << LINE << std::endl;

    // -- Recorrer la memoria
    int addr_int; LVM_Memory_Block mem_block;
    for(auto& pair : mem){
        // -- Desensamblar la memoria
        addr_int = pair.first; mem_block = pair.second;

        // Usar un ostringstream para formatear direccion de memoria
        std::ostringstream addr_mem;
        addr_mem << "0m" << std::setfill('0') << std::setw(8) << addr_int;

        // -- Imprimir contenido
        os << std::left << std::setw(gap) << addr_mem.str() << std::setw(gap) << mem_block.get_type_of_alloc_str() << std::setw(gap) << mem_block.get_value_str() << std::endl;
    }
}