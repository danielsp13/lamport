/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file EU.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de EU de CPU para la maquina virtual de lamport
 */

#include "LVM/CPU/EU.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [EU] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [EU] -----

LVM_CPU_EU& LVM_CPU_EU::get_instance(){
    static LVM_CPU_EU instance;
    return instance;
}

void LVM_CPU_EU::execute_start_program(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "inicio de programa";
    tracker.track(tracker_msg);


}

void LVM_CPU_EU::execute_end_program(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "fin de programa";
    tracker.track(tracker_msg);
}

void LVM_CPU_EU::execute_initialize_global_var(){
    
}

void LVM_CPU_EU::execute_end_initialize_global_var(){
    execute_syscall_terminate_current_thread();
}

void LVM_CPU_EU::execute_start_process(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "iniciando proceso con id: " + std::to_string(thread_manager.get_current_thread()->get_id());
    tracker.track(tracker_msg);
}

void LVM_CPU_EU::execute_end_process(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "terminando proceso con id: " + std::to_string(thread_manager.get_current_thread()->get_id());
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_terminate_current_thread();
}

void LVM_CPU_EU::execute_load(int reg_dest, int segment_op_1, int virt_dir_op_1, int offset_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "cargando contenido de memoria (segmento " + std::to_string(segment_op_1) + " -> " + std::to_string(virt_dir_op_1) + "+" + std::to_string(offset_op_1) + ") " + "en registro " + "%r" + std::to_string(reg_dest);
    tracker.track(tracker_msg);

    // -- Obtener bloque de memoria
    const LVM_Memory_Block& mem_block = memory_manager.mem_access(segment_op_1,virt_dir_op_1,offset_op_1);

    // -- Volcar contenido en registro
    registers(reg_dest,mem_block);
}

void LVM_CPU_EU::execute_store(int reg_dest, int reg_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "guardando contenido de registro " + "%r" + std::to_string(reg_dest) + " en registro " + "%r" + std::to_string(reg_op_1);
    tracker.track(tracker_msg);

    registers[reg_dest] = registers[reg_op_1];
}

void LVM_CPU_EU::execute_store(int segment_dest, int virt_dir_dest, int offset_dir_dest, int reg_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "guardando contenido de registro " + "%r" + std::to_string(reg_op_1) + " en memoria (segmento " + std::to_string(segment_dest) + " -> " + std::to_string(virt_dir_dest) + "+" + std::to_string(offset_dir_dest) + ")";
    tracker.track(tracker_msg);

    // -- Obtener bloque de memoria
    LVM_Memory_Block& mem_block = memory_manager.mem_access(segment_dest,virt_dir_dest,offset_dir_dest);
    
    // -- Obtener registro
    const LVM_Register& reg = registers[reg_op_1];

    // -- Copiar valor de registro en bloque
    switch (reg.get_type_of_alloc())
    {
    case REG_CONTAINS_INTEGER:
    {
        mem_block.allocate_value<int>(reg.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        mem_block.allocate_value<float>(reg.get_value<float>());
        break;
    }
    case REG_CONTAINS_CHAR:
    {
        mem_block.allocate_value<char>(reg.get_value<char>());
        break;
    }
    case REG_CONTAINS_STRING:
    {
        mem_block.allocate_value<std::string>(reg.get_value<std::string>());
        break;
    }
    case REG_CONTAINS_BOOL:
    {
        mem_block.allocate_value<bool>(reg.get_value<bool>());
        break;
    }
    default:
        throw std::invalid_argument("CONTENIDO DE REGISTRO PARA OP_STORE INVÁLIDO, INSTRUCCION [" + std::to_string(registers.get_pc()) + "].");
        break;
    } 
}

void LVM_CPU_EU::execute_jmp_unconditional(long virt_dir_op_1){
    // -- Obtener bloque de memoria
    const LVM_Memory_Block& mem_block = memory_manager.mem_access(LVM_Segment_Table::SEGMENT_FOR_LABELS,virt_dir_op_1);

    // -- Modificar PC
    registers.set_pc(mem_block.get_value<long>());

    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "salto incondicional a instruccion: " + std::to_string(mem_block.get_value<long>());
    tracker.track(tracker_msg);
}

void LVM_CPU_EU::execute_jmp_conditional(bool condition, int reg_op_1, long virt_dir_op_2){
    // -- Obtener bloque de memoria
    const LVM_Memory_Block& mem_block = memory_manager.mem_access(LVM_Segment_Table::SEGMENT_FOR_LABELS,virt_dir_op_2);

    // -- Obtener registro de evaluacion de condicion
    const LVM_Register& reg = registers[reg_op_1];

    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "evaluando registro " + "%r" + std::to_string(reg_op_1) + "(" + reg.get_value_str() + ")" + " para saltar a instruccion: " + std::to_string(mem_block.get_value<long>()) + ".";
    

    // -- Comprobar si se evalua la condicion
    if(reg.get_value<bool>() == condition){
        registers.set_pc(mem_block.get_value<long>());

        // -- Registrar en traza de ejecucion
        tracker_msg += "Decision: salta";
    }
    else{
        registers.set_pc(registers.get_pc()+1);

        // -- Registrar en traza de ejecucion
        tracker_msg += "Decision: NO salta";
    }

    // -- Registrar en traza de ejecucion
    tracker.track(tracker_msg);
}

void LVM_CPU_EU::execute_push(int reg_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar push en pila de hebra para argumento de funcion: " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")";
    tracker.track(tracker_msg);
    
    thread_manager.get_current_thread()->get_stack().push(registers[reg_op_1]);
}

