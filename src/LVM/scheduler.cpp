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

int LVM_Scheduler::generate_quantum(){
    const int QUANTUM_MIN = 1;
    const int QUANTUM_MAX = 4;

    static std::random_device rd;          // Inicializa solo una vez.
    static std::mt19937 mt(rd());          // Generador Mersenne Twister con semilla de rd.
    std::uniform_int_distribution<int> dist(QUANTUM_MIN, QUANTUM_MAX);  // Distribución uniforme entre 1 y 4.
    
    return dist(mt);
}

void LVM_Scheduler::transfer_new_threads_to_ready(){
    // -- Comprobar que no esta vacia la cola
    if(!new_queue.empty()){
        while(!new_queue.empty()){
            // -- Obtener nueva hebra
            std::unique_ptr<LVM_Thread> new_thread = std::move(new_queue.pop());
            // -- Marcar como lista
            new_thread->set_state(LVM_THREAD_READY);
            // -- Mandar a la cola de listas
            ready_queue.push(std::move(new_thread));

           
        }

        // -- Cuando se ha terminado, mover la hebra actual tambien a la cola de listas
        if(current_thread){
            current_thread->set_state(LVM_THREAD_READY);
            current_thread->reset_counters();
            ready_queue.push(std::move(current_thread));
            current_thread = nullptr;
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
    /*std::cout << "(PLANIFICADOR) planificando... " << std::endl; std::cout.flush();
    std::cout << "Nuevas (" << new_queue.size() << "), ";
    std::cout << "Listas (" << ready_queue.size() << "), ";
    std::cout << "Bloqueadas (" << blocked_queue.size() << "), ";
    std::cout << "Terminadas (" << terminated_queue.size() << ")" << std::endl; std::cout.flush();*/
    // -- 0. Preparar al planificador si no se ha hecho antes
    prepare_scheduler();

    // -- 1. Comprobar si hay hebras nuevas y volcarlas en cola de listas
    transfer_new_threads_to_ready();

    // -- 2. Comprobar el numero de hebras
    if(total_threads == 1){
        // -- 2.1 Comprobar si tiene hebra actual definida
        if(!current_thread){
            // -- 2.2 Ejecutar una hebra de la cola de listas
            run_thread();
        }

        // -- Retornar (tiene todo el tiempo de CPU)
        return;
    }

    // -- 3. Comprobar si hay una hebra actual
    if(current_thread){

        // -- 3.0 Comprobar si la hebra ha entrado en seccion critica
        if(current_thread->in_atomic_section()){
            // -- 3.0.1 Retornar, se queda en CPU hasta que se marque que ha salido
            return;
        }

        // -- 3.1 Comprobar si la hebra ha finalizado definitivamente
        if(current_thread->is_terminated()){
            // -- 3.1.1 Comprobar si la hebra que ha terminado es hija de alguien
            if(current_thread->is_child()){
                // -- 3.1.1.1 Obtener padre
                LVM_Thread * parent = current_thread->get_parent();
                // -- 3.1.1.2 Eliminar hebra del padre
                parent->remove_child(current_thread.get());

                // -- 3.1.1.3 Intentar desbloquear al padre
                if(parent->childs_have_finished()){
                    unblock_thread(parent->get_id());
                }
            }

            // -- 3.1.2 Enviar a la cola de terminadas
            terminate_thread();
            // -- 3.1.3 Ejecutar otra hebra de la cola de listas (si hay)
            run_thread();

            return;
        }

        // -- 3.2 Comprobar si cumplio su quantum
        if(current_thread->get_total_instructions_executed() >= current_thread->get_quantum()){
            // -- 3.2.1 Marcar hebra como lista
            current_thread->set_state(LVM_THREAD_READY);
            // -- 3.2.2 Resetar sus contadores
            current_thread->reset_counters();
            // -- 3.2.3 Mandar a la cola de listas
            ready_queue.push(std::move(current_thread));
            // -- 3.2.4 Obtener una nueva hebra para ejecutar
            run_thread();

            return;
        }

        // -- 3.2 En caso contrario retornar, sigue teniendo el control de CPU
        return;
    }

    // -- 4. Intentar obtener una nueva hebra de la cola de listos
    run_thread();
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
            // -- Establecer un quantum aleatorio para la hebra
            current_thread->set_quantum(generate_quantum());
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

   
    current_thread = nullptr;
}

void LVM_Scheduler::semaphore_block_thread(){
    // -- Marcar hebra actual como bloqueada
    current_thread->set_state(LVM_THREAD_BLOCKED);
    // -- Mandar hebra actual a la cola de bloqueadas
    semaphore_blocked_queue.push(std::move(current_thread));

    current_thread = nullptr;
}

void LVM_Scheduler::semaphore_unblock_thread(){
    if(!semaphore_blocked_queue.empty()){
        std::unique_ptr thread = std::move(semaphore_blocked_queue.pop());
        thread->set_state(LVM_THREAD_READY);

        ready_queue.push(std::move(thread));
    }
}

void LVM_Scheduler::unblock_thread(int id){
    // -- Obtener vector con los elementos de la cola
    std::vector<std::unique_ptr<LVM_Thread>> blocked_threads;
    while(!blocked_queue.empty()){
        blocked_threads.push_back(std::move(blocked_queue.pop()));
    }

    for(int i=0; i<blocked_threads.size(); i++){
        if(blocked_threads[i]->get_id() == id){
            // -- Mover thread a la cola de preparados
            std::unique_ptr<LVM_Thread> thread = std::move(blocked_threads[i]);
            thread->set_state(LVM_THREAD_READY);
            ready_queue.push(std::move(thread));
        }
        else{
            blocked_queue.push(std::move(blocked_threads[i]));
        }
    }

   
}

void LVM_Scheduler::terminate_thread(){
    // -- Marcar hebra actual como terminada
    current_thread->set_state(LVM_THREAD_TERMINATED);
    // -- Mandar hebra actual a la cola de terminadas
    terminated_queue.push(std::move(current_thread));
    // -- Incrementar contador de hebras terminadas
    total_finished_threads++;

    current_thread = nullptr;
}