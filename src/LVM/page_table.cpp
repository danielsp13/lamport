/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file page_table.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de la tabla de paginas de la maquina virtual de lamport
 */

#include "LVM/page_table.hpp"

const std::string LINE = "==========================================================";
const unsigned int gap = 22;


// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [PAGE TABLE] -----

void LVM_Page_Table::print_segment(int segment, std::ostream & os){
    // -- Obtener mapa de direcciones
    std::map<int,int> pages = address_table[segment];

    os << std::left << "Segmento número (" << segment << ")" << std::endl << LINE << std::endl;
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

void LVM_Page_Table::print_segment_array(int segment, std::ostream & os){
    // ---- Obtener el mapa
    std::multimap<int,int> pages = address_array_table.at(segment);

    os << std::left << "Segmento número (" << segment << ")" << std::endl << LINE << std::endl;
    os << std::left << std::setw(gap) << "Dirección Virtual" << std::setw(gap) << "Dirección Física" << std::endl << LINE << std::endl;

    int virtual_addr, phisical_addr; int actual_key = 0; int offset = 0;
    for(auto& pair_address : pages){
        // -- Desensamblar direcciones
        virtual_addr = pair_address.first; phisical_addr = pair_address.second;

        // -- Comprobar si la key ha cambiado
        if(actual_key != virtual_addr){
            actual_key = virtual_addr;
            offset = 0;
        }
        
        // Usar un ostringstream para formatear direccion de memoria
        std::ostringstream addr_mem;
        addr_mem << "0m" << std::setfill('0') << std::setw(8) << phisical_addr;

        std::string virtual_addr_offset = std::to_string(virtual_addr) + "+(" + std::to_string(offset) + ")";

        // -- Imprimir contenido
        os << std::left << std::setw(gap) << virtual_addr_offset << std::setw(gap) << addr_mem.str() << std::endl;

        // -- Incrementar offset
        offset++;
    }

    os << LINE << std::endl << std::endl;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [PAGE TABLE] -----

LVM_Page_Table& LVM_Page_Table::get_instance(){
    static LVM_Page_Table instance;
    return instance;
}

int& LVM_Page_Table::operator()(int segment, int page){
    return this->address_table[segment][page];
}

int& LVM_Page_Table::operator()(int segment, int page, int offset){
    // ---- Obtener el multimapa
    std::multimap<int,int>& pages = address_array_table[segment];

    // ---- Obtener entradas coincidentes con la página solicitada
    auto pages_target = pages.equal_range(page);
    
    // ---- Iterar
    int i = 0;
    for(auto it = pages_target.first; it != pages_target.second; ++it){
        if(i == offset)
            return it->second; // Regresar una referencia al valor, lo que permite su modificación
        
        ++i;
    }
    
    // ----  Si no encontramos la entrada deseada, insertarla y regresar una referencia al valor
    auto inserted = pages.emplace(page, -3);
    return inserted->second;
}

const int LVM_Page_Table::operator()(int segment, int page, int offset) const{
    //std::map<int,std::multimap<int,int>> address_array_table;
    // ---- Obtener multimapa
    std::multimap<int,int> pages = address_array_table.at(segment);

    // ---- Obtener entradas coincidentes con la pagina solicitada
    auto pages_target = pages.equal_range(page);
    // ---- Iterar
    int i = 0;

    for(auto it = pages_target.first; it != pages_target.second; ++it){
        if(i == offset)
            return it->second;
        
        ++i;
    }

    return -3;    
}

const int LVM_Page_Table::operator()(int segment, int page) const {
    // ---- Comprobar si el segmento es el del tipo array
    if(segment == SEGMENT_FOR_VARIABLES_ARRAY){
        // ---- Buscar en la tabla de arrays
        return 0;
    }
    else{
        // ---- Buscar en la tabla normal
        return address_table.at(segment).at(page);
    }
}

void LVM_Page_Table::print_page_table(std::ostream& os){
    const std::string TITLE = "TABLA DE PAGINAS";
    
    os << LINE << std::endl << TITLE << std::endl << LINE << std::endl;

    // -- Imprimir segmento de literales
    print_segment(SEGMENT_FOR_LITERALS,os);
    // -- Imprimir segmento de variables
    print_segment(SEGMENT_FOR_VARIABLES,os);
    if(!address_array_table.empty()){
        // -- Imprimir segmento de variables (array)
        print_segment_array(SEGMENT_FOR_VARIABLES_ARRAY,os);
    }
    // -- Imprimir segmento de etiquetas
    print_segment(SEGMENT_FOR_LABELS,os);
}