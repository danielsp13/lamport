/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file CU.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de CU de CPU para la maquina virtual de lamport
 */

#include "LVM/CPU/CU.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [CU] -----

int LVM_CPU_CU::get_segment(IR_operand_t type, int virtual_dir, int offset_dir){
    switch (type)
    {
    case IR_OPERAND_LITERAL:
    {
        return LVM_Segment_Table::SEGMENT_FOR_LITERALS;
        break;
    }
    case IR_OPERAND_VARIABLE:
    {
        if(memory_manager.check_phisical_addr(segment_thread,virtual_dir)){
            return segment_thread;

            break;
        }

        return LVM_Segment_Table::SEGMENT_FOR_GLOBAL_VARIABLES;

        break;
    }
    case IR_OPERAND_VARIABLE_ARRAY:
    {
        if(memory_manager.check_phisical_addr(segment_thread,virtual_dir,offset_dir)){
            return segment_thread;

            break;
        }

        return LVM_Segment_Table::SEGMENT_FOR_GLOBAL_VARIABLES;

        break;
    }
    case IR_OPERAND_LABEL:
    {
        return LVM_Segment_Table::SEGMENT_FOR_LABELS;
        break;
    }
    
    default:
        return -1;
        break;
    }
}

int LVM_CPU_CU::get_offset(IR_operand_t type, int offset_reg){
    if(type != IR_OPERAND_VARIABLE_ARRAY)
        return 0;

    return registers[offset_reg].get_value<int>();
}

int LVM_CPU_CU::get_value_from_operand(int n_operand, bool offset){
    switch (n_operand)
    {
    case 0:
    {
        try{
            if(offset)
                return fetched_instr_operand_dest.value().get_offset();

            return fetched_instr_operand_dest.value().get_address();
        }
        catch(const std::exception& e){
            std::cerr << TRACKER_HEADER << "EXCEPCION OBTENIDA AL DECODIFICAR OPERANDO DESTINO DE INSTRUCCION : " << fetched_instr->get_code_instr_str() << std::endl;
            std::cerr << TRACKER_HEADER << "Motivo: " << e.what() << std::endl;
            abort();
        }
        break;
    }
    case 1:
    {
        try{
            if(offset)
                return fetched_instr_operand_1.value().get_offset();

            return fetched_instr_operand_1.value().get_address();
        }
        catch(const std::exception& e){
            std::cerr << TRACKER_HEADER << "EXCEPCION OBTENIDA AL DECODIFICAR OPERANDO 1 DE INSTRUCCION : " << fetched_instr->get_code_instr_str() << std::endl;
            std::cerr << TRACKER_HEADER << "Motivo: " << e.what() << std::endl;
            abort();
        }
        break;
    }
    case 2:
    {
        try{
            if(offset)
                return fetched_instr_operand_2.value().get_offset();

            return fetched_instr_operand_2.value().get_address();
        }
        catch(const std::exception& e){
            std::cerr << TRACKER_HEADER << "EXCEPCION OBTENIDA AL DECODIFICAR OPERANDO 2 DE INSTRUCCION : " << fetched_instr->get_code_instr_str() << std::endl;
            std::cerr << TRACKER_HEADER << "Motivo: " << e.what() << std::endl;
            abort();
        }
        break;
    }
    
    default:
        return -1000;
        break;
    }
}

void LVM_CPU_CU::decode(){
    // -- Obtener operando de destino
    fetched_instr_operand_dest = fetched_instr->get_operand_destiny();
    // -- Obtener operando 1
    fetched_instr_operand_1 = fetched_instr->get_operand_1();
    // -- Obtener operando 2
    fetched_instr_operand_2 = fetched_instr->get_operand_2();

    // -- Comprobar tipo de instruccion a ejecutar. Alterar flags
    instr_checker.check(fetched_instr_code);

    if(instr_checker.is_instr_decoded()){
        // -- Registrar en traza de ejecucion
        std::string tracker_msg = TRACKER_HEADER + "instruccion decodificada";
        tracker.track(tracker_msg);
    }
}

