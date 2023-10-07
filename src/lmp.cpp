/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp.cpp
 * @author Daniel Perez Ruiz
 * @brief Programa principal del interprete de lamport
 */

// ===============================================================

// ----- INCLUSION DE COMPONENTES DE GESTION DE INTERPRETE -----

#include "lmp_utils/lmp_io.hpp"         ///< Gestion de entrada/salida de lmp
#include "lmp_utils/lmp_analysis.hpp"   ///< Parsing de fichero de lmp
#include "lmp_utils/lmp_ir.hpp"         ///< Gestion de codigo intermedio
#include "lmp_utils/lmp_logging.hpp"    ///< Gestion de logging de lmp

// ===============================================================

// ----- DEFINICION DE MODULOS DE INTERPRETE DISPONIBLES -----

#define LMP_IO_IS_AVAIABLE true
#define LMP_ANALYSIS_IS_AVAIABLE true
#define LMP_ANALYSIS_VERBOSE_RESULT_IS_AVAIABLE false
#define LMP_LOGGING_ANALYSIS_IS_AVAIABLE true
#define LMP_IR_IS_AVAIABLE true
#define LMP_IR_VERBOSE_RESULT_IS_AVAIABLE true
#define LMP_LOGGING_IR_IS_AVAIABLE true

// ===============================================================

// ----- MOTOR PRINCIPAL DE INTERPRETE -----

/**
 * @brief Funcion principal de ejecucion de interprete lamport
 * @param nargs : numero de argumentos de ejecucion
 * @param argv : argumentos de ejecucion
 * @return resultado de ejecucion
 */
int lmp(int nargs, char *argv[]);

// ===============================================================

// ----- FUNCIONES DE DEPURACION -----

/**
 * @brief Funcion provisional para realizacion de tests sobre
 * implementaciones
 */
void beta_test();

// ===============================================================

// ----- PROGRAMA PRINCIPAL -----

int main(int nargs, char *argv[]){
    // -- Ejecutar tests
    //beta_test();

    // -- Ejecutar motor de interprete
    return lmp(nargs, argv);
}

// ===============================================================

// ----- IMPLEMENTACION DE MOTOR PRINCIPAL DE INTERPRETE -----

int lmp(int nargs, char *argv[]){
    int exec_result = 0;
    std::string lmp_file;

    /////////////////////////////////////////////////////////////////////////

    // -- Comprobar disponibilidad de flujo de E/S
    if(!LMP_IO_IS_AVAIABLE)
        return exec_result;

    // ---- Inicializar flujo de e/s
    lmp_file = LMP_IO_Manager::get_instance().start(nargs,argv);

    /////////////////////////////////////////////////////////////////////////

    // -- Comprobar disponiblidad de analizador de codigo
    if(!LMP_ANALYSIS_IS_AVAIABLE)
        return exec_result;

    // ---- Analizar fichero lamport
    exec_result = LMP_Analyzer::get_instance().start(LMP_ANALYSIS_VERBOSE_RESULT_IS_AVAIABLE);

    // ---- Cerrar fichero lamport
    LMP_IO_Manager::get_instance().close(); // Invocacion explicita de destructor

    /////////////////////////////////////////////////////////////////////////
    
    // -- Comprobar disponibilidad de logging de analisis
    if(!LMP_LOGGING_ANALYSIS_IS_AVAIABLE)
        return exec_result;
    
    // ---- Obtener logging de analisis
    LMP_Logging::get_instance().log_analysis(lmp_file);

    // ---- Si hubo errores retornar inmediatamente
    if(exec_result == EXIT_FAILURE)
        return exec_result;

    /////////////////////////////////////////////////////////////////////////

    // -- Comprobar disponibilidad de generacion de instrucciones IR
    if(!LMP_IR_IS_AVAIABLE)
        return exec_result;

    // ---- Generar instrucciones IR
    exec_result = exec_result == EXIT_FAILURE ? EXIT_FAILURE : LMP_IR_Manager::get_instance().start(LMP_IR_VERBOSE_RESULT_IS_AVAIABLE);

    // ---- Liberar todos los recursos en este punto
    LMP_Analyzer::get_instance().~LMP_Analyzer();
    
    /////////////////////////////////////////////////////////////////////////

    // -- Comprobar disponibilidad de logging de ir
    if(!LMP_LOGGING_IR_IS_AVAIABLE)
        return exec_result;

    // ---- Obtener ficheros de logging
    LMP_Logging::get_instance().log_ir();

    // -- Retornar codigo de exito
    return exec_result;
}

// ===============================================================

// ----- IMPLEMENTCION DE FUNCIONES DE DEPURACION -----

void beta_test(){
    // --- Aqui va codigo de prueba de estructuras
    
    // -- Salir de forma exitosa
    exit(EXIT_SUCCESS);
}