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

struct statement * create_statement_assignment(char *variable_name, struct expression *expr){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_ASSIGNMENT;
    st->kind_str = strdup("assignment");
    if(!st->kind_str){
        free(st->kind_str);
        return NULL;
    }

    st->stmt.statement_assignment.variable_name = strdup(variable_name);
    if(!st->stmt.statement_assignment.variable_name){
        free(st->stmt.statement_assignment.variable_name);
        return NULL;
    }

    st->stmt.statement_assignment.expr = expr;
    st->next = NULL;

    return st;
}

struct statement * create_statement_while(struct expression *condition, struct statement *body){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_WHILE;
    st->kind_str = strdup("while");
    if(!st->kind_str){
        free(st->kind_str);
        return NULL;
    }
    st->stmt.statement_while.condition = condition;
    st->stmt.statement_while.body = body;
    st->next = NULL;

    return st;
}

struct statement * create_statement_for(char *counter_name, struct expression *initialization, struct expression *finish, struct statement *body){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_FOR;
    st->kind_str = strdup("for");
    if(!st->kind_str){
        free(st->kind_str);
        return NULL;
    }

    st->stmt.statement_for.counter_name = strdup(counter_name);
    st->stmt.statement_for.intialization = initialization;
    st->stmt.statement_for.finish = finish;
    st->stmt.statement_for.body = body;
    st->next = NULL;

    return st;
}

struct statement * create_statement_if_else(struct expression *condition, struct statement *if_body, struct statement *else_body){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_IF_ELSE;
    st->kind_str = strdup("if/else");
    if(!st->kind_str){
        free(st->kind_str);
        return NULL;
    }
    st->stmt.statement_if_else.condition = condition;
    st->stmt.statement_if_else.if_body = if_body;
    st->stmt.statement_if_else.else_body = else_body;
    st->next = NULL;

    return st; 
}

struct statement * create_statement_procedure_inv(char *procedure_name, struct parameter_list *parameters){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_PROCEDURE_INV;
    st->kind_str = strdup("procedure invocation");
    if(!st->kind_str){
        free(st->kind_str);
        return NULL;
    }
    st->stmt.statement_procedure_inv.procedure_name = strdup(procedure_name);
    if(st->stmt.statement_procedure_inv.procedure_name){
        free(st->stmt.statement_procedure_inv.procedure_name);
        return NULL;
    }

    st->stmt.statement_procedure_inv.parameters = parameters;
    st->next = NULL;

    return st; 
}

struct statement * create_block_of_statements(statement_t block_type, struct statement *body){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    switch (block_type)
    {
    case STMT_BLOCK_BEGIN:
        st->kind_str = strdup("begin/end block");
        break;
    
    case STMT_BLOCK_COBEGIN:
        st->kind_str = strdup("cobegin/coend block");
        break;

    case STMT_ATOMIC:
        st->kind_str = strdup("atomic block");
        break;
    }
    if(!st->kind_str){
        free(st->kind_str);
        return NULL;
    }

    st->kind = block_type;
    st->stmt.statement_block.body = body;
    st->next = NULL;

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

struct statement * create_statement_fork(char *process_name, struct statement *stmt){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_FORK;
    st->kind_str = strdup("fork process");
    if(!st->kind_str){
        free(st->kind_str);
        return NULL;
    }
    st->stmt.statement_fork.forked_process = strdup(process_name);
    if(!st->stmt.statement_fork.forked_process){
        free(st->stmt.statement_fork.forked_process);
        return NULL;
    }

    st->stmt.statement_fork.stmt = stmt;
    st->next = NULL;

    return st; 
}

struct statement * create_statement_return(struct expression *returned_expr){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_RETURN;
    st->kind_str = strdup("return statement");
    if(!st->kind_str){
        free(st->kind_str);
        return NULL;
    }
    st->stmt.statement_return.returned_expr = returned_expr;
    st->next = NULL;

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

    // -- Liberar en funcion del tipo de sentencia
    switch (stmt->kind)
    {
    case STMT_ASSIGNMENT:
        free(stmt->stmt.statement_assignment.variable_name);
        free_expression(stmt->stmt.statement_assignment.expr);
        break;

    case STMT_WHILE:
        free_expression(stmt->stmt.statement_while.condition);
        free_list_statements(stmt->stmt.statement_while.body);
        break;

    case STMT_FOR:
        if(stmt->stmt.statement_for.counter_name)
            free(stmt->stmt.statement_for.counter_name);
        free_expression(stmt->stmt.statement_for.intialization);
        free_expression(stmt->stmt.statement_for.finish);
        free_list_statements(stmt->stmt.statement_for.body);
        break;

    case STMT_IF_ELSE:
        free_expression(stmt->stmt.statement_if_else.condition);
        free_list_statements(stmt->stmt.statement_if_else.if_body);
        if(stmt->stmt.statement_if_else.else_body)
            free_list_statements(stmt->stmt.statement_if_else.else_body);
        break;

    case STMT_PROCEDURE_INV:
        free(stmt->stmt.statement_procedure_inv.procedure_name);
        if(stmt->stmt.statement_procedure_inv.parameters)
            free_list_parameters(stmt->stmt.statement_procedure_inv.parameters);
        break;

    case STMT_BLOCK_BEGIN:
        free_list_statements(stmt->stmt.statement_block.body);
        break;

    case STMT_BLOCK_COBEGIN:
        free_list_statements(stmt->stmt.statement_block.body);
        break;

    case STMT_FORK:
        free(stmt->stmt.statement_fork.forked_process);
        free_list_statements(stmt->stmt.statement_fork.stmt);
        break;

    case STMT_ATOMIC:
        free_list_statements(stmt->stmt.statement_block.body);
        break;

    case STMT_RETURN:
        free_expression(stmt->stmt.statement_return.returned_expr);
        break;
    }

