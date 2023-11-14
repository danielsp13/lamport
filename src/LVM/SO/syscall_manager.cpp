/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file syscall_manager.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de gestor de llamadas al sistema de LVM
 */

#include "LVM/SO/syscall_manager.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [SYSCALL MANAGER] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [SYSCALL MANAGER] -----

LVM_Syscall_Manager& LVM_Syscall_Manager::get_instance(){
    static LVM_Syscall_Manager instance;
    return instance;
}

void LVM_Syscall_Manager::handle_syscall_print(LVM_Register_type_t type, reg_data data){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Impresion en salida estandar de ";
    

    switch (type)
    {
    case REG_CONTAINS_INTEGER:
    {
        tracker_msg += "valor entero";
        std::cout << std::get<int>(data);
        break;
    }   
    case REG_CONTAINS_REAL:
    {
        tracker_msg += "valor real";
        std::cout << std::get<float>(data);
        break;
    }
    case REG_CONTAINS_CHAR:
    {
        tracker_msg += "valor caracter";
        std::cout << std::get<char>(data);
        break;
    }
    case REG_CONTAINS_STRING:
    {
        tracker_msg += "valor string";
        std::string value = std::get<std::string>(data);
        value.erase(std::remove(value.begin(), value.end(), '\"'), value.end());

        std::cout << value;
        break;
    }
    case REG_CONTAINS_BOOL:
    {
        tracker_msg += "valor booleano";
        std::cout << std::get<std::string>(data);
        break;
    }
    default:
    {
        break;
    }
    }

    // -- Registrar en traza de ejecucion
    tracker.track(tracker_msg);
}

void LVM_Syscall_Manager::handle_syscall_print_endl(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Impresion en salida estandar de salto de linea";
    tracker.track(tracker_msg);

    std::cout << std::endl;
}

void LVM_Syscall_Manager::handle_syscall_enter_atomic(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Marcar entrada de seccion atomica de hebra con id " + std::to_string(thread_manager.get_current_thread()->get_id());
    tracker.track(tracker_msg);

    thread_manager.current_thread_enters_atomic();
}

void LVM_Syscall_Manager::handle_syscall_exit_atomic(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Marcar salida de seccion atomica de hebra con id " + std::to_string(thread_manager.get_current_thread()->get_id());
    tracker.track(tracker_msg);

    thread_manager.current_thread_exits_atomic();
}

void LVM_Syscall_Manager::handle_syscall_block_current_thread(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Bloqueando hebra con id: " + std::to_string(thread_manager.get_current_thread()->get_id()) + ". No participara en el siguiente ciclo de planificacion.";
    tracker.track(tracker_msg);

    thread_manager.block_current_thread();
}

void LVM_Syscall_Manager::handle_syscall_terminate_current_thread(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Terminando hebra con id: " + std::to_string(thread_manager.get_current_thread()->get_id()) + ". No participara en el siguiente ciclo de planificacion.";
    tracker.track(tracker_msg);

    thread_manager.terminate_current_thread();
}

void LVM_Syscall_Manager::handle_syscall_sleep_current_thread(int milliseconds){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Durmiendo hebra con id: " + std::to_string(thread_manager.get_current_thread()->get_id()) + " un total de: " + std::to_string(milliseconds) + " milisegundos.";
    tracker.track(tracker_msg);

    thread_manager.sleep_current_thread(milliseconds);
}

void LVM_Syscall_Manager::handle_syscall_unblock_thread(int id){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Desbloqueando hebra con id: " + std::to_string(thread_manager.get_current_thread()->get_id()) + ". Participara en el siguiente ciclo de planificacion.";
    tracker.track(tracker_msg);

    thread_manager.terminate_current_thread();
}

void LVM_Syscall_Manager::handle_syscall_create_thread(int pc){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Creando hebra con id: " + std::to_string(thread_manager.get_total_threads()) + ", hija de hebra con id " + std::to_string(thread_manager.get_current_thread()->get_id()) + ". Participara en el siguiente ciclo de planificacion.";
    tracker.track(tracker_msg);

    thread_manager.create_thread(thread_manager.get_total_threads(),pc,thread_manager.get_current_thread()->get_segment(),thread_manager.get_current_thread());
}

void LVM_Syscall_Manager::handle_syscall_create_thread(int id, int pc){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Creando hebra con id: " + std::to_string(id) + ", hija de hebra con id " + std::to_string(thread_manager.get_current_thread()->get_id()) + ". Participara en el siguiente ciclo de planificacion.";
    tracker.track(tracker_msg);

    thread_manager.create_thread(id,pc,thread_manager.get_current_thread()->get_segment(),thread_manager.get_current_thread());
}


void LVM_Syscall_Manager::handle_syscall_create_thread(int id, int pc, int ret_dir){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Creando hebra con id: " + std::to_string(id) + ", hija de hebra con id " + std::to_string(thread_manager.get_current_thread()->get_id()) + ". Participara en el siguiente ciclo de planificacion.";
    tracker.track(tracker_msg);

    thread_manager.create_thread_with_ret(id,pc,thread_manager.get_current_thread()->get_segment(),thread_manager.get_current_thread(),ret_dir);
}

void LVM_Syscall_Manager::handle_syscall_sem_wait(int sem_addr){
    int sem_phisical_addr = memory_manager.get_phisical_addr(LVM_Segment_Table::SEGMENT_FOR_GLOBAL_VARIABLES,sem_addr,0);
    thread_manager.emplace_sem(sem_phisical_addr);

    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Hebra con id: " + std::to_string(thread_manager.get_current_thread()->get_id()) + " realiza WAIT sobre semaforo de direccion fisica: " + std::to_string(sem_phisical_addr);
    tracker.track(tracker_msg);

    LVM_Memory_Block& mem_block = memory_manager.mem_access(LVM_Segment_Table::SEGMENT_FOR_GLOBAL_VARIABLES,sem_addr);
    int sem_counter = mem_block.get_value<int>() - 1;

    if(sem_counter < 0){
        thread_manager.sem_wait(sem_phisical_addr);
    }

    mem_block.allocate_value<int>(sem_counter);
}

void LVM_Syscall_Manager::handle_syscall_sem_signal(int sem_addr){
    int sem_phisical_addr = memory_manager.get_phisical_addr(LVM_Segment_Table::SEGMENT_FOR_GLOBAL_VARIABLES,sem_addr,0);
    thread_manager.emplace_sem(sem_phisical_addr);

    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Hebra con id: " + std::to_string(thread_manager.get_current_thread()->get_id()) + " realiza SIGNAL sobre semaforo de direccion fisica: " + std::to_string(sem_phisical_addr);
    tracker.track(tracker_msg);

    LVM_Memory_Block& mem_block = memory_manager.mem_access(LVM_Segment_Table::SEGMENT_FOR_GLOBAL_VARIABLES,sem_addr);
    int sem_counter = mem_block.get_value<int>() + 1;

    if(sem_counter <= 0){
        thread_manager.sem_signal(sem_phisical_addr);
    }

    mem_block.allocate_value<int>(sem_counter);
}