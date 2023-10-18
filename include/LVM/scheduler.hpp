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
#include <memory>

#include "LVM/thread.hpp"           ///< Hebras
#include "LVM/threads_queue.hpp"    ///< Colas de hebras

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
        // -- Total de hebras terminadas
        int total_finished_threads = 0;

        // -- Estado de planificador
        LVM_Scheduler_state_t state = LVM_SCHED_INIT;

        /**
         * @brief Constructor de la clase, por defecto
         */
        LVM_Scheduler() = default;

        /**
         * @brief Prepara al planificador de hebras para su funcionamiento
         */
        void prepare_scheduler();

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
         * @brief Obtiene la hebra actual
         * @return hebra actual
         */
        LVM_Thread* get_current_thread();

        /**
         * @brief Funcion de planificacion
         */
        void schedule();

        /**
         * @brief Inserta una nueva hebra en la cola de nuevos
         * @param thread : hebra
         */
        void new_thread(std::unique_ptr<LVM_Thread> thread);
        
        /**
         * @brief Inserta una nueva hebra en la cola de nuevos
         * @param thread : hebra
         */
        void new_thread_raw(LVM_Thread * thread);

        /**
         * @brief Prepara y ejecuta la primera hebra lista
         */
        void run_thread();

        /**
         * @brief Bloquea la hebra actual y la manda a la cola de bloqueados
         */
        void block_current_thread();

        /**
         * @brief Desbloquea la hebra del frente de cola de bloqueados y la
         * mueve a la cola de listos
         */
        void unblock_thread();

        /**
         * @brief Indica que la hebra actual ha terminado su ejecucion definitivamente
         */
        void terminate_thread();

        /**
         * @brief Comprueba si todas las hebras han terminado su ejecucion definitivamente
         * @return TRUE si han terminado todas y cada una de las hebras definidas, FALSE en otro caso
         */
        bool program_terminated() const { return total_threads == total_finished_threads; };
};

#endif //_LAMPORT_LVM_SCHEDULER_DPR_