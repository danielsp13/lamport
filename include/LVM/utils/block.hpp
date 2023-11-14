/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file block.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de bloque de datos abstracto para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_UTILS_BLOCK_DPR_
#define _LAMPORT_LVM_UTILS_BLOCK_DPR_ 

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <variant>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <unordered_map>

// -- Especificamos los tio de dato
using data_block = std::variant<int,float,char,std::string,bool,long>;

// ===============================================================

// ----- DEFINICION DE TIPOS DE BLOQUE -----

/**
 * @brief Enumerado que representa tipo de bloque
 */
typedef enum{
    BLOCK_EMPTY,            ///< bloque vacio
    BLOCK_INTEGER,          ///< bloque contiene entero
    BLOCK_REAL,             ///< bloque contiene real
    BLOCK_CHAR,             ///< bloque contiene char
    BLOCK_STRING,           ///< bloque contiene string
    BLOCK_BOOL,             ///< bloque contiene bool
    BLOCK_ADDRESS_INSTR,    ///< bloque contiene direccion a instruccion
} LVM_Block_type_t;

/**
 * @brief Mapa que contiene la conversion del tipo de bloque a string
 */
const std::unordered_map<LVM_Block_type_t, std::string> LVM_Block_type_t_str = {
    {BLOCK_EMPTY,"empty"},
    {BLOCK_INTEGER,"integer"},
    {BLOCK_REAL,"real"},
    {BLOCK_CHAR,"char"},
    {BLOCK_STRING,"string"},
    {BLOCK_BOOL,"boolean"},
    {BLOCK_ADDRESS_INSTR,"instr. address"},
};

// ===============================================================

// ----- DEFINICION DE CLASE BLOQUE -----

/**
 * @brief Clase que representa un bloque
 */
class LVM_Block{
    private:
        // -- Indica el estado del bloque
        LVM_Block_type_t allocates_type;
        // -- Valor almacenado en el bloque
        data_block value_allocated;

        /**
         * @brief Especifica el tipo de bloque
         */
        template <typename T>
        void set_allocates_type(){
                if constexpr (std::is_same_v<T,int>)
                allocates_type = BLOCK_INTEGER;
            else if constexpr (std::is_same_v<T,float>)
                allocates_type = BLOCK_REAL;
            else if constexpr (std::is_same_v<T,char>)
                allocates_type = BLOCK_CHAR;
            else if constexpr (std::is_same_v<T,char *>)
                allocates_type = BLOCK_STRING;
            else if constexpr (std::is_same_v<T,std::string>)
                allocates_type = BLOCK_STRING;
            else if constexpr (std::is_same_v<T,bool>)
                allocates_type = BLOCK_BOOL;
            else if constexpr (std::is_same_v<T,long>)
                allocates_type = BLOCK_ADDRESS_INSTR;
            else
                throw std::invalid_argument("TIPO DE BLOQUE INVALIDO");
        };

    public:
        /**
         * @brief Constructor de bloque (vacio)
         */
        LVM_Block()
            : allocates_type(BLOCK_EMPTY), value_allocated(0) {};

        /**
         * @brief Destructor de clase
         */
        ~LVM_Block() = default;
        
        /**
         * @brief Obtiene el valor contenido en el bloque
         * @return Contenido de bloque
         */
        template <typename T>
        T get_value() const {return std::get<T>(value_allocated);};
    
        /**
         * @brief Obtiene el tipo de bloque
         * @return tipo de bloque
         */
        LVM_Block_type_t get_type_of_alloc() const {return allocates_type; };

        /**
         * @brief Obtiene el tipo de bloque en formato string
         * @return tipo de bloque en str
         */
        std::string get_type_of_alloc_str() const;
        
        /**
         * @brief Obtiene el valor de bloque en str
         * @return valor de bloque en str
         */
        std::string get_value_str() const;

        /**
         * @brief Inserta un valor en el bloque
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


#endif //_LAMPORT_LVM_UTILS_BLOCK_DPR_