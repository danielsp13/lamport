/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file segment_table.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de la tabla de segmentos de la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_SEGMENT_TABLE_
#define _LAMPORT_LVM_SEGMENT_TABLE_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <variant>

// ===============================================================

// ----- DEFINICION DE CLASE TABLA DE SEGMENTOS -----

/**
 * @brief Clase encargada de gestionar la traducción de direcciones virtuales a direcciones físicas en la Máquina Virtual.
 * Esta clase implementa un esquema de segmentación simple, donde distintos segmentos representan literales, variables y etiquetas.
 * Cada segmento tiene un rango predefinido de direcciones virtuales. La tabla mapea direcciones virtuales dentro de un segmento 
 * a direcciones físicas en la memoria de la Máquina Virtual.
 */
class LVM_Segment_Table{
    private:
        // -- Tabla de direcciones
        std::map<int,std::pair<std::string,std::multimap<int,int>>> address_table;

        /**
         * @brief Constructor por defecto
         */
        LVM_Segment_Table(){
            new_segment(SEGMENT_FOR_LITERALS,"literales");
            new_segment(SEGMENT_FOR_LABELS,"etiquetas");
            new_segment(SEGMENT_FOR_GLOBAL_VARIABLES,"variables globales");
        };

        /**
         * @brief Imprime un segmento
         * @param segment : indice de segmento
         * @param os : flujo de salida
         */
        void print_segment(int segment, std::ostream & os = std::cout);

        /**
         * @brief Obtiene la direccion fisica del segmento especificado
         * @param segment : segmento
         * @param virtual_dir : direccion virtual
         * @param offset : desplazamiento sobre direccion virtual
         * @return referencia al indice de direccion fisica
         */
        int& get_phisical_addr(int segment, int virtual_dir, int offset=0);

        /**
         * @brief Obtiene la direccion fisica del segmento especificado
         * @param segment : segmento
         * @param virtual_dir : direccion virtual
         * @param offset : desplazamiento sobre direccion virtual
         * @return indice de direccion fisica
         */
        const int get_phisical_addr(int segment, int virtual_dir, int offset=0) const;

        // -- Total de segmentos dedicados a threads
        int total_segments_for_threads = SEGMENT_FOR_THREADS;

    public:
        // -- Variables de segmento
        static const int SEGMENT_FOR_LITERALS = 0;
        static const int SEGMENT_FOR_LABELS = 1;
        static const int SEGMENT_FOR_GLOBAL_VARIABLES = 2;
        static const int SEGMENT_FOR_THREADS = 3;

        // -- Variables de inicio y fin de memoria fisica
        static const int START_ADDR_FOR_LITERALS = 0;
        static const int END_ADDR_FOR_LITERALS = 999;

        static const int START_ADDR_FOR_LABELS = 1000;
        static const int END_ADDR_FOR_LABELS = 1999;

        static const int START_ADDR_FOR_VARIABLES = 2000;

        /**
         * @brief Obtiene la instancia de la tabla de paginas
         * @return instance
         */
        static LVM_Segment_Table& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */ 
        ~LVM_Segment_Table() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Segment_Table(const LVM_Segment_Table&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Segment_Table&) = delete;

        /**
         * @brief Incluye un nuevo segmento en la tabla de segmentos
         * @param segment : indice de segmento
         * @param segment_name : nombre de segmento
         */
        void new_segment(int segment, std::string segment_name);

        /**
         * @brief Obtiene un nuevo indice de segmento para un thread
         * @return nuevo segmento
         */
        int get_new_segment_for_thread() { return this->total_segments_for_threads++; };

        /**
         * @brief Sobrecarga del operador de ()
         * @param segment : indice de segmento
         * @param virtual_dir : indice virtual
         * @return direccion fisica
         */
        int& operator()(int segment, int virtual_dir);

        /**
         * @brief Sobrecarga del operador de ()
         * @param segment : indice de segmento
         * @param virtual_dir : indice virtual
         * @param offset : desplazamiento en pagina
         * @return direccion fisica
         */
        int& operator()(int segment, int virtual_dir, int offset);

        /**
         * @brief Sobrecarga del operador de () (constante)
         * @param segment : indice de segmento
         * @param virtual_dir : indice virtual
         * @return direccion fisica
         */
        const int operator()(int segment, int virtual_dir) const;

        /**
         * @brief Sobrecarga del operador de () (constante)
         * @param segment : indice de segmento
         * @param virtual_dir : indice virtual
         * @param offset : desplazamiento
         * @return direccion fisica
         */
        const int operator()(int segment, int virtual_dir, int offset) const;

        /**
         * @brief Imprime el contenido de la tabla de segmentos
         * @param os : flujo de impresion
         */
        void print_segment_table(std::ostream& os = std::cout);
};

#endif //_LAMPORT_LVM_SEGMENT_TABLE_