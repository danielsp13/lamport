/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file chronometer.hpp
 * @author Daniel Perez Ruiz
 * @brief Cronometro de eventos en la ejecucion de LVM
 */

#ifndef _LAMPORT_LVM_TRACKER_CHRONOMETER_DPR_
#define _LAMPORT_LVM_TRACKER_CHRONOMETER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include <sstream>
#include <thread>

using time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;

// ===============================================================

// ----- DEFINICION DE CLASE TRACKER -----

class LVM_Tracker_Chronometer{
    private:
        // -- Flag que indica el estado del cronometro
        bool running = false;
        // -- Flujo de cadena de caracteres para sacar salida de timestamp
        std::ostringstream stream;
        // -- Punto de tiempo inicial
        time_point start_time;
        // -- Punto de tiempo actual
        time_point actual_time;

        /**
         * @brief Constructor de la clase (por defecto)
         */
        LVM_Tracker_Chronometer() = default;

        /**
         * @brief Genera el timestamp en el flujo de strings
         */
        void parse_timestamp();

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static LVM_Tracker_Chronometer& get_instance();

        /**
         * @brief Destructor de la clase (por defecto)
         */
        ~LVM_Tracker_Chronometer() = default;

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Tracker_Chronometer(const LVM_Tracker_Chronometer&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Tracker_Chronometer&) = delete;
        
        /**
         * @brief Inicia el cronometro
         */
        void start();

        /**
         * @brief Genera un timestamp, devolviendo un string con el tiempo transcurrido desde que se inicio el cronometro
         * @return timestamp en formato string
         */
        std::string timestamp();

        /**
         * @brief Detiene el cronometro
         */
        void stop();
};


#endif //_LAMPORT_LVM_TRACKER_CHRONOMETER_DPR_