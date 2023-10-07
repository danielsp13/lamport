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
#include "lmp_tasker.hpp"               ///< Notificador de tareas

// ===============================================================

// ----- DEFINICION DE CLASE ANALIZADOR DE CODIGO LAMPORT -----

/**
 * @brief Clase analizadora de codigo lamport. Se encarga de realizar
 * el analisis sintactico y semantico
 */
class LMP_Analyzer{
    private:
        // -- Notificador de eventos
        LMP_Tasker& tasker = LMP_Tasker::get_instance();
        // -- Variable de control de analizador
        bool ANALYZER_STATE = true;

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

        /**
         * @brief Constructor de la clase
         */
        LMP_Analyzer() {};
    public:
        /**
         * @brief Obtiene la instancia del manejador
         * @return instance
         */
        static LMP_Analyzer& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~LMP_Analyzer();

        /**
         * @brief Inicializa el procedimiento de analisis
         * @param verbose_avaiable : especifica si los resultados del analisis deben mostrarse por pantalla o no
         * @return codigo de resultado de exito/fracaso en analisis completo
         */
        int start(bool verbose_avaiable);

        /**
         * @brief Constructor de copia (eliminado)
         */
        LMP_Analyzer(const LMP_Analyzer&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LMP_Analyzer&) = delete;
};

#endif //_LMP_INTERPRETER_ANALYSIS_DPR_