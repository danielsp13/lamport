/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file initializer.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de cargador de arranque de la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_INITIALIZER_DPR_
#define _LAMPORT_LVM_INITIALIZER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <variant>

#include "memory.hpp"               ///< Memoria de LVM
#include "segment_table.hpp"        ///< Tabla de segmentos de LVM
#include "bounds.hpp"               ///< Registro de limites de arrays
#include "IR/table.hpp"             ///< Tablas IR
#include "instruction_table.hpp"    ///< Tabla de instrucciones IR


// ===============================================================

// ----- DEFINICION DE CLASE INITIALIZER -----

// -- Especifica tipo de contenido de bloque
using mem_block_content = std::variant<IR_literal,IR_variable,IR_label>;

/**
 * @brief Cargador de arranque del sistema. Esta clase es la encargada de consultar las tablas
 * de literales, de variables y de etiquetas, y volcar su contenido a la memoria
 * Ademas implementa la traduccion de direcciones virtuales a direcciones fisicas
 * 
 * Finalmente, es la encargada de crear las diferentes hebras de ejecucion del sistema
 */
class LVM_Initializer{
    private:
        // -- Tablas mapeadoras de literales, variables y etiquetas
        IR_Tables& tables = IR_Tables::get_instance();
        // -- Memoria de maquina virtual
        LVM_Memory& memory = LVM_Memory::get_instance();
        // -- Tabla de segmentos
        LVM_Segment_Table& segment_table = LVM_Segment_Table::get_instance();
        // -- Registro de limites de arrays
        LVM_Bounds& bounds_arrays = LVM_Bounds::get_instance();
        // -- Planificador
        

        /**
         * @brief Constructor de la clase
         */
        LVM_Initializer() {};

        /**
         * @brief Inicializa un bloque de memoria con el contenido esperado
         * @param content_type : entero discriminante de contenido
         * @param content : contenido de inicio de bloque
         * @return bloque de memoria inicializado
         */
        LVM_Memory_Block initialize_mem_block(int content_type, const mem_block_content& content);

        /**
         * @brief Vuelca a memoria los literales registrados en la tabla IR
         */
        void dump_literals();

        /**
         * @brief Vuelca a memoria las variables registradas en la tabla IR
         */
        void dump_variables();

        /**
         * @brief Vuelca a memoria las etiquetas registradas en la tabla IR
         */
        void dump_labels();

    public:
        /**
         * @brief Obtiene la instancia del 
         */
        static LVM_Initializer& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */ 
        ~LVM_Initializer() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Initializer(const LVM_Initializer&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Initializer&) = delete;

        /**
         * @brief Vuelca a memoria el contenido de las tablas IR
         */
        void dump_to_memory();

        void create_threads();
};

#endif //_LAMPORT_LVM_INITIALIZER_DPR_