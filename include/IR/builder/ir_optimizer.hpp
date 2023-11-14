/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_optimizer.hpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del optimizador de codigo intermedio Lineal (IR)
 */

#ifndef _LAMPORT_IR_OPTIMIZER_DPR_
#define _LAMPORT_IR_OPTIMIZER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

// ===============================================================

// ----- DEFINICION DE CLASE OPTIMIZADORA DE CODIGO IR -----

/**
 * @brief Clase que contiene metodos de optimizacion de codigo IR.
 * El objetivo es explorar el AST en favor de poder generar 
 * posteriormente instrucciones IR mas faciles de interpretar
 * en la fase de simulacion
 */
class IR_Optimizer{
    private:
        /**
         * @brief Constructor del optimizador
         */
        IR_Optimizer() {};
    public:
        /**
         * @brief Obtiene la instancia del optimizador de instrucciones IR
         * @return instance
         */
        static IR_Optimizer& get_instance();

        /**
         * @brief Aplica el algoritmo de constant folding a la expresion indiada
         * @param expr : expresion
         * @return expresion reducida
         */
        struct expression * constant_folding(struct expression * expr);

        /**
         * @brief Constructor de copia (eliminado)
         */
        IR_Optimizer(const IR_Optimizer&) = delete;

        /**
         * @brief Operador de asignacion (eliminado)
         */
        void operator=(const IR_Optimizer&) = delete;
};

#endif //_LAMPORT_IR_OPTIMIZER_DPR_