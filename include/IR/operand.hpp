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

/**
 * @brief Enumerado que representa los tipos de operando de instruccion
 */
enum class IR_operand_t{
    IR_OPERAND_REGISTER,        ///< El operando es un registro
    IR_OPERAND_LITERAL,         ///< El operando es un literal
    IR_OPERAND_LABEL,           ///< El operando es una etiqueta
    IR_OPERAND_VARIABLE,        ///< El operando es una variable
    IR_OPERAND_VARIABLE_ARRAY,  ///< El operando es una variable de tipo array
};

// ===============================================================

// ----- DEFINICION DE CLASE OPERANDO IR -----

/**
 * @brief Clase que representa un operando de instruccion en el lenguaje
 * de representacion intermedia
 */
class IR_operand{
    private:
        IR_operand_t kind;      ///< Tipo de operando
        int address;            ///< Direccion de operando
        int offset;             ///< Direccion de desplazamiento (siempre apunta a un registro) (para variables array) 

    public:
        /**
         * @brief Constructor por defecto de la clase
         */
        IR_operand()
            : kind(IR_operand_t::IR_OPERAND_REGISTER), address(0), offset(0) {};

        /**
         * @brief Constructor de operando
         * @param kind : tipo de operando
         * @param addr : direccion en mapa
         */
        IR_operand(IR_operand_t kind, int addr)
            : kind(kind), address(addr), offset(0) {};

        /**
         * @brief Constructor de operando (acceso a variables array)
         * @param kind : tipo de operando
         * @param addr : direccion en mapa
         * @param offset : desplazamiento en el vector
         */
        IR_operand(IR_operand_t kind, int addr, int offset)
            : kind(kind), address(addr), offset(offset) {};

        /**
         * @brief Obtiene el tipo de operando
         * @return Tipo de operando
         */
        IR_operand_t get_kind() {return kind;};

        /**
         * @brief Obtiene la direccion de operando
         * @return direccion
         */
        int get_address() {return address;};

        /**
         * @brief Obtiene el desplazamiento en el vector de un operando
         * @return offset
         */
        int get_offset() {return offset;};
};

#endif // _LAMPORT_IR_OPERAND_DPR_
