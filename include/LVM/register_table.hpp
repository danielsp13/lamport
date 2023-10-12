/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file register_table.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de tabla de registros para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_REGISTER_TABLE_DPR_
#define _LAMPORT_LVM_REGISTER_TABLE_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <iomanip>
#include <vector>

#include "register.hpp"                 ///< Registros de LVM
#include "memory_block.hpp"             ///< Bloque de memoria LVM

// ===============================================================

// ----- DEFINICION DE TABLA DE REGISTROS -----

/**
 * @brief Clase que representa una tabla de registros. Contiene un vector
 * con registros limitados, aunque se puede habilitar redimensionamiento dinamico
 */
class LVM_Register_Table{
    private:
        // -- Numero de registros iniciales
        const int N_REGISTERS = 4096;
        // -- Tabla de registros
        std::vector<LVM_Register> register_table;

        // -- Indica si el redimensionamiento de tabla esta disponible
        const bool RESIZE_AVAIABLE = true;

        /**
         * @brief Constructor de tabla de registros
         */
        LVM_Register_Table() : register_table(N_REGISTERS) {};

        /**
         * @brief Redimensiona la tabla de registros para albergar mas capacidad
         */
        void resize_register_table();

    public:
        /**
         * @brief Obtiene la instancia de la tabla de registros
         * @return instance
         */
        static LVM_Register_Table& get_instance();

        /**
         * @brief Destructor de la clase
         */ 
        ~LVM_Register_Table() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Register_Table(const LVM_Register_Table&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Register_Table&) = delete;

        /**
         * @brief Sobrecarga del operador (). Almacena el contenido de un bloque de memoria en registro
         * @param i : indice de registro
         * @param mem_block : bloque de memoria
         */
        void operator()(int i, const LVM_Memory_Block& mem_block);

        /**
         * @brief Devuelve el vector de registros
         * @return registros
         */
        const std::vector<LVM_Register> & get_registers() const {return this->register_table; };

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
         * @brief Imprime la tabla de registros
         * @param os : flujo de impresion
         */
        void print_register_table(std::ostream & os = std::cout);
};

#endif //_LAMPORT_LVM_REGISTER_TABLE_DPR_