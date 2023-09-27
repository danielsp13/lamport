/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file label.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio  (Etiquetas de IR Lineal)
 */

#ifndef _LAMPORT_IR_LABEL_DPR_
#define _LAMPORT_IR_LABEL_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>

// ===============================================================

// ----- DEFINICION DE CLASE ETIQUETA -----

/**
 * @brief Clase que representa una etiqueta en el lenguaje de representacion
 * intermedia
 */
class IR_label{
    private:
        int id;                 ///< Identificador de etiqueta
        std::string label;      ///< Etiqueta

    public:
        /**
         * @brief Constructor de etiqueta
         * @param id : identificador de etiqueta
         */
        IR_label(int id) : id(id), label("L" + std::to_string(id)) {};

        /**
         * @brief Obtiene el identificador de etiqueta
         * @return id de etiqueta
         */
        int get_id() {return id; };

        /**
         * @brief Obtiene el nombre de etiqueta
         * @return nombre de etiqueta
         */
        std::string get_label() {return label;};
};

#endif //_LAMPORT_IR_LABEL_DPR_
