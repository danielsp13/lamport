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

#include "table.hpp"                    ///< Tabla de literales,variables y etiquetas
#include "instruction_table.hpp"        ///< Tabla de instrucciones
#include "AST/AST.h"                    ///< Abstract Syntax Tree (AST)

#include "ir_translator_decl.hpp"       ///< Traductor de declaraciones
#include "ir_translator_stmt.hpp"       ///< Traductor de sentencias
#include "ir_translator_proc.hpp"       ///< Traductor de procesos
#include "ir_translator_subprog.hpp"    ///< Traductor de subprogramas

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

        /**
         * @brief Constructor de la clase (privado por ser singleton)
         */
        IR_Builder() = default;
      
        /**
         * @brief Traduce un programa a instrucciones IR
         * @param prog : programa AST
         */
        void translate_program_to_ir_instructions(struct program * prog);

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