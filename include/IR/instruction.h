/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file instruction.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio [IR] lineal
 */

#ifndef _LAMPORT_IR_INSTRUCTION_DPR_
#define _LAMPORT_IR_INSTRUCTION_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "instruction_type.h"           ///< Tipos de instrucciones IR
#include "operand.h"                    ///< Operando de instruccion IR

// ===============================================================

// ----- DEFINICION DE VARIABLES GLOBALES -----   

// Variable para definir ID de etiquetas de salto (contador)
extern unsigned long CURRENT_JMP_LABEL_ID;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURA INSTRUCCION -----

/**
 * 
 */
struct IR_instruction{
    IR_instruction_type_t kind;         ///< Tipo de instruccion IR
    char * kind_str;                    ///< Tipo de instruccion IR (str)

    struct IR_operand * op_left;               ///< Operando izquierdo de instruccion
    struct IR_operand * op_right;              ///< Operando derecho de instruccion
    struct IR_operand * op_result;             ///< Operando resultado/destino de instruccion

    char * jmp_label;                   ///< Etiqueta para saltos
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE ASISTENCIA DE GESTION DE INSTRUCCIONES IR LINEAL -----

/**
 * @brief Crea una etiqueta de salto para la instruccion
 */
char * generate_IR_instruction_jmp_label_ID();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE INSTRUCCIONES IR LINEAL -----

/**
 * @brief Crea y reserva memoria para una instruccion IR lineal
 * @param kind : tipo de instruccion
 * @return puntero a instruccion creado (pero no inicializado)
 */
struct IR_instruction * create_IR_instruction(IR_instruction_type_t kind);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE LIBERACION DE INSTRUCCIONES IR LINEAL -----

/**
 * @brief Libera la memoria reservada para una instruccion IR lineal
 * @param instr : instruccion IR lineal
 */
void free_IR_instruction(struct IR_instruction * instr);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE INSTRUCCIONES IR LINEAL -----

/**
 * @brief Imprime una instruccion IR lineal
 * @param instr : instruccion IR lineal
 */
void print_IR_instruction(struct IR_instruction * instr);

#endif //_LAMPORT_IR_INSTRUCTION_DPR_