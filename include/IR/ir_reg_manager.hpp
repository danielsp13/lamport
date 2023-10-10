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
#include <stack>

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
        // Flag que especifica si hay reset de registros
        const bool RESET_REGISTERS_AVARIABLE = false;
        // Pila de indices de registros para llamadas a procedimientos
        std::stack<int> reg_stack;

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
        int get_next_register() {return this->reg_counter++; };

        /**
         * @brief Resetea el contador de registro
         */
        void reset_register_counter() { RESET_REGISTERS_AVARIABLE ? this->reg_counter = 0 : false ;};

        /**
         * @brief Inserta un indice de registro en la pila
         * @param id_reg : indice de registro en la pila
         */
        void push_reg_into_stack(int id_reg) {
            reg_stack.push(id_reg); 
        };

        /**
         * @brief Retira el indice de registro del tope de la pila
         * @return indice de registro del tope de pila
         */
        int pop_reg_from_stack() {
            int top = reg_stack.top();
            reg_stack.pop();
            return top;
        }; 

        /**
         * @brief Limpia la pila de registros
         */
        void clean_stack() {
            while(!reg_stack.empty())
                reg_stack.pop();
        };

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