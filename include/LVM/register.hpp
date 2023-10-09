/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file register.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de registro para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_REGISTER_DPR_
#define _LAMPORT_LVM_REGISTER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <unordered_map>

#include <variant>

// ===============================================================

// ----- DEFINICION DE CONTENIDO DE REGISTRO -----

/**
 * @brief Enumerado que representa tipos de contenidos de registro
 */
typedef enum{
    REG_EMPTY,                     ///< Bloque de memoria vacio
    REG_CONTAINS_INTEGER,          ///< Bloque de memoria contiene entero
    REG_CONTAINS_REAL,             ///< Bloque de memoria contiene real
    REG_CONTAINS_CHAR,             ///< Bloque de memoria contiene char
    REG_CONTAINS_STRING,           ///< Bloque de memoria contiene string
    REG_CONTAINS_BOOL,             ///< Bloque de memoria contiene bool
} LVM_Register_type_t;

// ===============================================================

// ----- DEFINICION DE CLASE REGISTRO -----

// -- Especificamos los tio de dato
using reg_data = std::variant<int,float,char,std::string,bool,long>;

// ===============================================================

// ----- DEFINICION DE TIPOS DE REGISTRO -----

/**
 * @brief Mapa que contiene la conversion del tipo de registro a string
 */
const std::unordered_map<LVM_Register_type_t, std::string> LVM_Register_type_t_str = {
    {REG_EMPTY,"empty"},
    {REG_CONTAINS_INTEGER,"integer"},
    {REG_CONTAINS_REAL,"real"},
    {REG_CONTAINS_CHAR,"char"},
    {REG_CONTAINS_STRING,"string"},
    {REG_CONTAINS_BOOL,"boolean"},
};

// ===============================================================

// ----- DEFINICION DE CLASE REGISTRO -----

/**
 * @brief Clase que representa un registro
 */
class LVM_Register{
    private:
        // -- Indica el estado del registro
        LVM_Register_type_t allocates_type;
        // -- Valor almacenado en el registro
        reg_data value_allocated;

        /**
         * @brief Especifica el tipo de registro
         */
        template <typename T>
        void set_allocates_type(){
                if constexpr (std::is_same_v<T,int>)
                allocates_type = REG_CONTAINS_INTEGER;
            else if constexpr (std::is_same_v<T,float>)
                allocates_type = REG_CONTAINS_REAL;
            else if constexpr (std::is_same_v<T,char>)
                allocates_type = REG_CONTAINS_CHAR;
            else if constexpr (std::is_same_v<T,char *>)
                allocates_type = REG_CONTAINS_STRING;
            else if constexpr (std::is_same_v<T,std::string>)
                allocates_type = REG_CONTAINS_STRING;
            else if constexpr (std::is_same_v<T,bool>)
                allocates_type = REG_CONTAINS_BOOL;
            else
                throw std::invalid_argument("TIPO DE REGISTRO INVALIDO");
        };

    public:
        /**
         * @brief Constructor de bloque (vacio)
         */
        LVM_Register()
            : allocates_type(REG_EMPTY), value_allocated(0) {};

        /**
         * @brief Constructor de bloque (integer)
         */
        LVM_Register(int value)
            : allocates_type(REG_CONTAINS_INTEGER), value_allocated(value) {};

        /**
         * @brief Constructor de bloque (real)
         */
        LVM_Register(float value)
            : allocates_type(REG_CONTAINS_REAL), value_allocated(value) {};

        /**
         * @brief Constructor de bloque (char)
         */
        LVM_Register(char value)
            : allocates_type(REG_CONTAINS_CHAR), value_allocated(value) {};

        /**
         * @brief Constructor de bloque (string)
         */
        LVM_Register(char *value)
            : allocates_type(REG_CONTAINS_STRING), value_allocated(std::string(value)) {};

        /**
         * @brief Constructor de bloque (string)
         */
        LVM_Register(std::string value)
            : allocates_type(REG_CONTAINS_STRING), value_allocated(value) {};

        /**
         * @brief Constructor de bloque (bool)
         */
        LVM_Register(bool value)
            : allocates_type(REG_CONTAINS_BOOL), value_allocated(value) {};

        /**
         * @brief Destructor de clase
         */
        ~LVM_Register() = default;
        
        /**
         * @brief Obtiene el valor contenido en el registro
         * @return Contenido de registro
         */
        template <typename T>
        T get_value() const {return std::get<T>(value_allocated);};
    
        /**
         * @brief Obtiene el tipo de registro
         * @return tipo de bloque
         */
        LVM_Register_type_t get_type_of_alloc() {return allocates_type; };

        /**
         * @brief Obtiene el tipo de registro en string
         * @return tipo de registro en str
         */
        std::string get_type_of_alloc_str() const;
        
        /**
         * @brief Obtiene el valor de registro en str
         * @return valor de bloque en str
         */
        std::string get_value_str() const;

        /**
         * @brief Inserta un valor en el registro
         * @param value : valor de registro
         */
        template <typename T>
        void allocate_value(T value){
            // -- Comprobar si es string de C, en ese caso convertir a std::string
            if constexpr (std::is_same_v<T,char*>)
                value = std::string(value);

            // -- Especificar nuevo tipo de registro
            this->set_allocates_type<T>();

            // -- Asignar valor a registro
            this->value_allocated = value;
        };

        /**
         * @brief Sobrecarga del operador +. Suma un registro con otro
         * @param otro : otro registro
         * @return nuevo registro con el valor resultado
         */
        LVM_Register operator+(const LVM_Register& otro) const;

        /**
         * @brief Sobrecarga del operador -. Resta un registro con otro
         * @param otro : otro registro
         * @return nuevo registro con el valor resultado
         */
        LVM_Register operator-(const LVM_Register& otro) const;
        
        /**
         * @brief Sobrecarga del operador *. Multiplica un registro con otro
         * @param otro : otro registro
         * @return nuevo registro con el valor resultado
         */
        LVM_Register operator*(const LVM_Register& otro) const;

        /**
         * @brief Sobrecarga del operador /. Divide un registro con otro
         * @param otro : otro registro
         * @return nuevo registro con el valor resultado
         */
        LVM_Register operator/(const LVM_Register& otro) const;
        
        /**
         * @brief Sobrecarga del operador %. Obtiene el resto de dividir un registro con otro
         * @param otro : otro registro
         * @return nuevo registro con el valor resultado
         */
        LVM_Register operator%(const LVM_Register & otro) const;

        /**
         * @brief Sobrecarga del operador - (unario). Obtiene el resultado de aplicar operacion unaria -
         * @return nuevo registro con el valor resultado
         */
        LVM_Register operator-() const;

        /**
         * @brief Sobrecarga de operador <. Obtiene un registro con el resultado de la comparacion
         * @param otro : otro registro
         * @return nuevo registro con el valor resultado
         */
        LVM_Register operator<(const LVM_Register & otro) const;

        LVM_Register operator<=(const LVM_Register & otro) const;

        LVM_Register operator>(const LVM_Register & otro) const;

        LVM_Register operator>=(const LVM_Register & otro) const;

        LVM_Register operator==(const LVM_Register & otro) const;

        LVM_Register operator!=(const LVM_Register & otro) const;

        LVM_Register operator&&(const LVM_Register & otro) const;

        LVM_Register operator||(const LVM_Register & otro) const;

        LVM_Register operator!() const;
};
#endif //_LAMPORT_LVM_REGISTER_DPR_