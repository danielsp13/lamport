/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_proc.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para PROCESOS (IR)
 */

#ifndef _LAMPORT_IR_TRANSLATOR_PROC_DPR_
#define _LAMPORT_IR_TRANSLATOR_PROC_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include "instruction_table.hpp"    ///< Tabla de instrucciones
#include "ir_reg_manager.hpp"       ///< Manejador de registros
#include "table.hpp"                ///< Tabla de literales, variables y etiquetas
#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

#include "ir_translator_decl.hpp"   ///< Traductor de declaraciones
#include "ir_translator_stmt.hpp"   ///< Traductor de sentencias
#include "ir_translator_expr.hpp"   ///< Traductor de expresiones

// ===============================================================

// ----- CLASE TRADUCTORA DE PROCESOS -----

class IR_Translator_Process{
    private:
        /// Tabla de instrucciones IR
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();
        /// Tabla de literales, variables y etiquetas
        IR_Tables& tables = IR_Tables::get_instance();
        /// Asignador de registros
        IR_Reg_Manager& reg_manager = IR_Reg_Manager::get_instance();
        
        // -- Traductor de declaraciones
        IR_Translator_Declaration& decl_translator = IR_Translator_Declaration::get_instance();
        // -- Traductor de sentencias
        IR_Translator_Statement& stmt_translator = IR_Translator_Statement::get_instance();
        // -- Traductor de sentencias
        IR_Translator_Expression& expr_translator = IR_Translator_Expression::get_instance();

        /**
         * @brief Constructor de la clase
         */
        IR_Translator_Process() = default;

        /**
         * @brief Traduce un proceso a instrucciones IR
         * @param proc : proceso AST
         */
        void translate_process_to_ir_instructions(struct process * proc);

        /**
         * @brief Traduce un proceso vectorizado a instrucciones IR
         * @param proc : proceso AST (vectorizado)
         */
        void translate_process_vector_to_ir_instructions(struct process * proc);

        /**
         * @brief Traduce una lista de procesos a instrucciones IR
         * @param list_proc : lista de procesos AST
         */
        void translate_list_process_to_ir_instructions(struct process * list_proc);

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static IR_Translator_Process& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~IR_Translator_Process() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Translator_Process(const IR_Translator_Process&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Translator_Process&) = delete;

        /**
         * @brief Traduce una lista de procesos
         * @param list_proc : lista de procesos
         */
        void translate(struct process * list_proc);
};

#endif //_LAMPORT_IR_TRANSLATOR_PROC_DPR_