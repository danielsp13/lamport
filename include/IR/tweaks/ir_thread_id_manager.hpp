/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_thread_id_manager.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del asignador de registros virtuales para representacion intermedia
 */

#ifndef _LAMPORT_IR_THREAD_ID_MANAGER_DPR_
#define _LAMPORT_IR_THREAD_ID_MANAGER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <string>


// ===============================================================

// ----- DEFINICION DE CLASE ASIGNADORA DE REGISTROS IR -----

/**
 * @brief Clase encargada de asignar registros virtuales en las instrucciones
 * IR donde se requieran
 */
class IR_Thread_Id_Manager{
    private:
        // -- ID inicial
        const int STARTING_ID = 0;

        // Variables contadora de id de hebras
        int id_thread = STARTING_ID;
        int last_id_thread = STARTING_ID;

        /**
         * @brief Constructor por defecto
         */
        IR_Thread_Id_Manager() {};

    public:
        /**
         * @brief Obtiene la instancia del manejador
         * @return instancia
         */
        static IR_Thread_Id_Manager& get_instance();

        /**
         * @brief Obtiene el id de hebra
         */
        int get_id();

        /**
         * @brief Obtiene el ultimo id de hebra
         */
        int get_last_id();

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Thread_Id_Manager(const IR_Thread_Id_Manager&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Thread_Id_Manager&) = delete;
};

#endif //_LAMPORT_IR_THREAD_ID_MANAGER_DPR_