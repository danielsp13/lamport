/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_decl.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para DECLARACIONES (IR)
 */

#ifndef _LAMPORT_IR_TRANSLATOR_DECL_DPR_
#define _LAMPORT_IR_TRANSLATOR_DECL_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include "instruction_table.hpp"    ///< Tabla de instrucciones
#include "ir_reg_manager.hpp"       ///< Manejador de registros
#include "table.hpp"                ///< Tabla de literales, variables y etiquetas
#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

#include "ir_translator_expr.hpp"       ///< Traductor de expresiones
#include "ir_translator_assistant.hpp"  ///< Asistente de traduccion

// ===============================================================

// ----- CLASE TRADUCTORA DE DECLARACIONES -----

class IR_Translator_Declaration{
    private:
        /// Tabla de instrucciones IR
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();
        /// Tabla de literales, variables y etiquetas
        IR_Tables& tables = IR_Tables::get_instance();
        /// Asignador de registros
        IR_Reg_Manager& reg_manager = IR_Reg_Manager::get_instance();
        
        // -- Asistente de traduccion
        IR_Translator_Assistant& assistant_translator = IR_Translator_Assistant::get_instance();
        // -- Traductor de expresiones
        IR_Translator_Expression& expr_translator = IR_Translator_Expression::get_instance();

        /**
         * @brief Constructor de la clase
         */
        IR_Translator_Declaration() = default;

        /**
         * @brief Traduce una declaracion a una instruccion IR
         * @param decl : declaracion AST
         */
        void translate_declaration_to_ir_instruction(struct declaration * decl, bool from_subprogram = false);

        /**
         * @brief Traduce una lista de declaraciones a instrucciones IR
         * @param list_decl : lista de declaraciones AST
         * @param from_subprogram : especifica si las declaraciones provienen de un subprograma
         */
        void translate_list_declarations_to_ir_instructions(struct declaration * list_decl, bool from_subprogram = false);

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static IR_Translator_Declaration& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~IR_Translator_Declaration() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Translator_Declaration(const IR_Translator_Declaration&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Translator_Declaration&) = delete;

        /**
         * @brief Traduce una lista de declaraciones
         * @param list_decl : lista de declaraciones
         * @param from_subprogram : especifica si la lista de declaraciones proviene de un subprograma
         */
        void translate(struct declaration * list_decl, bool from_subprogam = false);
};

#endif //_LAMPORT_IR_TRANSLATOR_DECL_DPR_