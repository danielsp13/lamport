/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file page_table.hpp
 * @author Daniel Perez Ruiz
 * @brief Simulador de la tabla de paginas de la maquina virtual de lamport
 */

#ifndef _LAMPORT_LVM_PAGE_TABLE_DPR_
#define _LAMPORT_LVM_PAGE_TABLE_DPR_

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

// ----- DEFINICION DE CLASE TABLA DE PAGINAS -----

/**
 * @brief Clase encargada de gestionar la traducción de direcciones virtuales a direcciones físicas en la Máquina Virtual.
 * Esta clase implementa un esquema de segmentación simple, donde distintos segmentos representan literales, variables y etiquetas.
 * Cada segmento tiene un rango predefinido de direcciones virtuales. La tabla mapea direcciones virtuales dentro de un segmento 
 * a direcciones físicas en la memoria de la Máquina Virtual.
 */
class LVM_Page_Table{
    private:
        // -- Tabla de direcciones
        std::map<int,std::map<int,int>> address_table;
        // -- Tabla de direcciones de variables array
        std::map<int,std::multimap<int,int>> address_array_table;


        /**
         * @brief Constructor por defecto
         */
        LVM_Page_Table(){};

        /**
         * @brief Imprime un segmento
         * @param segment : indice de segmento
         * @param os : flujo de salida
         */
        void print_segment(int segment, std::ostream & os = std::cout);

        /**
         * @brief Imprime un segmento (arrays)
         * @param segment : indice de segmento
         * @param os : flujo de salida
         */
        void print_segment_array(int segment, std::ostream & os = std::cout);

    public:
        // -- Variables de segmento
        static const int SEGMENT_FOR_LITERALS = 0;
        static const int SEGMENT_FOR_VARIABLES = 1;
        static const int SEGMENT_FOR_VARIABLES_ARRAY = 2;
        static const int SEGMENT_FOR_LABELS = 3;

        // -- Variables de inicio y fin de memoria fisica
        static const int START_ADDR_FOR_LITERALS = 0;
        static const int END_ADDR_FOR_LITERALS = 999;

        static const int START_ADDR_FOR_VARIABLES = 1000;
        static const int END_ADDR_FOR_VARIABLES = 1999;

        static const int START_ADDR_FOR_VARIABLES_ARRAY = 2000;
        static const int END_ADDR_FOR_VARIABLES_ARRAY = 5999;

        static const int START_ADDR_FOR_LABELS = 6000;
        static const int END_ADDR_FOR_LABELS = 6999;

        /**
         * @brief Obtiene la instancia de la tabla de paginas
         * @return instance
         */
        static LVM_Page_Table& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */ 
        ~LVM_Page_Table() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Page_Table(const LVM_Page_Table&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Page_Table&) = delete;

        /**
         * @brief Sobrecarga del operador de ()
         * @param segment : indice de segmento
         * @param page : indice de pagina
         * @return direccion fisica
         */
        int& operator()(int segment, int page);

        /**
         * @brief Sobrecarga del operador de ()
         * @param segment : indice de segmento
         * @param page : indice de pagina
         * @param offset : desplazamiento en pagina
         * @return direccion fisica
         */
        int& operator()(int segment, int page, int offset);

        /**
         * @brief Sobrecarga del operador de () (constante)
         * @param segment : indice de segmento
         * @param page : indice de pagina
         * @return direccion fisica
         */
        const int operator()(int segment, int page) const;

        /**
         * @brief Sobrecarga del operador de () (constante)
         * @param segment : indice de segmento
         * @param page : indice de pagina
         * @param offset : desplazamiento
         * @return direccion fisica
         */
        const int operator()(int segment, int page, int offset) const;

        /**
         * @brief Imprime el contenido de la tabla de paginas
         * @param os : flujo de impresion
         */
        void print_page_table(std::ostream& os = std::cout);
};

#endif //_LAMPORT_LVM_PAGE_TABLE_DPR_