/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file instruction_type.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de tipos de instrucciones de codigo
 * intermedio IR Lineal
 */

#ifndef _LAMPORT_IR_INSTRUCTION_TYPE_
#define _LAMPORT_IR_INSTRUCTION_TYPE_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <string>
#include <unordered_map>

// ===============================================================

// ----- DEFINICION DE TIPOS DE INSTRUCCIONES IR -----

/**
 * @brief Enumerado que representa los diferentes tipos de instrucciones
 * de lenguaje IR
 */
typedef enum{
    // -- Definicion de instrucciones de carga y descarga
    IR_OP_LOAD,                 ///< Instruccion de carga
    IR_OP_STORE,                ///< Instruccion de almacenamiento

    // -- Definicion de instrucciones de operaciones aritmeticas (binarias)
    IR_OP_ADD,                  ///< Instruccion de suma de operandos
    IR_OP_SUB,                  ///< Instruccion de resta de operandos
    IR_OP_MULT,                 ///< Instruccion de multiplicacion de operandos
    IR_OP_DIV,                  ///< Instruccion de division de operandos
    IR_OP_MOD,                  ///< Instruccion de modulo

    // -- Definicion de instrucciones de operaciones aritmeticas (unarias)
    IR_OP_NEG,                  ///< Instruccion de negacion

    // -- Definicion de instrucciones de operaciones logicas (binarias)
    IR_OP_AND,                  ///< Instruccion de conjuncion logica
    IR_OP_OR,                   ///< Instruccion de disyuncion logica
    
    // -- Definicion de instrucciones de operaciones logicas (unarias)
    IR_OP_NOT,                  ///< Instruccion de negacion logica

    // -- Definicion de instrucciones de operaciones de comparacion
    IR_OP_CMP_LT,               ///< Instruccion de comparacion (<)
    IR_OP_CMP_LTE,              ///< Instruccion de comparacion (<=)
    IR_OP_CMP_GT,               ///< Instruccion de comparacion (>)
    IR_OP_CMP_GTE,              ///< Instruccion de comparacion (>=)
    IR_OP_CMP_EQ,               ///< Instruccion de comparacion (==)
    IR_OP_CMP_NEQ,              ///< Instruccion de comparacion (!=)

    // -- Definicion de instrucciones de gestion de hebras
    IR_OP_FORK,                 ///< Instruccion de creacion de hebra
    IR_OP_JOIN,                 ///< Instruccion de ...

    // -- Definicion de instrucciones de salto
    IR_OP_JMP,                  ///< Instruccion de salto incondicional
    IR_OP_JMP_TRUE,             ///< Instruccion de salto si verdadero
    IR_OP_JMP_FALSE,            ///< Instruccion de salto si falso

    // -- Definicion de instrucciones de entrada/salida
    IR_OP_PRINT,                ///< Instruccion de impresion
    IR_END_PRINT,               ///< Indica fin de flujo de salida

    // -- Definicion de instrucciones para procedimientos/funciones (subprogramas)
    IR_OP_CALL,                 ///< Instruccion de llamada a subprograma
    IR_OP_RET,                  ///< Instruccion de retorno de subprograma

    // -- Definicion de instrucciones de gestion de pila de ejecucion
    IR_OP_PUSH,                 ///< Instruccion de empuje en pila
    IR_OP_PUSH_LOCAL,           ///< Instruccion de empuje en pila de variables locales
    IR_OP_POP,                  ///< Instruccion de expulsion en pila
    IR_OP_POP_LOCAL,            ///< Instruccion de expulsion en pila para variables locales
    
    // -- Definicion de instrucciones de gestion de bloques concurrentes
    IR_OP_COBEGIN,              ///< Instruccion de inicio de bloque concurrente
    IR_OP_COEND,                ///< Instruccion de fin de bloque concurrente

    // -- Definicion de instrucciones de gestion de bloques atomicos
    IR_OP_ATOMIC_BEGIN,         ///< Instruccion de inicio de bloque atomico
    IR_OP_ATOMIC_END,           ///< Instruccion de fin de bloque atomico

    // -- Definicion de instrucciones de tipo etiqueta
    IR_LABEL,

    // -- Definicion de instrucciones de inicio y fin de proceso
    IR_START_PROCESS,           ///< Instruccion de comienzo de proceso
    IR_END_PROCESS,             ///< Instruccion de fin de proceso

    // -- Definicion de instruccion de fin de programa
    IR_START_PROGRAM,           ///< Instruccion de inicio de programa
    IR_END_PROGRAM,             ///< Instruccion de fin de programa          

    // ----------------------------------------------------

    NOT_IR_START_SUBPROGRAM_INSTR,
    NOT_IR_END_SUBPROGRAM_INSTR,

} IR_instruction_type_t;

