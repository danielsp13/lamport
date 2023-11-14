/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file CU_checker.hpp
 * @author Daniel Perez Ruiz
 * @brief Comprobador de instrucciones de Unidad de Control (CU) de CPU para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_CPU_CU_CHECKER_DPR_
#define _LAMPORT_LVM_CPU_CU_CHECKER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>

#include "IR/instruction_type.hpp"  ///< Instrucciones IR

// ===============================================================

// ----- DEFINICION DE CLASE CU CHECKER CPU -----

class LVM_CPU_CU_Checker{
    private:
        // -- Flag que indica si la instruccion ha sido decodificada
        bool instr_decoded = false;

        // -- Flag de etiqueta
        bool label_pointer = false;
        // -- Flag de inicio del programa
        bool start_program = false;
        // -- Flag que indica si el programa ha terminado
        bool end_program = false;
        // -- Flag que indica inicio de seccion de inicializacion de variables globales
        bool start_initialize_global_var = false;
        // -- Flag que indica fin de seccion de inicializacion de variables globales
        bool end_initialize_global_var = false;
        // -- Flag de comienzo de proceso
        bool start_process = false;
        // -- Flag de fin de proceso
        bool end_process = false;
        // -- Flag de operacion de carga
        bool load_operation = false;
        // -- Flag de operacion de almacenamiento
        bool store_operation = false;
        // -- Flag de operacion ALU (binaria)
        bool ALU_operation_binary = false;
        // -- Flag de operacion ALU (unaria)
        bool ALU_operation_unary = false;
        // -- Flag de operacion de salto incondicional
        bool jmp_operation_unconditional = false;
        // -- Flag de operacion de salto condicional
        bool jmp_operation_conditional = false;
        // -- Flag de operacion de push en pila
        bool push_operation = false;
        // -- Flag de operacion de pop en pila
        bool pop_operation = false;
        // -- Flag de operacion de call a subprograma
        bool call_operation = false;
        // -- Flag de operacion de retorno de subprograma
        bool ret_operation = false;
        // -- Flag de llamada al sistema
        bool system_call_operation = false;

        /**
         * @brief Constructor de la clase (por defecto)
         */
        LVM_CPU_CU_Checker() = default;

