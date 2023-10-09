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
#include <vector>
#include <variant>
#include <unordered_map>

#include "AST/type.h"           ///< Tipo de dato AST
#include "semantic/symbol.h"    ///< Simbolo

// ===============================================================

// ----- DEFINICION DE VARIABLES GLOBALES -----    

// ===============================================================

// ----- DEFINICION DE CLASE TIPO DE VARIABLE -----

/**
 * @brief Enumerado que representa un tipo de variable en el
 * lenguaje de representacion intermedia
 */
typedef enum{
    IR_VAR_LOCAL,               ///< Variable local
    IR_VAR_GLOBAL,              ///< Variable global
} IR_variable_t;

/**
 * @brief Mapa que contiene la conversion del tipo de variable a string
 */
const std::unordered_map<IR_variable_t,std::string> IR_variable_t_str = {
    {IR_VAR_LOCAL,"local"},
    {IR_VAR_GLOBAL,"global"},
};

/**
 * @brief Mapa que contiene la conversion de tipo de simbolo a tipo de variable IR
 */
const std::unordered_map<symbol_t,IR_variable_t> AST_symbol_IR_var_t = {
    {SYMBOL_LOCAL,IR_VAR_LOCAL},
    {SYMBOL_GLOBAL,IR_VAR_GLOBAL},
    {SYMBOL_PARAM,IR_VAR_LOCAL},
};

// ===============================================================

// ----- DEFINICION DE CLASE TIPO DE DATO DE VARIABLE -----

/**
 * @brief Enumerado que representa los diferentes tipos de dato de variable en el
 * lenguaje de representacion intermedia.
 */
typedef enum{
    IR_VAR_TYPE_INT,                 ///< Tipo entero
    IR_VAR_TYPE_REAL,                ///< Tipo float
    IR_VAR_TYPE_CHAR,                ///< Tipo char
    IR_VAR_TYPE_STR,                 ///< Tipo string
    IR_VAR_TYPE_BOOL,                ///< Tipo bool
    IR_VAR_TYPE_ARRAY,               ///< Tipo array
    IR_VAR_TYPE_SEMAPHORE,           ///< Tipo semaforo
    IR_VAR_TYPE_DPROCESS,            ///< Tipo proceso dinamico
    IR_VAR_TYPE_PROCESS,             ///< Tipo proceso estatico
} IR_variable_type_t;

/**
 * @brief Mapa que contiene la conversion del tipo de dato de variable a string
 */
const std::unordered_map<IR_variable_type_t, std::string> IR_variable_type_t_str = {
    {IR_VAR_TYPE_INT, "integer"},
    {IR_VAR_TYPE_REAL, "real"},
    {IR_VAR_TYPE_CHAR, "char"},
    {IR_VAR_TYPE_STR, "string"},
    {IR_VAR_TYPE_BOOL, "boolean"},
    {IR_VAR_TYPE_ARRAY, "array"},
    {IR_VAR_TYPE_SEMAPHORE, "semaphore"},
    {IR_VAR_TYPE_DPROCESS, "dynamic process"},
    {IR_VAR_TYPE_PROCESS, "static process"},
};

/**
 * @brief Mapa que contiene la conversion de tipo de dato AST de con el tipo de dato IR
 */
const std::unordered_map<type_t,IR_variable_type_t> AST_type_IR_type = {
    {TYPE_INTEGER,IR_VAR_TYPE_INT},
    {TYPE_BOOLEAN,IR_VAR_TYPE_BOOL},
    {TYPE_CHAR,IR_VAR_TYPE_CHAR},
    {TYPE_STRING,IR_VAR_TYPE_STR},
    {TYPE_REAL,IR_VAR_TYPE_REAL},
    {TYPE_ARRAY,IR_VAR_TYPE_ARRAY},
    {TYPE_SEMAPHORE,IR_VAR_TYPE_SEMAPHORE},
    {TYPE_DPROCESS,IR_VAR_TYPE_DPROCESS}
};

// ===============================================================

