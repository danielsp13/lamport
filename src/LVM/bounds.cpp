/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file bounds.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de comprobador de limites de arrays
 */

#include "LVM/bounds.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [BOUNDS] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [BOUNDS] -----

LVM_Bounds& LVM_Bounds::get_instance(){
    static LVM_Bounds instance;
    return instance;
}

void LVM_Bounds::check_if_is_negative_offset(int offset){
    if(offset < 0){
        std::string offset_str = "[" + std::to_string(offset) + "].";
        throw std::out_of_range(EXCEP_OUT_BOUNDS_MSG + " se encontró " + offset_str);
    }
}

void LVM_Bounds::check_if_exceds_bound(int virtual_addr, int phisical_addr, int offset){
    if(phisical_addr == -3 || phisical_addr > upper_bounds[virtual_addr]){
        std::string offset_str = "[" + std::to_string(offset) + "].";
        throw std::out_of_range(EXCEP_OUT_BOUNDS_MSG + " se encontró " + offset_str);
    }
}

void LVM_Bounds::print_bounds(std::ostream & os){
    const std::string LINE = "==========================================================";
    const std::string TITLE = "REGISTRO DE LIMITES DE ACCESOS A ARRAYS";
    const unsigned int gap = 22;

    os << LINE << std::endl << TITLE << std::endl << LINE << std::endl;
    os << std::left << std::setw(gap) << "Dirección Virtual" << std::setw(gap) << "Direccion de memoria" << std::endl;
    os << LINE << std::endl;

    int virtual_addr, phisical_addr;

    for(auto& pair : upper_bounds){
        virtual_addr = pair.first; phisical_addr = pair.second;

        // Usar un ostringstream para formatear direccion de memoria
        std::ostringstream addr_mem;
        addr_mem << "0m" << std::setfill('0') << std::setw(8) << phisical_addr;

        // -- Imprimir contenido
        os << std::left << std::setw(gap) << virtual_addr << std::setw(gap) << addr_mem.str() << std::endl;
    }
}