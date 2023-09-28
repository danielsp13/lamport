/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_io.h
 * @author Daniel Perez Ruiz
 * @brief 
 */

#include "lmp_utils/lmp_io.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IO MANAGER] -----

void LMP_IO_Manager::print_header(char *interpreter){
    std::cout << interpreter << " : Un interprete del lenguaje lamport." << std::endl;
    std::cout << "Version de interprete: " << this->INTERPRETER_VERSION << std::endl;
    std::cout << "Autor: " << this->AUTHOR << std::endl << std::endl;
}

void LMP_IO_Manager::print_help(char *interpreter){
    std::cout << "Uso de interprete: " << interpreter << " <fichero.lmp>" << std::endl;
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
    if(this->IO_STATE)
        this->cerrar_fichero();
}

std::string LMP_IO_Manager::start(int nargs, char *argv[]){
    // -- Imprimir cabecera
    this->print_header(argv[0]);

    // -- Comprobar argumentos correctos
    if(nargs < this->N_ARGUMENTS_REQUIRED){
        this->print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    // -- Asignar nombre de interprete
    this->interpreter = std::string(argv[0]);
    this->lmp_file_name = std::string(argv[1]);
    this->IO_STATE = true;

    // -- Abrir fichero
    if(!this->abrir_fichero()){
        std::cout << "Error al abrir el fichero: " << this->lmp_file_name << "." << std::endl;
        exit(EXIT_FAILURE);
    }

    // -- Retornar nombre de fichero analizado
    return this->lmp_file_name;
}

