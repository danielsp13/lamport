/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file statement.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO sentencias
 */

#include "AST/statement.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (SENTENCIAS) -----

struct statement * create_statement(statement_t kind){
    struct statement *st = malloc(sizeof(*st));

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar tipo de sentencia (statement_t y str)
    st->kind = kind;
    switch (st->kind)
    {
    case STMT_ASSIGNMENT:
    {
        st->kind_str = strdup("assignment");
        break;
    }

    case STMT_WHILE:
    {
        st->kind_str = strdup("while");
        break;
    }
    
    case STMT_FOR:
    {
        st->kind_str = strdup("for");
        break;
    }

    case STMT_IF_ELSE:
    {
        st->kind_str = strdup("if/else");
        break;
    }

    case STMT_PROCEDURE_INV:
    {
        st->kind_str = strdup("procedure invocation");
        break;
    }

    case STMT_BLOCK_BEGIN:
    {
        st->kind_str = strdup("begin/end block");
        break;
    }
    
    case STMT_BLOCK_COBEGIN:
    {
        st->kind_str = strdup("cobegin/coend block");
        break;
    }

    case STMT_ATOMIC:
    {
        st->kind_str = strdup("atomic block");
        break;
    }

    case STMT_FORK:
    {
        st->kind_str = strdup("fork process");
        break;
    }

    case STMT_JOIN:
    {
        st->kind_str = strdup("join process");
        break;
    }

    case STMT_RETURN:
    {
        st->kind_str = strdup("return statement");
        break;
    }

    case STMT_PRINT:
    {
        st->kind_str = strdup("print statement");
        break;
    }

    default:
    {
        st->kind_str = NULL;
        break;
    }
    }

    // -- Comprobar asignacion de tipo de sentencia (str) exitosa
    if(!st->kind_str){
        // -- Liberar memoria reservada para la expresion
        free(st);
        return NULL;
    }

    // -- Asignar puntero a siguiente sentencia (NULL)
    st->next = NULL;

    // -- Retornar sentencia creada
    return st;
}

struct statement * create_statement_assignment(char *variable_name, struct expression *index_expr, struct expression *expr, unsigned long line){
    struct statement *st = create_statement(STMT_ASSIGNMENT);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar nombre de variable
    st->stmt.statement_assignment.variable_name = strdup(variable_name);
    // -- Comprobar asignacion de nombre de variable exitosa
    if(!st->stmt.statement_assignment.variable_name){
        // -- Liberar memoria reservada al nodo
        free(st);
        return NULL;
    }

    // -- Asignar expresion de indice (si la asignacion se esta realizando sobre un array)
    st->stmt.statement_assignment.index_expr = index_expr;

    // -- Asignar expresion
    st->stmt.statement_assignment.expr = expr;

    // -- Asignar linea donde se utilizo el identificador
    st->stmt.statement_assignment.line = line;

    // -- Asignar referencia de simbolo de tabla de simbolos (NULL)
    st->stmt.statement_assignment.symb = NULL;

    // -- Retornar sentencia creada e inicializada
    return st;
}

struct statement * create_statement_while(struct expression *condition, struct statement *body, unsigned long line){
    struct statement *st = create_statement(STMT_WHILE);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asingar expresion de condicion
    st->stmt.statement_while.condition = condition;
    // -- Asignar cuerpo de bucle
    st->stmt.statement_while.body = body;

    // -- Asignar linea
    st->stmt.statement_while.line = line;

    // -- Retornar sentencia creada e inicializada
    return st;
}

struct statement * create_statement_for(char *counter_name, struct expression *initialization, struct expression *finish, struct statement *body, unsigned long line){
    struct statement *st = create_statement(STMT_FOR);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar variable de contador de for
    st->stmt.statement_for.counter_name = strdup(counter_name);
    // -- Comprobar asignacion de contador de for exitosa
    if(!st->stmt.statement_for.counter_name){
        // -- Liberar memoria reservada para la sentencia
        free(st);
        return NULL;
    }

    // -- Asignar inicializacion de bucle
    st->stmt.statement_for.intialization = initialization;
    // -- Asignar finalizacion de bucle
    st->stmt.statement_for.finish = finish;
    // -- Asignar cuerpo de bucle
    st->stmt.statement_for.body = body;