void LVM_CPU_CU::execute(){
    // -- Obtener y ejecutar en funcion del flag activado
    if(instr_checker.is_start_program()){
        EU.execute_start_program();

        return;
    }
    if(instr_checker.is_end_program()){
        EU.execute_end_program();
        program_ended = true;

        registers.set_pc(instructions.size());

        return;
    }
    if(instr_checker.is_start_process()){
        EU.execute_start_process();

        return;
    }
    if(instr_checker.is_end_process()){
        EU.execute_end_process();

        return;
    }
    if(instr_checker.is_initialize_global_var()){
        EU.execute_initialize_global_var();

        update_pc(true);

        return;
    }
    if(instr_checker.is_end_initialize_global_var()){
        EU.execute_end_initialize_global_var();

        return;
    }
    if(instr_checker.is_load_operation()){
        //std::cout << "Es un load: "<< std::endl; //std::cout.flush();
        int reg_dest = get_value_from_operand(0);
        IR_operand_t op_1_type = fetched_instr_operand_1.value().get_kind();
        int virt_dir_op_1 = get_value_from_operand(1);
        int offset_op_1 = get_offset(op_1_type,get_value_from_operand(1,true));
        int segment_dir_op_1 = get_segment(op_1_type,virt_dir_op_1,offset_op_1);
        

        // -- Comprobar si se trata de un acceso a array y comprobar limites
        if(op_1_type == IR_OPERAND_VARIABLE_ARRAY){
            memory_manager.check_array_bounds(segment_dir_op_1,virt_dir_op_1,offset_op_1);
        }
        
        EU.execute_load(reg_dest,segment_dir_op_1,virt_dir_op_1,offset_op_1);

        return;
    }
    if(instr_checker.is_store_operation()){
        //std::cout << "Es un store: "<< std::endl; //std::cout.flush();
        IR_operand_t dest_type = fetched_instr_operand_dest.value().get_kind();
        int dest_addr = get_value_from_operand(0);

        int reg_op_1 = get_value_from_operand(1);

        // -- Comprobar si el destino de store es un registro
        if(dest_type == IR_OPERAND_REGISTER){
            EU.execute_store(dest_addr,reg_op_1);

            return;
        }

        int offset_addr = get_offset(dest_type,get_value_from_operand(0,true));
        int segment_addr = get_segment(dest_type,dest_addr,offset_addr);

        // -- Comprobar si el destino de estore es un acceso a array y comprobar limites
        if(dest_type == IR_OPERAND_VARIABLE_ARRAY){
            memory_manager.check_array_bounds(segment_addr,dest_addr,offset_addr);
        }
        
        EU.execute_store(segment_addr,dest_addr,offset_addr,reg_op_1);
        
        return;
    }
    if(instr_checker.is_alu_binary_operation()){
        //std::cout << "Es un ALU Binary: "<< std::endl; //std::cout.flush();
        int reg_dest = get_value_from_operand(0);
        int reg_op_1 = get_value_from_operand(1);
        int reg_op_2 = get_value_from_operand(2);

        ALU.execute_binary_operation(fetched_instr_code,reg_dest,reg_op_1,reg_op_2);

        return;
    }
    if(instr_checker.is_alu_unary_operation()){
        //std::cout << "Es un ALU Unary: "<< std::endl; //std::cout.flush();
        int reg_dest = get_value_from_operand(0);
        int reg_op_1 = get_value_from_operand(1);

        ALU.execute_unary_operation(fetched_instr_code,reg_dest,reg_op_1);

        return;
    }
    if(instr_checker.is_jmp_operation_unconditional()){
        int virt_dir_op_1 = get_value_from_operand(1);

        EU.execute_jmp_unconditional(virt_dir_op_1);

        return;
    }
    if(instr_checker.is_jmp_operation_conditional()){
        bool condition = fetched_instr_code == IR_OP_JMP_TRUE;
        int reg_op_1 = get_value_from_operand(1);
        int virt_dir_op_2 = get_value_from_operand(2);

        EU.execute_jmp_conditional(condition,reg_op_1,virt_dir_op_2);

        return;
    }
    if(instr_checker.is_push_operation()){
        int reg_op_1 = get_value_from_operand(1);

        EU.execute_push(reg_op_1);

        return;
    }
    if(instr_checker.is_pop_operation()){
        int reg_op_1 = get_value_from_operand(1);

        EU.execute_pop(reg_op_1);

        return;
    }
    if(instr_checker.is_call_operation()){
        int virt_dir_op_1 = get_value_from_operand(1);
        EU.execute_call(virt_dir_op_1);

        return;
    }
    if(instr_checker.is_ret_operation()){
        EU.execute_ret();

        return;
    }
    if(instr_checker.is_system_call_operation()){
        //std::cout << "Es una llamada al sistema: "<< std::endl; //std::cout.flush();
        manage_system_call();
        return;
    }

    //std::cout << "NO ES NADA: "<< std::endl; //std::cout.flush();
}

