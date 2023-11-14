/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file posix_signals_manager.hpp
 * @author Daniel Perez Ruiz
 * @brief Manejador de signals POSIX de Linux
 */

#ifndef _LAMPORT_LVM_LINUX_POSIX_SIGNALS_MANAGER_DPR_
#define _LAMPORT_LVM_LINUX_POSIX_SIGNALS_MANAGER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <csignal>
#include <execinfo.h>
#include <unistd.h>

#include "LVM/LVM.hpp"      ///< LVM

// ===============================================================

// ----- DEFINICION DE CLASE MANEJADORA DE SIGNALS POSIX -----

class LVM_Linux_Posix_Signals_Manager{
    private:
        // -- Indica si el manejador de signal Ctrl+C esta disponible
        static bool SIGINT_handler_avaiable;
        // -- Indica si el manejador de signal violacion de segmento esta disponible
        static bool SIGSEGV_handler_avaiable;
        // -- Indica si el manejador de signal aborto esta disponible
        static bool SIGABRT_handler_avaiable;

        /**
         * @brief Manejador de signal SIGSEGV (violacion de segmento)
         * @param signum : identificador de signal
         */
        static void handle_sigsegv(int signum);

        /**
         * @brief Manejador de signal SIGABRT (violacion de segmento)
         * @param signum : identificador de signal
         */
        static void handle_sigabrt(int signum);

        /**
         * @brief Manejador de signal SIGINT (Ctrl+C)
         * @param signum : identificador de signal
         */
        static void handle_sigint(int signum);
    public:
        /**
         * @brief Inicializa los manejadores de signals POSIX
         */
        static void init_signal_handlers();
};

#endif //_LAMPORT_LVM_LINUX_POSIX_SIGNALS_MANAGER_DPR_