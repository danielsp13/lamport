/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_ir.hpp
 * @author Daniel Perez Ruiz
 * @brief Gestor de codigo intermedio de interprete lamport
 */

#ifndef _LMP_INTERPRETER_IR_DPR_
#define _LMP_INTERPRETER_IR_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <iostream>
#include <string>
#include <cstring>

#include "IR/ir_builder.hpp"        ///< Constructor de codigo intermedio
#include "lmp_tasker.hpp"           ///< Notificador de eventos

// ===============================================================

// ----- DEFINICION DE CLASE MANEJADORA DE CODIGO IR -----

/**
 * 
 */
class LMP_IR_Manager{
    private:
        // -- Constructor de instrucciones IR
        IR_Builder& ir_builder = IR_Builder::get_instance();
        // -- Notificador de eventos
        LMP_Tasker& tasker = LMP_Tasker::get_instance();

        /**
         * @brief Constructor de la clase
         */
        LMP_IR_Manager() {};
    public:
        /**
         * @brief Obtiene la instancia del manejador
         * @return instance
         */ 
        static LMP_IR_Manager& get_instance();

        /**
         * @brief Inicializa el manejador de codigo intermedio
         * @param verbose_avaiable : flag de impresion de contenido
         * @return exito / fracaso de generacion
         */
        int start(bool verbose_avaiable);

        /**
         * @brief Constructor de copia (eliminado)
         */
        LMP_IR_Manager(const LMP_IR_Manager&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const LMP_IR_Manager&) = delete;
};

#endif //_LMP_INTERPRETER_IR_DPR_