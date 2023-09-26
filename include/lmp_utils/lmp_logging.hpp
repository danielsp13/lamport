/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_logging.h
 * @author Daniel Perez Ruiz
 * @brief Gestor de registro de eventos de lamport
 */

#ifndef _LMP_INTERPRETER_LOGGING_DPR_
#define _LMP_INTERPRETER_LOGGING_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string>

#include "lmp_c_analysis_bridge.hpp"    ///< Puente de C a C++ para analizador lamport

// ===============================================================

// ----- DEFINICION DE CLASE GESTORA DE LOGGING -----

/**
 * @brief Clase manejadora de loggings de interpretacion de codigo lamport
 * Genera ficheros de log para diversas situaciones producidas en la interpretacion
 */
class LMP_Logging{
    private:
        // -- Fichero de registro de errores
        FILE * LMP_LOGGING_ERRORS_FILE = nullptr;
        // -- Fichero de registro de AST
        FILE * LMP_LOGGING_AST_FILE = nullptr;
        // -- Fichero de registro de IR
        FILE * LMP_LOGGING_IR_FILE = nullptr;

        // -- Nombre de directorio donde se almacenaran los registros
        const std::string LMP_LOG_DIR = "log";
        // -- Nombre de directorio donde se almacenan los registros de errores
        const std::string LMP_ERRORS_DIR = "errors";
        // -- Nombre de directorio donde se almacenan los registros de AST
        const std::string LMP_AST_DIR = "AST";
        // -- Nombre de directorio donde se almacena los registros de representacion intermedia
        const std::string LMP_IR_DIR = "IR";

        // -- Extension de fichero de logging
        const std::string LMP_LOG_FILE_EXT = ".log";

        // -- Cabecera de nombre de fichero de logging de errores
        const std::string LMP_LOG_FILE_ERRORS_HEADER = "log_errors_";
        // -- Cabecera de nombre de fichero de logging de ast
        const std::string LMP_LOG_FILE_AST_HEADER = "log_ast_";
        // -- Cabecera de nombre de fichero de logging de ir
        const std::string LMP_LOG_FILE_IR_HEADER = "log_ir_";

        // -- Nombre de fichero 
        std::string LMP_FILE;

        /**
         * @brief Procesa el fichero a analizar por el interprete, dejando solo su nombre y eliminando rutas
         * @param lmp_file : ruta de fichero lamport
         */
        void parse_lmp_file(std::string lmp_file);

        /**
         * @brief Crea un directorio
         * @param dirname : nombre de directorio
         * @return TRUE si lo creo con exito, FALSE en otro caso
         */
        bool create_dir(std::string dirname);

        /**
         * @brief Comprueba si un directorio existe
         * @param dirname : nombre de directorio
         * @return TRUE si el directorio existe, FALSE en otro caso
         */
        bool check_dir(std::string dirname);

        /**
         * @brief Crea el directorio principal de logging
         * @return TRUE si lo creo con exito, FALSE en otro caso
         */
        bool create_logging_dir();

        /**
         * @brief Crea el directorio de logging de errores
         * @return TRUE si lo creo con exito, FALSE en otro caso
         */
        bool create_logging_errors_dir();

        /**
         * @brief Crea el directorio de logging de AST
         * @return TRUE si lo creo con exito, FALSE en otro caso
         */
        bool create_logging_ast_dir();

        /**
         * @brief Crea el directorio de logging de IR
         * @return TRUE si lo creo con exito, FALSE en otro caso
         */
        bool create_logging_ir_dir();

        /**
         * @brief Crea un fichero dentro del directorio especificado
         * @param dirname : nombre de directorio
         * @param log_header : cabecera de nombre de fichero
         * @return puntero a fichero abierto
         */
        FILE * create_logging_file_in_dir(std::string dirname, std::string log_header);

        /**
         * @brief Prepara el logging de errores, creando directorios y ficheros
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool init_log_errors();

        /**
         * @brief Prepara el logging de AST, creando directorios y ficheros
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool init_log_ast();
        
        /**
         * @brief Prepara el logging de IR, creando directorios y ficheros
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool init_log_ir();

        /**
         * @brief Realiza el logging de errores
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool make_log_errors();

        /**
         * @brief Realiza el logging de AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool make_log_ast();

        /**
         * @brief Realiza el logging de IR
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool make_log_ir();

    public:
        /**
         * @brief Constructor de la clase
         */
        LMP_Logging() {};

        /**
         * @brief Destructor de la clase
         */
        ~LMP_Logging();

        /**
         * @brief Realiza el log de eventos de interpretacion
         * @param lmp_file : fichero analizado por el interprete
         */
        void log(std::string lmp_file);
};


#endif //_LMP_INTERPRETER_LOGGING_DPR_