// ----- DEFINICION DE CLASE TIPO DE VARIABLE IR -----

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
        IR_variable_type(IR_variable_type_t kind) 
            : type(kind), array_size(1) {};

        /**
         * @brief Constructor de tipo de dato array
         * @param arr_kind : tipo de array
         * @param arr_size : longitud de array
         */
        IR_variable_type(IR_variable_type_t arr_kind, size_t arr_size) 
            : type(IR_VAR_TYPE_ARRAY), array_subtype(arr_kind), array_size(arr_size) {};

        /**
         * @brief Comprueba si el tipo de dato es un array
         * @return TRUE si es array, FALSE en otro caso
         */
        bool is_array() { return type == IR_VAR_TYPE_ARRAY;};

        /**
         * @brief Obtiene el tipo de dato en formato string
         */
        std::string get_type_str();
};

// ===============================================================

// ----- DEFINICION DE CLASE VARIABLE IR -----

// -- Especificamos que es un tipo de dato atomico
using data_type = std::variant<int,float,char,std::string,bool>;

/**
 * @brief Clase que representa una variable en el lenguaje de representacion
 * intermedia. Aqui solo se definen el tipo de dato de la variable, y los
 * diferentes tipos de literales disponibles
 */
class IR_variable{
    private:
        IR_variable_t kind;             ///< Tipo de variable
        std::string var_name;           ///< Nombre de variable
        std::string pseudo_name;        ///< Pseudonimo de variable (si es indice)
        IR_variable_type type;          ///< Tipo de dato de variable
        data_type value;                ///< Valor de variable
        
        /**
         * @brief Inicializa la variable con un valor por defecto
         */
        void initialize_variable();

    public:
        /**
         * @brief Constructor de variable
         * @param kind : tipo de variable (local/global)
         * @param var_name : nombre de variable
         * @param type : tipo de dato de variable (no array)
         */
        IR_variable(IR_variable_t kind, const char *var_name, IR_variable_type_t type)
            : kind(kind), var_name(var_name), type(type) { initialize_variable(); };

        /**
         * @brief Constructor de variable
         * @param kind : tipo de variable (local/global)
         * @param var_name : nombre de variable
         * @param type : tipo de dato de variable (contenido de array)
         * @param size : size de array
         */
        IR_variable(IR_variable_t kind, const char *var_name, IR_variable_type_t type, size_t size)
            : kind(kind), var_name(var_name), type(type,size) { initialize_variable(); };

        /**
         * @brief Destructor de variable (por defecto)
         */
        ~IR_variable() = default;

        /**
         * @brief Obtiene el tipo de variable
         * @return tipo de variable
         */
        IR_variable_t get_kind() const { return kind; };

        /**
         * @brief Comprueba que la variable es local
         * @return TRUE si es local, FALSE en otro caso
         */
        bool is_local() const {return kind == IR_VAR_LOCAL; };

        /**
         * @brief Comprueba que la variable es global
         * @return TRUE si es global, FALSE en otro caso
         */
        bool is_global() const {return kind == IR_VAR_GLOBAL; };

        /**
         * @brief Obtiene nombre de variable
         * @return nombre de variable
         */
        std::string get_name() { return var_name; };

        /**
         * @brief Obtiene el tipo de dato de la variable
         * @return tipo de dato
         */
        IR_variable_type_t get_type() const { return type.type; } ;

        /**
         * @brief Obtiene el tipo de dato del array de variable
         * @return tipo de array
         */
        IR_variable_type_t get_array_type() const {return type.array_subtype; } ;

        /**
         * @brief Obtiene la dimension del array de variable
         * @return dimension de variable
         */
        size_t get_size_array() const {return type.array_size; };

        /**
         * @brief Comprueba si la variable es un array
         * @return TRUE si es un array, FALSE en otro caso
         */
        bool is_array() { return type.is_array(); };

        /**
         * @brief Obtiene el tipo de variable en formato string
         * @return tipo de variable en formato string
         */
        std::string get_kind_str();

        /**
         * @brief Obtiene el tipo de dato de variable en formato string
         * @return tipo de dato en string
         */
        std::string get_type_str() { return type.get_type_str(); };

        /**
         * @brief Obtiene el valor inicial de variable en formato string
         * @return valor en str
         */
        std::string get_initial_value_str() const;

        /**
         * @brief Obtiene el valor inicial de variable
         * @return valor de variable
         */
        template <typename T>
        T get_initial_value() const { return std::get<T>(value); };
};

#endif //_LAMPORT_IR_VARIABLE_DPR_