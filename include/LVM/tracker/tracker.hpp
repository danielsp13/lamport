/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file tracker.hpp
 * @author Daniel Perez Ruiz
 * @brief Gestor de seguimiento de ejecucion de LVM
 */

#ifndef _LAMPORT_LVM_TRACKER_DPR_
#define _LAMPORT_LVM_TRACKER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <vector>
#include <string>

#include "chronometer.hpp"      ///< Cronometro de eventos

// ===============================================================

// ----- DEFINICION DE CLASE TRACKER -----

class LVM_Tracker{
    private:
        // -- Flag que especifica si el tracking de LVM esta disponible
        bool activated = false;

        // -- Vector con el contenido de la ejecucion de la maquina virtual
        std::vector<std::string> trace;

        // -- Vector con el contenido de la ejecucion de un bloque de CPU
        std::vector<std::string> CPU_cycle_trace;
        
        // -- Cronometro
        LVM_Tracker_Chronometer& chrono = LVM_Tracker_Chronometer::get_instance();

        // -- Flag que indica si el modo resumido esta activado
        const bool RESUMED_MODE = true;
        // -- Flag que indica si el modo full esta activado
        const bool FULL_MODE = false;

        /**
         * @brief Constructor de clase. Inicializa el cronometro
         */
        LVM_Tracker() = default;

    public:
        /**
         * @brief Obtiene la instancia de la clase
         * @return instance
         */
        static LVM_Tracker& get_instance();

        /**
         * @brief Destructor de la clase
         */
        ~LVM_Tracker() { chrono.stop(); };

        /**
         * @brief Constructor de copia (eliminado)
         */
        LVM_Tracker(const LVM_Tracker&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LVM_Tracker&) = delete;

        /**
         * @brief Activa el gestor de ejecucion de LVM
         */
        void activate();

        /**
         * @brief Inserta un nuevo mensaje en la traza de ejecucion (junto a su timestamp)
         * @param msg : mensaje
         * @param resumed : flag que indica si se debe incluir el mensaje o no
         */
        void track(std::string msg, bool resumed = false);

        /**
         * @brief Confirma la traza de ejecucion de un ciclo de CPU
         */
        void confirm_track_cycle();

        /**
         * @brief Imprime la traza de ejecucion de la maquina virtual
         * @param os : flujo de salida (por defecto cout)
         */
        void print_trace(std::ostream& os = std::cout);

        /**
         * @brief Imprime la traza de ejecucion de un ciclo de CPU
         * @param os : flujo de salida (por defecto cout)
         */
        void print_cpu_cycle_trace(std::ostream& os = std::cout);
};

#endif //_LAMPORT_LVM_TRACKER_DPR_