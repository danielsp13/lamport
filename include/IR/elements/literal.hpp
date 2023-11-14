/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file literal.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio  (Literales de IR Lineal)
 */

#ifndef _LAMPORT_IR_LITERAL_DPR_
#define _LAMPORT_IR_LITERAL_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <variant>
#include <unordered_map>

// ===============================================================

// ----- DEFINICION DE VARIABLES GLOBALES -----    

// ===============================================================

// ----- DEFINICION DE TIPOS DE LITERALES IR -----

/**
 * @brief Enumerado que representa los diferentes tipos de literales
 * de la representacion intermedia
 */
typedef enum {
    IR_LIT_INTEGER,             ///< Literal entero
    IR_LIT_REAL,                ///< Literal flotante
    IR_LIT_CHAR,                ///< Literal de caracter
    IR_LIT_STRING,              ///< Literal de cadena de caracteres (string)
    IR_LIT_BOOLEAN,             ///< Literal booleano
} IR_literal_t; 

/**
 * @brief Mapa que contiene la conversion del tipo de literal a string
 */
const std::unordered_map<IR_literal_t, std::string> IR_literal_t_str = {
    {IR_LIT_INTEGER,"integer"},
    {IR_LIT_REAL,"real"},
    {IR_LIT_CHAR,"char"},
    {IR_LIT_STRING,"string"},
    {IR_LIT_BOOLEAN,"boolean"}
};

// ===============================================================

// ----- DEFINICION DE CLASE LITERAL IR -----

/**
 * @brief Clase que representa a un literal en el lenguaje de representacion
 * intermedia. Aqui solo se definen los diferentes tipos de literales disponibles
 * ademas de algunas funciones de gestion
 */
class IR_literal{
    private:
        IR_literal_t kind;                                      ///< Tipo de literal
        std::variant<int, float, char, std::string, bool> lit;  ///< Valor de literal

    public:
        /**
         * @brief Constructor de literal
         */
        IR_literal() {};

        /**
         * @brief Crea un literal entero
         * @param l_int : valor de literal
         */
        void literal_integer(int l_int) { kind = IR_LIT_INTEGER; lit = l_int; };

        /**
         * @brief Crea un literal real
         * @param l_real : valor de literal
         */
        void literal_real(float l_real) { kind = IR_LIT_REAL; lit = l_real; };

        /**
         * @brief Crea un literal de caracter
         * @param l_char : valor de literal
         */
        void literal_char(char l_char) { kind = IR_LIT_CHAR; lit = l_char; };

        /**
         * @brief Crea un literal de string
         * @param l_str : valor de literal
         */
        void literal_string(std::string l_str) { kind = IR_LIT_STRING; lit = l_str; };

        /**
         * @brief Crea un literal de boolean
         * @param l_bool : valor de literal
         */
        void literal_bool(bool l_bool) { kind = IR_LIT_BOOLEAN; lit = l_bool; };

        /**
         * @brief Devuelve el tipo e literal
         * @return tipo de literal
         */
        IR_literal_t get_kind() { return kind; };

        /**
         * @brief Obtiene el valor de literal
         * @return tipo de literal
         */
        template <typename T>
        T get_literal() const {return std::get<T>(lit);};

        /**
         * @brief Obtiene el valor de literal en formato string
         * @return valor de literal en string
         */
        std::string to_string() const;

        /**
         * @brief Obtiene el tipo de literal en formato string
         * @return tipo de literal en string
         */
        std::string get_kind_str() const;
};

#endif //_LAMPORT_IR_LITERAL_DPR_