    // -- Asignar linea donde se utilizo el identificador de contador
    st->stmt.statement_for.line = line;
    // -- Asignar referencia de simbolo de tabla de simbolos (NULL)
    st->stmt.statement_for.symb = NULL;

    // -- Retornar sentencia creada e inicializada
    return st;
}

struct statement * create_statement_if_else(struct expression *condition, struct statement *if_body, struct statement *else_body, unsigned long line){
    struct statement *st = create_statement(STMT_IF_ELSE);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar expresion de condicion de if
    st->stmt.statement_if_else.condition = condition;
    // -- Asignar cuerpo de if
    st->stmt.statement_if_else.if_body = if_body;
    // -- Asignar cuerpo de else
    st->stmt.statement_if_else.else_body = else_body;

    // -- Asignar linea
    st->stmt.statement_if_else.line = line;
    
    // -- Retornar sentencia creada e inicializada
    return st;
}

struct statement * create_statement_procedure_inv(char *procedure_name, struct expression *arguments_list, unsigned long line){
    struct statement *st = create_statement(STMT_PROCEDURE_INV);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar nombre de procedimiento
    st->stmt.statement_procedure_inv.procedure_name = strdup(procedure_name);
    // -- Comprobar asignacion de procedimiento exitosa
    if(!st->stmt.statement_procedure_inv.procedure_name){
        // -- Liberar memoria reservada para la sentencia
        free(st);
        return NULL;
    }

    // -- Asignar lista de argumentos de invocacion
    st->stmt.statement_procedure_inv.arguments_list = arguments_list;

    // -- Asignar linea donde se uso el identificador de procedimiento
    st->stmt.statement_procedure_inv.line = line;
    // -- Asignar referencia de simbolo de tabla de simbolos (NULL)
    st->stmt.statement_procedure_inv.symb = NULL;
    
    // -- Retornar sentencia creada e inicializada
    return st;
}

struct statement * create_block_of_statements(statement_t block_type, struct statement *body){
    struct statement *st = create_statement(block_type);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar bloque de sentencias
    st->stmt.statement_block.body = body;

    // -- Retornar sentencia creada e inicializada
    return st;
}

struct statement * create_statement_block_begin(struct statement *body){
    return create_block_of_statements(STMT_BLOCK_BEGIN, body);
}

struct statement * create_statement_block_cobegin(struct statement *body){
    return create_block_of_statements(STMT_BLOCK_COBEGIN, body);
}

struct statement * create_statement_atomic(struct statement *body){
    return create_block_of_statements(STMT_ATOMIC, body);
}

struct statement * create_statement_fork(char *process_name, unsigned long line){
    struct statement *st = create_statement(STMT_FORK);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar nombre de proceso
    st->stmt.statement_fork.forked_process = strdup(process_name);
    // -- Comprobar asignacion de nombre de proceso exitosa
    if(!st->stmt.statement_fork.forked_process){
        // -- Liberar memoria reservada para la sentencia
        free(st);
        return NULL;
    }

    // -- Asignar linea donde se uso el identificador de proceso
    st->stmt.statement_fork.line = line;

    // -- Asignar referencia de simbolo de tabla de simbolos (NULL)
    st->stmt.statement_fork.symb = NULL;

    // -- Retornar sentencia creada e inicializada
    return st;
}

struct statement * create_statement_join(char *process_name, unsigned long line){
    struct statement *st = create_statement(STMT_JOIN);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar nombre de proceso
    st->stmt.statement_join.joined_process = strdup(process_name);
    // -- Comprobar asignacion de nombre de proceso exitosa
    if(!st->stmt.statement_join.joined_process){
        // -- Liberar memoria reservada para la sentencia
        free(st);
        return NULL;
    }

    // -- Asignar linea donde se uso el identificador de proceso
    st->stmt.statement_join.line = line;

    // -- Asignar referencia de simbolo de tabla de simbolos (NULL)
    st->stmt.statement_join.symb = NULL;

    // -- Retornar sentencia creada e inicializada
    return st;
}

