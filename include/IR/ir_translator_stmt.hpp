/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_stmt.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para SENTENCIAS (IR)
 */

#ifndef _LAMPORT_IR_TRANSLATOR_STMT_DPR_
#define _LAMPORT_IR_TRANSLATOR_STMT_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include "instruction_table.hpp"    ///< Tabla de instrucciones
#include "ir_reg_manager.hpp"       ///< Manejador de registros
#include "table.hpp"                ///< Tabla de literales, variables y etiquetas
#include "ir_optimizer.hpp"         ///< Optimizador de instrucciones IR
#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

#include "ir_translator_expr.hpp"   ///< Traductor de expresiones
#include "ir_translator_assistant.hpp"  ///< Asistente de traduccion

// ===============================================================

// ----- CLASE TRADUCTORA DE EXPRESIONES -----

class IR_Translator_Statement{
    private:
        /// Tabla de instrucciones IR
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();
        /// Tabla de literales, variables y etiquetas
        IR_Tables& tables = IR_Tables::get_instance();
        /// Asignador de registros
        IR_Reg_Manager& reg_manager = IR_Reg_Manager::get_instance();

        /// Traductor de expresiones
        IR_Translator_Expression& expr_translator = IR_Translator_Expression::get_instance();
        /// Asistente de traduccion
        IR_Translator_Assistant& assistant_translator = IR_Translator_Assistant::get_instance();

        // -- Precedencia de las operaciones
        std::string precedence = "";

        /**
         * @brief Constructor de la clase
         */
        IR_Translator_Statement() = default;

        /**
         * @brief Traduce una sentencia a instrucciones IR
         * @param stmt : sentencia AST
         * @param from_subprogram : flag que indica si es una sentencia de subprograma
         */
        void translate_statement_to_ir_instructions(struct statement * stmt, bool from_subprogram  = false);
        
        /**
         * @brief Traduce una sentencia de asignacion a instrucciones IR
         * @param stmt : sentencia AST
         * @param from_subprogram : flag que indica si es una sentencia de subprograma
         */
        void translate_statement_assignment_to_ir_instructions(struct statement * stmt, bool from_subprogram = false);

        /**
         * @brief Traduce una sentencia de if/else a instrucciones IR
         * @param stmt : sentencia AST
         * @param from_subprogram : flag que indica si es una sentencia de subprograma
         */
        void translate_statement_ifelse_to_ir_instructions(struct statement * stmt, bool from_subprogram = false);

        /**
         * @brief Traduce una sentencia de bucle for a instrucciones IR
         * @param stmt : sentencia AST
         * @param from_subprogram : flag que indica si es una sentencia de subprograma
         */
        void translate_statement_for_to_ir_instructions(struct statement * stmt, bool from_subprogram = false);

        /**
         * @brief Traduce una sentencia de bucle while a instrucciones IR
         * @param stmt : sentencia AST
         */
        void translate_statement_while_to_ir_instructions(struct statement * stmt, bool from_subprogram = false);

        /**
         * @brief Traduce una sentencia de impresion a instrucciones IR
         * @param stmt : sentencia AST
         */
        void translate_statement_print_to_ir_instructions(struct statement * stmt, bool from_subprogram = false);

        /**
         * @brief Traduce una sentencia de invocacion a procedimiento a instrucciones IR
         * @param stmt : sentencia AST
         */
        void translate_statement_procedure_inv_to_ir_instructions(struct statement * stmt, bool from_subprogram = false);

        /**
         * @brief Traduce una sentencia de retorno de funcion a instrucciones IR
         * @param stmt : sentencia AST
         */
        void translate_statement_return_to_ir_instructions(struct statement * stmt, bool from_subprogram = false);

        /**
         * @brief Traduce una sentencia fork a instrucciones IR
         * @param stmt : sentencia AST
         */
        void translate_statement_fork_to_ir_instructions(struct statement * stmt, bool from_subprogram = false);
        
        /**
         * @brief Traduce una sentencia join a instrucciones IR
         * @param stmt : sentencia AST
         */
        void translate_statement_join_to_ir_instructions(struct statement * stmt, bool from_subprogram = false);

        /**
         * @brief Traduce una lista de sentencias a instrucciones IR
         * @param list_stmt : lista de sentencias AST
         * @param from_subprogram : comprueba si se refiere a un subprograma
         */
        void translate_list_statements_to_ir_instructions(struct statement * list_stmt, bool from_subprogram = false);

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static IR_Translator_Statement& get_instance();

        /**
         * @brief Especifica la precedencia de las operaciones de sentencia
         */
        void set_precedence(std::string prec){ precedence = prec; };

        /**
         * @brief Resetea precedencia de operaciones de sentencia
         */
        void reset_precedence() {precedence = ""; };

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~IR_Translator_Statement() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Translator_Statement(const IR_Translator_Statement&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Translator_Statement&) = delete;

        /**
         * @brief Traduce una lista de sentencias a codigo IR
         * @param list_stmt : sentencias
         * @param from_subprogram : especifica si las sentencias provienen de un subprograma
         */
        void translate(struct statement * list_stmt, bool from_subprogam = false);
};

#endif //_LAMPORT_IR_TRANSLATOR_STMT_DPR_