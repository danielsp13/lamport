/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_analysis.h
 * @author Daniel Perez Ruiz
 * @brief Gestor de analisis de ficheros de lenguaje lamport
 */

#ifndef _LMP_INTERPRETER_ANALYSIS_DPR_
#define _LMP_INTERPRETER_ANALYSIS_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE C -----

#include <iostream>
#include <cstdlib>
#include "lmp_c_analysis_bridge.hpp"    ///< Puente de C a C++ para analizador lamport


// ===============================================================

// ----- DEFINICION DE CLASE ANALIZADOR DE CODIGO LAMPORT -----

/**
 * @brief Clase analizadora de codigo lamport. Se encarga de realizar
 * el analisis sintactico y semantico
 */
class LMP_Analyzer{
    private:
        /**
         * @brief Realiza el analisis sintactico
         * @return TRUE si se realizo sin errores, FALSE en otro caso
         */
        bool exec_parser();

        /**
         * @brief Realiza el analisis semantico
         * @return TRUE si se realizo sin errores, FALSE en otro caso
         */
        bool exec_semantic();
    public:
        /**
         * @brief Constructor de la clase
         */
        LMP_Analyzer() {};

        /**
         * @brief Destructor de la clase
         */
        ~LMP_Analyzer();

        /**
         * @brief Inicializa el procedimiento de analisis
         * @return codigo de resultado de exito/fracaso en analisis completo
         */
        int start();
};

#endif //_LMP_INTERPRETER_ANALYSIS_DPR_