/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file thread_stack.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion de pila de hebra lamport
 */

#ifndef _LAMPORT_LVM_SO_THREAD_STACK_DPR_
#define _LAMPORT_LVM_SO_THREAD_STACK_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <vector>

#include "LVM/CPU/register.hpp"         ///< Registro de CPU
#include "LVM/utils/block.hpp"          ///< Bloque de datos

// ===============================================================

// ----- DEFINICION DE CLASE PILA DE HEBRA -----

class LVM_Thread_Stack{
    private:
        // -- Contenedor pila
        std::vector<LVM_Block> stack;
        // -- Puntero a tope de pila
        int top_pointer;
    
    public:
        /**
         * @brief Constructor por defecto
         */
        LVM_Thread_Stack() = default;

        /**
         * @brief Destructor (por defecto)
         */
        ~LVM_Thread_Stack() = default;

        /**
         * @brief Inserta el contenido de un registro en la pila
         * @param reg : registro
         */
        void push(const LVM_Register& reg);

        /**
         * @brief Inserta la direccion de retorno de subprograma en la pila
         * @param ret_dir : direccion de retorno
         */
        void push_ret_dir(long ret_dir);

        /**
         * @brief Obtiene el tope de la pila y lo elimina
         * @return bloque de datos
         */
        LVM_Block top_and_pop();

        /**
         * @brief Obtiene el tope de la pila y lo elimina, convirtiendo el bloque en un registro
         * @return bloque de datos, en un bloque registro
         */
        LVM_Register top_and_pop_reg();

};

#endif //_LAMPORT_LVM_SO_THREAD_STACK_DPR_