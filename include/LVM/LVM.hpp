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

#include "memory.hpp"               ///< Memoria de la maquina virtual
#include "page_table.hpp"           ///< Tabla de paginas
#include "initializer.hpp"          ///< Iniciador de maquina virtual
#include "register_table.hpp"       ///< Tabla de registros
#include "IR/instruction_table.hpp" ///< Tabla de instrucciones IR

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

class LVM{
    private:
        // -- Memoria de la maquina virtual
        LVM_Memory& memory = LVM_Memory::get_instance();
        // -- Tabla de paginas
        LVM_Page_Table& pages_table = LVM_Page_Table::get_instance();
        // -- Iniciador de maquina virtual
        LVM_Initializer& initializer = LVM_Initializer::get_instance();
        // -- Registros de maquina virtual
        LVM_Register_Table& register_table = LVM_Register_Table::get_instance();
        // -- Tabla de instrucciones a ejecutar
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();

        // -- Especifica el estado en el que se encuentra la maquina virtual
        LVM_states_t state = LVM_STATE_BORN;
        // -- Contador de programa
        int program_counter = 0;

        /**
         * @brief Constructor de la maquina virtual
         */
        LVM() = default;

        /**
         * @brief Obtiene el la direccion fisica a partir de una virtual proporcionada
         * por un operando de instruccion
         * @param op : operando de instruccion
         * @return direccion fisica
         */
        int get_phisical_address_from_operand(const IR_operand & op);

        /**
         * @brief Ejecuta la instruccion especificada por el indice
         */
        void execute_instruction(int index);

        /**
         * @brief Ejecuta la instruccion de almacenamiento en registro
         * @param instr : instruccion IR_OP_LOAD
         */
        void execute_instruction_load(const IR_instruction & instr);

        /**
         * @brief Ejecuta la instruccion de almacenamiento en memoria
         * @param instr : instruccion IR_OP_STORE
         */
        void execute_instruction_store(const IR_instruction & instr);

        /**
         * @brief Ejecuta la instruccion de impresion de contenido
         * @param instr : instruccion IR_OP_PRINT
         */
        void execute_instruction_print(const IR_instruction & instr);

    public:
        /**
         * @brief Obtiene la instancia de la maquina virtual
         * @return instancia
         */
        static LVM& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~LVM() = default;

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
        bool start();
};

#endif //_LAMPORT_LVM_LVM_DPR_