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

// ----- MANEJADORES DE INTERPRETE -----

// -- Manejador de flujos de entrada/salida
LMP_IO_Manager io_manager;
// -- Analizador de fichero lamport
LMP_Analyzer lmp_analyzer;
// -- Manejador de logging
LMP_Logging lmp_logger;

// ===============================================================

// ----- PROGRAMA PRINCIPAL -----

int main(int nargs, char *argv[]){
    int exec_result = 0;
    std::string lmp_file;

    // -- Inicializar flujo de e/s
    lmp_file = io_manager.start(nargs,argv);
    // -- Analizar fichero lamport
    exec_result = lmp_analyzer.start();
    // -- Obtener ficheros de logging
    lmp_logger.log(lmp_file);

    // -- Retornar codigo de exito
    return exec_result;
}