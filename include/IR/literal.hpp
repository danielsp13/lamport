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

// ===============================================================

// ----- DEFINICION DE VARIABLES GLOBALES -----    

// ===============================================================

// ----- DEFINICION DE TIPOS DE LITERALES IR -----

/**
 * @brief Enumerado que representa los diferentes tipos de literales
 * de la representacion intermedia
 */
enum class IR_literal_t{
    IR_LIT_INTEGER,             ///< Literal entero
    IR_LIT_REAL,                ///< Literal flotante
    IR_LIT_CHAR,                ///< Literal de caracter
    IR_LIT_STRING,              ///< Literal de cadena de caracteres (string)
    IR_LIT_BOOLEAN,             ///< Literal booleano
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
        IR_literal() {};

        void literal_integer(int l_int) { kind = IR_literal_t::IR_LIT_INTEGER; lit = l_int; };

        void literal_real(float l_real) { kind = IR_literal_t::IR_LIT_REAL; lit = l_real; };

        void literal_char(char l_char) { kind = IR_literal_t::IR_LIT_CHAR; lit = l_char; };

        void literal_string(std::string l_str) { kind = IR_literal_t::IR_LIT_STRING; lit = l_str; };

        void literal_bool(bool l_bool) { kind = IR_literal_t::IR_LIT_BOOLEAN; lit = l_bool; };

        IR_literal_t get_kind() { return kind; };

        template <typename T>
        T get_literal() const {return std::get<T>(lit);};

        std::string to_string() const{
            std::string lit_str;
            switch (kind)
            {
            case IR_literal_t::IR_LIT_INTEGER:
            {
                lit_str = std::to_string(std::get<int>(lit));
                break;
            }
            case IR_literal_t::IR_LIT_REAL:
            {
                lit_str = std::to_string(std::get<float>(lit));
                break;
            }
            case IR_literal_t::IR_LIT_CHAR:
            {
                lit_str = "\'" + std::string(1, std::get<char>(lit)) + "\'";
                break;
            }
            case IR_literal_t::IR_LIT_STRING:
            {
                lit_str = "\"" + std::get<std::string>(lit) + "\"";
                break;
            }
            case IR_literal_t::IR_LIT_BOOLEAN:
            {
                lit_str = std::get<bool>(lit) ? "true" : "false";
                break;
            }
            
            default:
                break;
            }

            return lit_str;
        };
};

#endif //_LAMPORT_IR_LITERAL_DPR_