    if(stmt->kind_str)
        free(stmt->kind_str);
    
    // -- Liberar nodo
    free(stmt);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO SENTENCIAS) -----

void print_AST_statements(struct statement *statements_list){
    const char *IDENT_ARROW = "------>";
    // -- Si NULL, simplemente devolver
    if(!statements_list){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }
        
    struct statement *current_statement = statements_list;
    while(current_statement){
        // -- Imprimir tipo de sentencia
        printf(" %s SENTENCIA DE TIPO: [%s]\n", IDENT_ARROW, current_statement->kind_str);

        printf(" %s CONTENIDO DE LA SENTENCIA DE TIPO: [%s]\n", IDENT_ARROW, current_statement->kind_str);
        // -- Imprimir sentencia
        switch (current_statement->kind)
        {
        case STMT_ASSIGNMENT:
            printf(" %s ASIGNACION A VARIABLE: [%s]\n", IDENT_ARROW, current_statement->stmt.statement_assignment.variable_name);
            printf(" %s EXPRESION ASIGNADA A VARIABLE: [%s]\n", IDENT_ARROW, current_statement->stmt.statement_assignment.variable_name);
            print_AST_expressions(current_statement->stmt.statement_assignment.expr);
            break;

        case STMT_WHILE:
            printf(" %s CONDICION DEL BUCLE WHILE\n", IDENT_ARROW);
            print_AST_expressions(current_statement->stmt.statement_while.condition);
            printf(" %s CUERPO DEL BUCLE WHILE\n", IDENT_ARROW);
            print_AST_statements(current_statement->stmt.statement_while.body);
            break;

        case STMT_FOR:
            printf(" %s NOMBRE DE CONTADOR DEL BUCLE FOR: [%s]\n", IDENT_ARROW, current_statement->stmt.statement_for.counter_name);
            printf(" %s EXPRESION DE INICIO DE CONTADOR DE BUCLE FOR\n", IDENT_ARROW);
            print_AST_expressions(current_statement->stmt.statement_for.intialization);
            printf(" %s EXPRESION DE FINIALIZACION DE BUCLE FOR\n", IDENT_ARROW);
            print_AST_expressions(current_statement->stmt.statement_for.finish);
            printf(" %s CUERPO DEL BUCLE FOR\n", IDENT_ARROW);
            print_AST_statements(current_statement->stmt.statement_for.body);
            break;

        case STMT_IF_ELSE:
            printf(" %s CONDICION DEL IF\n", IDENT_ARROW);
            print_AST_expressions(current_statement->stmt.statement_if_else.condition);
            printf(" %s CUERPO DEL IF\n", IDENT_ARROW);
            print_AST_statements(current_statement->stmt.statement_if_else.if_body);
            printf(" %s CUERPO DEL ELSE\n", IDENT_ARROW);
            print_AST_statements(current_statement->stmt.statement_if_else.else_body);
            break;

        case STMT_BLOCK_BEGIN:
            printf(" %s CONTENIDO DEL BLOQUE BEGIN/END \n", IDENT_ARROW);
            print_AST_statements(current_statement->stmt.statement_block.body);
            break;

        case STMT_BLOCK_COBEGIN:
            printf(" %s CONTENIDO DEL BLOQUE COBEGIN/COEND \n", IDENT_ARROW);
            print_AST_statements(current_statement->stmt.statement_block.body);
            break;

        case STMT_ATOMIC:
            printf(" %s CONTENIDO DEL BLOQUE ATOMIC \n", IDENT_ARROW);
            print_AST_statements(current_statement->stmt.statement_block.body);
            break;

        case STMT_PROCEDURE_INV:
            printf(" %s INVOCACION DE PROCEDIMIENTO DE NOMBRE: [%s]\n", IDENT_ARROW, current_statement->stmt.statement_procedure_inv.procedure_name);
            printf(" %s PARAMETROS DEL PROCEDIMIENTO: [%s]\n", IDENT_ARROW, current_statement->stmt.statement_procedure_inv.procedure_name);
            print_AST_parameters(current_statement->stmt.statement_procedure_inv.parameters);
            break;

        case STMT_FORK:
            printf(" %s FORK DEL PROCESO CON NOMBRE: [%s]\n", IDENT_ARROW, current_statement->stmt.statement_fork.forked_process);
            printf(" %s SENTENCIAS DE FORK DE PROCESO: [%s]\n", IDENT_ARROW, current_statement->stmt.statement_fork.forked_process);
            print_AST_statements(current_statement->stmt.statement_fork.stmt);
            break;
        
        case STMT_RETURN:
            printf(" %s EXPRESION DE RETORNO\n", IDENT_ARROW);
            print_AST_expressions(current_statement->stmt.statement_return.returned_expr);
            break;
        }

        // Ir a la siguiente sentencia
        current_statement = current_statement->next;
    }
    
}