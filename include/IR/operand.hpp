/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file operand.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio  (Operandos de IR Lineal)
 */

#ifndef _LAMPORT_IR_OPERAND_DPR_
#define _LAMPORT_IR_OPERAND_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <memory>

// ===============================================================

// ----- DEFINICION DE TIPOS DE OPERANDO IR -----

enum class IR_operand_t{
    IR_OPERAND_REGISTER,        ///< El operando es un registro
    IR_OPERAND_LITERAL,         ///< El operando es un literal
    IR_OPERAND_LABEL,           ///< El operando es una etiqueta
    IR_OPERAND_VARIABLE         ///< El operando es una variable
};

// ===============================================================

// ----- DEFINICION DE CLASE OPERANDO IR -----

class IR_operand{
    private:
        IR_operand_t kind;      ///< Tipo de operando
        int address;            ///< Direccion de operando

    public:
        IR_operand(IR_operand_t kind, int addr)
            : kind(kind), address(addr) {};

        IR_operand_t get_kind() {return kind;};

        int get_address() {return address;};
};

#endif // _LAMPORT_IR_OPERAND_DPR_
