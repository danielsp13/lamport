/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file scheduler.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del planificador para la maquina virtual de lamport
 */

#include "LVM/scheduler.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [SCHEDULER] -----

void LVM_Scheduler::prepare_scheduler(){
    // -- Se prepara solo si el estado es inicial
    if(state == LVM_SCHED_INIT){
        // -- Actualizar estado
        state = LVM_SCHED_RUNNING;

        // -- Bajarar la cola de hebras nuevas
        new_queue.shuffle_once();

        // -- Obtener la primera hebra de la cola
        current_thread = std::move(new_queue.pop());

        // -- Cambiar el estado a preparado
        current_thread->set_state(LVM_THREAD_RUNNING);

        // -- Mandar el resto de threads a la cola de listos
        std::unique_ptr<LVM_Thread> thread;
        while(!new_queue.empty()){
            thread = std::move(new_queue.pop());
            thread->set_state(LVM_THREAD_READY);

            ready_queue.push(std::move(thread));
        }
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [SCHEDULER] -----

LVM_Scheduler& LVM_Scheduler::get_instance(){
    static LVM_Scheduler instance;
    return instance;
}

LVM_Thread* LVM_Scheduler::get_current_thread(){
    return current_thread.get();
}

void LVM_Scheduler::schedule(){
    // -- Preparar al planificador si no se ha hecho antes
    prepare_scheduler();

    // -- Atributos de comprobacion
    bool have_current_thread = current_thread != nullptr;
    bool have_single_thread = total_threads == 1;
    bool current_thread_execute_instruction = current_thread->has_finished_instruction();
    bool current_thread_terminated = current_thread->is_terminated();

    // -- Comprobar el numero de hebras
    if(!have_current_thread && have_single_thread){
        run_thread();
        return;
    }

    // -- Comprobar si hay hebra actual y no ha terminado su trabajo completo
    if(have_current_thread && (!current_thread_terminated || current_thread_execute_instruction)){
        // -- Marcar hebra como lista
        current_thread->set_state(LVM_THREAD_READY);
        // -- Mandar a la cola de listas
        ready_queue.push(std::move(current_thread));
        // -- Traer una nueva hebra a ejecutar
        run_thread();
        return;
    }

    // -- Comprobar si la hebra actual ha terminado su trabajo
    if(current_thread_terminated){
        // -- Traer una nueva hebra a ejecutar
        run_thread();
    }
    

}

void LVM_Scheduler::new_thread(std::unique_ptr<LVM_Thread> thread){
    // -- Comprobar que el estado de la hebra es nuevo
    if(thread->is_new()){
        // -- Insertar en la cola de nuevos
        new_queue.push(std::move(thread));
        // -- Aumentar contador de hebras
        total_threads++;
    }
}

void LVM_Scheduler::new_thread_raw(LVM_Thread * thread){
    // -- Comprobar que el estado de la hebra es nuevo
    if(thread->is_new()){
        // -- Insertar en la cola de nuevos
        new_queue.push(std::unique_ptr<LVM_Thread>(thread));
        // -- Aumentar contador de hebras
        total_threads++;
    }
}

void LVM_Scheduler::run_thread(){
    if(!ready_queue.empty()){
        // -- Extraer primera hebra de la cola de preparados
        current_thread = std::move(ready_queue.pop());

        // -- Comprobar que el estado de la hebra es listo
        if(current_thread->is_ready()){
            // -- Cambiar estado a ejecutando
            current_thread->set_state(LVM_THREAD_RUNNING);
        }
        else{
            // -- Lanzar excepcion
            throw std::runtime_error("SE HA INTENTADO EJECUTAR UNA HEBRA QUE NO ESTABA PREPARADA.");
        }
    }
}

void LVM_Scheduler::block_current_thread(){
    // -- Marcar hebra actual como bloqueada
    current_thread->set_state(LVM_THREAD_BLOCKED);
    // -- Mandar hebra actual a la cola de bloqueadas
    blocked_queue.push(std::move(current_thread));

    // -- Marcar nullptr
    current_thread = nullptr;
}

void LVM_Scheduler::unblock_thread(){
    // -- Extraer la primera hebra de la cola de bloqueados
    std::unique_ptr<LVM_Thread> thread = std::move(blocked_queue.pop());

    // -- Cambiar estado de hebra a listo
    thread->set_state(LVM_THREAD_READY);

    // -- Incluir hebra en la cola de preparados
    ready_queue.push(std::move(thread));
}

void LVM_Scheduler::terminate_thread(){
    // -- Marcar hebra actual como terminada
    current_thread->set_state(LVM_THREAD_TERMINATED);
    // -- Mandar hebra actual a la cola de terminadas
    terminated_queue.push(std::move(current_thread));
    // -- Incrementar contador de hebras terminadas
    total_finished_threads++;

    // -- Marcar nullptr
    current_thread = nullptr;
}