/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file thread_manager.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de gestor de hebras/procesos de LVM
 */

#ifndef _LAMPORT_LVM_THREAD_MANAGER_DPR_
#define _LAMPORT_LVM_THREAD_MANAGER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <vector>
#include <stack>
#include <map>
#include <thread>
#include <string>
#include <chrono>

#include "thread.hpp"       /// < Hebra
#include "scheduler.hpp"    /// < Planificador de hebras

#include "LVM/memory/segment_table.hpp"     ///< Tabla de segmentos de direcciones virtuales
#include "LVM/tracker/tracker.hpp"          ///< Gestor de eventos de maquina virtual

// ===============================================================

// ----- DEFINICION DE CLASE THREAD MANAGER -----

class LVM_Thread_Manager{
    private:
        // -- Planificador de hebras
        LVM_Scheduler& scheduler = LVM_Scheduler::get_instance();
        // -- Mapa de colas de semaforos
        std::map<int,LVM_Threads_Queue> semaphores;

        // -- Gestor de eventos de maquina virtual
        LVM_Tracker& tracker = LVM_Tracker::get_instance();
        // -- Cabecera de mensajes de traza de ejecucion de LVM
        const std::string TRACKER_HEADER = "[Thread Manager]: ";

        /**
         * @brief Constructor de la clase (por defecto)
         */
        LVM_Thread_Manager() = default;
 
    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static LVM_Thread_Manager& get_instance();

        /**
         * @brief Destructor de clase (por defecto)
         */
        ~LVM_Thread_Manager() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Thread_Manager(const LVM_Thread_Manager&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Thread_Manager&) = delete;

        /**
         * @brief Realiza una nueva planificacion de hebras
         */
        void schedule();

        /**
         * @brief Obtiene el total de hebras
         * @return total_threads
         */
        int get_total_threads() {return scheduler.get_total_threads(); };

        /**
         * @brief Obtiene la hebra actual
         * @return hebra actual
         */
        LVM_Thread * get_current_thread() {return scheduler.get_current_thread(); };

        /**
         * @brief Obtiene la hebra actual (junto con su propiedad)
         * @return hebra actual
         */
        std::unique_ptr<LVM_Thread> get_current_thread_unique() {return scheduler.get_current_thread_unique(); };

        /**
         * @brief Crea una nueva hebra
         * @param id : identificador de hebra
         * @param pc : contador de programa
         * @param segment : segmento de direcciones de memoria de la hebra
         * @param parent : puntero a padre de hebra (por defecto nulo)
         * @param priority : prioridad de la hebra (por defecto 1)
         * @param quantum : quantum inicial de hebra (por defecto 0)
         * @param childs : hijos de la hebra (por defecto 0)
         */
        void create_thread(int id, int pc, int segment, LVM_Thread * parent = nullptr, int priority = 1, int quantum = 0, int childs = 0);

        /**
         * @brief Crea una nueva hebra
         * @param id : identificador de hebra
         * @param pc : contador de programa
         * @param segment : segmento de direcciones de memoria de la hebra
         * @param parent : puntero a padre de hebra (por defecto nulo)
         */
        void create_thread_with_ret(int id, int pc, int segment, LVM_Thread * parent, int ret_dir);

        /**
         * @brief Crea una hebra maestra para el programa principal
         * @param quantum : quantum inicial de hebra maestra
         */
        void create_master_thread(int quantum);

        /**
         * @brief Duerme la hebra actual unos milisegundos
         * @param milliseconds : milisegundos
         */
        void sleep_current_thread(int milliseconds);

        /**
         * @brief Bloquea la hebra actual
         */
        void block_current_thread();
        
        /**
         * @brief Termina la hebra actual
         */
        void terminate_current_thread();

        /**
         * @brief Desbloquea una hebra
         * @param id : identificador de hebra a desbloquear
         */
        void unblock_thread(int id);

        /**
         * @brief Indica que la hebra actual entra en seccion atomica
         */
        void current_thread_enters_atomic();

        /**
         * @brief Indica que la hebra actual sale de seccion critica
         */
        void current_thread_exits_atomic();

        /**
         * @brief Comprueba si todas las hebras definidas han terminado su ejecucion
         */
        bool check_all_threads_terminated() const;

        /**
         * @brief Define una nueva cola de semaforo para la direccion especificada
         * @param sem_addr : direccion de semaforo
         */
        void emplace_sem(int sem_addr);

        /**
         * @brief Realiza sem wait sobre el semaforo de la direccion especificada
         * @param sem_addr : direccion de semaforo
         */
        void sem_wait(int sem_addr);

        /**
         * @brief Realiza sem signal sobre el semaforo de la direccion especificada
         * @param sem_addr : direccion de semaforo
         */
        void sem_signal(int sem_addr);
};

#endif //_LAMPORT_LVM_THREAD_MANAGER_DPR_