        /**
         * @brief Comprueba si la instruccion es un puntero a etiqueta y activa el flag correspondiente
         */
        inline void check_label_pointer(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la instruccion es el inicio de programa
         */
        inline void check_start_program(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la instruccion es indica el fin de programa
         */
        inline void check_end_program(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la instruccion indica el comienzo de inicializacion de variables globales
         */
        inline void check_initalize_var_global(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la instruccion indica el fin de inicializacion de variables globales
         */
        inline void check_end_initialize_var_global(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la instruccion es el comienzo de un proceso
         */
        inline void check_start_process(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la instruccion es el fin de un proceso
         */
        inline void check_end_process(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la instruccion es una operacion de carga
         */
        inline void check_load_operation(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la instruccion es una operacion de almacenamiento
         */
        inline void check_store_operation(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la operacion requiere de la ALU de la CPU (operacion binaria) y activa el flag correspondiente
         */
        inline void check_ALU_binary_operation(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la operacion requiere de la ALU de la CPU (operacion unaria) y activa el flag correspondiente
         */
        inline void check_ALU_unary_operation(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la operacion es de salto a instruccion y activa el flag correspondiente
         */
        inline void check_jump_operation(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la operacion es un push sobre pila de hebra
         */
        inline void check_push_operation(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la operacion es un pop sobre pila de hebra
         */
        inline void check_pop_operation(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la operacion es una llamada a subprograma
         */
        inline void check_call_operation(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la operacion es un retorno de subprograma
         */
        inline void check_ret_operation(IR_instruction_type_t instr_code);

        /**
         * @brief Comprueba si la operacion es una llamada al sistema y activa el flag correspondiente
         */
        inline void check_system_call(IR_instruction_type_t instr_code);

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static LVM_CPU_CU_Checker& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~LVM_CPU_CU_Checker() = default;

        /**
         * @brief Indica si la instruccion ha sido decodificada correctamente
         * @return estado de flag instr_decoded
         */
        inline bool is_instr_decoded() {return instr_decoded; };

        /**
         * @brief Indica si la instruccion es un puntero a etiqueta
         * @return estado de flag label_pointer
         */
        inline bool is_label_pointer() {return label_pointer; };

        /**
         * @brief Indica si la instruccion es el inicio de un programa
         * @return estado de flag start_program
         */
        inline bool is_start_program() {return start_program; };

        /**
         * @brief Indica si la instruccion es el fin de un programa
         * @return estado de flag end_program
         */
        inline bool is_end_program() {return end_program; };

        /**
         * @brief Indica si la instruccion denota el comienzo de operaciones de inicializacion de variables globales
         * @return estado de flag de start_initialize_global_var
         */
        inline bool is_initialize_global_var() {return start_initialize_global_var; };

        /**
         * @brief Indica si la instruccion denota el comienzo de operaciones de inicializacion de variables globales
         * @return estado de flag de end_initialize_global_var
         */
        inline bool is_end_initialize_global_var() {return end_initialize_global_var; };

        /**
         * @brief Indica si la instruccion denota el inicio de un proceso
         * @return estado de flag start_process
         */
        inline bool is_start_process() {return start_process; };

        /**
         * @brief Indica si la instruccion denota el fin de un proceso
         * @return estado de flag end_process
         */
        inline bool is_end_process() {return end_process; };

        /**
         * @brief Indica si la instruccion denota una operacion de carga
         * @return estado de flag load_operation
         */
        inline bool is_load_operation() {return load_operation; };

        /**
         * @brief Indica si la instruccion denota una operacion de almacenamiento
         * @return estado de flag store_operation
         */
        inline bool is_store_operation() {return store_operation; };

        /**
         * @brief Indica si la instruccion es una operacion ALU binaria
         * @return estado de flag ALU_operation_binary
         */
        inline bool is_alu_binary_operation() {return ALU_operation_binary; };

        /**
         * @brief Indica si la instruccion es una operacion ALU unaria
         * @return estado de flag ALU_operation_unary
         */
        inline bool is_alu_unary_operation() {return ALU_operation_unary; };

        /**
         * @brief Indica si la instruccion denota un salto incondicional
         * @return estado de flag jmp_operation_unconditional
         */
        inline bool is_jmp_operation_unconditional() {return jmp_operation_unconditional; };

        /**
         * @brief Indica si la instruccion denota un salto condicional
         * @return estado de flag jmp_operation_conditional
         */
        inline bool is_jmp_operation_conditional() {return jmp_operation_conditional; };

        /**
         * @brief Indica si la instruccion denota un push
         * @return estado de flag push_operation
         */
        inline bool is_push_operation() {return push_operation; };

        /**
         * @brief Indica si la instruccion denota un push
         * @return estado de flag pop_operation
         */
        inline bool is_pop_operation() {return pop_operation; };

        /**
         * @brief Indica si la instruccion denota una operacion de llamada a subprograma
         * @return estado de flag call_operation
         */
        inline bool is_call_operation() {return call_operation; };

        /**
         * @brief Indica si la instruccion denota una operacion de retorno de subprograma
         * @return estado de flag ret_operation
         */
        inline bool is_ret_operation() {return ret_operation; };

        /**
         * @brief Indica si la instruccion es una llamada al sistema
         * @return estado de flag system_call_operation
         */
        inline bool is_system_call_operation() {return system_call_operation;} ;

        /**
         * @brief Comprueba el tipo de codigo de instruccion
         * @param instr_code : codigo de instruccion
         */
        void check(IR_instruction_type_t instr_code);

        /**
         * @brief Resetea los flags de comprobacion de instruccion
         */
        void reset_flags();
};

#endif