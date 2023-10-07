/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_optimizer.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del optimizador de codigo intermedio Lineal (IR)
 */

#include "IR/ir_optimizer.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_OPTIMIZER] -----

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_OPTIMIZER] -----

IR_Optimizer& IR_Optimizer::get_instance(){
    static IR_Optimizer instance;
    return instance;
}

struct expression * IR_Optimizer::constant_folding(struct expression * expr){
    // -- Comprobar que hay expresion
    if(!expr)
        return nullptr;
    

    // -- Rotar en funcion del tipo de expresion
    switch (expr->kind)
    {
    case EXPR_BINARY:
    {
        // -- Explorar miembros de operacion binaria
        expr->expr.expression_binary_operation.left = constant_folding(expr->expr.expression_binary_operation.left);
        expr->expr.expression_binary_operation.right = constant_folding(expr->expr.expression_binary_operation.right);

        // -- Comprobar el tipo de expresion de ambos miembros
        bool left_is_literal = expr->expr.expression_binary_operation.left->kind == EXPR_LITERAL;
        bool right_is_literal = expr->expr.expression_binary_operation.right->kind == EXPR_LITERAL;
        if(left_is_literal && right_is_literal){
            // -- Comprobar el tipo de literal que es
            bool left_is_integer = expr->expr.expression_binary_operation.left->expr.expression_literal.kind == EXPR_LITERAL_INTEGER;
            bool right_is_integer = expr->expr.expression_binary_operation.right->expr.expression_literal.kind == EXPR_LITERAL_INTEGER;

            // -- Operaciones en caso de operaciones entre enteros
            if(left_is_integer && right_is_integer){
                // -- Realizar operacion
                int left_value = expr->expr.expression_binary_operation.left->expr.expression_literal.value.integer_literal;
                int right_value = expr->expr.expression_binary_operation.right->expr.expression_literal.value.integer_literal;

                // -- Comprobar el tipo de operacion
                int resultado = 0;
                switch (expr->expr.expression_binary_operation.kind)
                {
                case EXPR_ADD:
                {
                    resultado = left_value + right_value;
                    break;
                }
                case EXPR_SUB:
                {
                    resultado = left_value - right_value;
                    break;
                }
                case EXPR_MULT:
                {
                    resultado = left_value * right_value;
                    break;
                }
                case EXPR_DIV:
                {
                    resultado = left_value / right_value;
                    break;
                }
                case EXPR_MOD:
                {
                    resultado = left_value % right_value;
                    break;
                }
                
                default:
                    break;
                }

                // -- Crear nueva expresion
                struct expression * folded_expr = create_expression_literal_integer(resultado);

                // -- Retornar nueva expresion
                return folded_expr;
            }
            // -- Operaciones en caso de operaciones entre reales
            else{
                // -- Realizar operacion
                float left_value = expr->expr.expression_binary_operation.left->expr.expression_literal.value.real_literal;
                float right_value = expr->expr.expression_binary_operation.right->expr.expression_literal.value.real_literal;

                // -- Comprobar el tipo de operacion
                float resultado = 0;
                switch (expr->expr.expression_binary_operation.kind)
                {
                case EXPR_ADD:
                {
                    resultado = left_value + right_value;
                    break;
                }
                case EXPR_SUB:
                {
                    resultado = left_value - right_value;
                    break;
                }
                case EXPR_MULT:
                {
                    resultado = left_value * right_value;
                    break;
                }
                case EXPR_DIV:
                {
                    resultado = left_value / right_value;
                    break;
                }
                
                default:
                    break;
                }

                // -- Crear nueva expresion
                struct expression * folded_expr = create_expression_literal_real(resultado);

                // -- Retornar nueva expresion
                return folded_expr;
            }
        }

        break;
    }
    case EXPR_UNARY:
    {
        // -- Explorar miembros de operacion unaria
        expr->expr.expression_unary_operation.left = constant_folding(expr->expr.expression_unary_operation.left);

        // -- Comprobar el tipo de expresion de operacion
        bool is_literal = expr->expr.expression_unary_operation.left->kind == EXPR_LITERAL;
        if(is_literal){
            // -- Comprobar si es literal entero
            bool is_integer = expr->expr.expression_unary_operation.left->expr.expression_literal.kind == EXPR_LITERAL_INTEGER;
            // -- Realizar operacion unaria si es entero
            if(is_integer){
                int value = expr->expr.expression_unary_operation.left->expr.expression_literal.value.integer_literal;
                int resultado = 0;


                // -- Comprobar tipo de operacion
                switch (expr->expr.expression_unary_operation.kind)
                {
                case EXPR_NEGATIVE:
                    resultado = -value;
                    break;
                
                default:
                    break;
                }

                // -- Crear nueva expresion
                struct expression * folded_expr = create_expression_literal_integer(resultado);

                // -- Retornar nueva expresion
                return folded_expr;
            }
            // -- Realizar operacion unaria si es flotante
            else{
                float value = expr->expr.expression_unary_operation.left->expr.expression_literal.value.real_literal;
                float resultado = 0;

                // -- Comprobar tipo de operacion
                switch (expr->expr.expression_unary_operation.kind)
                {
                case EXPR_NEGATIVE:
                    resultado = -value;
                    break;
                
                default:
                    break;
                }

                // -- Crear nueva expresion
                struct expression * folded_expr = create_expression_literal_real(resultado);

                // -- Retornar nueva expresion
                return folded_expr;
            }
        }

        break;
    }
    case EXPR_IDENTIFIER:
    {
        break;
    }
    case EXPR_LITERAL:
    {
        break;
    }
    case EXPR_FUNCTION_INV:
    {
        break;
    }
    case EXPR_GROUPED:
    {   
        return constant_folding(expr->expr.grouped_expression);
        break;
    }
    
    default:
        break;
    }

    // -- Retornar expresion original en caso de que no se puedan realizar optimizaciones
    return expr;
}