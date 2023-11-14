/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file scheduler.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del planificador para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_SCHEDULER_DPR_
#define _LAMPORT_LVM_SCHEDULER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <random>

#include "thread.hpp"           ///< Hebras
#include "threads_queue.hpp"    ///< Colas de hebras

#include "LVM/tracker/tracker.hpp"  ///< Gestor de eventos de LVM

// ===============================================================

// ----- DEFINICION DE ESTADOS DE SCHEDULER -----

typedef enum{
    LVM_SCHED_INIT,         ///< El planificador ha sido creado
    LVM_SCHED_RUNNING,      ///< El planificador esta iniciado
} LVM_Scheduler_state_t;

// ===============================================================

// ----- DEFINICION DE CLASE SCHEDULER -----

class LVM_Scheduler{
    private:
        // -- Cola de hebras nuevas
        LVM_Threads_Queue new_queue;
        // -- Cola de hebras listas para ejecutar
        LVM_Threads_Queue ready_queue;
        // -- Cola de hebras bloqueadas
        LVM_Threads_Queue blocked_queue;
        // -- Cola de hebras terminadas
        LVM_Threads_Queue terminated_queue;

        // -- Hebra actual
        std::unique_ptr<LVM_Thread> current_thread = nullptr;

        // -- Total de hebras
        int total_threads = 0;
        // -- Total de hebras activas
        int total_active_threads = 0;
        // -- Total de hebras terminadas
        int total_finished_threads = 0;

        // -- Estado de planificador
        LVM_Scheduler_state_t state = LVM_SCHED_INIT;

        // -- Gestor de eventos de maquina virtual
        LVM_Tracker& tracker = LVM_Tracker::get_instance();
        // -- Cabecera de mensajes de traza de ejecucion de LVM
        const std::string TRACKER_HEADER = "[Thread Manager > Sched]: ";


        /**
         * @brief Constructor de la clase, por defecto
         */
        LVM_Scheduler() = default;

        /**
         * @brief Prepara al planificador de hebras para su funcionamiento
         */
        void prepare_scheduler();

        /**
         * @brief Genera un quantum para la hebra actual
         * @return quantum
         */
        int generate_quantum();

        /**
         * @brief Transfiere las hebras de la cola de nuevas a la cola de listas
         */
        void transfer_new_threads_to_ready();

    public:
        /**
         * @brief Obtiene la instancia del planificador
         * @return instancia del planificador
         */
        static LVM_Scheduler& get_instance();

        /**
         * @brief Destructor de la clase por defecto
         */
        ~LVM_Scheduler() = default;

        /**
         * @brief Obtiene el total de hebras
         * @return total threads
         */
        int get_total_threads() const { return total_threads; };

        /**
         * @brief Obtiene la hebra actual
         * @return hebra actual
         */
        LVM_Thread* get_current_thread();

        /**
         * @brief Obtiene la hebra actual (junto a su propiedad)
         */
        std::unique_ptr<LVM_Thread> get_current_thread_unique();

        /**
         * @brief Funcion de planificacion
         */
        void schedule();
        
        /**
         * @brief Inserta una nueva hebra en la cola de nuevos
         * @param thread : hebra
         * @param priority : prioridad de la hebra (por defecto 1)
         */
        void new_thread_raw(LVM_Thread * thread);

        /**
         * @brief Mueve una hebra a la cola de listas
         * @param th : hebra
         */
        void move_thread_to_ready(std::unique_ptr<LVM_Thread> th);

        /**
         * @brief Prepara y ejecuta la primera hebra lista
         */
        void run_thread();

        /**
         * @brief Bloquea la hebra actual y la manda a la cola de bloqueados
         */
        void block_current_thread();

        /**
         * @brief Desbloquea la hebra con el id especificado y la coloca en la cola de listos
         * @param id : identificador de hebra
         */
        void unblock_thread(int id);

        /**
         * @brief Indica que la hebra actual ha terminado su ejecucion definitivamente
         */
        void terminate_thread();

        /**
         * @brief Comprueba si todas las hebras definidas han terminado su ejecucion por completo
         * @return Total de hebras terminadas
         */
        bool check_all_threads_terminated() {return total_threads == total_finished_threads; };
};

#endif //_LAMPORT_LVM_SCHEDULER_DPR_