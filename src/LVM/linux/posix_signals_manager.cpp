/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file posix_signals_manager.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del manejador de signals POSIX de Linux
 */

#include "LVM/linux/posix_signals_manager.hpp"

bool LVM_Linux_Posix_Signals_Manager::SIGINT_handler_avaiable = true;
bool LVM_Linux_Posix_Signals_Manager::SIGSEGV_handler_avaiable = false;
bool LVM_Linux_Posix_Signals_Manager::SIGABRT_handler_avaiable = false;

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [POSIX SIGNALS MANAGER] -----

void LVM_Linux_Posix_Signals_Manager::handle_sigsegv(int signum){
    LVM::get_instance().notify_posix_interrupt_sigsegv();
}

void LVM_Linux_Posix_Signals_Manager::handle_sigabrt(int signum){
    LVM::get_instance().notify_posix_interrupt_sigabrt();
}

void LVM_Linux_Posix_Signals_Manager::handle_sigint(int signum){
    LVM::get_instance().notify_posix_interrupt_sigint();
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [POSIX SIGNALS MANAGER] -----

void LVM_Linux_Posix_Signals_Manager::init_signal_handlers(){
    if(SIGINT_handler_avaiable)
        signal(SIGINT,LVM_Linux_Posix_Signals_Manager::handle_sigint);

    if(SIGSEGV_handler_avaiable)
        signal(SIGSEGV,LVM_Linux_Posix_Signals_Manager::handle_sigsegv);

    if(SIGABRT_handler_avaiable)
        signal(SIGABRT,LVM_Linux_Posix_Signals_Manager::handle_sigabrt);
}