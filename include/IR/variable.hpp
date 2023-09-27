/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file variable.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio  (Variables de IR Lineal)
 */

#ifndef _LAMPORT_IR_VARIABLE_DPR_
#define _LAMPORT_IR_VARIABLE_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

// ===============================================================

// ----- DEFINICION DE VARIABLES GLOBALES -----    

// ===============================================================

// ----- DEFINICION DE CLASE TIPO DE VARIABLE -----

/**
 * @brief Clase que representa un tipo de variable en el
 * lenguaje de representacion intermedia
 */
enum class IR_variable_t{
    IR_VAR_LOCAL,               ///< Variable local
    IR_VAR_GLOBAL,              ///< Variable global
};

// ===============================================================

// ----- DEFINICION DE CLASE TIPO DE DATO DE VARIABLE -----

/**
 * @brief Enumerado que representa los diferentes tipos de dato de variable en el
 * lenguaje de representacion intermedia.
 */
enum class IR_variable_type_t{
    IR_VAR_INT,                 ///< Tipo entero
    IR_VAR_REAL,                ///< Tipo float
    IR_VAR_CHAR,                ///< Tipo char
    IR_VAR_STR,                 ///< Tipo string
    IR_VAR_BOOL,                ///< Tipo bool
    IR_VAR_ARRAY,               ///< Tipo array
    IR_VAR_SEMAPHORE,           ///< Tipo semaforo
    IR_VAR_DPROCESS,            ///< Tipo proceso
};

/**
 * @brief Clase que representa un tipo de variable en el lenguaje de representacion
 * intermedia.
 */
class IR_variable_type{
    public:
        IR_variable_type_t type;                ///< Tipo de dato de variable
        IR_variable_type_t array_subtype;       ///< Subtipo de dato de array
        size_t array_size;                      ///< Longitud de array

        /**
         * @brief Constructor de tipo de dato de variable
         * @param kind : tipo de dato
         */
        IR_variable_type(IR_variable_type_t kind) : type(kind) {};

        /**
         * @brief Constructor de tipo de dato array
         * @param arr_kind : tipo de array
         * @param arr_size : longitud de array
         */
        IR_variable_type(IR_variable_type_t arr_kind, size_t arr_size) 
            : type(IR_variable_type_t::IR_VAR_ARRAY), array_subtype(arr_kind), array_size(arr_size) {};

        /**
         * @brief Comprueba si el tipo de dato es un array
         * @return TRUE si es array, FALSE en otro caso
         */
        bool is_array() { return type == IR_variable_type_t::IR_VAR_ARRAY;};
};

// ===============================================================

// ----- DEFINICION DE CLASE VARIABLE -----

/**
 * @brief Clase que representa una variable en el lenguaje de representacion
 * intermedia. Aqui solo se definen el tipo de dato de la variable, y los
 * diferentes tipos de literales disponibles
 */
class IR_variable{
    private:
        IR_variable_t kind;             ///< Tipo de variable
        std::string var_name;           ///< Nombre de variable
        IR_variable_type type;          ///< Tipo de dato de variable
        
    public:
        /**
         * @brief Constructor de variable
         * @param kind : tipo de variable (local/global)
         * @param var_name : nombre de variable
         * @param type : tipo de dato de variable (no array)
         */
        IR_variable(IR_variable_t kind,const char *var_name, IR_variable_type_t type)
            : kind(kind), var_name(var_name), type(type) {};

        /**
         * @brief Constructor de variable
         * @param kind : tipo de variable (local/global)
         * @param var_name : nombre de variable
         * @param type : tipo de dato de variable (contenido de array)
         * @param size : size de array
         */
        IR_variable(IR_variable_t kind,const char *var_name, IR_variable_type_t type, size_t size)
            : kind(kind), var_name(var_name), type(type,size) {};

        /**
         * @brief Obtiene el tipo de variable
         * @return tipo de variable
         */
        IR_variable_t get_kind() { return kind; };

        /**
         * @brief Destructor de variable (por defecto)
         */
        ~IR_variable() = default;

        /**
         * @brief Comprueba que la variable es local
         * @return TRUE si es local, FALSE en otro caso
         */
        bool is_local() {return kind == IR_variable_t::IR_VAR_LOCAL; };

        /**
         * @brief Comprueba que la variable es global
         * @return TRUE si es global, FALSE en otro caso
         */
        bool is_global() {return kind == IR_variable_t::IR_VAR_GLOBAL; };

        /**
         * @brief Obtiene nombre de variable
         * @return nombre de variable
         */
        std::string get_name() { return var_name; };

        /**
         * @brief Obtiene el tipo de dato de la variable
         */
        IR_variable_type_t get_type() { return type.type; };

        /**
         * @brief Instancia de variable a string
         * @return nombre de variable
         */
        std::string to_string() const{ return var_name; }
};

#endif //_LAMPORT_IR_VARIABLE_DPR_