/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ALU.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de ALU de CPU para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_CPU_ALU_DPR_
#define _LAMPORT_LVM_CPU_ALU_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>

#include "registers.hpp"    ///< Registros de CPU
#include "IR/instruction_type.hpp"  ///< Tipos de instrucciones IR

#include "LVM/tracker/tracker.hpp"  ///< Gestor de traza de ejecucion de LVM

// ===============================================================

// ----- DEFINICION DE CLASE ALU CPU -----

class LVM_CPU_ALU{
    private:
        // -- Registros de CPU
        LVM_CPU_Registers& registers = LVM_CPU_Registers::get_instance();

        // -- Gestor de traza de ejecucion de LVM
        LVM_Tracker& tracker = LVM_Tracker::get_instance();
        // -- Cabecera de mensajes de traza de ejecucion de LVM
        const std::string TRACKER_HEADER = "[CPU > Unidad Aritm-Logica]: ";

        /**
         * @brief Constructor de la clase (por defecto)
         */
        LVM_CPU_ALU() = default;

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static LVM_CPU_ALU& get_instance();

        /**
         * @brief Destructor de la clase
         */ 
        ~LVM_CPU_ALU() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_CPU_ALU(const LVM_CPU_ALU&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_CPU_ALU&) = delete;

        /**
         * @brief Ejecuta una instruccion de tipo operacion binaria
         * @param instr_code : codigo de instruccion
         * @param reg_dest : indice de registro de destino
         * @param reg_op_1 : indice de registro de operando 1
         * @param reg_op_2 : indice de registro de operando 2
         * 
         * --- IR_OP_ADD (suma)
         * --- IR_OP_SUB (resta)
         * --- IR_OP_MULT (multiplicacion)
         * --- IR_OP_DIV (division)
         * --- IR_OP_MOD (resto)
         * 
         * --- IR_OP_CMP_LTE (menor o igual)
         * --- IR_OP_CMP_LT (menor)
         * --- IR_OP_CMP_GTE (mayor o igual)
         * --- IR_OP_CMP_GT (mayor)
         * --- IR_OP_CMP_EQ (igual)
         * --- IR_OP_CMP_NEQ (no igual)
         * 
         * --- IR_OP_AND (conjuncion logica)
         * --- IR_OP_OR (disyuncion logica)
         */
        void execute_binary_operation(IR_instruction_type_t instr_code, int reg_dest, int reg_op_1, int reg_op_2);

        /**
         * @brief Ejecuta una instruccion de tipo operacion unaria
         * @param instr_code : codigo de instruccion
         * @param reg_dest : indice de registro de destino
         * @param reg_op_1 : indice de registro de operando 1
         * 
         * --- IR_OP_NEG (negacion aritmetica)
         * --- IR_OP_NOT (negacion logica)
         */
        void execute_unary_operation(IR_instruction_type_t instr_code, int reg_dest, int reg_op_1);
};

#endif //_LAMPORT_LVM_CPU_ALU_DPR_