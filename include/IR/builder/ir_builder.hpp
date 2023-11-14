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

#include "IR/builder/ir_printer.hpp"              ///< Impresion de instrucciones IR
#include "IR/tables/table.hpp"                    ///< Tablas de literales, variables y etiquetas
#include "IR/tables/instruction_table.hpp"        ///< Tabla de instrucciones
#include "IR/translators/ir_translator_prog.hpp"  ///< Traductor de programas

#include "IR/tweaks/ir_thread_id_manager.hpp"     ///< Manejador de hebras de id

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
        // -- Traductor de programa Lamport
        IR_Translator_Program& prog_translator = IR_Translator_Program::get_instance();

        // -- Instrucciones IR
        IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();
        // -- Tablas de variables, etiquetas y literales
        IR_Tables& tables = IR_Tables::get_instance();
        // -- Impresor de instrucciones IR
        IR_Printer& printer = IR_Printer::get_instance();

        // -- Asignador de hebras
        IR_Thread_Id_Manager& id_thread_manager = IR_Thread_Id_Manager::get_instance();


        /**
         * @brief Constructor de la clase (privado por ser singleton)
         */
        IR_Builder() = default;
        
        /**
         * @brief Convierte el vector de instrucciones en formato string
         */
        void instructions_to_str();

        /**
         * @brief Repasar la tabla de instrucciones para recalcular id y saltos directos entre procesos dinamicos 
         */
        void reparse_dynamic_process();

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