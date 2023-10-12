/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file memory_block.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de bloque de memoria para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_MEMORY_BLOCK_DPR_
#define _LAMPORT_LVM_MEMORY_BLOCK_DPR_ 

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

// ----- DEFINICION DE TIPOS DE BLOQUE DE MEMORIA -----

/**
 * @brief Enumerado que representa tipo de bloque de memoria
 */
typedef enum{
    MEM_BLOCK_EMPTY,            ///< Bloque de memoria vacio
    MEM_BLOCK_INTEGER,          ///< Bloque de memoria contiene entero
    MEM_BLOCK_REAL,             ///< Bloque de memoria contiene real
    MEM_BLOCK_CHAR,             ///< Bloque de memoria contiene char
    MEM_BLOCK_STRING,           ///< Bloque de memoria contiene string
    MEM_BLOCK_BOOL,             ///< Bloque de memoria contiene bool
    MEM_BLOCK_ADDRESS_INSTR,    ///< Bloque de memoria contiene direccion a instruccion
} LVM_Memory_Block_type_t;

/**
 * @brief Mapa que contiene la conversion del tipo de bloque a string
 */
const std::unordered_map<LVM_Memory_Block_type_t, std::string> LVM_Memory_Block_type_t_str = {
    {MEM_BLOCK_EMPTY,"empty"},
    {MEM_BLOCK_INTEGER,"integer"},
    {MEM_BLOCK_REAL,"real"},
    {MEM_BLOCK_CHAR,"char"},
    {MEM_BLOCK_STRING,"string"},
    {MEM_BLOCK_BOOL,"boolean"},
    {MEM_BLOCK_ADDRESS_INSTR,"instr. address"},
};

// ===============================================================

// ----- DEFINICION DE CLASE BLOQUE DE MEMORIA -----

/**
 * @brief Clase que representa un bloque de memoria
 */
class LVM_Memory_Block{
    private:
        // -- Indica el estado del bloque de memoria
        LVM_Memory_Block_type_t allocates_type;
        // -- Valor almacenado en el bloque de memoria
        block value_allocated;

        /**
         * @brief Especifica el tipo de bloque de memoria
         */
        template <typename T>
        void set_allocates_type(){
                if constexpr (std::is_same_v<T,int>)
                allocates_type = MEM_BLOCK_INTEGER;
            else if constexpr (std::is_same_v<T,float>)
                allocates_type = MEM_BLOCK_REAL;
            else if constexpr (std::is_same_v<T,char>)
                allocates_type = MEM_BLOCK_CHAR;
            else if constexpr (std::is_same_v<T,char *>)
                allocates_type = MEM_BLOCK_STRING;
            else if constexpr (std::is_same_v<T,std::string>)
                allocates_type = MEM_BLOCK_STRING;
            else if constexpr (std::is_same_v<T,bool>)
                allocates_type = MEM_BLOCK_BOOL;
            else if constexpr (std::is_same_v<T,long>)
                allocates_type = MEM_BLOCK_ADDRESS_INSTR;
            else
                throw std::invalid_argument("TIPO DE BLOQUE DE MEMORIA INVALIDO");
        };

    public:
        /**
         * @brief Constructor de bloque (vacio)
         */
        LVM_Memory_Block()
            : allocates_type(MEM_BLOCK_EMPTY), value_allocated(0) {};

        /**
         * @brief Destructor de clase
         */
        ~LVM_Memory_Block() = default;
        
        /**
         * @brief Obtiene el valor contenido en el bloque
         * @return Contenido de bloque
         */
        template <typename T>
        T get_value() const {return std::get<T>(value_allocated);};
    
        /**
         * @brief Obtiene el tipo de bloque de memoria
         * @return tipo de bloque
         */
        LVM_Memory_Block_type_t get_type_of_alloc() const {return allocates_type; };

        /**
         * @brief Obtiene el tipo de bloque de memoria en formato string
         * @return tipo de bloque en str
         */
        std::string get_type_of_alloc_str() const;
        
        /**
         * @brief Obtiene el valor de bloque en str
         * @return valor de bloque en str
         */
        std::string get_value_str() const;

        /**
         * @brief Inserta un valor en el bloque de memoria
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



#endif //_LAMPORT_LVM_MEMORY_BLOCK_DPR_