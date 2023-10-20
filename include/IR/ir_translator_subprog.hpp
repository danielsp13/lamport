/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_proc.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para PROCESOS (IR)
 */

#ifndef _LAMPORT_IR_TRANSLATOR_SUBPROG_DPR_
#define _LAMPORT_IR_TRANSLATOR_SUBPROG_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stack>

#include "instruction_table.hpp"    ///< Tabla de instrucciones
#include "ir_reg_manager.hpp"       ///< Manejador de registros
#include "table.hpp"                ///< Tabla de literales, variables y etiquetas
#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

#include "ir_translator_decl.hpp"       ///< Traductor de declaraciones
#include "ir_translator_stmt.hpp"       ///< Traductor de sentencias
#include "ir_translator_expr.hpp"    ///< Traductor de expresiones
#include "ir_translator_assistant.hpp"  ///< Asistente de traduccion

// ===============================================================

// ----- CLASE TRADUCTORA DE PROCESOS -----

class IR_Translator_Subprogram{
    private:
        /// Tabla de instrucciones IR
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();
        /// Tabla de literales, variables y etiquetas
        IR_Tables& tables = IR_Tables::get_instance();
        /// Asignador de registros
        IR_Reg_Manager& reg_manager = IR_Reg_Manager::get_instance();
        
        // -- Asistente de traduccion
        IR_Translator_Assistant& assistant_translator = IR_Translator_Assistant::get_instance();
        // -- Traductor de declaraciones
        IR_Translator_Declaration& decl_translator = IR_Translator_Declaration::get_instance();
        // -- Traductor de sentencias
        IR_Translator_Statement& stmt_translator = IR_Translator_Statement::get_instance();
        // -- Traductor de expresiones
        IR_Translator_Expression& expr_translator = IR_Translator_Expression::get_instance();

        /**
         * @brief Constructor de la clase
         */
        IR_Translator_Subprogram() = default;

        /**
         * @brief Traduce un subprograma a instrucciones IR
         * @param subprog : subprograma AST
         */
        void translate_subprogram_to_ir_instructions(struct subprogram * subprog);

        /**
         * @brief Traduce una lista de subprogramas a instrucciones IR
         * @param list_subprog : lista de subprogramas AST
         */
        void translate_list_subprograms_to_ir_instructions(struct subprogram * list_subprog);

        /**
         * @brief Traduce una lista de parametros a instrucciones IR
         * @param list_param : lista de parametros AST
         */
        void translate_list_parameters_to_ir_instructions(struct parameter * list_param);  

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static IR_Translator_Subprogram& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~IR_Translator_Subprogram() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Translator_Subprogram(const IR_Translator_Subprogram&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Translator_Subprogram&) = delete;

        /**
         * @brief Traduce una lista de subprogramas
         * @param list_subprog : lista de subprogramas
         */
        void translate(struct subprogram * list_subprog);
};

#endif //_LAMPORT_IR_TRANSLATOR_SUBPROG_DPR_