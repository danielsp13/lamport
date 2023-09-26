/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_logging.h
 * @author Daniel Perez Ruiz
 * @brief Gestor de registro de eventos de lamport
 */

#ifndef _LMP_COMPILER_LOGGING_DPR_
#define _LMP_COMPILER_LOGGING_DPR_

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

        void parse_lmp_file(std::string lmp_file);

        bool create_dir(std::string dirname);

        bool check_dir(std::string dirname);

        bool create_logging_dir();

        bool create_logging_errors_dir();

        bool create_logging_ast_dir();

        bool create_logging_ir_dir();

        FILE * create_logging_file_in_dir(std::string dirname, std::string log_header);

        bool init_log_errors();

        bool init_log_ast();
        
        bool init_log_ir();

        bool make_log_errors();

        bool make_log_ast();

        bool make_log_ir();

    public:
        LMP_Logging() {};

        ~LMP_Logging();

        void log(std::string lmp_file);
};


#endif //_LMP_COMPILER_LOGGING_DPR_