/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_c_io_bridge.hpp
 * @author Daniel Perez Ruiz
 * @brief Cabecera puente entre implementaciones C y C++
 */

#ifndef _LMP_INTERPRETER_C_IO_BRIDGE_DPR_
#define _LMP_INTERPRETER_C_IO_BRIDGE_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE C -----

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===============================================================

// ----- IMPORTACION DE FUNCIONES Y VARIABLES EXTERNAS (FLEX/BISON) -----

/**
 * @brief Variable global definida por Flex. Puntero al archivo de entrada del
 * que se leera el texto fuente para el analisis lexico.
 */
extern FILE *yyin;

#ifdef __cplusplus
}
#endif

#endif //_LMP_INTERPRETER_C_IO_BRIDGE_DPR_