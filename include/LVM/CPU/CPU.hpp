/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file CPU.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de CPU para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_CPU_DPR_
#define _LAMPORT_LVM_CPU_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>

#include "registers.hpp"    ///< Registros de CPU
#include "ALU.hpp"          ///< Unidad Aritmetico Logica de CPU
#include "CU.hpp"           ///< Unidad de control de CPU    

#include "LVM/SO/thread.hpp"        ///< Hebra LVM
#include "LVM/tracker/tracker.hpp"  ///< Gestor de eventos de CPU

// ===============================================================

// ----- DEFINICION DE CLASE CPU -----

class LVM_CPU{
    private:
        // -- Registros de CPU
        LVM_CPU_Registers& registers = LVM_CPU_Registers::get_instance();
        // -- Unidad Aritmetico Logica de CPU
        LVM_CPU_ALU& ALU = LVM_CPU_ALU::get_instance();
        // -- Unidad de Control de CPU
        LVM_CPU_CU& CU = LVM_CPU_CU::get_instance();

        // -- Contador de ciclos de CPU
        int cycle_counter = 0;

        // -- Gestor de eventos de LVM
        LVM_Tracker& tracker = LVM_Tracker::get_instance();
        
        /**
         * @brief Constructor de clase (por defecto)
         */
        LVM_CPU() = default;
    public:
        /**
         * @brief Obtiene la instancia
         * @return instancia
         */
        static LVM_CPU& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~LVM_CPU() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_CPU(const LVM_CPU&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_CPU&) = delete;

        /**
         * @brief Obtiene el ciclo de CPU
         * @return contador de ciclos
         */
        int get_cycle() const { return cycle_counter; };

        /**
         * @brief Comprueba si el programa ha terminado de ejecutarse
         * @return TRUE si el programa ha terminado, FALSE en otro caso
         */
        bool program_terminated() const {return CU.check_program_ended(); };

        /**
         * @brief Ejecuta la siguiente instruccion a la que apunta el contador de programa
         * @param current_thread : hebra que ejecuta la CPU
         */
        void execute_next_instruction(LVM_Thread * current_thread);
};

#endif //_LAMPORT_LVM_CPU_DPR_
