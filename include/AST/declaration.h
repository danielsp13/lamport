/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file declaration.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO declaraciones
 */

#ifndef _LAMPORT_AST_DECLARATION_DPR_
#define _LAMPORT_AST_DECLARATION_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE NODO -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "expression.h"         ///< Expresiones
#include "type.h"               ///< Tipos
#include "print_assistant.h"    ///< Asistencia de impresion de AST

#include "semantic/symbol.h"    ///< Simbolo (para resolucion de nombres)

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST (NODO DECLARACIONES) -----

/**
 * @brief Estructura que representa una declaración en Lamport.
 * 
 * Esta estructura almacena información sobre una declaración en el programa Lamport.
 * Puede contener el nombre de la declaración, su tipo, un valor (si es una expresión),
 * y un enlace a la siguiente declaración en el programa.
 */
struct declaration{
    char *name;                 ///< Nombre de la declaracion.
    struct type *type;          ///< Tipo de la declaracion.
    struct expression *value;   ///< Valor asociado (si es declaracion de variable)
    unsigned long line;         ///< Linea donde se realizo la declaracion de variable
    struct declaration *next;   ///< Puntero a la siguiente declaracion
    
    struct symbol *symb;        ///< Referencia al símbolo asociado en la tabla de símbolos.
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (DECLARACIONES) -----

/**
 * @brief Crea y reserva memoria para una declaracion, inicialiando su contenido
 * @param name : Nombre de la declaracion
 * @param type : Tipo de la declaracion
 * @param value : Valor de una expresion (declaraciones de variables)
 * @param line : linea donde se realizo la declaracion de la variable
 * @return puntero a la declaracion creada
 */
struct declaration * create_declaration_variable(char *name, struct type *type, struct expression *value, unsigned long line);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO DECLARACIONES) ------

/**
 * @brief Libera la memoria asignada para una lista de declaraciones
 * @param declarations_list : Puntero a lista enlazada de declaraciones
 */
void free_list_declarations(struct declaration *declarations_list);

/**
 * @brief Libera la memoria asignada para un nodo de tipo declaracion
 * @param decl : nodo declaracion
 */
void free_declaration(struct declaration *decl);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO DECLARACIONES) -----

/**
 * @brief Imprime una lista de nodos de declaraciones
 * @param declarations_list : Puntero a lista enlazada de declaraciones
 * @param depth : Profundidad en la impresion de la lista de nodos
 */
void print_AST_declarations(struct declaration *declarations_list, unsigned int depth);


#endif //_LAMPORT_AST_DECLARATION_DPR_