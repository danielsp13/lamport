/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file page_table.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de la tabla de paginas de la maquina virtual de lamport
 */

#include "LVM/page_table.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [PAGE TABLE] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [PAGE TABLE] -----

LVM_Page_Table& LVM_Page_Table::get_instance(){
    static LVM_Page_Table instance;
    return instance;
}

int& LVM_Page_Table::operator()(int segment, int page){
    return this->address_table[segment][page];
}

const int LVM_Page_Table::operator()(int segment, int page) const{
    return this->address_table.at(segment).at(page);
}

void LVM_Page_Table::print_page_table(std::ostream& os){
    const std::string LINE = "==========================================================";
    const std::string TITLE = "TABLA DE PAGINAS";
    const unsigned int gap = 22;

    os << LINE << std::endl << TITLE << std::endl << LINE << std::endl;

    int segment_int; std::map<int,int> pages;
    for(auto& pair : address_table){
        // -- Desensamblar el segmento
        segment_int = pair.first; pages = pair.second;

        os << std::left << "Segmento número (" << segment_int << ")" << std::endl << LINE << std::endl;
        os << std::left << std::setw(gap) << "Dirección Virtual" << std::setw(gap) << "Dirección Física" << std::endl << LINE << std::endl;

        int virtual_addr, phisical_addr;
        for(auto& pair_address : pages){
            // -- Desensamblar direcciones
            virtual_addr = pair_address.first; phisical_addr = pair_address.second;
            
            // Usar un ostringstream para formatear direccion de memoria
            std::ostringstream addr_mem;
            addr_mem << "0m" << std::setfill('0') << std::setw(8) << phisical_addr;

            // -- Imprimir contenido
            os << std::left << std::setw(gap) << virtual_addr << std::setw(gap) << addr_mem.str() << std::endl;
        }

        os << LINE << std::endl << std::endl;
    }
}