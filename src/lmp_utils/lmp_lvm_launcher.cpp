/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_lvm_launcher.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de gestor de maquina virtual de interprete lamport
 */

#include "lmp_utils/lmp_lvm_launcher.hpp"


// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [LVM LAUNCHER] -----


// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [LVM LAUNCHER] -----

LMP_LVM_Launcher& LMP_LVM_Launcher::get_instance(){
    static LMP_LVM_Launcher instance;
    return instance;
}

int LMP_LVM_Launcher::preload_lvm(bool verbose_avaiable){
    tasker.task_preload_lvm();
    if(lvm.preload_lvm(verbose_avaiable))
        tasker.task_ok();
    else
        tasker.task_nop();

    return 0;
}

int LMP_LVM_Launcher::start(){
    tasker.task_execute_lvm();
    lvm.start();
    return 0;
}