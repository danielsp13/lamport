/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_io.h
 * @author Daniel Perez Ruiz
 * @brief 
 */

#include "lmp_utils/lmp_io.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IO MANAGER] -----

void LMP_IO_Manager::print_header(char *compiler){
    std::cout << compiler << " : Un compilador JIT del lenguaje lamport." << std::endl;
    std::cout << "Version de compilador: " << this->COMPILER_VERSION << std::endl;
    std::cout << "Autor: " << this->AUTHOR << std::endl << std::endl;
}

void LMP_IO_Manager::print_help(char *compiler){
    std::cout << "Uso de compilador: " << compiler << " <fichero.lmp>" << std::endl;
}

bool LMP_IO_Manager::abrir_fichero(){
    // -- Abrir fichero e intentar asignar a puntero
    yyin = fopen(this->lmp_file_name.c_str(), "r");

    // -- Comprobar exito de apertura de fichero
    if(!yyin)
        return false;
    
    // -- Retornar exito
    return true;
}

bool LMP_IO_Manager::cerrar_fichero(){
    // -- Intentar cerrar fichero
    if(!yyin)
        return true;

    if(fclose(yyin) == EOF)
        return false;

    // -- Retornar exito
    return true;
}


// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IO MANAGER] -----

LMP_IO_Manager& LMP_IO_Manager::get_instance(){
    static LMP_IO_Manager instance;
    return instance;
}

LMP_IO_Manager::~LMP_IO_Manager(){
    this->close();
}

void LMP_IO_Manager::close(){
    if(this->IO_STATE){
        this->IO_STATE = false;
        
        tasker.task_close_file_msg(this->lmp_file_name);
        if(!this->cerrar_fichero())
            tasker.task_nop();
        else
            tasker.task_ok();
    }
}

std::string LMP_IO_Manager::start(int nargs, char *argv[]){
    // -- Imprimir cabecera
    this->print_header(argv[0]);

    // -- Comprobar argumentos correctos
    if(nargs < this->N_ARGUMENTS_REQUIRED){
        this->print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    // -- Asignar nombre de compilador
    this->compiler = std::string(argv[0]);
    this->lmp_file_name = std::string(argv[1]);

    // -- Abrir fichero
    tasker.task_open_file_msg(lmp_file_name);
    if(!this->abrir_fichero()){
        tasker.task_nop();
        std::cout << "Error al abrir el fichero: " << this->lmp_file_name << "." << std::endl;
        exit(EXIT_FAILURE);
    }
    this->IO_STATE = true;
    tasker.task_ok();

    // -- Retornar nombre de fichero analizado
    return this->lmp_file_name;
}

