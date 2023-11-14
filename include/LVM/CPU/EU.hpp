/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file CU.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de Unidad de Ejecucion (EU) de CPU para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_CPU_EU_DPR_
#define _LAMPORT_LVM_CPU_EU_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include "registers.hpp"                    ///< Registros de CPU
#include "LVM/memory/memory_manager.hpp"    ///< Manejador de memoria de LVM
#include "LVM/SO/thread_manager.hpp"        ///< Manejador de hebras de LVM
#include "LVM/SO/syscall_manager.hpp"       ///< Manejador de llamadas al sistema

#include "LVM/tracker/tracker.hpp"          ///< Gestor de traza de ejecucion de LVM

// ===============================================================

// ----- DEFINICION DE CLASE EU CPU -----

class LVM_CPU_EU{
    private:
        // -- Registros de CPU
        LVM_CPU_Registers& registers = LVM_CPU_Registers::get_instance();
        // -- Manejador de memoria
        LVM_Memory_Manager& memory_manager = LVM_Memory_Manager::get_instance();
        // -- Manejador de hebras de LVM
        LVM_Thread_Manager& thread_manager = LVM_Thread_Manager::get_instance();
        // -- Manejador de llamadas de sistema de LVM
        LVM_Syscall_Manager& syscall_manager = LVM_Syscall_Manager::get_instance();

        // -- Gestor de traza de ejecucion de LVM
        LVM_Tracker& tracker = LVM_Tracker::get_instance();
        // -- Cabecera de mensajes de traza de ejecucion de LVM
        const std::string TRACKER_HEADER = "[CPU > Unidad de Ejecucion]: ";

        /**
         * @brief Constructor de clase (por defecto)
         */
        LVM_CPU_EU() = default;
    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static LVM_CPU_EU& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~LVM_CPU_EU() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_CPU_EU(const LVM_CPU_EU&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_CPU_EU&) = delete;

        /**
         * @brief Ejecuta una instruccion de inicio de programa
         */
        void execute_start_program();

        /**
         * @brief Ejecuta una instruccion de fin de programa
         */
        void execute_end_program();

        /**
         * @brief Ejecuta una instruccion de inicio de inicializacion de variables globales
         */
        void execute_initialize_global_var();

        /**
         * @brief Ejecuta una instruccion de fin de inicializacion de variables globales
         */
        void execute_end_initialize_global_var();

        /**
         * @brief Ejecuta una instruccion de inicio de proceso
         */
        void execute_start_process();

        /**
         * @brief Ejecuta una instruccion de fin de proceso
         */
        void execute_end_process();

        /**
         * @brief Ejecuta una instruccion de carga de valor de bloque de memoria en registro
         * @param reg_dest : indice de registro destino
         * @param segment_op_1 : segmento donde se encuentra el bloque de memoria
         * @param virt_dir_op_1 : direccion virtual del bloque de memoria
         * @param offset_op_1 : desplazamiento en la direccion virtual
         */
        void execute_load(int reg_dest, int segment_op_1, int virt_dir_op_1, int offset_op_1=0);

        /**
         * @brief Ejecuta una instruccion de carga de valor de registro en otro registro
         * @param reg_dest : indice de registro destino
         * @param reg_op_1 : indice de registro de precedencia
         */
        void execute_store(int reg_dest, int reg_op_1);

        /**
         * @brief Ejecuta una instruccion de carga de valor de registro en bloque de memoria
         * @param segment_dest : segmento donde se encuentra el bloque de memoria destino
         * @param virt_dir_dest : direccion virtual del bloque de memoria destino
         * @param offset_dir_dest : desplazamiento en la direccion virtual
         * @param reg_op_1 : indice de registro de precedencia
         */
        void execute_store(int segment_dest, int virt_dir_dest, int offset_dir_dest, int reg_op_1);

        /**
         * @brief Ejecuta una instruccion de salto incondicional
         * @param virt_dir_op_1 : direccion virtual donde se encuentra la direccion de salto
         */
        void execute_jmp_unconditional(long virt_dir_op_1);

        /**
         * @brief Ejecuta una instruccion de salto condicional
         * @param condition : condicion de salto
         * @param reg_op_1 : direccion de registro donde se encuentra la condicion a evaluar
         * @param virt_dir_op_2 : direccion virtual donde se encuentra la direccion de salto
         */
        void execute_jmp_conditional(bool condition, int reg_op_1, long virt_dir_op_2);

        /**
         * @brief Ejecuta una instruccion de push sobre la pila de la hebra
         * @param reg_op_1 : direccion de registro
         */
        void execute_push(int reg_op_1);

        /**
         * @brief Ejecuta una instruccion de pop sobre la pila de la hebra
         * @param reg_op_1 : direccion de registro
         */
        void execute_pop(int reg_op_1);

        /**
         * @brief Ejecuta una instruccion de llamada a subprograma
         * @param label_dir_op_1 : direccion de salto
         */ 
        void execute_call(int label_dir_op_1);

        /**
         * @brief Ejecuta una instruccion de retorno de subprograma
         */
        void execute_ret();

        /**
         * @brief Realiza una llamada al sistema para la operacion print
         * @param reg_op_1 : indice de registro
         */
        void execute_syscall_print(int reg_op_1);

        /**
         * @brief Realiza una llamada al sistema para la operacion de print de salto de linea
         */
        void execute_syscall_print_endl();

        /**
         * @brief Realiza una llamada al sistema para la operacion de entrada en seccion atomica
         */
        void execute_syscall_enter_atomic();

        /**
         * @brief Realiza una llamada al sistema para la operacion de salida de seccion atomica
         */
        void execute_syscall_exit_atomic();

        /**
         * @brief Realiza una llamada al sistema para bloquear la hebra actual en ejecucion
         */
        void execute_syscall_block_current_thread();

        /**
         * @brief Realiza una llamada al sistema para dormir la hebra actual
         * @param milliseconds : milisegundos
         */
        void execute_syscall_sleep_current_thread(int milliseconds);

        /**
         * @brief Realiza una llamada al sistema para terminar la ejecucion de la hebra actual
         */
        void execute_syscall_terminate_current_thread();

        /**
         * @brief Realiza una llamada al sistema sobre operacion wait de semaforo
         * @param sem_addr_op_1 : direccion de semaforo
         */
        void execute_syscall_sem_wait(int sem_addr_op_1);

        /**
         * @brief Realiza una llamada al sistema sobre operacion signal de semaforo
         * @param sem_addr_op_1 : direccion de semaforo
         */
        void execute_syscall_sem_signal(int sem_addr_op_1);

        /**
         * @brief Realiza una llamada al sistema para crear una hebra dinamica
         */
        void execute_syscall_create_thread();

        /**
         * @brief Realiza una llamada al sistema para crear una hebra dinamica
         * @param id : id de la hebra
         * @param pc : contador de programa
         * @param from_mem : indica si proviene de memoria
         * @param ret_dir : direccion de retorno
         */
        void execute_syscall_create_thread(int id, int pc, bool from_mem = false, int ret_dir = 0);
};

#endif //_LAMPORT_LVM_CPU_EU_DPR_
