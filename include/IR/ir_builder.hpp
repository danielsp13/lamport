/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_builder.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal (IR)
 */

#ifndef _LAMPORT_IR_BUILDER_DPR_
#define _LAMPORT_IR_BUILDER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <optional>

#include "table.hpp"                ///< Tabla IR
#include "instruction.hpp"          ///< Instruccion IR
#include "instruction_table.hpp"    ///< Tabla de instruccioness
#include "ir_optimizer.hpp"         ///< Optimizador de instrucciones IR
#include "ir_reg_manager.hpp"       ///< Asignador de registros virtuales
#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

// ===============================================================

// ----- DEFINICION DE CONTADORES -----

// ===============================================================

// ----- DEFINICION DE CLASE CONSTRUCTORA DE CODIGO IR -----

/**
 * @brief Clase encargada de traducir el AST generado en fases de
 * analisis en instrucciones de representacion intermedia
 */
class IR_Builder{
    private:
        // -- Manejador de tablas de literales, variables y etiquetas
        IR_Tables& tables = IR_Tables::get_instance();
        // -- Optimizador de AST / instrucciones IR
        IR_Optimizer& optimizer = IR_Optimizer::get_instance();
        // -- Asignador de Registros Virtuales
        IR_Reg_Manager& reg_manager = IR_Reg_Manager::get_instance();
        // -- Tabla de instrucciones
        IR_Instruction_Table& instruction_table = IR_Instruction_Table::get_instance();
        // -- Pila de llamadas a subprogramas
        std::stack<int> call_subprog_stack;
        // -- Generador de etiquetas anonimas
        int id_label_annonymous = 0;

        /**
         * @brief Constructor de la clase (privado por ser singleton)
         */
        IR_Builder() {};

        /**
         * @brief Inserta una id de etiqueta de subprograma
         * @param id_label : indice de etiqueta de subprograma
         */
        void push_call_subprog(int id_label) { call_subprog_stack.push(id_label); };

        /**
         * @brief Realiza pop del tope de pila de id de etiquetas de subprograma
         * @return tope de pila
         */
        int pop_call_subprog() {
            int top = call_subprog_stack.top();
            call_subprog_stack.pop();
            return top;
        };

        /**
         * @brief Crea un operando de tipo registro
         * @param id_reg : identificador de registro
         * @return operando
         */
        IR_operand emit_operand_register(int id_reg);

        /**
         * @brief Crea un operando de tipo registro
         * @param id_lit : identificador de literal
         * @return operando
         */
        IR_operand emit_operand_literal(int id_lit);

        /**
         * @brief Crea un operando de tipo variable
         * @param id_var : identificador de variable
         * @return operando
         */
        IR_operand emit_operand_variable(int id_var);

        /**
         * @brief Crea un operando de tipo variable array
         * @param id_var : identificador de variable
         * @param offset : desplazamiento en el vector
         * @return operando
         */
        IR_operand emit_operand_variable_array(int id_var, int offset);

        /**
         * @brief Crea un operando de tipo etiqueta
         * @param id_label : identificador de etiqueta
         * @return operando
         */
        IR_operand emit_operand_label(int id_label);

        /**
         * @brief Obtiene un nuevo identificador anonimo de etiqueta si es necesario
         * @return id de etiqueta anonima, en formato string
         */
        std::string get_next_label_id();

