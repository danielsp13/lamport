/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file type_checking.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para implementar comprobacion de
 * tipos en el AST
 */

#include "semantic/type_checking.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE TYPE CHECKING (EXPRESIONES) -----

struct type * typecheck_expression(struct expression *expr){
    // -- Comprobar que hay tipo
    if(!expr)
        return NULL;

    // -- Retornar tipo en funcion del tipo de expresion
    switch (expr->kind)
    {
    case EXPR_BINARY:
    {
        return typecheck_expression_binary(expr);
        break;
    }
    case EXPR_UNARY:
    {
        return typecheck_expression_unary(expr);
        break;
    }
    case EXPR_IDENTIFIER:
    {
        return typecheck_expression_identifier(expr);
        break;
    }
    case EXPR_LITERAL:
    {
        return typecheck_expression_literal(expr);
        break;
    }
    case EXPR_FUNCTION_INV:
    {
        return typecheck_expression_function_inv(expr);
        break;
    }
    case EXPR_GROUPED:
    {
        return typecheck_expression_grouped(expr);
        break;
    }
    default:
    {
        return NULL;
        break;
    }
    }
}

struct type * typecheck_expression_binary(struct expression *expr){
    // -- Definir tipo resultado
    struct type * result = NULL;

    const unsigned long def_line = expr->expr.expression_binary_operation.line;
    char *action = expr->expr.expression_binary_operation.action;
    struct type * type_left = typecheck_expression(expr->expr.expression_binary_operation.left);
    struct type * type_right = typecheck_expression(expr->expr.expression_binary_operation.right);

    // -- Comprobar que hay tipos de operandos
    if(!type_left || !type_right)
        return result;

