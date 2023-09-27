/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_manager.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal (IR)
 */

#ifndef _LAMPORT_IR_BUILDER_DPR_
#define _LAMPORT_IR_BUILDER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <optional>

#include "table.hpp"                ///< Tabla IR
#include "instruction.hpp"          ///< Instruccion IR
#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

// ===============================================================

// ----- DEFINICION DE CONTADORES -----

// ===============================================================

// ----- DEFINICION DE CLASE CONSTRUCTORA DE CODIGO IR -----

class IR_Builder{
    private:
        // -- Manejador de tablas de literales, variables y etiquetas
        IR_Tables tables = IR_Tables::get_instance();
        // -- Vector de instrucciones
        std::vector<IR_instruction> ir_instructions;

        /**
         * @brief Constructor de la clase (privado por ser singleton)
         */
        IR_Builder() {};

        /**
         * @brief Convierte el codigo de una instruccion especificada a string
         * @param instr_code : codigo de instruccion
         * @return cadena con el codigo de instruccion
         */
        std::string ir_code_instruction_to_string(IR_instruction_type_t instr_code);

        /**
         * @brief Convierte el operando de una instruccion especificada a string
         * @param op : operando de instruccion
         * @return cadena con el operando de instruccion
         */
        std::string ir_operand_instruction_to_string(IR_operand op);

        /**
         * @brief Convierte la instruccion especificada a string
         * @param index : indice de instruccion
         * @return cadena con la instruccion
         */
        std::string ir_instruction_to_string(unsigned int index);

        /**
         * @brief Imprime las instrucciones IR 
         * @param output : destino de impresion
         */
        void print_ir_instructions(FILE * output);

        /**
         * @brief Incluye una nueva instruccion IR (sin argumentos)
         * @param code_instr : codigo de instruccion
         */
        void add_instruction(IR_instruction_type_t code_instr);

        /**
         * @brief Incluye una nueva instruccion IR (1 operando)
         * @param code_instr : codigo de instruccion
         * @param op_1 : operando 1
         */
        void add_instruction(IR_instruction_type_t code_instr, IR_operand op_1);

        /**
         * @brief Incluye una nueva instruccion IR (1 destino y 1 operando)
         * @param code_instr : codigo de instruccion
         * @param op_dest : operando de destino
         * @param op_1 : operando 1
         */
        void add_instruction(IR_instruction_type_t code_instr, IR_operand op_dest, IR_operand op_1);

        /**
         * @brief Incluye una nueva instruccion IR (1 destino y 2 operando)
         * @param code_instr : codigo de instruccion
         * @param op_dest : operando de destino
         * @param op_1 : operando 1
         * @param op_2 : operando 2
         */
        void add_instruction(IR_instruction_type_t code_instr, IR_operand op_dest, IR_operand op_1, IR_operand op_2);

    public:
        /**
         * @brief Obtiene la instancia del manejador
         * @return instance
         */
        static IR_Builder& get_instance();

        /**
         * @brief Inicializa el manejador de instrucciones IR
         */
        int start();

        
};

#endif //_LAMPORT_IR_BUILDER_DPR_