void LVM_CPU_CU::manage_system_call(){
    switch (fetched_instr_code)
    {
    case IR_OP_PRINT:
    {
        int reg_op_1 = get_value_from_operand(1);
        EU.execute_syscall_print(reg_op_1);

        update_pc(true);

        break;
    }
    case IR_END_PRINT:
    {
        EU.execute_syscall_print_endl();

        update_pc(true);

        break;
    }
    case IR_OP_ATOMIC_BEGIN:
    {
        EU.execute_syscall_enter_atomic();

        update_pc(true);

        break;
    }
    case IR_OP_ATOMIC_END:
    {
        EU.execute_syscall_exit_atomic();

        update_pc(true);

        break;
    }
    case IR_OP_SEM_WAIT:
    {
        int sem_addr_op_1 = get_value_from_operand(1);
        thread_manager.get_current_thread()->set_pc(registers.get_pc()+1);
        EU.execute_syscall_sem_wait(sem_addr_op_1);

        update_pc(true);

        break;
    }
    case IR_OP_SEM_SIGNAL:
    {
        int sem_addr_op_1 = get_value_from_operand(1);
        EU.execute_syscall_sem_signal(sem_addr_op_1);

        update_pc(true);

        break;
    }
    case IR_START_DPROCESS:
    {
        int jmp_addr = get_value_from_operand(0);
        int id = get_value_from_operand(1);
        // -- Comprobar si se trata de un fork o de un cobegin
        if(fetched_instr_operand_2.has_value()){
            int call_addr = get_value_from_operand(2);
            EU.execute_syscall_create_thread(id,call_addr,true,jmp_addr);

            // -- Modificar PC a la direccion de salto directo
            registers.set_pc(jmp_addr);
        }
        else{
            EU.execute_syscall_create_thread(id,registers.get_pc()+1);
            // -- Modificar PC a la direccion de salto directo
            registers.set_pc(jmp_addr);
        }

        break;
    }
    case IR_WAIT_PROCESS:
    {
        // -- Mover PC
        thread_manager.get_current_thread()->set_pc(registers.get_pc()+1);
        // -- Mover registros
        thread_manager.get_current_thread()->set_registers(registers.get_registers());
        // -- Marcar instruccion como ejecutada
        thread_manager.get_current_thread()->instruction_executed();

        update_pc(true);

        // -- Bloquear
        EU.execute_syscall_block_current_thread();
        break;
    }
    case IR_SLEEP_PROCESS:
    {
        int milliseconds = get_value_from_operand(1);
        EU.execute_syscall_sleep_current_thread(milliseconds);

        update_pc(true);
        
        break;
    }
    default:
        break;
    }
}

void LVM_CPU_CU::update_pc(bool forced){
    // -- Flag de estado de incremento. Incremento en una unidad
    bool increment_pc_once = instr_checker.is_label_pointer() 
    || instr_checker.is_start_program()
    || instr_checker.is_start_process() || instr_checker.is_end_process() 
    || instr_checker.is_load_operation() || instr_checker.is_store_operation()
    || instr_checker.is_alu_binary_operation() || instr_checker.is_alu_unary_operation() 
    || instr_checker.is_push_operation() || instr_checker.is_pop_operation()
    || forced;

    // -- Modificar contador de programa en funcion del flag activado
    if(increment_pc_once){
        registers.set_pc(registers.get_pc()+1);
        return;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [CU] -----

LVM_CPU_CU& LVM_CPU_CU::get_instance(){
    static LVM_CPU_CU instance;
    return instance;
}

void LVM_CPU_CU::fetch(){
    // -- Obtener instruccion a la que apunta el contador de programa
    fetched_instr = std::make_shared<IR_instruction>(instructions[registers.get_pc()]);

    // -- Obtener codigo de instruccion captada
    fetched_instr_code = fetched_instr->get_code_instr();
    //std::cout << "Codigo entero de instruccion (" << fetched_instr->get_code_instr_str() << "): " << fetched_instr_code << std::endl; //std::cout.flush();

    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "PC = " + std::to_string(registers.get_pc());
    if(fetched_instr->get_code_instr() == IR_LABEL){
        tracker_msg +=  "; instr. captada: IR_LABEL";
    }
    else{
        tracker_msg +=  "; instr. captada: " + fetched_instr->get_code_instr_str();
    }
    tracker.track(tracker_msg);

    // -- Decodificar
    decode();

    // -- Ejecutar
    execute();

    // -- Registrar en traza de ejecucion
    tracker_msg = TRACKER_HEADER + "instruccion ejecutada";
    tracker.track(tracker_msg);

    // -- Actualizar contador de programa (si procede)
    update_pc();

    // -- Resetear flags
    instr_checker.reset_flags();
}