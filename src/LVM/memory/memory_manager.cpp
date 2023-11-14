/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file memory_manager.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de manejador de memoria para la maquina virtual de lamport
 */

#include "LVM/memory/memory_manager.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [MEMORY MANAGER] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [MEMORY MANAGER] -----

LVM_Memory_Manager& LVM_Memory_Manager::get_instance(){
    static LVM_Memory_Manager instance;
    return instance;
}

LVM_Memory_Block& LVM_Memory_Manager::mem_access(int segment, int virtual_dir, int offset){
    // -- Obtener direccion fisica
    int phisical_addr = segment_table(segment,virtual_dir,offset);

    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Accediendo a memoria. Direccion virtual: " + "(segmento " + std::to_string(segment) + " -> " + std::to_string(virtual_dir) + "+" + std::to_string(offset) + ")" + " <-> direccion fisica: (" + std::to_string(phisical_addr) + ")";
    tracker.track(tracker_msg);


    return memory[phisical_addr];
}

const LVM_Memory_Block& LVM_Memory_Manager::mem_access(int segment, int virtual_dir, int offset) const{
    // -- Obtener direccion fisica
    int phisical_addr = segment_table(segment,virtual_dir,offset);

    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Accediendo a memoria. Direccion virtual: " + "(segmento " + std::to_string(segment) + " -> " + std::to_string(virtual_dir) + "+" + std::to_string(virtual_dir) + ")" + " <-> direccion fisica: (" + std::to_string(phisical_addr) + ")";
    tracker.track(tracker_msg);


    return memory[phisical_addr];
}

int LVM_Memory_Manager::get_phisical_addr(int segment, int virtual_dir, int offset){
    return segment_table(segment,virtual_dir,offset);
}

bool LVM_Memory_Manager::check_phisical_addr(int virtual_segment, int virtual_dir, int offset){
    return get_phisical_addr(virtual_segment,virtual_dir,offset) != -3;
}

void LVM_Memory_Manager::check_array_bounds(int virtual_segment, int virtual_dir, int offset_dir){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Validando acceso a array.";
    tracker.track(tracker_msg);

    // -- Obtener direccion fisica
    int phisical_addr = segment_table(virtual_segment,virtual_dir,offset_dir);

    array_bounds.check_if_is_negative_offset(offset_dir);
    array_bounds.check_if_exceds_bound(virtual_dir,phisical_addr,offset_dir);
}

void LVM_Memory_Manager::print_segment_table(std::ostream& os){
    segment_table.print_segment_table(os);
}

void LVM_Memory_Manager::print_memory(std::ostream& os){
    memory.print_memory(os);
}