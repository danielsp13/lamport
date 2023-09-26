/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_io.h
 * @author Daniel Perez Ruiz
 * @brief Gestor de entrada/salida de interprete lamport
 */

#ifndef _LMP_INTERPRETER_IO_DPR_
#define _LMP_INTERPRETER_IO_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <cstring>
#include <string>

#include "lmp_c_io_bridge.hpp"      ///< Puente de C a C++ para entrada/salida lamport

// ===============================================================

// ----- DEFINICION DE CLASE MANEJADORA DE FLUJO DE I/O -----

/**
 * @brief Clase que maneja los flujos de entrada/salida con el interprete
 * Se encarga de abrir el fichero pasado como argumento y asignarlo al
 * puntero de entrada de bison para poder realizar posteriormente el analisis
 */
class LMP_IO_Manager{
    private:
        // -- Nombre de interprete
        std::string interpreter;
        // -- Nombre de fichero lamport
        std::string lmp_file_name;

        // -- Version de interprete
        const std::string INTERPRETER_VERSION = "0.0.7";
        // -- Autor de interprete
        const std::string AUTHOR = "Daniel Perez Ruiz";

        // -- Numero de argumentos requeridos para ejecucion de interprete
        const unsigned int N_ARGUMENTS_REQUIRED = 2;

        /**
         * @brief Imprime la cabecera del interprete
         * @param interpreter : nombre de interprete
         */
        void print_header(char *interpreter);

        /**
         * @brief Imprime la ayuda de uso de interprete
         * @param interpreter : nombre de interprete
         */
        void print_help(char *interpreter);

        /**
         * @brief Abre el fichero de codigo lamport
         * @return TRUE si se abrio correctamente, FALSE en otro caso
         */
        bool abrir_fichero();

        /**
         * @brief Cierra el fichero de codigo lamport
         * @return TRUE si se cerro correctamente, FALSE en otro caso
         */
        bool cerrar_fichero();

    public:
        /**
         * @brief Constructor de la clase
         */
        LMP_IO_Manager() {};

        /**
         * @brief Destructor de la clase
         */
        ~LMP_IO_Manager();
        
        /**
         * @brief Inicializa el manejador de IO
         * @param nargs : numero de argumentos
         * @param argv : argumentos
         * @return nombre de fichero abierto
         */
        std::string start(int nargs, char *argv[]);
};

#endif //_LMP_INTERPRETER_IO_DPR_