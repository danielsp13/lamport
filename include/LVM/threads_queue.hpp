/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file threads_queue.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de colas de hebras para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_THREADS_QUEUE_DPR_
#define _LAMPORT_LVM_THREADS_QUEUE_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <memory>
#include <queue>
#include <vector>

#include <algorithm>
#include <random>
#include <chrono>

#include "thread.hpp"       ///< Hebras de LVM

// ===============================================================

// ----- DEFINICION DE CLASE INITIALIZER -----

class LVM_Threads_Queue{
    private:
        // -- Cola de hebras
        std::queue<std::unique_ptr<LVM_Thread>> queue;
        // -- Flag que indica si la cola ha sido barajada
        bool shuffled = false;

    public:
        /**
         * @brief Constructor de la cola
         */
        LVM_Threads_Queue() = default;

        /**
         * @brief Destructor de la cola
         */
        ~LVM_Threads_Queue() = default;

        /**
         * @brief Inserta un nuevo hilo en la cola
         * @param thread : hilo a insertar en la cola
         */
        void push(std::unique_ptr<LVM_Thread> thread);

        /**
         * @brief Obtiene el frente de cola y lo elimina
         * @return hebra del frente de cola
         */
        std::unique_ptr<LVM_Thread> pop();

        /**
         * @brief Comprueba si la cola esta vacia
         * @return TRUE si esta vacia, FALSE en otro caso
         */
        bool empty() const { return queue.empty(); };

        /**
         * @brief Obtiene el numero de elementos de la cola
         * @return size
         */
        size_t size() const {return queue.size(); };

        /**
         * @brief Limpia la cola
         */
        void clear();

        /**
         * @brief Bajara el contenido de la cola una vez
         */
        void shuffle_once();
};

#endif //_LAMPORT_LVM_THREADS_QUEUE_DPR_