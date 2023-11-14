/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file threads_queue.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de cola de hebras para la maquina virtual de lamport
 */

#include "LVM/SO/threads_queue.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [THREADS_QUEUE] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [THREADS_QUEUE] -----

void LVM_Threads_Queue::push(std::unique_ptr<LVM_Thread> thread){
    queue.push(std::move(thread));
}

std::unique_ptr<LVM_Thread> LVM_Threads_Queue::pop(){
    std::unique_ptr<LVM_Thread> thread = std::move(const_cast<std::unique_ptr<LVM_Thread>&>(queue.top()));
    queue.pop();

    return thread;
}

void LVM_Threads_Queue::clear(){
    while(!empty()){
        pop();
    }
}

void LVM_Threads_Queue::shuffle_once(){
    // -- Comprobar que no se ha barajado aun
    if(!shuffled){
        shuffled = true;

        // -- Obtener vector con los elementos de la cola
        std::vector<std::unique_ptr<LVM_Thread>> threads;

        while(!empty()){
            threads.push_back(std::move(pop()));
        }

        // -- Barajar vector
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(threads.begin(), threads.end(), std::default_random_engine(seed));

        // -- Recuperar cola
        for(int i=0; i<threads.size(); i++){
            push(std::move(threads[i]));
        }
    }

}