    // -- Deliberar en funcion del tipo de operacion binaria
    switch (expr->expr.expression_binary_operation.kind)
    {
    case EXPR_ADD:
    {
        result = typecheck_expression_binary_arithmetic(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_SUB:
    {
        result = typecheck_expression_binary_arithmetic(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_MULT:
    {
        result = typecheck_expression_binary_arithmetic(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_DIV:
    {
        result = typecheck_expression_binary_arithmetic(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_MOD:
    {
        result = typecheck_expression_binary_arithmetic(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_GT:
    {
        result = typecheck_expression_binary_comparison(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_LT:
    {
        result = typecheck_expression_binary_comparison(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_GTE:
    {
        result = typecheck_expression_binary_comparison(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_LTE:
    {
        result = typecheck_expression_binary_comparison(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_EQ:
    {
        result = typecheck_expression_binary_comparison_equality(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_NEQ:
    {
        result = typecheck_expression_binary_comparison_equality(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_AND:
    {
        result = typecheck_expression_binary_comparison(action,type_left,type_right,def_line);
        break;
    }
    case EXPR_OR:
    {
        result = typecheck_expression_binary_comparison(action,type_left,type_right,def_line);
        break;
    }
    default:
        break;
    }

    // -- Liberar tipos de operandosas
    free_type(type_left); type_left = NULL;
    free_type(type_right); type_right = NULL;

    // -- retornar resultado
    return result;
}

struct type * typecheck_expression_unary(struct expression *expr){
    // -- Definir tipo resultado
    struct type * result = NULL;

    const unsigned long def_line = expr->expr.expression_unary_operation.line;
    char *action = expr->expr.expression_unary_operation.action;
    struct type * type_left = typecheck_expression(expr->expr.expression_unary_operation.left);

    // -- Comprobar que hay tipos de operandos
    if(!type_left)
        return result;

    // -- Deliberar en funcion del tipo de operacion binaria
    switch (expr->expr.expression_binary_operation.kind)
    {
    case EXPR_NEGATIVE:
    {
        result = typecheck_expression_unary_arithmetic(action,type_left,def_line);
        break;
    }
    case EXPR_NOT:
    {
        result = typecheck_expression_unary_logical(action,type_left,def_line);
        break;
    }
    default:
        break;
    }

    // -- Liberar tipos de operandos
    free_type(type_left); type_left = NULL;

    // -- retornar resultado
    return result;
}

struct type * typecheck_expression_identifier(struct expression *expr){
    // -- Definir tipo resultado
    struct type * result = NULL;

    // -- Obtener el tipo de dato a traves del simbolo registrado
    if(expr->expr.expression_identifier.symb->type)
        result = copy_type(expr->expr.expression_identifier.symb->type);

    // -- retornar resultado
    return result;
}

struct type * typecheck_expression_literal(struct expression *expr){
    // -- Definir tipo resultado
    struct type * result = NULL;

    // -- Decidir tipo en funcion del literal
    switch (expr->expr.expression_literal.kind)
    {
    case EXPR_LITERAL_INTEGER:
    {
        result = create_basic_type(TYPE_INTEGER);
        break;
    }
    case EXPR_LITERAL_REAL:
    {
        result = create_basic_type(TYPE_REAL);
        break;
    }
    case EXPR_LITERAL_CHARACTER:
    {
        result = create_basic_type(TYPE_CHAR);
        break;
    }
    case EXPR_LITERAL_STRING:
    {
        result = create_basic_type(TYPE_STRING);
        break;
    }
    case EXPR_LITERAL_BOOLEAN:
    {
        result = create_basic_type(TYPE_BOOLEAN);
        break;
    }
    
    default:
        break;
    }

    // -- retornar resultado
    return result;
}

struct type * typecheck_expression_function_inv(struct expression *expr){
    // -- Definir tipo resultado
    struct type * result = NULL;

    // -- Obtener el tipo de dato a traves del simbolo registrado
    result = copy_type(expr->expr.expression_function_inv.symb->type);

    // -- Realizar typechecking a los argumentos de la invocacion de funcion
    struct expression *current_argument = expr->expr.expression_function_inv.arguments_list;
    struct type *current_type_parameter = expr->expr.expression_function_inv.symb->list_type_parameters;
    unsigned int position = 0;

    struct type * type_a = NULL;
    while(current_argument && current_type_parameter){
        type_a = typecheck_expression(current_argument);
        if(!equals_type(type_a,current_type_parameter)){
            // -- Realizar handling de error: tipo de argumento no valido
            struct error *err = create_error_semantic_unmatched_types_expression_function_inv(expr->expr.expression_function_inv.line,expr->expr.expression_function_inv.function_name,position,expr->kind_str,current_type_parameter->kind_str);
            add_error_semantic_to_list(err);
        }

        current_argument = current_argument->next;
        current_type_parameter = current_type_parameter->next;
        position++;

        free_type(type_a); type_a = NULL;
    }

    // -- retornar resultado
    return result;
}

struct type * typecheck_expression_grouped(struct expression *expr){
    // -- Definir tipo resultado
    struct type * result = NULL;

    // -- Evaluar expresion
    result = typecheck_expression(expr->expr.grouped_expression);

    // -- retornar resultado
    return result;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE TYPE CHECKING (EXPRESIONES : DELIBERACIONES) -----

struct type * typecheck_expression_binary_arithmetic(char *action, struct type *type_left, struct type *type_right,unsigned long line){
    // -- Caso 1: Ambos tipos son integer
    if(type_left->kind == TYPE_INTEGER && type_right->kind == TYPE_INTEGER)
        return create_basic_type(TYPE_INTEGER);
    // -- Caso 2: Ambos tipos son real
    if(type_left->kind == TYPE_REAL && type_right->kind == TYPE_REAL)
        return create_basic_type(TYPE_REAL);
    // -- Caso 3: Operando izquierdo es de tipo array
    if(type_left->kind == TYPE_ARRAY){
        // -- Comprobar comparacion con subtipo (integer con integer)
        if(type_left->subtype->kind == TYPE_INTEGER && type_right->kind == TYPE_INTEGER)
            return create_basic_type(TYPE_INTEGER);
        // -- Comprobar comparacion con subtipo (real con real)
        if(type_left->subtype->kind == TYPE_REAL && type_right->kind == TYPE_REAL)
            return create_basic_type(TYPE_REAL);
    }
    // -- Caso 4: Operando derecho es de tipo array
    if(type_right->kind == TYPE_ARRAY){
        // -- Comprobar comparacion con subtipo (integer con integer)
        if(type_left->kind == TYPE_INTEGER && type_right->subtype->kind == TYPE_INTEGER)
            return create_basic_type(TYPE_INTEGER);
        // -- Comprobar comparacion con subtipo (real con real)
        if(type_left->kind == TYPE_REAL && type_right->subtype->kind == TYPE_REAL)
            return create_basic_type(TYPE_REAL);
    }
    
    
    // -- Caso 3: Error de tipos, incluir error semantico
    struct error * err = create_error_semantic_unmatched_types_expression_binary(line,type_left->kind_str,type_right->kind_str,action);
    add_error_semantic_to_list(err);

    // -- Retornar INTEGER (aunque se haya producido un error)
    return create_basic_type(TYPE_INTEGER);
}

struct type * typecheck_expression_binary_comparison(char *action, struct type *type_left, struct type *type_right,unsigned long line){
    // -- Caso 1: Ambos tipos son iguales
    if(type_left->kind == type_right->kind){
        // -- Comprobar ademas que son numeros (o enteros o reales)
        if(type_left->kind == TYPE_INTEGER || type_left->kind == TYPE_REAL){
            return create_basic_type(TYPE_BOOLEAN);
        }
    }

    // -- Caso 2: Error de tipos, incluir error semantico
    struct error * err = create_error_semantic_unmatched_types_expression_binary(line,type_left->kind_str,type_right->kind_str,action);
    add_error_semantic_to_list(err);

    // -- Retornar BOOLEAN (aunque se haya producido un error)
    return create_basic_type(TYPE_BOOLEAN);
}

struct type * typecheck_expression_binary_comparison_equality(char *action, struct type *type_left, struct type *type_right,unsigned long line){
    // -- Caso 1: Ambos tipos son iguales
    if(type_left->kind == type_right->kind){
        return create_basic_type(TYPE_BOOLEAN);
    }

    // -- Caso 2: Error de tipos, incluir error semantico
    struct error * err = create_error_semantic_unmatched_types_expression_binary(line,type_left->kind_str,type_right->kind_str,action);
    add_error_semantic_to_list(err);

    // -- Retornar BOOLEAN (aunque se haya producido un error)
    return create_basic_type(TYPE_BOOLEAN);
}

struct type * typecheck_expression_unary_arithmetic(char *action, struct type *type, unsigned long line){
    // -- Caso 1: Es de tipo integer
    if(type->kind == TYPE_INTEGER)
        return create_basic_type(TYPE_INTEGER);
    // -- Caso 2: Es de tipo real
    if(type->kind == TYPE_REAL)
        return create_basic_type(TYPE_REAL);
    // -- Caso 3: Es de tipo array
    if(type->kind == TYPE_ARRAY){
        // -- Caso 3.1: Es de tipo integer
        if(type->subtype->kind == TYPE_INTEGER)
            return create_basic_type(TYPE_INTEGER);
        // -- Caso 3.2: Es de tipo real
        if(type->subtype->kind == TYPE_REAL)
            return create_basic_type(TYPE_REAL);
    }

    // -- Caso 3: Error de tipos, incluir error semantico
    struct error * err = create_error_semantic_unmatched_types_expression_unary(line,type->kind_str,action);
    add_error_semantic_to_list(err);

    // -- Retornar INTEGER (aunque haya producido un error)
    return create_basic_type(TYPE_INTEGER);
}

struct type * typecheck_expression_unary_logical(char *action, struct type *type, unsigned long line){
    // -- Caso 1: Es de tipo boolean
    if(type->kind == TYPE_BOOLEAN)
        return create_basic_type(TYPE_BOOLEAN);
    
    // -- Caso 3: Error de tipos, incluir error semantico
    struct error * err = create_error_semantic_unmatched_types_expression_unary(line,type->kind_str,action);
    add_error_semantic_to_list(err);

    // -- Retornar INTEGER (aunque haya producido un error)
    return create_basic_type(TYPE_BOOLEAN);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE TYPE CHECKING (NODOS AST) -----

void typecheck_declaration(struct declaration *decl){
    // -- Comprobar si la declaracion es de un array
    if(decl->type->kind == TYPE_ARRAY){
        // -- Comprobar si la expresion del tipo de array pertenece a un literal
        if(decl->type->size->kind != EXPR_LITERAL){
            // -- Incluir error en la lista de errores semanticos
            struct error *err = create_error_semantic_invalid_static_array(decl->line);
            add_error_semantic_to_list(err);
        }

        // -- Comprobar si la expresion de size de array es entera
        struct type * type_size_arr = typecheck_expression(decl->type->size);
        struct type * expected_type = create_basic_type(TYPE_INTEGER);

        if(!equals_type(expected_type,type_size_arr)){
            // -- Incluir error en la lista de errores semanticos
            struct error *err = create_error_semantic_invalid_array_size(decl->line,type_size_arr->kind_str);
            add_error_semantic_to_list(err);
        }

        // -- Liberar memoria de tipos
        free_type(type_size_arr); free_type(expected_type);
    }

    // Comprobar que tiene valor de inicializacion
    if(!decl->value)
        return;

    // -- En ese caso, comprobar que el tipo de declaracion coincide con el tipo de dato de la expresion
    struct type * type_expr = typecheck_expression(decl->value);

    if(!equals_type(decl->type,type_expr)){
        // -- Incluir error en la lista de errores semanticos
        struct error *err = create_error_semantic_unmatched_types_declaration(decl->line,decl->type->kind_str,type_expr->kind_str);
        add_error_semantic_to_list(err);
    }

    // -- Liberar memoria de tipo
    free_type(type_expr);

}

void typecheck_statement(struct statement *stmt){
    if(!stmt)
        return;
    
    struct type * type_a = NULL; struct type * type_b = NULL; 
    struct type * type_c = NULL; struct type * type_d = NULL;

    // -- Realizar comprobacion en funcion del tipo de sentencia
    switch (stmt->kind)
    {
    case STMT_ASSIGNMENT:
    {
        // -- Si es una variable indexada, comprobar que el indexador es un entero
        if(stmt->stmt.statement_assignment.index_expr){
            type_c = typecheck_expression(stmt->stmt.statement_assignment.index_expr);
            if(type_c->kind != TYPE_INTEGER){
                // -- Handling de error: indexador de variable array no integer
                struct error *err = create_error_semantic_unmatched_types_statement_assignment(UNMATCHED_TYPES_STMT_ASSIGNMENT_INDEX,stmt->stmt.statement_assignment.line,type_c->kind_str,NULL);
                add_error_semantic_to_list(err);
            }
        }
        else if(stmt->stmt.statement_assignment.symb->type->kind == TYPE_ARRAY){
            // -- Handling de error: no hay indexacion
            struct error *err = create_error_semantic_unmatched_types_statement_assignment(UNMATCHED_TYPES_STMT_ASSIGNMENT_ARRAY_NO_INDEX,stmt->stmt.statement_assignment.line,NULL,NULL);
            add_error_semantic_to_list(err);
        }
        

        // -- Comprobar tipo de dato de asignacion
        type_a = copy_type(stmt->stmt.statement_assignment.symb->type);
        type_b = typecheck_expression(stmt->stmt.statement_assignment.expr);

        if(!equals_type(type_a,type_b)){
            // -- Handling de error: asignacion de expresion a variable mismatch
            struct error *err = create_error_semantic_unmatched_types_statement_assignment(UNMATCHED_TYPES_STMT_ASSIGNMENT,stmt->stmt.statement_assignment.line,type_a->kind_str,type_b->kind_str);
            add_error_semantic_to_list(err);
        }

        // -- Liberar tipos
        free_type(type_a); free_type(type_b); free_type(type_c);

        break;
    }
    case STMT_WHILE:
    {
        // -- Comprobar que la condicion del while es booleana
        type_a = typecheck_expression(stmt->stmt.statement_while.condition);

        if(type_a->kind != TYPE_BOOLEAN){
            // -- Handling de error: condicion no booleana
            struct error *err = create_error_semantic_unmatched_types_statement_while(stmt->stmt.statement_while.line,type_a->kind_str);
            add_error_semantic_to_list(err);
        }

        // -- Liberar tipos
        free_type(type_a); free_type(type_b); free_type(type_c);

        // -- Realizar typechecking al contenido del cuerpo
        typecheck_list_statements(stmt->stmt.statement_while.body);

        break;
    }
    case STMT_FOR:
    {
        // -- Comprobar que el la variable y la expresion de inicio coinciden en tipos
        type_a = create_basic_type(TYPE_INTEGER);
        type_b = typecheck_expression(stmt->stmt.statement_for.intialization);

        if(!equals_type(type_a,type_b)){
            // -- Handling de error: asignacion de expresion a variable mismatch
            struct error *err = create_error_semantic_unmatched_types_statement_for(UNMATCHED_TYPES_STMT_FOR_INIT,stmt->stmt.statement_for.line,type_a->kind_str,type_b->kind_str);
            add_error_semantic_to_list(err);
        }

        // -- Comprobar rango de fin del bucle, integer
        type_c = typecheck_expression(stmt->stmt.statement_for.finish);
        
        if(type_c->kind != TYPE_INTEGER){
            // -- Handling de error: rango de fin no integer
            struct error *err = create_error_semantic_unmatched_types_statement_for(UNMATCHED_TYPES_STMT_FOR_END_EXR,stmt->stmt.statement_for.line,type_c->kind_str,NULL);
            add_error_semantic_to_list(err);
        }

        // -- Liberar la memoria antes de proceder
        free_type(type_a); free_type(type_b); free_type(type_c);

        // -- Realizar typechecking al contenido del cuerpo
        typecheck_list_statements(stmt->stmt.statement_for.body);

        break;
    }
    case STMT_IF_ELSE:
    {
        // -- Comprobar condicion de if, boolean
        type_a = typecheck_expression(stmt->stmt.statement_if_else.condition);

        if(type_a->kind != TYPE_BOOLEAN){
            // -- Realizar handling de error: condicion no booleana
            struct error *err = create_error_semantic_unmatched_types_statement_ifelse(stmt->stmt.statement_if_else.line,type_a->kind_str);
            add_error_semantic_to_list(err);
        }

        // -- Liberar tipos
        free_type(type_a); free_type(type_b); free_type(type_c);

        // -- Realizar typechecking al contenido del cuerpo if
        typecheck_list_statements(stmt->stmt.statement_if_else.if_body);

        // -- Realizar typechecking al contenido del cuerpo else
        typecheck_list_statements(stmt->stmt.statement_if_else.else_body);

        break;
    }
    case STMT_BLOCK_BEGIN:
    {
        // -- Realizar typechecking al contenido del cuerpo
        typecheck_list_statements(stmt->stmt.statement_block.body);

        // -- Liberar tipos
        free_type(type_a); free_type(type_b); free_type(type_c);

        break;
    }
    case STMT_BLOCK_COBEGIN:
    {
        // -- Realizar typechecking al contenido del cuerpo
        typecheck_list_statements(stmt->stmt.statement_block.body);
        break;
    }
    case STMT_ATOMIC:
    {
        // -- Realizar typechecking al contenido del cuerpo
        typecheck_list_statements(stmt->stmt.statement_block.body);
        break;
    }
    case STMT_FORK:
    {
        // -- Realizar typechecking al simbolo de proceso
        type_a = copy_type(stmt->stmt.statement_fork.symb->type);

        if(type_a->kind != TYPE_DPROCESS){
            // -- Realizar handling de error: no fork a proceso
            struct error *err = create_error_semantic_unmatched_types_statement_fork(stmt->stmt.statement_fork.line,type_a->kind_str);
            add_error_semantic_to_list(err);
        }

        // -- Liberar tipos
        free_type(type_a); free_type(type_b); free_type(type_c);

        break;
    }

    case STMT_JOIN:
    {
        // -- Realizar typechecking al simbolo de proceso
        type_a = copy_type(stmt->stmt.statement_join.symb->type);

        if(type_a->kind != TYPE_DPROCESS){
            // -- Realizar handling de error: no join a proceso
            struct error *err = create_error_semantic_unmatched_types_statement_join(stmt->stmt.statement_join.line,type_a->kind_str);
            add_error_semantic_to_list(err);
        }

        // -- Liberar tipos
        free_type(type_a); free_type(type_b); free_type(type_c);

        break;
    }
    case STMT_PROCEDURE_INV:
    {
        // -- Realizar typechecking a lista de argumentos
        struct expression *current_argument = stmt->stmt.statement_procedure_inv.arguments_list;
        struct type *current_type_parameter = stmt->stmt.statement_procedure_inv.symb->list_type_parameters;
        unsigned int position = 0;
        while(current_argument && current_type_parameter){
            type_a = typecheck_expression(current_argument);
            if(!equals_type(type_a,current_type_parameter)){
                // -- Realizar handling de error: tipo de argumento no valido
                struct error *err = create_error_semantic_unmatched_types_statement_procedure_inv(stmt->stmt.statement_procedure_inv.line,stmt->stmt.statement_procedure_inv.procedure_name,position,type_a->kind_str,current_type_parameter->kind_str);
                add_error_semantic_to_list(err);
            }

            current_argument = current_argument->next;
            current_type_parameter = current_type_parameter->next;
            position++;

            // -- Liberar tipos
            free_type(type_a);
        }

        break;
    }
    case STMT_RETURN:
    {
        // -- Realizar typechecking a expresion de retorno
        // -- NO HACER AQUI, TYPECHECK EN SUBPROGRAM
        break;
    }
    case STMT_PRINT:
    {
        // -- No se hace nada aqui
        break;
    }
    default:
        break;
    }
}

void typecheck_subprogram(struct subprogram *subprog){
    // -- Realizar typecheck a declaraciones de subprograma
    typecheck_list_declarations(subprog->declarations);
    // -- Realizar typecheck a sentencias de subprograma
    typecheck_list_statements(subprog->statements);

    // -- Realizar comprobacion explicita de sentencia de retorno
    if(subprog->kind == SUBPROGRAM_FUNCTION){
        struct type * type_b = typecheck_expression(subprog->ret->stmt.statement_return.returned_expr);

        if(!equals_type(subprog->type,type_b)){
            // -- Handling error: tipo de funcion con retorno mismatch
            struct error * err = create_error_semantic_unmatched_types_subprogram_function_return(subprog->line,subprog->name_subprogram,subprog->type->kind_str,type_b->kind_str);
            add_error_semantic_to_list(err);
        }

        free_type(type_b);
    }
}

void typecheck_process(struct process *proc){
    // -- Si es un vector, realizar typecheck a contenidos de vector
    if(proc->kind == PROCESS_VECTOR){
        struct type * type_a = NULL; struct type * type_b = NULL;
        struct type * type_c = NULL;

        // -- Comprobar indexador, integer
        type_a = copy_type(proc->symb_index->type);
        if(type_a->kind != TYPE_INTEGER){
            // -- Handling error: indexador de proceso no integer
            struct error * err = create_error_semantic_unmatched_types_process_vector(UNMATCHED_TYPES_PROC_VECTOR_INDEX,proc->line,type_a->kind_str);
            add_error_semantic_to_list(err);
        }

        // -- Comprobar rango de inicio y de fin de vector

        // ---- Comprobar primero que son literales puros
        // -- Comprobar si la expresion del tipo de array pertenece a un literal
        if(proc->index_start->kind != EXPR_LITERAL || proc->index_end->kind != EXPR_LITERAL){
            // -- Incluir error en la lista de errores semanticos
            struct error *err = create_error_semantic_invalid_static_array(proc->line);
            add_error_semantic_to_list(err);
        }

        type_b = typecheck_expression(proc->index_start);
        type_c = typecheck_expression(proc->index_end);

        if(type_b->kind != TYPE_INTEGER){
            // -- Handling error: rango de inicio de vctor de proceso no integer
            struct error * err = create_error_semantic_unmatched_types_process_vector(UNMATCHED_TYPES_PROC_VECTOR_START_RANGE,proc->line,type_b->kind_str);
            add_error_semantic_to_list(err);
        }
        if(type_c->kind != TYPE_INTEGER){
            // -- Handling error: rango de fin de vector de proceso no integer
            struct error * err = create_error_semantic_unmatched_types_process_vector(UNMATCHED_TYPES_PROC_VECTOR_END_RANGE,proc->line,type_c->kind_str);
            add_error_semantic_to_list(err);
        }

        free_type(type_a); type_a = NULL;
        free_type(type_b); type_b = NULL;
        free_type(type_c); type_c = NULL;
    }

    // -- Realizar typecheck a lista de declaraciones
    typecheck_list_declarations(proc->declarations);

    // -- Realizar typecheck a lista de sentencias
    typecheck_list_statements(proc->statements);
}

void typecheck_program(struct program *prog){
    // -- Realizar typechecking de las declaraciones de programa
    typecheck_list_declarations(prog->declarations);

    // -- Realizar typechecking de los subprogramas de programa
    typecheck_list_subprograms(prog->subprograms);

    // -- Realizar typechecking de los procesos de programa
    typecheck_list_process(prog->process);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE TYPE CHECKING (LISTA NODOS AST) -----

void typecheck_list_declarations(struct declaration *list_decl){
    if(!list_decl)
        return;

    struct declaration *current_decl = list_decl;
    while(current_decl){
        // -- Realizar typechecking a declaracion
        typecheck_declaration(current_decl);
        // -- Ir a siguiente declaracion
        current_decl = current_decl->next;
    }
}

void typecheck_list_statements(struct statement *list_statements){
    if(!list_statements)
        return;
    
    struct statement *current_stmt = list_statements;
    while(current_stmt){
        // -- Realizar typechecking a sentencia
        typecheck_statement(current_stmt);
        // -- Ir a siguiente sentencia
        current_stmt = current_stmt->next;
    }
}

void typecheck_list_subprograms(struct subprogram *list_subprograms){
    if(!list_subprograms)
        return;

    struct subprogram *current_subprogram = list_subprograms;
    while(current_subprogram){
        // -- Realizar typechecking a subprograma
        typecheck_subprogram(current_subprogram);

        // -- Ir a siguiente subprograma
        current_subprogram = current_subprogram->next;
    }
}

void typecheck_list_process(struct process *list_process){
    if(!list_process)
        return;

    struct process *current_process = list_process;
    while(current_process){
        // -- Realizar typechecking a proceso
        typecheck_process(current_process);

        // -- Ir a siguiente proceso
        current_process = current_process->next;
    }
}