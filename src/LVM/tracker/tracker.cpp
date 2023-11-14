/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file tracker.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de gestor de seguimiento de ejecucion de LVM
 */

#include "LVM/tracker/tracker.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [TRACKER] -----


// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [TRACKER] -----

LVM_Tracker& LVM_Tracker::get_instance(){
    static LVM_Tracker instance;
    return instance;
}

void LVM_Tracker::activate(){
    if(!activated){
        activated = true;
        chrono.start();
    }
}

void LVM_Tracker::track(std::string msg){
    if(activated){
        if(msg == "\n"){
            CPU_cycle_trace.push_back(msg + "\n");
            return;            
        }

        std::string new_lvm_event = chrono.timestamp() + " " + msg + "\n";
        CPU_cycle_trace.push_back(new_lvm_event);
    }
}

void LVM_Tracker::confirm_track_cycle(){
    for(int i=0; i<CPU_cycle_trace.size(); i++){
        trace.push_back(CPU_cycle_trace[i]);
    }
    CPU_cycle_trace.clear();
}

void LVM_Tracker::print_trace(std::ostream& os){
    if(activated){
        for(int i=0; i<trace.size(); i++){
            os << trace[i];
        }
        os.flush();
    }
}

void LVM_Tracker::print_cpu_cycle_trace(std::ostream& os){
    if(activated){
        for(int i=0; i<CPU_cycle_trace.size(); i++){
            os << CPU_cycle_trace[i];
        }
        os << std::endl;
        os.flush();
    }
}