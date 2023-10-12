/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file memory.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de memoria para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_MEMORY_DPR_
#define _LAMPORT_LVM_MEMORY_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

#include "memory_block.hpp"         ///< Bloque de memoria

// ===============================================================

// ----- DEFINICION DE CLASE MEMORIA -----

/**
 * @brief Clase que representa la simulacion de una memoria. Consta
 * de una serie de posiciones de memoria que almacenan bloques
 */
class LVM_Memory{
    private:
        // -- Memoria
        std::map<int,LVM_Memory_Block> mem;

        /**
         * @brief Constructor de memoria
         */
        LVM_Memory() {};
    public:
        /**
         * @brief Obtiene la instancia de la memoria
         * @return instancia
         */
        static LVM_Memory& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~LVM_Memory() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Memory(const LVM_Memory&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Memory&) = delete;
        
        /**
         * @brief Sobrecarga del operador []
         * @param i : indice de acceso a memoria
         * @return Referencia a bloque de memoria
         */
        LVM_Memory_Block& operator[](int i);

        /**
         * @brief Sobrecarga del operador []
         * @param i : indice de acceso a memoria
         * @return Referencia constante al bloque de memoria
         */
        const LVM_Memory_Block& operator[](int i) const;

        /**
         * @brief Imprime el contenido de la memoria
         * @param os : flujo de salida
         */
        void print_memory(std::ostream& os = std::cout);
};

#endif //_LAMPORT_LVM_MEMORY_DPR_