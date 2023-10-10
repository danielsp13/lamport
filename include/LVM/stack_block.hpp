/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file stack_block.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de bloque de pila para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_STACK_BLOCK_DPR_
#define _LAMPORT_LVM_STACK_BLOCK_DPR_ 

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <variant>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <unordered_map>

// -- Especificamos los tio de dato
using block = std::variant<int,float,char,std::string,bool,long>;

// ===============================================================

// ----- DEFINICION DE TIPOS DE BLOQUE DE PILA -----

/**
 * @brief Enumerado que representa tipo de bloque de pila
 */
typedef enum{
    STACK_BLOCK_EMPTY,            ///< bloque de pila vacio
    STACK_BLOCK_INTEGER,          ///< bloque de pila contiene entero
    STACK_BLOCK_REAL,             ///< bloque de pila contiene real
    STACK_BLOCK_CHAR,             ///< bloque de pila contiene char
    STACK_BLOCK_STRING,           ///< bloque de pila contiene string
    STACK_BLOCK_BOOL,             ///< bloque de pila contiene bool
    STACK_BLOCK_ADDRESS_INSTR,    ///< bloque de pila contiene direccion a instruccion
} LVM_Stack_Block_type_t;

/**
 * @brief Mapa que contiene la conversion del tipo de bloque a string
 */
const std::unordered_map<LVM_Stack_Block_type_t, std::string> LVM_Stack_Block_type_t_str = {
    {STACK_BLOCK_EMPTY,"empty"},
    {STACK_BLOCK_INTEGER,"integer"},
    {STACK_BLOCK_REAL,"real"},
    {STACK_BLOCK_CHAR,"char"},
    {STACK_BLOCK_STRING,"string"},
    {STACK_BLOCK_BOOL,"boolean"},
    {STACK_BLOCK_ADDRESS_INSTR,"instr. address"},
};

// ===============================================================

// ----- DEFINICION DE CLASE BLOQUE DE PILA -----

/**
 * @brief Clase que representa un bloque de pila
 */
class LVM_Stack_Block{
    private:
        // -- Indica el estado del bloque de pila
        LVM_Stack_Block_type_t allocates_type;
        // -- Valor almacenado en el bloque de pila
        block value_allocated;

        /**
         * @brief Especifica el tipo de bloque de pila
         */
        template <typename T>
        void set_allocates_type(){
                if constexpr (std::is_same_v<T,int>)
                allocates_type = STACK_BLOCK_INTEGER;
            else if constexpr (std::is_same_v<T,float>)
                allocates_type = STACK_BLOCK_REAL;
            else if constexpr (std::is_same_v<T,char>)
                allocates_type = STACK_BLOCK_CHAR;
            else if constexpr (std::is_same_v<T,char *>)
                allocates_type = STACK_BLOCK_STRING;
            else if constexpr (std::is_same_v<T,std::string>)
                allocates_type = STACK_BLOCK_STRING;
            else if constexpr (std::is_same_v<T,bool>)
                allocates_type = STACK_BLOCK_BOOL;
            else if constexpr (std::is_same_v<T,long>)
                allocates_type = STACK_BLOCK_ADDRESS_INSTR;
            else
                throw std::invalid_argument("TIPO DE BLOQUE DE PILA INVALIDO");
        };

    public:
        /**
         * @brief Constructor de bloque (vacio)
         */
        LVM_Stack_Block()
            : allocates_type(STACK_BLOCK_EMPTY), value_allocated(0) {};

        /**
         * @brief Destructor de clase
         */
        ~LVM_Stack_Block() = default;
        
        /**
         * @brief Obtiene el valor contenido en el bloque
         * @return Contenido de bloque
         */
        template <typename T>
        T get_value() const {return std::get<T>(value_allocated);};
    
        /**
         * @brief Obtiene el tipo de bloque de pila
         * @return tipo de bloque
         */
        LVM_Stack_Block_type_t get_type_of_alloc() const {return allocates_type; };

        /**
         * @brief Obtiene el tipo de bloque de pila en formato string
         * @return tipo de bloque en str
         */
        std::string get_type_of_alloc_str() const;
        
        /**
         * @brief Obtiene el valor de bloque en str
         * @return valor de bloque en str
         */
        std::string get_value_str() const;

        /**
         * @brief Inserta un valor en el bloque de pila
         * @param value : valor de bloque
         */
        template <typename T>
        void allocate_value(T value){
            // -- Comprobar si es string de C, en ese caso convertir a std::string
            if constexpr (std::is_same_v<T,char*>)
                value = std::string(value);

            // -- Especificar nuevo tipo de bloque
            this->set_allocates_type<T>();

            // -- Asignar valor a bloque
            this->value_allocated = value;
        };
};


#endif //_LAMPORT_LVM_STACK_BLOCK_DPR_