struct statement * create_statement_return(struct expression *returned_expr, unsigned long line){
    struct statement *st = create_statement(STMT_RETURN);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar expresion de retorno
    st->stmt.statement_return.returned_expr = returned_expr;

    // -- Asignar linea donde se definio la expresion de retorno
    st->stmt.statement_return.line = line;

    // -- Retornar sentencia creada e inicializada
    return st;
}

struct statement * create_statement_print(struct expression *expressions_list){
    struct statement *st = create_statement(STMT_PRINT);

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar lista de expresiones a imprimir
    st->stmt.statement_print.expressions_list = expressions_list;

    // -- Retornar sentencia creada e inicializada
    return st;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO SENTENCIAS) -----

void free_list_statements(struct statement *statements_list){
    struct statement *current_statement = statements_list;
    while(current_statement){
        // -- Seleccionar siguiente en la lista
        struct statement *next = current_statement->next;
        // -- Liberar nodo
        free_statement(current_statement);
        // -- Nodo actual -> siguiente
        current_statement = next;
    }
}

void free_statement(struct statement *stmt){

    // -- Si NULL, simplemente devolver
    if(!stmt)
        return;

    // -- Liberar tipo de sentencia (str)
    if(stmt->kind_str){
        free(stmt->kind_str);
        stmt->kind_str = NULL;
    }

    // -- Liberar en funcion del tipo de sentencia
    switch (stmt->kind)
    {
    case STMT_ASSIGNMENT:
    {
        free(stmt->stmt.statement_assignment.variable_name);
        stmt->stmt.statement_assignment.variable_name = NULL;

        free_expression(stmt->stmt.statement_assignment.index_expr);
        stmt->stmt.statement_assignment.index_expr = NULL;
        free_expression(stmt->stmt.statement_assignment.expr);
        stmt->stmt.statement_assignment.expr = NULL;

        // -- Liberacion de simbolo
        if(stmt->stmt.statement_assignment.symb){
            free_symbol(stmt->stmt.statement_assignment.symb);
            stmt->stmt.statement_assignment.symb = NULL;
        }
        break;
    }

    case STMT_WHILE:
    {
        free_expression(stmt->stmt.statement_while.condition);
        stmt->stmt.statement_while.condition = NULL;

        free_list_statements(stmt->stmt.statement_while.body);
        stmt->stmt.statement_while.body = NULL;
        break;
    }

    case STMT_FOR:
    {
        free(stmt->stmt.statement_for.counter_name);
        stmt->stmt.statement_for.counter_name = NULL;

        free_expression(stmt->stmt.statement_for.intialization);
        stmt->stmt.statement_for.intialization = NULL;
        free_expression(stmt->stmt.statement_for.finish);
        stmt->stmt.statement_for.finish = NULL;

        free_list_statements(stmt->stmt.statement_for.body);
        stmt->stmt.statement_for.body = NULL;

        // -- Liberacion de simbolo
        if(stmt->stmt.statement_for.symb){
            free_symbol(stmt->stmt.statement_for.symb);
            stmt->stmt.statement_for.symb = NULL;
        }
        break;
    }

    case STMT_IF_ELSE:
    {
        free_expression(stmt->stmt.statement_if_else.condition);
        stmt->stmt.statement_if_else.condition = NULL;

        free_list_statements(stmt->stmt.statement_if_else.if_body);
        stmt->stmt.statement_if_else.if_body = NULL;

        if(stmt->stmt.statement_if_else.else_body){
            free_list_statements(stmt->stmt.statement_if_else.else_body);
            stmt->stmt.statement_if_else.else_body = NULL;
        }
        break;
    }

    case STMT_PROCEDURE_INV:
    {
        free(stmt->stmt.statement_procedure_inv.procedure_name);
        stmt->stmt.statement_procedure_inv.procedure_name = NULL;

        if(stmt->stmt.statement_procedure_inv.arguments_list){
            free_list_expressions(stmt->stmt.statement_procedure_inv.arguments_list);
            stmt->stmt.statement_procedure_inv.arguments_list = NULL;
        }


        // -- Liberacion de simbolo
        if(stmt->stmt.statement_procedure_inv.symb){
            free_symbol(stmt->stmt.statement_procedure_inv.symb);
            stmt->stmt.statement_procedure_inv.symb = NULL;
        }
        
        break;
    }

    case STMT_BLOCK_BEGIN:
    {
        free_list_statements(stmt->stmt.statement_block.body);
        stmt->stmt.statement_block.body = NULL;
        break;
    }

    case STMT_BLOCK_COBEGIN:
    {
        free_list_statements(stmt->stmt.statement_block.body);
        stmt->stmt.statement_block.body = NULL;
        break;
    }

    case STMT_FORK:
    {
        free(stmt->stmt.statement_fork.forked_process);
        stmt->stmt.statement_fork.forked_process = NULL;

        // -- Liberacion de simbolo
        if(stmt->stmt.statement_fork.symb){
            free_symbol(stmt->stmt.statement_fork.symb);
            stmt->stmt.statement_fork.symb = NULL;   
        }
        break;
    }

    case STMT_JOIN:
    {
        free(stmt->stmt.statement_join.joined_process);
        stmt->stmt.statement_join.joined_process = NULL;

        // -- Liberacion de simbolo
        if(stmt->stmt.statement_join.symb){
            free_symbol(stmt->stmt.statement_join.symb);
            stmt->stmt.statement_join.symb = NULL;   
        }
        break;
    }

    case STMT_ATOMIC:
    {
        free_list_statements(stmt->stmt.statement_block.body);
        stmt->stmt.statement_block.body = NULL;
        break;
    }

    case STMT_RETURN:
    {
        free_expression(stmt->stmt.statement_return.returned_expr);
        stmt->stmt.statement_return.returned_expr = NULL;

        /*if(stmt->stmt.statement_return.function_name){
            free(stmt->stmt.statement_return.function_name);
            stmt->stmt.statement_return.function_name = NULL;
        }*/

        break;
    }

    case STMT_PRINT:
    {
        free_list_expressions(stmt->stmt.statement_print.expressions_list);
        stmt->stmt.statement_print.expressions_list = NULL;
        break;
    }
    }
    
    // -- Liberar nodo
    free(stmt);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO SENTENCIAS) -----

