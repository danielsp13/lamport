/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_tasker.hpp
 * @author Daniel Perez Ruiz
 * @brief Impresor de tareas de compilador lamport
 */

#ifndef _LMP_COMPILER_TASKER_DPR_
#define _LMP_COMPILER_TASKER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// ===============================================================

// ----- DEFINICION DE CLASE GESTORA DE TAREAS -----

/**
 * @brief Clase notificadora de eventos en el compilador
 * Se encarga de producir mensajes al usuario sobre lo que se esta
 * realizando en un momento determinado
 */
class LMP_Tasker{
    private:
        const std::string TASK_HEADER_MSG = std::string("[TASK] ");
        const std::string ANSI_COLOR_GREEN = "\033[32m";
        const std::string ANSI_COLOR_RED = "\033[31m";
        const std::string ANSI_COLOR_YELLOW = "\033[33m";
        const std::string ANSI_COLOR_BLUE = "\033[34m";
        const std::string ANSI_COLOR_RESET = "\033[0m";

        const std::string ANSI_COLOR_WALL_WHITE = "\033[47m";
        const std::string ANSI_COLOR_BOLD = "\033[1m";

        const bool COLORS_AVAIABLE = true;
        const bool TASKER_AVAIABLE = true;

        const int TASK_DELAY = 200;
        const int TASK_EXECUTION_DELAY = 400;
        bool DELAY_AVAIABLE;

        /**
         * @brief Constructor de la clase
         * @param delay : especifica si hay delay
         */
        LMP_Tasker(bool delay = false)
            : DELAY_AVAIABLE(delay) {};

        /**
         * @brief Produce un retardo en la ejecucion de una tarea
         */
        void task_delay();

        /**
         * @brief Produce un retardo en la ejecucion del simulador
         */
        void task_execution_delay();

        /**
         * @brief Imprime un mensaje en verde
         */
        inline void print_green() { std::cout << (COLORS_AVAIABLE ? ANSI_COLOR_GREEN : ""); };

        /**
         * @brief Imprime un mensaje en rojo
         */
        inline void print_red() { std::cout << (COLORS_AVAIABLE ? ANSI_COLOR_RED : ""); };

        /**
         * @brief Imprime un mensaje en amarillo
         */
        inline void print_yellow() { std::cout << (COLORS_AVAIABLE ? ANSI_COLOR_YELLOW : ""); };

        /**
         * @brief Imprime un mensaje en azul
         */
        inline void print_blue() { std::cout << (COLORS_AVAIABLE ? ANSI_COLOR_BLUE : ""); };

        /**
         * @brief Resetea el color
         */
        inline void print_reset() { std::cout << (COLORS_AVAIABLE ? ANSI_COLOR_RESET : ""); };

        /**
         * @brief Imprime fondo blanco
         */
        inline void print_wall_white() { std::cout << (COLORS_AVAIABLE ? ANSI_COLOR_WALL_WHITE : ""); };

        /**
         * @brief Imprime negrita
         */
        inline void print_bold() { std::cout << (COLORS_AVAIABLE ? ANSI_COLOR_BOLD : ""); };

    public:
        /**
         * @brief Destructor de la clase
         */
        ~LMP_Tasker() = default;

        /**
         * @brief Obtiene la instancia del manejador
         * @param delay : especifica si hay delay
         * @return instancia
         */
        static LMP_Tasker& get_instance(bool delay = false);

        /**
         * @brief Indica la tarea de apertura de archivo
         * @param filename : nombre de archivo
         */
        void task_open_file_msg(std::string filename);

        /**
         * @brief Indica la tarea de cierre de archivo
         * @param filename : nombre de archivo
         */
        void task_close_file_msg(std::string filename);

        /**
         * @brief Indica la tarea de analisis sintactico
         */
        void task_parser();

        /**
         * @brief Indica la tarea de analisis semantico (resolucion de nombres)
         */
        void task_semantic_name_resolution();

        /**
         * @brief Indica la tarea de analisis semantico (comprobacion de tipos)
         */
        void task_semantic_type_checking();

        /**
         * @brief Indica la tarea de generacion de codigo intermedio
         */
        void task_translate_to_ir();

        /**
         * @brief Indica la tarea de logging de AST
         * @param filename : archivo de registro
         */
        void task_logging_ast(std::string filename);

        /**
         * @brief Indica la tarea de logging de errores sintacticos
         * @param filename : archivo de registro
         */
        void task_logging_error_syntax(std::string filename);

        /**
         * @brief Indica la tarea de logging de errores semanticos
         * @param filename : archivo de registro
         */
        void task_logging_error_semantic(std::string filename);

        /**
         * @brief Indica la tarea de logging de IR
         * @param filename : archivo de registro
         */
        void task_logging_ir(std::string filename);

        /**
         * @brief Indica la tarea de logging de LVM
         * @param filename : archivo de registro
         */
        void task_logging_lvm(std::string filename);

        /**
         * @brief Indica la tarea de logging de traza de ejecucion de LVM
         * @param filename : archivo de registro
         */
        void task_logging_lvm_trace(std::string filename);

        /**
         * @brief Indica la tarea de liberacion de recursos
         */
        void task_free_resources();

        /**
         * @brief Indica la tarea de preparacion de maquina virtual
         */
        void task_preload_lvm();

        /**
         * @brief Indica la tarea de ejecucion de maquina virtual
         */
        void task_execute_lvm();

        /**
         * @brief Indica la tarea de apagado de maquina virtual
         */
        void task_shutdown_lvm();

        /**
         * @brief Indica que la tarea se completo con exito
         */
        void task_ok();

        /**
         * @brief Indica que la tarea se completo con fallos
         */
        void task_nop();
};

#endif //_LMP_COMPILER_TASKER_DPR_