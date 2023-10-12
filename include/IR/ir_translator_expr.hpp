/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_expr.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para EXPRESIONES (IR)
 */

#ifndef _LAMPORT_IR_TRANSLATOR_EXPR_DPR_
#define _LAMPORT_IR_TRANSLATOR_EXPR_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include "instruction_table.hpp"    ///< Tabla de instrucciones
#include "ir_reg_manager.hpp"       ///< Manejador de registros
#include "table.hpp"                ///< Tabla de literales, variables y etiquetas
#include "ir_optimizer.hpp"         ///< Optimizador de instrucciones IR
#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

#include "ir_translator_assistant.hpp"  ///< Asistente de traduccion

// ===============================================================

// ----- CLASE TRADUCTORA DE EXPRESIONES -----

class IR_Translator_Expression{
    private:
        /// Tabla de instrucciones IR
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();
        /// Tabla de literales, variables y etiquetas
        IR_Tables& tables = IR_Tables::get_instance();
        /// Optimizador de instrucciones
        IR_Optimizer& optimizer = IR_Optimizer::get_instance();
        /// Asignador de registros
        IR_Reg_Manager& reg_manager = IR_Reg_Manager::get_instance();

        // -- Asistente de traduccion
        IR_Translator_Assistant& assistant_translator = IR_Translator_Assistant::get_instance();

        /**
         * @brief Constructor de la clase
         */
        IR_Translator_Expression() = default;

        /**
         * @brief Traduce una expresion a instrucciones IR
         * @param expr : expresion AST
         * @param from_subprogram : comprueba si se refiere a un subprograma
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_to_ir_instructions(struct expression * expr, bool from_subprogram = false);

        /**
         * @brief Traduce una expression a insrucciones IR (operacion binaria)
         * @param expr : expresion AST
         * @param from_subprogram : comprueba si se refiere a un subprograma
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_binary_operation_to_ir_instructions(struct expression * expr, bool from_subprogram = false);

        /**
         * @brief Traduce una expression a insrucciones IR (operacion unaria)
         * @param expr : expresion AST
         * @param from_subprogram : comprueba si se refiere a un subprograma
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_unary_operation_to_ir_instructions(struct expression * expr, bool from_subprogram = false);

        /**
         * @brief Traduce una expression a insrucciones IR (identificador)
         * @param expr : expresion AST
         * @param from_subprogram : comprueba si se refiere a un subprograma
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_identifier_to_ir_instructions(struct expression * expr, bool from_subprogram = false);

        /**
         * @brief Traduce una expression a insrucciones IR (literal)
         * @param expr : expresion AST
         * @param from_subprogram : comprueba si se refiere a un subprograma
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_literal_to_ir_instructions(struct expression * expr, bool from_subprogram = false);

        /**
         * @brief Traduce una expression a insrucciones IR (invocacion de funcion)
         * @param expr : expresion AST
         * @param from_subprogram : comprueba si se refiere a un subprograma
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_function_inv_to_ir_instructions(struct expression * expr, bool from_subprogram = false);

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static IR_Translator_Expression& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~IR_Translator_Expression() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Translator_Expression(const IR_Translator_Expression&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Translator_Expression&) = delete;

        /**
         * @brief Optimiza la expresion pasada como argumento
         * @param expr : expresion
         * @return expresion reducida
         */
        struct expression * optimize(struct expression * expr);

        /**
         * @brief Traduce una expresion a codigo IR
         * @param expr : expresion
         * @param from_subprogram : especifica si la expresion proviene de un subprograma
         * @return registro donde se encuentra el resultado final de la expresion
         */
        int translate(struct expression * expr, bool from_subprogam = false);
};

#endif //_LAMPORT_IR_TRANSLATOR_EXPR_DPR_