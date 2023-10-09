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
         * @brief Comprueba si una instruccion es una operacion de carga
         * @param instr : instruccion
         * @return TRUE si es una operacion de carga, FALSE en otro caso
         */
        inline bool instruction_is_load_or_store(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una etiqueta
         * @param instr : instruccion
         * @return TRUE si es una etiqueta, FALSE en otro caso
         */
        inline bool instruction_is_label_pointer(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una operacion binaria
         * @param instr : instruccion
         * @return TRUE si es una operacion binaria, FALSE en otro caso
         */
        inline bool instruction_is_binary_operation(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una operacion unaria
         * @param instr : instruccion
         * @return TRUE si es una operacion unaria, FALSE en otro caso
         */
        inline bool instruction_is_unary_operation(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es un salto
         * @param instr : instruccion
         * @return TRUE si es una operacion unaria, FALSE en otro caso
         */
        inline bool instruction_is_jump(const IR_instruction & instr);

        /**
         * @brief Comprueba si una instruccion es una operacion de impresion
         * @param instr : instruccion
         * @return TRUE si es una operacion de impresion, FALSE en otro caso
         */
        inline bool instruction_is_print(const IR_instruction & instr);

        /**
         * @brief Obtiene el conjunto de registros a los que refiere una instruccion
         * @param instr : instruccion
         * @return vector con los registros de la tabla de registros a los que hace referencia
         */
        std::vector<LVM_Register> get_registers_from_operands(const IR_instruction & instr);

        /**
         * @brief Ejecuta la instruccion especificada por el indice
         */
        void execute_instruction(int index);

        /**
         * @brief Ejecuta una instruccion de almacenamiento a memoria o a registro
         * @param instr : instruccion IR_OP_LOAD o IR_OP_STORE
         */
        void execute_instruction_load_or_store(IR_instruction & instr);

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
         * @brief Ejecuta la instruccion de operacion binaria
         * @param instr : instruccion
         * Tipos de instrucciones binarias
         * --- IR_OP_ADD (suma)
         * --- IR_OP_SUB (resta)
         * --- IR_OP_MULT (multiplicacion)
         * --- IR_OP_DIV (division)
         * --- IR_OP_MOD (resto)
         * 
         * --- IR_OP_CMP_LTE (menor o igual)
         * --- IR_OP_CMP_LT (menor)
         * --- IR_OP_CMP_GTE (mayor o igual)
         * --- IR_OP_CMP_GT (mayor)
         * --- IR_OP_CMP_EQ (igual)
         * --- IR_OP_CMP_NEQ (no igual)
         * 
         * --- IR_OP_AND (conjuncion logica)
         * --- IR_OP_OR (disyuncion logica)
         */
        void execute_instruction_binary_operation(const IR_instruction & instr);

        /**
         * @brief Ejecuta la instruccion de operacion unaria
         * @param instr : instruccion
         * Tipos de instrucciones unarias
         * --- IR_OP_NEG (negacion aritmetica)
         * --- IR_OP_NOT (negacion logica)
         */
        void execute_instruction_unary_operation(const IR_instruction & instr);

        /**
         * @brief Ejecuta instruccion de salto
         * @param instr : instruccion
         * Tipos de instrucciones de salto
         * --- IR_OP_JMP (salto incondicional)
         * --- IR_OP_JMP_FALSE (salto condicional si falso)
         * --- IR_OP_JMP_TRUE (salto condicional si verdadero)
         */
        void execute_instruction_jump(const IR_instruction & instr);
    
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
        bool start();
};

#endif //_LAMPORT_LVM_LVM_DPR_