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

#include "IR/tweaks/ir_reg_manager.hpp"       ///< Manejador de registros
#include "IR/tables/instruction_table.hpp"    ///< Tabla de instrucciones
#include "IR/tables/table.hpp"                ///< Tabla de literales, variables y etiquetas
#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

#include "IR/translators/ir_translator_expr.hpp"       ///< Traductor de expresiones
#include "IR/translators/ir_translator_assistant.hpp"  ///< Asistente de traduccion

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

        /// -- Variable de control de precedencia de declaraciones
        std::string precedence;

        /**
         * @brief Constructor de la clase
         */
        IR_Translator_Declaration() = default;

        /**
         * @brief Obtiene el scope de la variable
         * @param var_name : nombre de variable
         * @param kind : tipo de simbolo de variable
         * @return scope de variable
         */
        IR_variable_t get_variable_scope(std::string var_name, const symbol_t & kind);

        /**
         * @brief Obtiene el tipo de dato de variable
         * @param var_name : nombre de variable
         * @param kind : tipo de dato de variable
         * @return tipo de dato de variable (en representacion intermedia)
         */
        IR_variable_type_t get_type_variable(std::string var_name, type_t & kind);

        /**
         * @brief Genera instrucciones de inicializacion de variables locales de subprogramas
         * @param var_name : nombre de variable local
         * @param var_type : tipo de dator de variable
         */
        int initialize_variable_local_subprogram(std::string var_name, IR_variable_type_t var_type);

        /**
         * @brief Traduce una declaracion a una instruccion IR
         * @param decl : declaracion AST
         * @param from_subprogram : especifica si las declaraciones provienen de un subprograma
         * @param subprogram_name : especifica el nombre del subprograma
         */
        void translate_declaration_to_ir_instruction(struct declaration * decl, bool from_subprogram = false);

        /**
         * @brief Traduce una lista de declaraciones a instrucciones IR
         * @param list_decl : lista de declaraciones AST
         * @param from_subprogram : especifica si las declaraciones provienen de un subprograma
         * @param subprogram_name : especifica el nombre del subprograma
         */
        void translate_list_declarations_to_ir_instructions(struct declaration * list_decl, bool from_subprogram = false);

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static IR_Translator_Declaration& get_instance();

        /**
         * @brief Especifica la precedencia de las operaciones de declaracion
         */
        void set_precedence(std::string prec){ precedence = prec; };

        /**
         * @brief Resetea precedencia de operaciones de declaracion
         */
        void reset_precedence() {precedence = ""; };

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
         * @param subprogram_name : nombre de subprograma
         */
        void translate(struct declaration * list_decl, bool from_subprogam = false);
};

#endif //_LAMPORT_IR_TRANSLATOR_DECL_DPR_