void LVM_CPU_EU::execute_pop(int reg_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar pop en pila de hebra para argumento de funcion: " + "%r" + std::to_string(reg_op_1);
    tracker.track(tracker_msg);

    // -- Volver a asignar registro a tabla
    registers[reg_op_1] = thread_manager.get_current_thread()->get_stack().top_and_pop_reg();
}

void LVM_CPU_EU::execute_call(int label_dir_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "";
    tracker.track(tracker_msg);

    thread_manager.get_current_thread()->get_stack().push_ret_dir(registers.get_pc());

    // -- Obtener bloque de memoria
    LVM_Memory_Block mem_block = memory_manager.mem_access(LVM_Segment_Table::SEGMENT_FOR_LABELS,label_dir_op_1);

    // -- Obtener direccion de etiqueta
    registers.set_pc(static_cast<int>(mem_block.get_value<long>()));
}

void LVM_CPU_EU::execute_ret(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizando retorno de subprograma. ";
    
    LVM_Block return_dir = thread_manager.get_current_thread()->get_stack().top_and_pop();
    
    if(thread_manager.get_current_thread()->is_child()){
        syscall_manager.handle_syscall_terminate_current_thread();
        return;
    }

    // --- Obtener la direccion de retorno
    registers.set_pc(return_dir.get_value<long>() + 1);

    tracker_msg += "Instruccion de regreso: " + registers.get_pc();
    tracker.track(tracker_msg);

    
}

void LVM_CPU_EU::execute_syscall_print(int reg_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada a sistema (print) con registro: " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")";
    tracker.track(tracker_msg);

    // -- Obtener registro
    const LVM_Register& reg = registers[reg_op_1];
    const LVM_Register_type_t type = reg.get_type_of_alloc();
    reg_data value;

    switch (type)
    {
    case REG_CONTAINS_INTEGER:
        value = reg.get_value<int>();
        break;
    case REG_CONTAINS_REAL:
        value = reg.get_value<float>();
        break;
    case REG_CONTAINS_CHAR:
        value = reg.get_value<char>();
        break;
    case REG_CONTAINS_STRING:
        value = reg.get_value<std::string>();
        break;
    case REG_CONTAINS_BOOL:
        value = reg.get_value_str();
        break;
    
    default:
        break;
    }

    syscall_manager.handle_syscall_print(type,value);
}

void LVM_CPU_EU::execute_syscall_print_endl(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada a sistema (print endl)";
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_print_endl();
}

void LVM_CPU_EU::execute_syscall_enter_atomic(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada a sistema (entrar en seccion atomica)";
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_enter_atomic();
}

void LVM_CPU_EU::execute_syscall_exit_atomic(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada a sistema (salir en seccion atomica)";
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_exit_atomic();
}

void LVM_CPU_EU::execute_syscall_block_current_thread(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada a sistema (bloquear hebra actual)";
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_block_current_thread();
}

void LVM_CPU_EU::execute_syscall_sleep_current_thread(int milliseconds){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada a sistema (dormir hebra actual)";
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_sleep_current_thread(registers[milliseconds].get_value<int>());
}

void LVM_CPU_EU::execute_syscall_terminate_current_thread(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada a sistema (terminar hebra actual)";
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_terminate_current_thread();
}

void LVM_CPU_EU::execute_syscall_create_thread(){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada a sistema (crear hebra)";
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_create_thread(registers.get_pc()+1);
}

void LVM_CPU_EU::execute_syscall_create_thread(int id, int pc, bool from_mem, int ret_dir){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada a sistema (crear hebra)";
    tracker.track(tracker_msg);

    int pc_dir = pc;
    if(from_mem){
        pc_dir = static_cast<int>(memory_manager.mem_access(LVM_Segment_Table::SEGMENT_FOR_LABELS,pc).get_value<long>());

        syscall_manager.handle_syscall_create_thread(id,pc_dir,ret_dir);

        return;
    }

    syscall_manager.handle_syscall_create_thread(id,pc_dir);
}

void LVM_CPU_EU::execute_syscall_sem_wait(int sem_addr_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada al sistema (operacion wait sobre semaforo)";
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_sem_wait(sem_addr_op_1);
}

void LVM_CPU_EU::execute_syscall_sem_signal(int sem_addr_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "realizar llamada al sistema (operacion signal sobre semaforo)";
    tracker.track(tracker_msg);

    syscall_manager.handle_syscall_sem_signal(sem_addr_op_1);
}