// ===============================================================

// ----- MAPA CONVERSOR DE ENUMERADO A STRING -----

const std::unordered_map<IR_instruction_type_t, std::string> instructions_str = {
    {IR_OP_LOAD, "IR_OP_LOAD"},
    {IR_OP_STORE, "IR_OP_STORE"},
    {IR_OP_ADD, "IR_OP_ADD"},
    {IR_OP_SUB, "IR_OP_SUB"},
    {IR_OP_MULT, "IR_OP_MULT"},
    {IR_OP_DIV, "IR_OP_DIV"},
    {IR_OP_MOD, "IR_OP_MOD"},
    {IR_OP_NEG, "IR_OP_NEG"},
    {IR_OP_AND, "IR_OP_AND"},
    {IR_OP_OR, "IR_OP_OR"},
    {IR_OP_NOT, "IR_OP_NOT"},
    {IR_OP_CMP_LT, "IR_OP_CMP_LT"},
    {IR_OP_CMP_LTE, "IR_OP_CMP_LTE"},
    {IR_OP_CMP_GT, "IR_OP_CMP_GT"},
    {IR_OP_CMP_GTE, "IR_OP_CMP_GTE"},
    {IR_OP_CMP_EQ, "IR_OP_CMP_EQ"},
    {IR_OP_CMP_NEQ, "IR_OP_CMP_NEQ"},
    {IR_OP_JMP, "IR_OP_JMP"},
    {IR_OP_JMP_TRUE, "IR_OP_JMP_TRUE"},
    {IR_OP_JMP_FALSE, "IR_OP_JMP_FALSE"},
    {IR_OP_PRINT, "IR_OP_PRINT"},
    {IR_END_PRINT,"IR_END_PRINT"},
    {IR_OP_CALL, "IR_OP_CALL"},
    {IR_OP_RET, "IR_OP_RET"},
    {IR_LABEL, ""},
    {IR_OP_PUSH,"IR_OP_PUSH"},
    {IR_OP_PUSH_LOCAL,"IR_OP_PUSH_LOCAL"},
    {IR_OP_POP,"IR_OP_POP"},
    {IR_OP_POP_LOCAL,"IR_OP_POP_LOCAL"},
    {IR_START_PROCESS,"IR_START_PROCESS"},
    {IR_END_PROCESS,"IR_END_PROCESS"},
    {IR_START_PROGRAM,"IR_START_PROGRAM"},
    {IR_END_PROGRAM,"IR_END_PROGRAM"},
    {NOT_IR_START_SUBPROGRAM_INSTR, " -------- START SUBPROGRAMS SECTION --------"},
    {NOT_IR_END_SUBPROGRAM_INSTR, " -------- END SUBPROGRAMS SECTION --------"},
    {IR_OP_ATOMIC_BEGIN," -->-- ATOMIC_BEGIN --<--"},
    {IR_OP_ATOMIC_END," -->-- ATOMIC_END --<--"},
    {IR_OP_FORK,"IR_OP_FORK"},
    {IR_OP_JOIN,"IR_OP_JOIN"},
};

#endif //_LAMPORT_IR_IR_INSTRUCTION_TYPE_