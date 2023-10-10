/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file table.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio  (Tabla de IR Lineal)
 */

#ifndef _LAMPORT_IR_TABLE_DPR_
#define _LAMPORT_IR_TABLE_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <memory>

#include "table_entry.hpp"          ///< Entrada de tabla IR
#include "literal.hpp"              ///< Literal IR
#include "variable.hpp"             ///< Variable IR
#include "label.hpp"                ///< Etiqueta IR

// ===============================================================

// ----- DEFINICION DE CLASE TABLA IR -----

class IR_Tables{
    private:
        // -- Tabla de literales
        std::vector<std::shared_ptr<IR_Table_Entry_Literal>> table_literals;
        // -- Tabla de variables
        std::vector<std::shared_ptr<IR_Table_Entry_Variable>> table_variables;
        // -- Tabla de etiquetas
        std::vector<std::shared_ptr<IR_Table_Entry_Label>> table_labels;

        /**
         * @brief Constructor de la clase (privado por ser singleton)
         */
        IR_Tables() {};
    public:
        /**
         * @brief Obtiene la instancia de la tabla
         * @return instance
         */
        static IR_Tables& get_instance();

        /**
         * @brief Inserta un literal en la tabla de literales (entero)
         * @param l_int : literal
         * @return direccion de registro del literal
         */
        int add_entry_literal(int l_int);

        /**
         * @brief Inserta un literal en la tabla de literales (real)
         * @param l_real : literal
         * @return direccion de registro del literal
         */
        int add_entry_literal(float l_real);

        /**
         * @brief Inserta un literal en la tabla de literales (char)
         * @param l_char : literal
         * @return direccion de registro del literal
         */
        int add_entry_literal(char l_char);

        /**
         * @brief Inserta un literal en la tabla de literales (string)
         * @param l_str : literal
         * @return direccion de registro del literal
         */
        int add_entry_literal(char *l_str);

        /**
         * @brief Inserta un literal en la tabla de literales (string)
         * @param l_str : literal
         * @return direccion de registro del literal
         */
        int add_entry_literal(std::string l_str);

        /**
         * @brief Inserta un literal en la tabla de literales (boolean)
         * @param l_bool : literal
         * @return direccion de registro del literal
         */
        int add_entry_literal(bool l_bool);

        /**
         * @brief Inserta una etiqueta en la tabla de etiquetas
         * @param label_id : identificador de etiqueta
         * @param addr : direccion a la que apunta la etiqueta
         * @return direccion de registro de etiqueta
         */
        int add_entry_label(std::string label_id, int addr);

        /**
         * @brief Modifica el contenido de una entrada de etiquetas
         * @param label_id : identificador de etiqueta
         * @param new_addr : nueva direccion a la que apunta la etiqueta
         * @return direccion de registro de etiqueta
         */
        int modify_entry_label(std::string label_id, int new_addr);

        /**
         * @brief Inserta una variable en la tabla de variables
         * @param kind : tipo de variable (local/global)
         * @param var_name : nombre de variable
         * @param type : tipo de variable
         * @return direccion de registro de variable
         */
        int add_entry_variable(IR_variable_t kind, std::string var_name, IR_variable_type_t type);

        /**
         * @brief Inserta una variable array en la tabla de variables
         * @param kind : tipo de variable (local/global)
         * @param var_name : nombre de variable
         * @param arr_type : tipo de variable
         * @param arr_size : longitud de array
         * @return direccion de registro de variable
         */
        int add_entry_variable(IR_variable_t kind, std::string var_name, IR_variable_type_t arr_type, size_t arr_size);

        /**
         * @brief Obtiene la dimension de la tabla de literales
         * @return size de tabla de etiquetas
         */
        int get_size_table_literals() {return this->table_literals.size(); };

        /**
         * @brief Obtiene la dimension de la tabla de variables
         * @return size de tabla de etiquetas
         */
        int get_size_table_variables() {return this->table_variables.size(); };

        /**
         * @brief Obtiene la dimension de la tabla de etiquetas
         * @return size de tabla de etiquetas
         */
        int get_size_table_labels() {return this->table_labels.size(); };

        /**
         * @brief Obtiene un literal de la tabla dado un indice
         * @param index : indice de entrada
         * @return puntero a literal IR
         */
        IR_literal * get_entry_literal(int index);

        /**
         * @brief Obtiene una variable de la tabla dado un indice
         * @param index : indice de entrada
         * @return puntero a variable IR
         */
        IR_variable * get_entry_variable(int index);

        /**
         * @brief Obtiene una etiqueta de la tabla dado un indice
         * @param index : indice de entrada
         * @return puntero a etiqueta IR
         */
        IR_label * get_entry_label(int index);

        /**
         * @brief Obtiene el indice donde se encuentra el registro del literal
         * @param l_int : literal a buscar
         * @return posicion en tabla, -1 en otro caso
         */
        int get_index_from_literal_value(int l_int);

        /**
         * @brief Obtiene el indice donde se encuentra el registro del literal
         * @param l_int : literal a buscar
         * @return posicion en tabla, -1 en otro caso
         */
        int get_index_from_literal_value(float l_real);

        /**
         * @brief Obtiene el indice donde se encuentra el registro del literal
         * @param l_int : literal a buscar
         * @return posicion en tabla, -1 en otro caso
         */
        int get_index_from_literal_value(char l_char);

        /**
         * @brief Obtiene el indice donde se encuentra el registro del literal
         * @param l_str : literal a buscar
         * @return posicion en tabla, -1 en otro caso
         */
        int get_index_from_literal_value(std::string l_str);

        /**
         * @brief Obtiene el indice donde se encuentra el registro del literal
         * @param l_int : literal a buscar
         * @return posicion en tabla, -1 en otro caso
         */
        int get_index_from_literal_value(bool l_bool);

        /**
         * @brief Obtiene el indice donde se encuentra el registro de la etiqueta
         * @param id_label : id de etiqueta a buscar
         * @return posicion en tabla, -1 en otro caso
         */
        int get_index_from_label_id(std::string id_label);

        /**
         * @brief Obtiene el indice donde se encuentra el registro de la variable local
         * @param var_name : nombre de variable
         * @return posicion en tabla, -1 en otro caso
         */
        int get_index_from_local_variable(std::string var_name);

        /**
         * @brief Obtiene el indice donde se encuentra el registro de la variable global
         * @param var_name : nombre de variable
         * @return posicion en tabla, -1 en otro caso
         */
        int get_index_from_global_variable(std::string var_name);

        /**
         * @brief Comprueba si la variable mapeada en el indice especificado es un array
         * @param index : indice de variable
         * @return TRUE si es array, FALSE en otro caso
         */
        bool check_if_variable_is_array_using_index(int index);

        /**
         * @brief Imprime la tabla de literales por la salida estandar
         */
        void print_literals_table(std::ostream& os = std::cout);

        /**
         * @brief Imprime la tabla de variables por la salida estandar
         */
        void print_variables_table(std::ostream& os = std::cout);

        /**
         * @brief Imprime la tabla de etiquetas por la salida estandar
         */
        void print_labels_table(std::ostream& os = std::cout);
};


#endif //_LAMPORT_IR_TABLE_DPR_