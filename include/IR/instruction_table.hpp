/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file instruction_table.hpp
 * @author Daniel Perez Ruiz
 * @brief Contenedor de instrucciones de codigo intermedio Lineal (IR)
 */

#ifndef _LAMPORT_IR_INSTRUCTION_TABLE_DPR_
#define _LAMPORT_IR_INSTRUCTION_TABLE_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----
#include <vector>

#include "instruction.hpp"          ///< Instruccion IR
#include "ir_printer.hpp"           ///< Impresor de instrucciones IR

// ===============================================================

// ----- DEFINICION DE CLASE CONTENEDORA DE INSTRUCCIONES IR -----

/**
 * @brief Clase que representa la tabla de instrucciones en codigo intermedio.
 * Es un vector ordenado donde cada posicion es una instruccion que la maquina virtual
 * implementada se encargara de ejecutar
 */
class IR_Instruction_Table{
    private:
        // -- Vector de instrucciones
        std::vector<IR_instruction> instruction_table;
        // -- Impresor de instrucciones
        IR_Printer& printer = IR_Printer::get_instance();

        /**
         * @brief Constructor de la clase
         */
        IR_Instruction_Table() = default;

    public:
        /**
         * @brief Obtiene la instancia de la tabla de instrucciones
         * @return instance
         */
        static IR_Instruction_Table& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~IR_Instruction_Table() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Instruction_Table(const IR_Instruction_Table&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Instruction_Table&) = delete;

        /**
         * @brief Obtiene el numero de instrucciones
         * @return numero de instrucciones
         */
        inline const int size() const {return this->instruction_table.size(); };

        /**
         * @brief Incluye una nueva instruccion IR en la lista
         * @param instr : instruccion
         */
        void add_instruction_to_list(IR_instruction instr);

        /**
         * @brief Incluye una nueva instruccion IR en la lista en la posicion indicada
         * @param instr : instruccion
         * @param position : posicion de vector
         */
        void add_instruction_to_list_in_position(IR_instruction instr, int position);

        /**
         * @brief Emite e incluye una nueva instruccion IR (sin argumentos)
         * @param code_instr : codigo de instruccion
         */
        void emit_instruction(IR_instruction_type_t code_instr);

        /**
         * @brief Emite e incluye una nueva instruccion IR (1 operando)
         * @param code_instr : codigo de instruccion
         * @param op_1 : operando 1
         */
        void emit_instruction(IR_instruction_type_t code_instr, IR_operand op_1);

        /**
         * @brief Emite e incluye una nueva instruccion IR (1 destino y 1 operando)
         * @param code_instr : codigo de instruccion
         * @param op_dest : operando de destino
         * @param op_1 : operando 1
         */
        void emit_instruction(IR_instruction_type_t code_instr, IR_operand op_dest, IR_operand op_1);

        /**
         * @brief Emite e incluye una nueva instruccion IR (1 destino y 2 operando)
         * @param code_instr : codigo de instruccion
         * @param op_dest : operando de destino
         * @param op_1 : operando 1
         * @param op_2 : operando 2
         */
        void emit_instruction(IR_instruction_type_t code_instr, IR_operand op_dest, IR_operand op_1, IR_operand op_2);

        /**
         * @brief Sobrecarga del operador []
         * @param i : indice de acceso a instruccion
         * @return Referencia a instruccion
         */
        IR_instruction& operator[](int i);

        /**
         * @brief Sobrecarga del operador []
         * @param i : indice de acceso a instruccion
         * @return  Referencia a instruccion (constante)
         */
        const IR_instruction& operator[](int i) const;
};

#endif //_LAMPORT_IR_INSTRUCTION_TABLE_DPR_