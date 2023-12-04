/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_io.h
 * @author Daniel Perez Ruiz
 * @brief Gestor de entrada/salida de compilador lamport
 */

#ifndef _LMP_COMPILER_IO_DPR_
#define _LMP_COMPILER_IO_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <cstring>
#include <string>

#include "lmp_c_io_bridge.hpp"      ///< Puente de C a C++ para entrada/salida lamport
#include "lmp_tasker.hpp"           ///< Notificador de tareas

// ===============================================================

// ----- DEFINICION DE CLASE MANEJADORA DE FLUJO DE I/O -----

/**
 * @brief Clase que maneja los flujos de entrada/salida con el compilador
 * Se encarga de abrir el fichero pasado como argumento y asignarlo al
 * puntero de entrada de bison para poder realizar posteriormente el analisis
 */
class LMP_IO_Manager{
    private:
        // -- Nombre de compilador
        std::string compiler;
        // -- Nombre de fichero lamport
        std::string lmp_file_name;

        // -- Version de compilador
        const std::string COMPILER_VERSION = "1.0.1-alpha";
        // -- Autor de compilador
        const std::string AUTHOR = "Daniel Perez Ruiz";

        // -- Numero de argumentos requeridos para ejecucion de compilador
        const unsigned int N_ARGUMENTS_REQUIRED = 2;

        // -- Comprueba estado de flujo I/O
        bool IO_STATE = false;

        // -- Notificador de tareas
        LMP_Tasker& tasker = LMP_Tasker::get_instance();

        /**
         * @brief Imprime la cabecera del compilador
         * @param compiler : nombre de compilador
         */
        void print_header(char *compiler);

        /**
         * @brief Imprime la ayuda de uso de compilador
         * @param compiler : nombre de compilador
         */
        void print_help(char *compiler);

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

        /**
         * @brief Constructor de la clase
         */
        LMP_IO_Manager() {};

    public:
        /**
         * @brief Obtiene la instancia del manejador
         * @return instance
         */
        static LMP_IO_Manager& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~LMP_IO_Manager();

        /**
         * @brief Cierra el flujo I/O
         */
        void close();
        
        /**
         * @brief Inicializa el manejador de IO
         * @param nargs : numero de argumentos
         * @param argv : argumentos
         * @return nombre de fichero abierto
         */
        std::string start(int nargs, char *argv[]);

        /**
         * @brief Constructor de copia (eliminado)
         */
        LMP_IO_Manager(const LMP_IO_Manager&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LMP_IO_Manager&) = delete;
};

#endif //_LMP_COMPILER_IO_DPR_