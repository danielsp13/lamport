/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file segment_table.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de la tabla de segmentos de la maquina virtual de lamport
 */

#include "LVM/memory/segment_table.hpp"

const std::string LINE = "==========================================================";
const unsigned int gap = 22;


// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [PAGE TABLE] -----

void LVM_Segment_Table::print_segment(int segment, std::ostream & os){
    // -- Obtener multimapa de direcciones
    std::multimap<int,int> address = address_table.at(segment).second;
    std::string segment_name = address_table.at(segment).first;

    os << std::left << "Segmento número (" << segment << ") : " << segment_name << std::endl << LINE << std::endl;
    os << std::left << std::setw(gap) << "Dirección Virtual" << std::setw(gap) << "Dirección Física" << std::endl << LINE << std::endl;

    int virtual_addr, phisical_addr; int actual_key = -1; int offset = 0;
    std::string virtual_addr_str;
    for(auto& pair_address : address){
        // -- Desensamblar
        virtual_addr = pair_address.first; phisical_addr = pair_address.second;

        // -- Formatear direccion de memoria fisica
        std::ostringstream addr_mem;
        addr_mem << "0m" << std::setfill('0') << std::setw(8) << phisical_addr;

        // -- Formatear direccion de memoria virtual
        virtual_addr_str = std::to_string(virtual_addr);
        if(actual_key != virtual_addr){
            actual_key = virtual_addr;
            offset = 0;
        }
        else{
            offset++;
            virtual_addr_str += "+(" + std::to_string(offset) + ")";
        }

        // -- Imprimir contenido
        os << std::left << std::setw(gap) << virtual_addr_str << std::setw(gap) << addr_mem.str() << std::endl;
    }

    os << LINE << std::endl << std::endl;
}

int& LVM_Segment_Table::get_phisical_addr(int segment, int virtual_dir, int offset){
    // --- Obtener multimapa
    std::multimap<int,int>& address = address_table[segment].second;

    // -- Obtener entradas coincidentes con la direccion virtual solicitada
    auto virtual_dirs_target = address.equal_range(virtual_dir);

    // -- Iterar sobre los targets
    int i = 0;
    for(auto it = virtual_dirs_target.first; it != virtual_dirs_target.second; ++it){
        if(i == offset){
            // Retornar indice fisico
            return it->second;
        }

        ++i;
    }

    // ----  Si no encontramos la entrada deseada, insertarla y regresar una referencia al valor
    auto inserted = address.emplace(virtual_dir, -3);
    return inserted->second;
}

const int LVM_Segment_Table::get_phisical_addr(int segment, int virtual_dir, int offset) const{
    // --- Obtener multimapa
    std::multimap<int,int> address = address_table.at(segment).second;

    // -- Obtener entradas coincidentes con la direccion virtual solicitada
    auto virtual_dirs_target = address.equal_range(virtual_dir);

    // -- Iterar sobre los targets
    int i = 0;
    for(auto it = virtual_dirs_target.first; it != virtual_dirs_target.second; ++it){
        if(i == offset){
            // Retornar indice fisico
            return it->second;
        }

        ++i;
    }

    // -- Retornar error
    return -3;
}

void LVM_Segment_Table::new_segment(int segment, std::string segment_name){
    // --- Definir mapa
    std::multimap<int,int> address;

    // --- Definir par
    std::pair<std::string,std::multimap<int,int>> n_segment;
    n_segment.first = segment_name;
    n_segment.second = address;

    // --- Insertar
    address_table[segment] = n_segment;
}


// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [PAGE TABLE] -----

LVM_Segment_Table& LVM_Segment_Table::get_instance(){
    static LVM_Segment_Table instance;
    return instance;
}

int& LVM_Segment_Table::operator()(int segment, int virtual_dir, int offset){
    return this->get_phisical_addr(segment,virtual_dir,offset);
}

const int LVM_Segment_Table::operator()(int segment, int virtual_dir, int offset) const{
    return this->get_phisical_addr(segment,virtual_dir);   
}

void LVM_Segment_Table::print_segment_table(std::ostream& os){
    const std::string TITLE = "TABLA DE SEGMENTOS";
    
    os << LINE << std::endl << TITLE << std::endl << LINE << std::endl;

    // -- Imprimir segmentos
    for(const auto& pair : address_table){
        print_segment(pair.first,os);
    }
}