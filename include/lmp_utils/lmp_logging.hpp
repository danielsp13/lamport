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
#include <fstream>
#include <string>

#include "lmp_c_analysis_bridge.hpp"    ///< Puente de C a C++ para analizador lamport
#include "IR/builder/ir_printer.hpp"            ///< Impresor de instrucciones IR
#include "LVM/LVM.hpp"                  ///< Maquina virtual de lamport
#include "lmp_tasker.hpp"               ///< Notificador de eventos

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
        std::ofstream LMP_LOGGING_IR_FILE;
        // -- Fichero de registro de LVM
        std::ofstream LMP_LOGGING_LVM_FILE;
        // -- Fichero de registro de traza de LVM
        std::ofstream LMP_LOGGING_LVM_TRACE_FILE;

        // -- Nombre de directorio donde se almacenaran los registros
        const std::string LMP_LOG_DIR = "log";
        // -- Nombre de directorio donde se almacenan los registros de errores
        const std::string LMP_ERRORS_DIR = "errors";
        // -- Nombre de directorio donde se almacenan los registros de AST
        const std::string LMP_AST_DIR = "AST";
        // -- Nombre de directorio donde se almacena los registros de representacion intermedia
        const std::string LMP_IR_DIR = "IR";
        // -- Nombre de directorio donde se almacena los registros de maquina virtual
        const std::string LMP_LVM_DIR = "LVM";

        // -- Extension de fichero de logging
        const std::string LMP_LOG_FILE_EXT = ".log";

        // -- Cabecera de nombre de fichero de logging de errores
        const std::string LMP_LOG_FILE_ERRORS_HEADER = "log_errors_";
        // -- Cabecera de nombre de fichero de logging de ast
        const std::string LMP_LOG_FILE_AST_HEADER = "log_ast_";
        // -- Cabecera de nombre de fichero de logging de ir
        const std::string LMP_LOG_FILE_IR_HEADER = "log_ir_";
        // -- Cabecera de nombre de fichero de logging de lvm
        const std::string LMP_LOG_FILE_LVM_HEADER = "log_lvm_initial_";
        // -- Cabecera de nombre de fichero de logging de traza de ejecucion
        const std::string LMP_LOG_FILE_LVM_TRACE_HEADER = "log_lvm_trace_";

        // -- Nombre de fichero 
        std::string LMP_FILE;
        // -- Nombre de fichero de log actual creado
        std::string actual_log_file;

        // -- Notificador de tareas
        LMP_Tasker& tasker = LMP_Tasker::get_instance();

        /**
         * @brief Procesa el fichero a analizar por el compilador, dejando solo su nombre y eliminando rutas
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
         * @brief Crea el directorio de logging de LVM
         * @return TRUE si lo creo con exito, FALSE en otro caso
         */
        bool create_logging_lvm_dir();

        /**
         * @brief Crea un fichero dentro del directorio especificado
         * @param dirname : nombre de directorio
         * @param log_header : cabecera de nombre de fichero
         * @return puntero a fichero abierto
         */
        FILE * create_logging_file_in_dir(std::string dirname, std::string log_header);

        /**
         * @brief Crea un fichero dentro del directorio especificado
         * @param dirname : nombre de directorio
         * @param log_header : cabecera de nombre de fichero
         * @return puntero a fichero abierto
         */
        std::ofstream create_logging_file_stream_in_dir(std::string dirname, std::string log_header);

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
         * @brief Prepara el logging de LVM, creando directorios y ficheros
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool init_log_lvm();

        /**
         * @brief Prepara el logging de traza de ejecucion de LVM, creando directorios y ficheros
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool init_log_lvm_trace();

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

        /**
         * @brief Realiza el logging de LVM
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool make_log_lvm();

        /**
         * @brief Realiza el logging de la traza de ejecucion de LVM
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool make_log_lvm_trace();

        /**
         * @brief Constructor de la clase
         */
        LMP_Logging() {};

    public:
        /**
         * @brief Obtiene la instancia del manejador
         * @return instance
         */
        static LMP_Logging& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~LMP_Logging();

        /**
         * @brief Realiza el log del analisis de codigo
         * @param lmp_file : fichero analizado por el compilador
         */
        void log_analysis(std::string lmp_file);

        /**
         * @brief Realiza el log de generacion de codigo intermedio
         */
        void log_ir();

        /**
         * @brief Realiza el log de maquina virtual
         */
        void log_lvm();

        /**
         * @brief Realiza el log de la traza de ejecucion de la maquina virtual
         */
        void log_lvm_trace();

        /**
         * @brief Constructor de copia (eliminado)
         */
        LMP_Logging(const LMP_Logging&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LMP_Logging&) = delete;
};


#endif //_LMP_COMPILER_LOGGING_DPR_