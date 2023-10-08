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

        /**
         * @brief Constructor por defecto
         */
        LVM_Page_Table(){};
    public:
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
         * @brief Sobrecarga del operador de () (constante)
         * @param segment : indice de segmento
         * @param page : indice de pagina
         * @return direccion fisica
         */
        const int operator()(int segment, int page) const;

        /**
         * @brief Imprime el contenido de la tabla de paginas
         * @param os : flujo de impresion
         */
        void print_page_table(std::ostream& os = std::cout);
};

#endif //_LAMPORT_LVM_PAGE_TABLE_DPR_