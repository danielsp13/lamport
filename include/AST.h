/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file AST.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles)
 */

#ifndef _LAMPORT_AST_DPR_
#define _LAMPORT_AST_DPR_

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST -----

/**
 * @brief Esta estructura representa a una declaracion de lamport.
 * Contiene el nombre, tipo, valor (si es una expresion), codigo
 * (si es una funcion) y un puntero a la siguiente declaracion
 * del programa
 */
struct declaration{
    char *name;
    struct type *type;
    struct expression *value;
    struct statement *code;
    struct declaration *next;
};

// ===============================================================

/**
 * @brief Crea y reserva memoria para una declaracion, inicialiando su contenido
 * @param name : Nombre de la declaracion
 * @param type : Tipo de la declaracion
 * @param value : Valor de una expresion (declaraciones de variables)
 * @param code : Cuerpo de una funcion (declaraciones de funciones)
 * @param next : Puntero a la siguiente declaracion
 */
struct declaration * create_declaration(char *name, struct type *type, struct statement *code, struct declaration *next);

#endif //_LAMPORT_AST_DPR_