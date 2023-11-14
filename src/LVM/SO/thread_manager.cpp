/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file thread_manager.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de gestor de hebras/procesos de LVM
 */

#include "LVM/SO/thread_manager.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [THREAD MANAGER] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [THREAD MANAGER] -----

LVM_Thread_Manager& LVM_Thread_Manager::get_instance(){
    static LVM_Thread_Manager instance;
    return instance;
}

void LVM_Thread_Manager::schedule(){
    scheduler.schedule();
}

void LVM_Thread_Manager::create_thread(int id, int pc, int segment, LVM_Thread * parent, int priority, int quantum, int childs){
    LVM_Thread * new_thread = new LVM_Thread(id,pc,segment,priority,parent);

    // -- Notificar al padre de la creacion de un nuevo hijo
    /*if(parent != nullptr){
        parent->set_child();
    }*/

    // -- Incluir quantum inicial
    new_thread->set_quantum(quantum);

    // -- Incluir numero de hijas
    new_thread->set_child_counter(childs);

    // -- Incluir en el planificador
    scheduler.new_thread_raw(new_thread);
}

void LVM_Thread_Manager::create_thread_with_ret(int id, int pc, int segment, LVM_Thread * parent, int ret_dir){
    LVM_Thread * new_thread = new LVM_Thread(id,pc,segment,1,parent);

    // -- Notificar al padre de la creacion de un nuevo hijo
    /*if(parent != nullptr){
        parent->set_child();
    }*/
    // -- Push de direccion de retorno
    new_thread->get_stack().push_ret_dir(ret_dir);

    // -- Incluir en el planificador
    scheduler.new_thread_raw(new_thread);
}

void LVM_Thread_Manager::create_master_thread(int quantum){
    create_thread(1000, 1, LVM_Segment_Table::SEGMENT_FOR_GLOBAL_VARIABLES, nullptr, LVM_Thread::MASTER_PRIORITY,quantum);
}

void LVM_Thread_Manager::sleep_current_thread(int milliseconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void LVM_Thread_Manager::block_current_thread(){
    scheduler.block_current_thread();
}

void LVM_Thread_Manager::terminate_current_thread(){
    scheduler.terminate_thread();
}

void LVM_Thread_Manager::unblock_thread(int id){
    scheduler.unblock_thread(id);
}

void LVM_Thread_Manager::current_thread_enters_atomic(){
    get_current_thread()->mark_atomic();
}

void LVM_Thread_Manager::current_thread_exits_atomic(){
    get_current_thread()->unmark_atomic();
}

bool LVM_Thread_Manager::check_all_threads_terminated() const{
    return scheduler.check_all_threads_terminated();
}

void LVM_Thread_Manager::emplace_sem(int sem_addr){
    semaphores.emplace(sem_addr,LVM_Threads_Queue());
}

void LVM_Thread_Manager::sem_wait(int sem_addr){
    // -- Mover esta hebra a la cola del semaforo especificado
    std::unique_ptr<LVM_Thread> thread = get_current_thread_unique();
    thread->set_state(LVM_THREAD_BLOCKED);
    thread->set_quantum(0);
    semaphores[sem_addr].push(std::move(thread));
}

void LVM_Thread_Manager::sem_signal(int sem_addr){
    std::unique_ptr<LVM_Thread> thread = std::move(semaphores[sem_addr].pop());
    // -- Mover esta hebra a la cola del semaforo especificado
    thread->set_state(LVM_THREAD_READY);

    scheduler.move_thread_to_ready(std::move(thread));
}