void print_AST_statements(struct statement *statements_list, unsigned int depth, FILE * output){
    // -- Determinar identacion de nodo
    char * IDENT_NODE_BRANCH = build_identation_branch(depth);
    char * IDENT_NODE = build_identation_spaces(depth);
    // -- Determinar profundidad del siguiente nodo
    const unsigned int NEXT_NODE_DEPTH = depth+2;

    // -- Si NULL, simplemente devolver
    if(!statements_list){
        fprintf(output,"%s%s %s\n",IDENT_NODE_BRANCH, IDENT_ARROW, NULL_NODE_MSG);

        // -- Liberar memoria utilizada para la identacion
        free(IDENT_NODE); IDENT_NODE = NULL;
        free(IDENT_NODE_BRANCH); IDENT_NODE_BRANCH = NULL;

        return;
    }
        
    struct statement *current_statement = statements_list;
    while(current_statement){
        // -- Imprimir tipo de sentencia
        fprintf(output,"%s%s %c SENTENCIA DE TIPO: [%s]\n", IDENT_NODE_BRANCH, IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL, current_statement->kind_str);

        // -- Imprimir sentencia
        switch (current_statement->kind)
        {
        case STMT_ASSIGNMENT:
        {
            fprintf(output,"%s%s %c ASIGNACION A VARIABLE: [%s]\n", IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL, current_statement->stmt.statement_assignment.variable_name);
            if(current_statement->stmt.statement_assignment.index_expr){
                fprintf(output,"%s%s %c EXPRESION DE INDICE DE ACCESO A ARRAY:\n", IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
                print_AST_expressions(current_statement->stmt.statement_assignment.index_expr,NEXT_NODE_DEPTH,output);
            }

            fprintf(output,"%s%s %c EXPRESION ASIGNADA A VARIABLE:\n", IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_statement->stmt.statement_assignment.expr,NEXT_NODE_DEPTH,output);
            break;
        }

        case STMT_WHILE:
        {
            fprintf(output,"%s%s %c CONDICION DEL BUCLE WHILE:\n", IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_statement->stmt.statement_while.condition,NEXT_NODE_DEPTH,output);
            fprintf(output,"%s%s %c CUERPO DEL BUCLE WHILE:\n",IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_statements(current_statement->stmt.statement_while.body,NEXT_NODE_DEPTH,output);
            break;
        }

        case STMT_FOR:
        {
            fprintf(output,"%s%s %c NOMBRE DE CONTADOR DEL BUCLE FOR: [%s]\n", IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL, current_statement->stmt.statement_for.counter_name);
            fprintf(output,"%s%s %c EXPRESION DE INICIO DE CONTADOR DE BUCLE FOR\n",IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_statement->stmt.statement_for.intialization,NEXT_NODE_DEPTH,output);
            fprintf(output,"%s%s %c EXPRESION DE FINIALIZACION DE BUCLE FOR\n",IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_statement->stmt.statement_for.finish,NEXT_NODE_DEPTH,output);
            fprintf(output,"%s%s %c CUERPO DEL BUCLE FOR\n",IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_statements(current_statement->stmt.statement_for.body,NEXT_NODE_DEPTH,output);
            break;
        }

        case STMT_IF_ELSE:
        {
            fprintf(output,"%s%s %c CONDICION DEL IF\n",IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_statement->stmt.statement_if_else.condition,NEXT_NODE_DEPTH,output);
            fprintf(output,"%s%s %c CUERPO DEL IF\n",IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_statements(current_statement->stmt.statement_if_else.if_body,NEXT_NODE_DEPTH,output);
            fprintf(output,"%s%s %c CUERPO DEL ELSE\n",IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_statements(current_statement->stmt.statement_if_else.else_body,NEXT_NODE_DEPTH,output);
            break;
        }

        case STMT_BLOCK_BEGIN:
        {
            print_AST_statements(current_statement->stmt.statement_block.body,NEXT_NODE_DEPTH,output);
            break;
        }

        case STMT_BLOCK_COBEGIN:
        {
            print_AST_statements(current_statement->stmt.statement_block.body,NEXT_NODE_DEPTH,output);
            break;
        }

        case STMT_ATOMIC:
        {
            print_AST_statements(current_statement->stmt.statement_block.body,NEXT_NODE_DEPTH,output);
            break;
        }

        case STMT_PROCEDURE_INV:
        {
            fprintf(output,"%s%s %c INVOCACION DE PROCEDIMIENTO DE NOMBRE: [%s]\n", IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL, current_statement->stmt.statement_procedure_inv.procedure_name);
            fprintf(output,"%s%s %c LISTADO DE ARGUMENTOS DE INVOCACION DEL PROCEDIMIENTO:\n", IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_statement->stmt.statement_procedure_inv.arguments_list,NEXT_NODE_DEPTH,output);
            break;
        }

        case STMT_FORK:
        {
            fprintf(output,"%s%s %c FORK DEL PROCESO CON NOMBRE: [%s]\n", IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL, current_statement->stmt.statement_fork.forked_process);
            break;
        }

        case STMT_JOIN:
        {
            fprintf(output,"%s%s %c JOIN DEL PROCESO CON NOMBRE: [%s]\n", IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL, current_statement->stmt.statement_join.joined_process);
            break;
        }
        
        case STMT_RETURN:
        {
            fprintf(output,"%s%s %c EXPRESION DE RETORNO:\n",IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_statement->stmt.statement_return.returned_expr,NEXT_NODE_DEPTH,output);
            break;
        }

        case STMT_PRINT:
        {
            fprintf(output,"%s%s %c LISTADO DE EXPRESIONES A IMPRIMIR:\n",IDENT_NODE, IDENT_BLANK_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_statement->stmt.statement_print.expressions_list,NEXT_NODE_DEPTH,output);
            break;
        }
        }

        fprintf(output,"\n");

        // Ir a la siguiente sentencia
        current_statement = current_statement->next;
    }

    // -- Liberar memoria utilizada para la identacion
    free(IDENT_NODE); IDENT_NODE = NULL;
    free(IDENT_NODE_BRANCH); IDENT_NODE_BRANCH = NULL;
}