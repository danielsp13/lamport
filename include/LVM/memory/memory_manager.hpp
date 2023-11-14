/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file memory_manager.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de manejador de memoria para la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_MEMORY_MANAGER_DPR_
#define _LAMPORT_LVM_MEMORY_MANAGER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

#include "LVM/memory/initializer.hpp"      ///< Inicializador de memoria
#include "LVM/memory/memory.hpp"           ///< Memoria
#include "LVM/memory/segment_table.hpp"    ///< Tabla de segmentos de memoria
#include "LVM/memory/bounds.hpp"           ///< Registro de limites de memoria de arrays

#include "LVM/tracker/tracker.hpp"  ///< Gestor de ejecucion de Maquina Virtual

// ===============================================================

// ----- DEFINICION DE CLASE MANEJADORA DE MEMORIA -----

class LVM_Memory_Manager{
    private:
        // -- Iniciador de memoria de maquina virtual
        LVM_Initializer& initializer = LVM_Initializer::get_instance();
        // -- Memoria de la maquina virtual
        LVM_Memory& memory = LVM_Memory::get_instance();
        // -- Tabla de segmentos de memoria
        LVM_Segment_Table& segment_table = LVM_Segment_Table::get_instance();
        // -- Comprobador de limites de memoria
        LVM_Bounds& array_bounds = LVM_Bounds::get_instance();

        // -- Gestor de ejecucion de maquina virtual
        LVM_Tracker& tracker = LVM_Tracker::get_instance();
        // -- Cabecera de mensajes de traza de ejecucion de LVM
        const std::string TRACKER_HEADER = "[Mem Manager]: ";
        
        /**
         * @brief Constructor de la clase (por defecto)
         */
        LVM_Memory_Manager() = default;
    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static LVM_Memory_Manager& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~LVM_Memory_Manager() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Memory_Manager(const LVM_Memory_Manager&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Memory_Manager&) = delete;

        /**
         * @brief Realiza un acceso a memoria devolviendo el bloque solicitado
         * @param segment : segmento donde se encuentra el bloque
         * @param virtual_dir : direccion virtual del bloque
         * @param offset : desplazamiento sobre la direccion virtual
         * @return Bloque de memoria solicitado
         */
        LVM_Memory_Block& mem_access(int segment, int virtual_dir, int offset=0);

        /**
         * @brief Realiza un acceso a memoria devolviendo el bloque solicitado
         * @param segment : segmento donde se encuentra el bloque
         * @param virtual_dir : direccion virtual del bloque
         * @param offset : desplazamiento sobre la direccion virtual
         * @return Bloque de memoria solicitado
         */
        const LVM_Memory_Block& mem_access(int segment, int virtual_dir, int offset=0) const;

        /**
         * @brief Obtiene la direccion fisica a partir de la virtual
         * @param segment : segmento virtual
         * @param virtual_dir : direccion virtual
         * @param offset : desplazamiento
         * @return direccion fisica
         */
        int get_phisical_addr(int segment, int virtual_dir, int offset);

        /**
         * @brief Comprueba si la direccion fisica esta disponible
         * @param virtual_segment : segmento virtual
         * @param virtual_dir : direccion virtual
         * @param offset : desplazamiento
         * @return TRUE si la direccion fisica existe, FALSE en otro caso
         */
        bool check_phisical_addr(int virtual_segment, int virtual_dir, int offset=0);

        /**
         * @brief Comprueba si un acceso a posicion de array es valido
         * @param virtual_segment : segmento virtual de memoria
         * @param virtual_dir : direccion virtual base de array
         * @param offset_dir : desplazamiento desde base virtual
         */
        void check_array_bounds(int virtual_segment, int virtual_dir, int offset_dir);

        /**
         * @brief Obtiene el inicializador de memoria del sistema
         * @return iniciador de memoria
         */
        LVM_Initializer& get_initializer() { return initializer; };

        /**
         * @brief Imprime el contenido de la tabla de segmentos
         * @param os : flujo de impresion
         */
        void print_segment_table(std::ostream& os = std::cout);

        /**
         * @brief Imprime el contenido de la memoria
         * @param os : flujo de impresion
         */
        void print_memory(std::ostream& os = std::cout);
};

#endif //_LAMPORT_LVM_MEMORY_MANAGER_DPR_
