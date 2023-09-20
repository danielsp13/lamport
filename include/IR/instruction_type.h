/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file instruction_type.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de tipos de instrucciones de codigo
 * intermedio IR Lineal
 */

#ifndef _LAMPORT_IR_INSTRUCTION_TYPE_
#define _LAMPORT_IR_INSTRUCTION_TYPE_

/**
 * @brief Enumerado que representa los diferentes tipos de instrucciones
 * de lenguaje IR
 */
typedef enum{
    // -- Definicion de instrucciones de operacion binaria aritmeticas
    IR_BIN_OP_SUM,
    IR_BIN_OP_SUB,
    IR_BIN_OP_MULT,
    IR_BIN_OP_DIV,
    IR_BIN_OP_MOD,
    // -- Definicion de instrucciones de operacion binaria de comparacion
    IR_BIN_OP_EQ,
    IR_BIN_OP_NEQ,
    IR_BIN_OP_GT,
    IR_BIN_OP_GTE,
    IR_BIN_OP_LT,
    IR_BIN_OP_LTE,
    // -- Definicion de instrucciones de operacion binaria logicas
    IR_BIN_OP_OR,
    IR_BIN_OP_AND,

    // -- Definicion de instrucciones de operacion unaria aritmetica
    IR_UN_OP_NEGATIVE,
    // -- Definicion de instrucciones de operacion unaria logica
    IR_UN_OP_NOT,

    // -- Definicion de instrucciones de asignacion
    IR_ASSIGNMENT,

    // -- Definicion de instrucciones de control de flujo
    IR_LABEL,
    IR_GOTO,
    IR_IF_GOTO,
    IR_IF_FALSE_GOTO,

    // -- Definicion de instrucciones de control de flujo para bucles
    IR_BEGIN_LOOP,
    IR_END_LOOP,

    // -- Definicion de instrucciones de procedimientos / funciones
    IR_CALL,
    IR_RETURN,
    IR_PARAM,
    IR_GET_PARAM,
    IR_RET_VALUE,

    // -- Definicion de instrucciones de manejo de procesos
    IR_FORK,
    IR_JOIN,
    IR_ATOMIC_START,
    IR_ATOMIC_END,

    // -- Definicion de instrucciones para impresion
    IR_PRINT,

} IR_instruction_type_t;


#endif //_LAMPORT_IR_IR_INSTRUCTION_TYPE_