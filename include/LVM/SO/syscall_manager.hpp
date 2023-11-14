/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file syscall_manager.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de gestor de llamadas al sistema de LVM
 */

#ifndef _LAMPORT_LVM_SYSCALL_MANAGER_DPR_
#define _LAMPORT_LVM_SYSCALL_MANAGER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <algorithm>

#include "LVM/CPU/register.hpp" ///< Registro CPU
#include "thread_manager.hpp"   ///< Manejador de hebras/procesos

#include "LVM/memory/memory_manager.hpp"    ///< Manejador de memoria de LVM
#include "LVM/tracker/tracker.hpp"          ///< Gestor de eventos de maquina virtual

// ===============================================================

// ----- DEFINICION DE CLASE SYSCALL_MANAGER -----

class LVM_Syscall_Manager{
    private:
        // -- Manejador de hebras y procesos
        LVM_Thread_Manager& thread_manager = LVM_Thread_Manager::get_instance();
        // -- Manejador de memoria del sistema
        LVM_Memory_Manager& memory_manager = LVM_Memory_Manager::get_instance();
        // -- Gestor de eventos de maquina virtual
        LVM_Tracker& tracker = LVM_Tracker::get_instance();
        const std::string TRACKER_HEADER = "[SO > Gestor de llamadas]: ";

        /**
         * @brief Constructor de la clase (por defecto)
         */
        LVM_Syscall_Manager() = default;

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static LVM_Syscall_Manager& get_instance();

        /**
         * @brief Destructor de clase (por defecto)
         */
        ~LVM_Syscall_Manager() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Syscall_Manager(const LVM_Syscall_Manager&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Syscall_Manager&) = delete;

        /**
         * @brief Llamada al sistema: impresion de contenido
         * @param type : tipo de contenido
         * @param data : contenido
         */
        void handle_syscall_print(LVM_Register_type_t type, reg_data data);

        /**
         * @brief Llamada al sistema: impresion de contenido (fin de linea)
         */
        void handle_syscall_print_endl();

        /**
         * @brief Llamada al sistema: entrar en seccion atomica
         */
        void handle_syscall_enter_atomic();

        /**
         * @brief Llamada al sistema: salir de seccion atomica
         */
        void handle_syscall_exit_atomic();

        /**
         * @brief Llamada al sistema: bloquear la hebra actual
         */
        void handle_syscall_block_current_thread();

        /**
         * @brief Llamada al sistema: terminar hebra actual
         */
        void handle_syscall_terminate_current_thread();

        /**
         * @brief Llamada al sistema: dormir hebra actual
         */
        void handle_syscall_sleep_current_thread(int milliseconds);

        /**
         * @brief Llamada al sistema: desbloquear hebra
         * @param id : identificador de hebra
         */
        void handle_syscall_unblock_thread(int id);

        /**
         * @brief Llamada al sistema: operacion sem wait sobre semaforo
         * @param sem_addr : direccion virtual sobre semaforo
         */
        void handle_syscall_sem_wait(int sem_addr);

        /**
         * @brief Llamada al sistema: operacion sem signal sobre semaforo
         * @param sem_addr : direccion virtual sobre semaforo
         */
        void handle_syscall_sem_signal(int sem_addr);

        /**
         * @brief Llamada al sistema: crear hebra
         */
        void handle_syscall_create_thread(int pc);

        /**
         * @brief Llamada al sistema: crear hebra
         */
        void handle_syscall_create_thread(int id, int pc);

        /**
         * @brief Llamada al sistema: crear hebra
         */
        void handle_syscall_create_thread(int id, int pc, int ret_dir);
};

#endif //_LAMPORT_LVM_SYSCALL_MANAGER_DPR_