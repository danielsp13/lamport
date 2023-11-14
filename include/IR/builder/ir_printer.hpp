/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_printer.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del impresor de codigo intermedio Lineal (IR)
 */

#ifndef _LAMPORT_IR_PRINTER_DPR_
#define _LAMPORT_IR_PRINTER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <cstring>
#include <string>
#include <vector>
#include <sstream>

#include "IR/tables/table.hpp"                  ///< Tabla IR
#include "IR/elements/instruction.hpp"          ///< Instruccion IR

// ===============================================================

// ----- DEFINICION DE CLASE IMPRESORA DE CODIGO IR -----

class IR_Printer{
    private:
        // -- Manejador de tablas de literales, variables y etiquetas
        IR_Tables& tables = IR_Tables::get_instance();

        // -- Vector con las instrucciones en str
        std::vector<std::string> ir_instructions_str;

        /**
         * @brief Constructor de la clase
         */
        IR_Printer() {};

        /**
         * @brief Convierte el codigo de una instruccion especificada a string
         * @param instr_code : codigo de instruccion
         * @return cadena con el codigo de instruccion
         */
        std::string ir_code_instruction_to_string(IR_instruction_type_t instr_code);

        /**
         * @brief Convierte el operando de una instruccion especificada a string
         * @param op : operando de instruccion
         * @return cadena con el operando de instruccion
         */
        std::string ir_operand_instruction_to_string(IR_operand op);

        /**
         * @brief Convierte la instruccion especificada a string
         * @param index : indice de instruccion
         * @return cadena con la instruccion
         */
        std::string ir_instruction_to_string(IR_instruction instr);

    public:
        /**
         * @brief Obtiene la instancia del manejador
         * @return instancia
         */
        static IR_Printer& get_instance();

        /**
         * @brief Imprime las instrucciones IR 
         * @param os : flujo de salida
         */
        void print_ir_instructions(std::ostream& os = std::cout);

        /**
         * @brief Imprime las tablas de mapa
         * @param os : flujo de salida
         */
        void print_tables(std::ostream& os = std::cout);

        /**
         * @brief Incluye una nueva instruccion IR en el vector de instrucciones para imprimir
         * @param instr : instruccion a imprimir
         */
        void add_ir_instruction_to_printer(IR_instruction instr);

        /**
         * @brief Incluye una nueva instruccion IR en el vector de instrucciones para imprimir
         * @param instr : instruccion a imprimir
         * @param position : posicion en vector
         */
        void add_ir_instruction_to_printer(IR_instruction instr, int position);

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Printer(const IR_Printer&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Printer&) = delete;

        /**
         * @brief Sobrecarga de operador ()
         * @param i : indice
         * @param instr : instruccion
         */
        void operator()(int i, const IR_instruction & instr);

        /**
         * @brief Limpia el vector de instrucciones str
         */
        void clear() { ir_instructions_str.clear(); };
};

#endif //_LAMPORT_IR_PRINTER_DPR_