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

// ===============================================================

// ----- DEFINICION DE CLASE ASIGNADORA DE REGISTROS IR -----

/**
 * @brief Clase encargada de asignar registros virtuales en las instrucciones
 * IR donde se requieran
 */
class IR_Reg_Manager{
    private:
        // Variable contadora de registros
        int reg_counter = 0;

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
        int get_next_register();

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