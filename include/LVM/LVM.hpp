/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file LVM.hpp
 * @author Daniel Perez Ruiz
 * @brief Maquina Virtual de Lamport
 */

#ifndef _LAMPORT_LVM_LVM_DPR_
#define _LAMPORT_LVM_LVM_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#include "memory.hpp"                   ///< Memoria de la maquina virtual
#include "page_table.hpp"               ///< Tabla de paginas
#include "initializer.hpp"              ///< Iniciador de maquina virtual
#include "CPU.hpp"                      ///< CPU de la maquina virtual
#include "IR/instruction_table.hpp"     ///< Tabla de instrucciones

// ===============================================================

// ----- DEFINICION DE ESTADOS DE LVM -----

typedef enum{
    LVM_STATE_BORN,             ///< La instancia de LVM acaba de ser creada
    LVM_STATE_PREPARED,         ///< La instancia de LVM esta preparada para ejecucion
    LVM_STATE_RUNNING,          ///< La instancia de LVM esta ejecutandose
    LVM_STATE_DEAD,             ///< La instancia de LVM esta muerta
    LVM_STATE_SHUTDOWN          ///< La instancia de LVM ha sido apagada
} LVM_states_t;

// ===============================================================

// ----- DEFINICION DE CLASE LAMPORT VIRTUAL MACHINE -----

/**
 * 
 */
class LVM{
    private:
        // -- Iniciador de memoria maquina virtual
        LVM_Initializer& initializer = LVM_Initializer::get_instance();
        // -- CPU de la maquina virtual
        LVM_CPU& cpu = LVM_CPU::get_instance();

        // -- Especifica el estado en el que se encuentra la maquina virtual
        LVM_states_t state = LVM_STATE_BORN;

        /**
         * @brief Constructor de la maquina virtual
         */
        LVM() = default;

    public:
        /**
         * @brief Obtiene la instancia de la maquina virtual
         * @return instancia
         */
        static LVM& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~LVM();

        /**
         * @brief Imprime el contenido de la tabla de paginas
         * @param os : flujo de impresion
         */
        void print_pages_table(std::ostream& os = std::cout);

        /**
         * @brief Imprime el contenido de la memoria
         * @param os : flujo de impresion
         */
        void print_memory(std::ostream& os = std::cout);

        /**
         * @brief Prepara la maquina virtual para ser ejecutada
         * @param verbose_avaiable flag de impresion de contenido
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool preload_lvm(bool verbose_avaiable);

        /**
         * @brief Ejecuta la maquina virtual
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool run();
};

#endif //_LAMPORT_LVM_LVM_DPR_