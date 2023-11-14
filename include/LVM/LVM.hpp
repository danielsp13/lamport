/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file LVM.hpp
 * @author Daniel Perez Ruiz
 * @brief Maquina Virtual de Lamport
 */

#ifndef _LAMPORT_LVM_LVM_DPR_
#define _LAMPORT_LVM_LVM_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <atomic>

#include "IR/tables/instruction_table.hpp"

#include "LVM/memory/memory_manager.hpp"        ///< Manejador de la memoria del sistema
#include "LVM/CPU/CPU.hpp"                      ///< CPU de la maquina virtual
#include "LVM/SO/thread_manager.hpp"            ///< Manejador de hebras
#include "LVM/tracker/tracker.hpp"              ///< Seguimiento de ejecucion de maquina virtual
#include "LVM/linux/posix_signals_manager.hpp"  ///< Gestor de signals de interrupcion de Linux

// ===============================================================

// ----- DEFINICION DE ESTADOS DE LVM -----

typedef enum{
    LVM_STATE_BORN,             ///< La instancia de LVM acaba de ser creada
    LVM_STATE_PREPARED,         ///< La instancia de LVM esta preparada para ejecucion
    LVM_STATE_RUNNING,          ///< La instancia de LVM esta ejecutandose
    LVM_STATE_DEAD,             ///< La instancia de LVM esta muerta
    LVM_STATE_SHUTDOWN          ///< La instancia de LVM ha sido apagada
} LVM_states_t;

// ===============================================================

// ----- DEFINICION DE CLASE LAMPORT VIRTUAL MACHINE -----

class LVM{
    private:
        // -- Gestor de memoria del sistema
        LVM_Memory_Manager& memory_manager = LVM_Memory_Manager::get_instance();
        // -- Gestor de hebras
        LVM_Thread_Manager& thread_manager = LVM_Thread_Manager::get_instance();
        // -- CPU de la maquina virtual
        LVM_CPU& CPU = LVM_CPU::get_instance();
        // -- Gestor de seguimiento de ejecucion de maquina virtual
        LVM_Tracker& tracker = LVM_Tracker::get_instance();
        // -- Cabecera de mensajes de traza de ejecucion de LVM
        const std::string TRACKER_HEADER = "[LVM]: ";

        // -- Especifica el estado en el que se encuentra la maquina virtual
        LVM_states_t state = LVM_STATE_BORN;

        // -- Flag que especifica la captura de CTRL+C
        std::atomic<bool> SIGINT_received;
        // -- Flag que especifica la captura de violacion de segmento
        std::atomic<bool> SIGSEGV_received;
        // -- Flag que especifica la captura de aborto
        std::atomic<bool> SIGABRT_received;

        /**
         * @brief Constructor de la maquina virtual
         */
        LVM() : SIGINT_received(false), SIGSEGV_received(false), SIGABRT_received(false) {};

        /**
         * @brief Comprueba si se han procu
         */
        bool check_posix_interrupt_signals_received() const;

        /**
         * @brief Comprueba si se necesitan evaluar 
         */
        bool check_initialize_global_vars();

    public:
        /**
         * @brief Obtiene la instancia de la maquina virtual
         * @return instancia
         */
        static LVM& get_instance();

        /**
         * @brief Notifica a la maquina virtual que se ha recibido SIGSEGV
         */
        void notify_posix_interrupt_sigsegv();

        /**
         * @brief Notifica a la maquina virtual que se ha recibido SIGABRT
         */
        void notify_posix_interrupt_sigabrt();

        /**
         * @brief Notifica a la maquina virtual que se ha recibido SIGINT
         */
        void notify_posix_interrupt_sigint();

        /**
         * @brief Destructor de la clase
         */
        ~LVM();

        /**
         * @brief Imprime el contenido de la tabla de segmentos
         * @param os : flujo de impresion
         */
        void print_segment_table(std::ostream& os = std::cout);

        /**
         * @brief Imprime el contenido de la memoria
         * @param os : flujo de impresion
         */
        void print_memory(std::ostream& os = std::cout);

        /**
         * @brief Imprime la traza de ejecucion de la maquina virtual
         * @param os : flujo de impresion
         */
        void print_lvm_trace(std::ostream& os = std::cout);

        /**
         * @brief Prepara la maquina virtual para ser ejecutada
         * @param verbose_avaiable flag de impresion de contenido
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool preload_lvm(bool verbose_avaiable);

        /**
         * @brief Ejecuta la maquina virtual
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool run();
};

#endif //_LAMPORT_LVM_LVM_DPR_