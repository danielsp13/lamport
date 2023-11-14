/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_prog.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para PROGRAMAS (IR)
 */

#ifndef _LAMPORT_IR_TRANSLATOR_PROG_DPR_
#define _LAMPORT_IR_TRANSLATOR_PROG_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include "AST/AST.h"                    ///< Abstract Syntax Tree (AST)

#include "IR/tables/table.hpp"              ///< Tablas de variables, etiquetas y literales
#include "IR/tables/instruction_table.hpp"  ///< Tabla de instrucciones

#include "IR/translators/ir_translator_decl.hpp"       ///< Traductor de declaraciones
#include "IR/translators/ir_translator_stmt.hpp"       ///< Traductor de sentencias
#include "IR/translators/ir_translator_proc.hpp"       ///< Traductor de procesos
#include "IR/translators/ir_translator_subprog.hpp"    ///< Traductor de subprogramas
#include "IR/translators/ir_translator_assistant.hpp"  ///< Asistente de traduccion

// ===============================================================

// ----- CLASE TRADUCTORA DE PROGRAMAS -----

class IR_Translator_Program{
    private:
        // -- Tablas de literales, variables y etiquetas
        IR_Tables& tables = IR_Tables::get_instance();
        // -- Instrucciones IR
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();

        // -- Traductor de declaraciones
        IR_Translator_Declaration& decl_translator = IR_Translator_Declaration::get_instance();
        // -- Traductor de sentencias
        IR_Translator_Statement& stmt_translator = IR_Translator_Statement::get_instance();
        // -- Traductor de procesos
        IR_Translator_Process& proc_translator = IR_Translator_Process::get_instance();
        // -- Traductor de subprogramas
        IR_Translator_Subprogram& subprog_translator = IR_Translator_Subprogram::get_instance();
        // -- Asistente de traduccion
        IR_Translator_Assistant& assistant_translator = IR_Translator_Assistant::get_instance();

        /**
         * @brief Constructor de la clase (por defecto)
         */
        IR_Translator_Program() = default;

        /**
         * @brief Traduce un programa a instrucciones IR
         * @param prog : programa AST
         */
        void translate_program_to_ir_instructions(struct program * prog);
    public:

        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static IR_Translator_Program& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~IR_Translator_Program() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Translator_Program(const IR_Translator_Program&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Translator_Program&) = delete;

        /**
         * @brief Traduce un programa
         */
        void translate();
};

#endif //_LAMPORT_IR_TRANSLATOR_PROG_DPR_