/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp.cpp
 * @author Daniel Perez Ruiz
 * @brief Programa principal del interprete de lamport
 */

// ===============================================================

// ----- INCLUSION DE COMPONENTES DE GESTION DE COMPILADOR -----

#include "lmp_utils/lmp_io.hpp"         ///< Gestion de entrada/salida de lmp
#include "lmp_utils/lmp_analysis.hpp"   ///< Parsing de fichero de lmp
#include "lmp_utils/lmp_logging.hpp"    ///< Gestion de logging de lmp

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
    beta_test();

    // -- Ejecutar motor de interprete
    //return lmp(nargs, argv);
}

// ===============================================================

// ----- IMPLEMENTACION DE MOTOR PRINCIPAL DE INTERPRETE -----

int lmp(int nargs, char *argv[]){
    int exec_result = 0;
    std::string lmp_file;

    // -- Inicializar flujo de e/s
    lmp_file = LMP_IO_Manager::get_instance().start(nargs,argv);
    // -- Analizar fichero lamport
    exec_result = LMP_Analyzer::get_instance().start();
    // -- Obtener ficheros de logging
    LMP_Logging::get_instance().log(lmp_file);

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