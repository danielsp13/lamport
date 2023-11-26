/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file registers.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de tabla de registros para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_CPU_REGISTERS_DPR_
#define _LAMPORT_LVM_CPU_REGISTERS_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <iomanip>
#include <vector>

#include "register.hpp"                 ///< Registros de LVM
#include "LVM/memory/memory.hpp"        ///< Bloque
#include "LVM/tracker/tracker.hpp"      ///< Tracker de LVM

// ===============================================================

// ----- DEFINICION DE TABLA DE REGISTROS -----

/**
 * @brief Clase que representa una tabla de registros. Contiene un vector
 * con registros limitados, aunque se puede habilitar redimensionamiento dinamico
 */
class LVM_CPU_Registers{
    private:
        // -- Tabla de registros
        std::vector<LVM_Register> registers;
        // -- Registro de contador de programa
        int program_counter;

        /**
         * @brief Constructor de tabla de registros
         */
        LVM_CPU_Registers() : registers(N_REGISTERS), program_counter(0) {};

    public:
        // -- Numero de registros iniciales
        static const int N_REGISTERS = 1024;

        /**
         * @brief Obtiene la instancia de la tabla de registros
         * @return instance
         */
        static LVM_CPU_Registers& get_instance();

        /**
         * @brief Destructor de la clase
         */ 
        ~LVM_CPU_Registers() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_CPU_Registers(const LVM_CPU_Registers&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_CPU_Registers&) = delete;

        /**
         * @brief Actualiza el valor del pc
         * @param pc : nuevo valor de pc
         */
        inline void set_pc(int pc){ program_counter = pc; };

        /**
         * @brief Obtiene el valor del pc
         * @return valor de pc
         */
        inline int get_pc(){ return program_counter; };

        /**
         * @brief Sobrecarga del operador (). Almacena el contenido de un bloque de memoria en registro
         * @param i : indice de registro
         * @param mem_block : bloque de memoria
         */
        void operator()(int i, const LVM_Memory_Block& mem_block);

        /**
         * @brief Obtiene los registros de una hebra
         * @param reg : registros de hebra
         */
        void set_registers(std::vector<LVM_Register> reg) { registers = reg; };

        /**
         * @brief Devuelve el vector de registros
         * @return registros
         */
        const std::vector<LVM_Register> & get_registers() const {return this->registers; };

        /**
         * @brief Sobrecarga del operador (). Obtiene un registro
         * @param i : indice de registro
         */
        const LVM_Register& operator()(int i) const;

        /**
         * @brief Sobrecarga del operador corchete []. Inserta un registro
         * @param i : indice de registro
         */
        LVM_Register& operator[](int i);

        /**
         * @brief Sobrecarga del operador []. Obtiene un registro
         * @param i : indice de registro
         */
        const LVM_Register& operator[](int i) const;

        /**
         * @brief Restaura los registros de un punto determinado
         * @param regs : vector de registros
         */
        void restore_registers(std::vector<LVM_Register> regs);

        /**
         * @brief Imprime la tabla de registros
         * @param os : flujo de impresion
         */
        void print_registers(std::ostream & os = std::cout);
};

#endif //_LAMPORT_LVM_REGISTERS_DPR_