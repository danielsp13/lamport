/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file context.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de contexto la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_CONTEXT_DPR_
#define _LAMPORT_LVM_CONTEXT_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <vector>
#include "register.hpp"

// ===============================================================

// ----- DEFINICION DE CLASE CONTEXTO -----

class LVM_Context{
    public:
        // --- Contador de programa
        int program_counter = 0;
        // --- Tabla de registros
        std::vector<LVM_Register> register_table;

        /**
         * @brief Constructor de la clase
         */
        LVM_Context() = default;

        /**
         * @brief Destructor de la clase
         */
        ~LVM_Context() = default;
};

#endif