        /**
         * @brief Traduce una declaracion a una instruccion IR
         * @param decl : declaracion AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_declaration_to_ir_instruction(struct declaration * decl);

        /**
         * @brief Traduce una declaracion de un subprograma a una instruccion IR
         * @param decl : declaracion (de un subprograma) AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_declaration_subprogram_to_ir_instruction(struct declaration * decl);

        /**
         * @brief Traduce una lista de declaraciones a instrucciones IR
         * @param list_decl : lista de declaraciones AST
         * @param from_subprogram : especifica si las declaraciones provienen de un subprograma
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_list_declarations_to_ir_instructions(struct declaration * list_decl, bool from_subprogram = false);

        /**
         * @brief Traduce un subprograma a instrucciones IR
         * @param subprog : subprograma AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_subprogram_to_ir_instructions(struct subprogram * subprog);

        /**
         * @brief Traduce una lista de subprogramas a instrucciones IR
         * @param list_subprog : lista de subprogramas AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_list_subprograms_to_ir_instructions(struct subprogram * list_subprog);

        /**
         * @brief Traduce una lista de parametros a instrucciones IR
         * @param list_param : lista de parametros AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_list_parameters_to_ir_instructions(struct parameter * list_param);

        /**
         * @brief Traduce un proceso a instrucciones IR
         * @param proc : proceso AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_process_to_ir_instructions(struct process * proc);

        /**
         * @brief Traduce una lista de procesos a instrucciones IR
         * @param list_proc : lista de procesos AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_list_process_to_ir_instructions(struct process * list_proc);

        /**
         * @brief Traduce una sentencia a instrucciones IR
         * @param stmt : sentencia AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_statement_to_ir_instructions(struct statement * stmt);
        
        /**
         * @brief Traduce una sentencia de asignacion a instrucciones IR
         * @param stmt : sentencia AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_statement_assignment_to_ir_instructions(struct statement * stmt);

        /**
         * @brief Traduce una sentencia de if/else a instrucciones IR
         * @param stmt : sentencia AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_statement_ifelse_to_ir_instructions(struct statement * stmt);

        /**
         * @brief Traduce una sentencia de bucle for a instrucciones IR
         * @param stmt : sentencia AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_statement_for_to_ir_instructions(struct statement * stmt);

        /**
         * @brief Traduce una sentencia de bucle while a instrucciones IR
         * @param stmt : sentencia AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_statement_while_to_ir_instructions(struct statement * stmt);

        /**
         * @brief Traduce una sentencia de impresion a instrucciones IR
         * @param stmt : sentencia AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_statement_print_to_ir_instructions(struct statement * stmt);

        /**
         * @brief Traduce una sentencia de invocacion a procedimiento a instrucciones IR
         * @param stmt : sentencia AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_statement_procedure_inv_to_ir_instructions(struct statement * stmt);

        /**
         * @brief Traduce una lista de sentencias a instrucciones IR
         * @param list_stmt : lista de sentencias AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_list_statements_to_ir_instructions(struct statement * list_stmt);

        /**
         * @brief Traduce una expresion a instrucciones IR
         * @param expr : expresion AST
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_to_ir_instructions(struct expression * expr);

        /**
         * @brief Traduce una expression a insrucciones IR (operacion binaria)
         * @param expr : expresion AST
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_binary_operation_to_ir_instructions(struct expression * expr);

        /**
         * @brief Traduce una expression a insrucciones IR (operacion unaria)
         * @param expr : expresion AST
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_unary_operation_to_ir_instructions(struct expression * expr);

        /**
         * @brief Traduce una expression a insrucciones IR (identificador)
         * @param expr : expresion AST
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_identifier_to_ir_instructions(struct expression * expr);

        /**
         * @brief Traduce una expression a insrucciones IR (literal)
         * @param expr : expresion AST
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_literal_to_ir_instructions(struct expression * expr);

        /**
         * @brief Traduce una expression a insrucciones IR (invocacion de funcion)
         * @param expr : expresion AST
         * @return identificador de registro donde se almacenara el contenido de la expresion, -1 en otro caso
         */
        int translate_expression_function_inv_to_ir_instructions(struct expression * expr);

        /**
         * @brief Traduce un programa a instrucciones IR
         * @param prog : programa AST
         * @return TRUE si se realizo con exito, FALSE en otro caso
         */
        bool translate_program_to_ir_instructions(struct program * prog);

    public:
        /**
         * @brief Obtiene la instancia del generador de instrucciones IR
         * @return instance
         */
        static IR_Builder& get_instance();

        /**
         * @brief Genera las instrucciones IR del programa
         * @param verbose_avaiable : flag de impresion de contenido
         * @return exito / fracaso de operacion
         */
        int build(bool verbose_avaiable);

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Builder(const IR_Builder&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Builder&) = delete;
};

#endif //_LAMPORT_IR_BUILDER_DPR_