/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file instruction.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio  (Instrucciones de IR Lineal)
 */

#ifndef _LAMPORT_IR_INSTRUCTION_DPR_
#define _LAMPORT_IR_INSTRUCTION_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <memory>
#include <optional>

#include "operand.hpp"              ///< Operando de instruccion IR
#include "instruction_type.hpp"     ///< Tipos de instrucciones IR

// ===============================================================

// ----- DEFINICION DE CLASE INSTRUCCION IR -----

class IR_instruction{
    private:
        IR_instruction_type_t instr_code;           ///< Codigo de instruccion
        std::optional<IR_operand> op_destiny;       ///< Operando de destino (registro)
        std::optional<IR_operand> op_1;             ///< Operando numero 1
        std::optional<IR_operand> op_2;             ///< Operando numero 2
    
    public:
        /**
         * @brief Constructor de instruccion (sin operandos)
         * @param code : codigo de instruccion
         */
        IR_instruction(IR_instruction_type_t code) 
            : instr_code(code) {};

        /**
         * @brief Constructor de instruccion (1 operando)
         * @param code : codigo de instruccion
         * @param op_1 : operando 1
         */
        IR_instruction(IR_instruction_type_t code, IR_operand op_1)
            : instr_code(code), op_1(op_1) {};

        /**
         * @brief Constructor de instruccion (2 operandos)
         * @param code : codigo de instruccion
         * @param dest : discriminant
         * @param op_1 : operando 1
         * @param op_2 : operando 2
         */
        IR_instruction(IR_instruction_type_t code, bool dest, IR_operand op_1, IR_operand op_2)
            : instr_code(code), op_1(op_1), op_2(op_2) {};

        /**
         * @brief Constructor de instruccion (un operando y un destino)
         * @param code : codigo de instruccion
         * @param destiny : operando de destino (registro)
         * @param op_1 : operando 1
         */
        IR_instruction(IR_instruction_type_t code, IR_operand destiny, IR_operand op_1)
            : instr_code(code), op_destiny(destiny), op_1(op_1) {};

        /**
         * @brief Constructor de instruccion (dos operandos y un destino)
         * @param code : codigo de instruccion
         * @param destiny : operando de destino (registro)
         * @param op_1 : operando 1
         * @param op_2 : operando 2
         */
        IR_instruction(IR_instruction_type_t code, IR_operand destiny, IR_operand op_1, IR_operand op_2)
            : instr_code(code), op_destiny(destiny), op_1(op_1), op_2(op_2) {};

        /**
         * @brief Devuelve el codigo de instruccion
         * @return codigo de instruccion
         */ 
        IR_instruction_type_t get_code_instr() const { return instr_code; };

        /**
         * @brief Devuelve el operando de destino
         * @return operando de destino
         */
        std::optional<IR_operand> get_operand_destiny() const { return op_destiny; } ;

        /**
         * @brief Devuelve el operando 1
         * @return operando 1
         */
        std::optional<IR_operand> get_operand_1() const { return op_1; } ;

        /**
         * @brief Devuelve el operando 2
         * @return operando 2
         */
        std::optional<IR_operand> get_operand_2() const { return op_2; } ;
};

#endif // _LAMPORT_IR_INSTRUCTION_DPR_