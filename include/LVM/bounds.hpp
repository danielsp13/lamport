/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file bounds.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de comprobador de limites de arrays
 */

#ifndef _LAMPORT_LVM_BOUNDS_DPR_
#define _LAMPORT_LVM_BOUNDS_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>

// ===============================================================

// ----- DEFINICION DE CLASE BOUNDS -----

class LVM_Bounds{
    private:
        // --- Registro de direcciones virtuales + limites
        std::map<int,int> upper_bounds;
        // --- Mensaje de excepcion
        const std::string EXCEP_OUT_BOUNDS_MSG = "INDICE DE ACCESO A ARRAY FUERA DE RANGO.";

        /**
         * @brief Constructor de clase (por defecto)
         */
        LVM_Bounds() = default;

    public:
        /**
         * @brief Obtiene la instancia de clase
         * @return instancia
         */
        static LVM_Bounds& get_instance();

        /**
         * @brief Destructor de clase
         */
        ~LVM_Bounds() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Bounds(const LVM_Bounds&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Bounds&) = delete;

        /**
         * @brief Registra un nuevo limite de acceso
         * @param virtual_addr : direccion virtual
         * @param last_phisical_addr : limite (direccion de memoria fisica)
         */
        void insert_upper_bounds(int virtual_addr, int last_phisical_addr) { upper_bounds[virtual_addr] = last_phisical_addr; };

        /**
         * @brief Comprueba si un offset de acceso es negativo
         * @param offset : offset
         */
        void check_if_is_negative_offset(int offset);

        /**
         * @brief Comprueba si un offset de acceso excede su rango
         * @param virtual_addr : direccion virtual de array
         * @param offset : desplazamiento realizado
         * @param phisical_addr : direccion fisica
         */
        void check_if_exceds_bound(int virtual_addr, int phisical_addr, int offset);

        /**
         * @brief Imprime el contenido de la tabla de limites
         * @param os : flujo de salida
         */
        void print_bounds(std::ostream & os = std::cout);
};

#endif //_LAMPORT_LVM_BOUNDS_DPR_