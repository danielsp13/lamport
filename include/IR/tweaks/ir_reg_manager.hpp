/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_reg_manager.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del asignador de registros virtuales para representacion intermedia
 */

#ifndef _LAMPORT_IR_REG_MANAGER_DPR_
#define _LAMPORT_IR_REG_MANAGER_DPR_

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
class IR_Reg_Manager{
    private:
        // Especifica valor inicial de registros de proposito general
        const int STARTING_REG_GENERAL_PURPOSE = 32;
        // Especifica valor inicial/final de registros de valores locales de subprograma
        const int STARTING_REG_SUBPROGRAM_VARS = 0;
        const int ENDING_REG_SUBPROGRAM_VARS = 30;
        // Especifica registro de retorno de funciones
        const int RETURN_REG_SUBPROGRAM_FUNCTION = 31;

        // Variables contadora de registros
        int reg_general_purpose_id = STARTING_REG_GENERAL_PURPOSE;
        int reg_subprogram_vars_id = STARTING_REG_SUBPROGRAM_VARS;
        
        // Flag que especifica si hay reset de registros
        const bool RESET_REGISTERS_AVARIABLE = false;
        /**
         * @brief Constructor por defecto
         */
        IR_Reg_Manager() {};

    public:
        /**
         * @brief Obtiene la instancia del manejador
         * @return instancia
         */
        static IR_Reg_Manager& get_instance();

        /**
         * @brief Obtiene el siguiente registro
         * @return identificador de siguiente registro
         */
        int get_next_general_purpose_register();

        /**
         * @brief Resetea el contador de registro
         */
        void reset_general_purpose_register_counter();

        /**
         * @brief Obtiene el siguiente registro de subprograma
         * @return identificador de siguiente registro (de subprograma)
         */
        int get_next_subprog_register();

        /**
         * @brief Obtiene el registro de retorno de un subprograma (funcion)
         * @return registro de retorno
         */
        int get_return_subprog_register();

        /**
         * @brief Reseta el contador de registros dedicados a subprogramas
         */
        void reset_subprog_register_counter();

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Reg_Manager(const IR_Reg_Manager&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Reg_Manager&) = delete;
};

#endif //_LAMPORT_IR_REG_MANAGER_DPR_