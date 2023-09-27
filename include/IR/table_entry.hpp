/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file table_entry.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio  (Entrada de Tabla de IR Lineal)
 */

#ifndef _LAMPORT_IR_ENTRY_TABLE_DPR_
#define _LAMPORT_IR_ENTRY_TABLE_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <memory>

#include "variable.hpp"     ///< Variable IR
#include "literal.hpp"      ///< Literal IR
#include "label.hpp"        ///< Etiqueta IR

// ===============================================================

// ----- DEFINICION DE CLASE ENTRADA DE TABLA IR -----

/**
 * @brief Clase que representa a una tabla de entrada en el lenguaje
 * de representacion intermedia.
 */
class IR_Table_Entry{
    public:
        /**
         * @brief Enumerado que representa los diferentes tipos de
         * entradas de tabla
         */
        enum IR_Table_Entry_t{
            IR_ENTRY_LITERAL,           ///< Entrada literal
            IR_ENTRY_VARIABLE,          ///< Entrada variable
            IR_ENTRY_LABEL,             ///< Entrada etiqueta
        };

        /**
         * @brief Obtiene el tipo de entrada
         * @return tipo de entrada
         */
        virtual IR_Table_Entry_t get_kind() const = 0;

        /**
         * @brief Destructor de entrada
         */
        virtual ~IR_Table_Entry() {};
};

/**
 * @brief Clase que representa a una tabla de entrada en el lenguaje
 * de representacion intermedia. Entrada de tipo literal
 */
class IR_Table_Entry_Literal : public IR_Table_Entry{
    private:
        std::unique_ptr<IR_literal> lit;    ///< Puntero a literal IR

    public:
        /**
         * @brief Constructor de entrada literal
         */
        IR_Table_Entry_Literal() {};

        /**
         * @brief Inserta un literal entero en la entrada
         * @param l_int valor de literal
         */
        void entry_literal_integer(int l_int){ lit = std::make_unique<IR_literal>(); lit->literal_integer(l_int); };

        /**
         * @brief Inserta un literal real en la entrada
         * @param l_real valor de literal
         */
        void entry_literal_real(float l_real){ lit = std::make_unique<IR_literal>(); lit->literal_real(l_real); };

        /**
         * @brief Inserta un literal de caracter en la entrada
         * @param l_char valor de literal
         */
        void entry_literal_char(char l_char){ lit = std::make_unique<IR_literal>(); lit->literal_char(l_char); };

        /**
         * @brief Inserta un literal string en la entrada
         * @param l_str valor de literal
         */
        void entry_literal_string(const char * l_str){ lit = std::make_unique<IR_literal>(); lit->literal_string(l_str); };

        /**
         * @brief Inserta un literal boolean en la entrada
         * @param l_bool valor de literal
         */
        void entry_literal_bool(bool l_bool){ lit = std::make_unique<IR_literal>(); lit->literal_bool(l_bool); };

        /**
         * @brief Obtiene el tipo de entrada de tabla
         * @return tipo de tabla
         */
        IR_Table_Entry_t get_kind() const {return IR_ENTRY_LITERAL; };

        /**
         * @brief Obtiene el tipo de literal
         * @return tipo de literal
         */
        IR_literal_t get_kind_literal() {return lit->get_kind();};

        /**
         * @brief Obtiene una referencia al literal almacenado
         * @return puntero a lit
         */
        IR_literal * get_literal() {return lit.get(); };
};

/**
 * @brief Clase que representa a una tabla de entrada en el lenguaje
 * de representacion intermedia. Entrada de tipo variable
 */
class IR_Table_Entry_Variable : public IR_Table_Entry{
    private:
        std::unique_ptr<IR_variable> var;   ///< Puntero a variable IR

    public:
        /**
         * @brief Constructor de entrada de variable
         * @param kind : tipo de variable (local/global)
         * @param var_name : nombre de variable
         * @param type : tipo de dato de variable (no array)
         */
        IR_Table_Entry_Variable(IR_variable_t kind,const char *var_name, IR_variable_type_t type)
            : var(std::make_unique<IR_variable>(kind,var_name,type)) {};

        /**
         * @brief Constructor de entrada de variable
         * @param kind : tipo de variable (local/global)
         * @param var_name : nombre de variable
         * @param arr_type : tipo de dato array
         * @param size : longitud de array
         */
        IR_Table_Entry_Variable(IR_variable_t kind,const char *var_name, IR_variable_type_t arr_type, size_t arr_size)
            : var(std::make_unique<IR_variable>(kind,var_name,arr_type,arr_size)) {};

        /**
         * @brief Obtiene el tipo de entrada de tabla
         * @return tipo de tabla
         */
        IR_Table_Entry_t get_kind() const {return IR_ENTRY_VARIABLE; };

        /**
         * @brief Obtiene el tipo de variable
         * @return tipo de variable
         */
        IR_variable_t get_kind_variable() {return var->get_kind(); };

        /**
         * @brief Obtiene el tipo de variable
         * @return tipo de variable
         */
        IR_variable_type_t get_type_variable() {return var->get_type();}; 

        /**
         * @brief Obtiene una referencia a la variable almacenada
         * @return puntero a variable
         */
        IR_variable * get_variable() {return var.get();};
};

/**
 * @brief Clase que representa a una tabla de entrada en el lenguaje
 * de representacion intermedia. Entrada de tipo etiqueta
 */
class IR_Table_Entry_Label : public IR_Table_Entry{
    private:
        std::unique_ptr<IR_label> label;    ///< Puntero a etiqueta IR

    public:
        /**
         * @brief Constructor de la entrada de etiqueta
         * @param id : identificador de etiqueta
         */
        IR_Table_Entry_Label(int id)
            : label(std::make_unique<IR_label>(id)) {};

        /**
         * @brief Obtiene el tipo de entrada de tabla
         * @return tipo de tabla
         */
        IR_Table_Entry_t get_kind() const {return IR_ENTRY_LABEL; };

        /**
         * @brief Obtiene una referencia a la etiqueta
         * @return puntero a etiqueta
         */
        IR_label * get_label() {return label.get(); };

};

#endif //_LAMPORT_IR_ENTRY_TABLE_DPR_