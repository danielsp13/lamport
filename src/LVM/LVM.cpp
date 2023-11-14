/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file LVM.cpp
 * @author Daniel Perez Ruiz
 * @brief Maquina Virtual de Lamport
 */

#include "LVM/LVM.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [LVM] -----

bool LVM::check_posix_interrupt_signals_received() const{
    return SIGSEGV_received.load() || SIGINT_received.load() || SIGABRT_received.load();
}

bool LVM::check_initialize_global_vars(){
    IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();

    for(int i=0; i<instructions.size(); i++){
        if(instructions[i].get_code_instr() == IR_INITIALIZE_GLOBAL_VAR)
            return true;
        else if(instructions[i].get_code_instr() == IR_START_PROCESS)
            return false;
    }
    
    return false;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [LVM] -----

LVM& LVM::get_instance(){
    static LVM instance;
    return instance;
}

void LVM::notify_posix_interrupt_sigsegv(){
    SIGSEGV_received.store(true);
}

void LVM::notify_posix_interrupt_sigabrt(){
    SIGABRT_received.store(true);
}

void LVM::notify_posix_interrupt_sigint(){
    SIGINT_received.store(true);
}

LVM::~LVM(){
    if(this->state != LVM_STATE_DEAD)
        this->state = LVM_STATE_SHUTDOWN;
}

void LVM::print_segment_table(std::ostream& os){
    if(this->state == LVM_STATE_BORN)
        return;

    memory_manager.print_segment_table(os);
}

void LVM::print_memory(std::ostream& os){
    if(this->state == LVM_STATE_BORN)
        return;

    memory_manager.print_memory(os);
}

void LVM::print_lvm_trace(std::ostream& os){
    if(this->state == LVM_STATE_BORN)
        return;

    tracker.print_trace(os);
}

bool LVM::preload_lvm(bool verbose_avaiable){
    if(this->state == LVM_STATE_BORN){
        // -- Cambiar estado a prepared
        this->state = LVM_STATE_PREPARED;

        // -- Volcar contenido a memoria
        memory_manager.get_initializer().dump_to_memory();

        // -- Crear hebras iniciales
        memory_manager.get_initializer().create_threads();

        // -- Imprimir contenido (si esta habilitado)
        if(verbose_avaiable){
            // -- Imprimir tabla de paginas
            memory_manager.print_segment_table();

            // -- Imprimir memoria
            memory_manager.print_memory();
        }

        return true;
    }
    
    return false;
}

bool LVM::run(){
    if(this->state == LVM_STATE_PREPARED){
        // -- Cambiar estado a ejecutandose
        this->state == LVM_STATE_RUNNING;

        // -- Inicializar el manejador de signals LINUX
        LVM_Linux_Posix_Signals_Manager::init_signal_handlers();

        // -- Inicializar gestor de traza de ejecucion
        tracker.activate();

        // -- Indicar inicio de maquina virtual
        tracker.track(TRACKER_HEADER + "inicio de Maquina Virtual de Lamport");
        
        // -- Seguir ejecutando maquina virtual ...
        while(!CPU.program_terminated() && !check_posix_interrupt_signals_received()){
            int actual_cycle = CPU.get_cycle();
            // -- Registrar nuevo ciclo de CPU
            tracker.track(TRACKER_HEADER + "Nuevo ciclo de CPU. Ciclo: " + std::to_string(actual_cycle));

            // -- Obtener una nueva planificacion y obtener nueva hebra a ejecutar
            thread_manager.schedule();
            LVM_Thread * current_thread = thread_manager.get_current_thread();

            // -- Registar hebra ganadora y quantum de tiempos
            if(current_thread->get_quantum() != 0){
                if(current_thread->in_atomic_section()){
                    tracker.track(TRACKER_HEADER + "Ejecucion (" + std::to_string(current_thread->get_total_instructions_executed()+1) + ") en seccion atomica de la hebra con id: " + std::to_string(current_thread->get_id()));
                }
                else{
                    tracker.track(TRACKER_HEADER + "Ejecucion (" + std::to_string(current_thread->get_total_instructions_executed()+1) + " de " + std::to_string(current_thread->get_quantum()) + ") de la hebra con id: " + std::to_string(current_thread->get_id()));
                }
            }
            else
                tracker.track(TRACKER_HEADER + "Ejecucion de la hebra con id: " + std::to_string(current_thread->get_id()));

            // -- Ejecutar 
            CPU.execute_next_instruction(current_thread);

            tracker.track(TRACKER_HEADER + "Fin de ciclo de CPU. Ciclo: " + std::to_string(actual_cycle));
            tracker.track("\n");

            // --- COUT
            //tracker.print_cpu_cycle_trace();

            // -- Confirmar ciclo
            tracker.confirm_track_cycle();
        }

        // -- Comprobar si se han recibido signals
        if(check_posix_interrupt_signals_received()){
            if(SIGSEGV_received.load()){
                std::cout << " SIGSEGV detectado: Violacion de Segmento (core generado). Abortando LVM." << std::endl; std::cout.flush();
                tracker.track(TRACKER_HEADER + "Violacion de Segmento producido. Captada signal SIGSEGV. Abortando maquina...");
            }
            else if(SIGINT_received.load()){
                std::cout << " SIGINT detectado: Ctrl+C. Terminando LVM." << std::endl; std::cout.flush();
                tracker.track(TRACKER_HEADER + "Ctrl+C producido. Captada signal SIGINT. Terminando maquina...");
            }
            else if(SIGABRT_received.load()){
                std::cout << " SIGABRT detectado: Fallo irrecuperable. Terminando LVM." << std::endl; std::cout.flush();
                tracker.track(TRACKER_HEADER + "Fallo irrecuperable producido. Captada signal SIGABRT. Terminando maquina...");
            }
        }

        tracker.track(TRACKER_HEADER + "fin de Maquina Virtual de Lamport");
        tracker.confirm_track_cycle();

        return true;
    }
    
    return false;
}