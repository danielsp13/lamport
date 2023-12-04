/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_tasker.cpp
 * @author Daniel Perez Ruiz
 * @brief Impresor de tareas de compilador lamport
 */

#include "lmp_utils/lmp_tasker.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [TASKER] -----

void LMP_Tasker::task_delay(){
    if(TASKER_AVAIABLE){
        if(!this->DELAY_AVAIABLE)
        return;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(TASK_DELAY));
    }
    
}

void LMP_Tasker::task_execution_delay(){
    if(TASKER_AVAIABLE){
        if(!this->DELAY_AVAIABLE)
        return;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(TASK_EXECUTION_DELAY));
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [TASKER] -----

LMP_Tasker& LMP_Tasker::get_instance(bool delay){
    static LMP_Tasker instance(delay);
    return instance;
}

void LMP_Tasker::task_open_file_msg(std::string filename){
    if(TASKER_AVAIABLE){
        print_yellow();
        std::cout << this->TASK_HEADER_MSG << "Abriendo fichero (" << filename << ") ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_close_file_msg(std::string filename){
    if(TASKER_AVAIABLE){
        print_yellow();
        std::cout << this->TASK_HEADER_MSG << "Cerrando fichero (" << filename << ") ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_parser(){
    if(TASKER_AVAIABLE){
        print_yellow();
        std::cout << this->TASK_HEADER_MSG << "Realizando analisis sintactico de fichero ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_semantic_name_resolution(){
    if(TASKER_AVAIABLE){
        print_yellow();
        std::cout << this->TASK_HEADER_MSG << "Realizando analisis semantico de fichero (resolución de nombres) ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
    
}

void LMP_Tasker::task_semantic_type_checking(){
    if(TASKER_AVAIABLE){
        print_yellow();
        std::cout << this->TASK_HEADER_MSG << "Realizando analisis semantico de fichero (comprobación de tipos) ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();  
    }
}

void LMP_Tasker::task_translate_to_ir(){
    if(TASKER_AVAIABLE){
        print_yellow();
        std::cout << this->TASK_HEADER_MSG << "Generando instrucciones IR para simulación ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_logging_ast(std::string filename){
    if(TASKER_AVAIABLE){
        print_blue();
        std::cout << this->TASK_HEADER_MSG << "Registrando AST generado en fichero (" << filename << ") ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_logging_error_syntax(std::string filename){
    if(TASKER_AVAIABLE){
        print_blue();
        std::cout << this->TASK_HEADER_MSG << "Registrando errores sintácticos producidos en fichero (" << filename << ") ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_logging_error_semantic(std::string filename){
    if(TASKER_AVAIABLE){
        print_blue();
        std::cout << this->TASK_HEADER_MSG << "Registrando errores semánticos producidos en fichero (" << filename << ") ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_logging_ir(std::string filename){
    if(TASKER_AVAIABLE){
        print_blue();
        std::cout << this->TASK_HEADER_MSG << "Registrando mapas e instrucciones IR generados en fichero (" << filename << ") ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_logging_lvm(std::string filename){
    if(TASKER_AVAIABLE){
        print_blue();
        std::cout << this->TASK_HEADER_MSG << "Registrando contenido de memoria y tabla de paginas de máquina virtual en fichero (" << filename << ") ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
    
}

void LMP_Tasker::task_logging_lvm_trace(std::string filename){
    if(TASKER_AVAIABLE){
        print_blue();
        std::cout << this->TASK_HEADER_MSG << "Registrando traza de ejecucion de máquina virtual en fichero (" << filename << ") ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_free_resources(){
    if(TASKER_AVAIABLE){
        print_yellow();
        std::cout << this->TASK_HEADER_MSG << "Liberando memoria dinámica reservada para recursos ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_preload_lvm(){
    if(TASKER_AVAIABLE){
        print_yellow();
        std::cout << this->TASK_HEADER_MSG << "Preparando Máquina Virtual. Volcando información a memoria ... ";
        std::cout.flush();
        print_reset();

        this->task_delay();
    }
}

void LMP_Tasker::task_execute_lvm(){
    if(true){
        std::cout << std::endl;
        std::cout.flush();
        print_wall_white(); print_bold(); print_blue();
        std::cout << this->TASK_HEADER_MSG << "Iniciando Máquina Virtual. Ejecutando código ... " << ANSI_COLOR_RESET << std::endl << std::endl;
        std::cout.flush();

        this->task_execution_delay();
    }
}

void LMP_Tasker::task_shutdown_lvm(){
    if(true){
        std::cout << std::endl;
        std::cout.flush();
        print_wall_white(); print_bold(); print_blue();
        std::cout << this->TASK_HEADER_MSG << "Finalizando ejecución de Máquina Virtual ... " << ANSI_COLOR_RESET << std::endl;
        std::cout.flush();

        this->task_execution_delay();
    }
    
}

void LMP_Tasker::task_ok(){
    if(TASKER_AVAIABLE){
        print_green();
        std::cout << "[ok]" << std::endl;
        print_reset();
    }
    
}

void LMP_Tasker::task_nop(){
    if(TASKER_AVAIABLE){
        print_red();
        std::cout << "[nop]" << std::endl;
        print_reset();
    }
}