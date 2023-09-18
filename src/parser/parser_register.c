/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file parser_register.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para gestion
 * de registro de bloques en la fase de parsing
 */

#include "parser/parser_register.h"

// ===============================================================

// ----- DEFINICION DE REGISTROS DE CONTROL DE BLOQUES -----

// -- Registro de nodos de declaraciones
struct AST_declaration_register *list_AST_decl_reg = NULL;

// -- Ultimo registro efectuado en el registro de nodos de declaraciones
struct AST_declaration_register *last_reg_of_list_AST_decl_reg = NULL;

// -- Registro de nodos de expresiones
struct AST_expression_register *list_AST_expr_reg = NULL;

// -- Ultimo registro efectuado en el registro de nodos de expresiones
struct AST_expression_register *last_reg_of_list_AST_expr_reg = NULL;

// -- Registro de nodos de sentencias
struct AST_statement_register *list_AST_stmt_reg = NULL;

// -- Ultimo registro efectuado en el registro de nodos de sentencias
struct AST_statement_register *last_reg_of_list_AST_stmt_reg = NULL;

// -- Registro de nodos de parametros
struct AST_parameter_register *list_AST_param_reg = NULL;

// -- Ultimo registro efectuado en el registro de nodos de parametros
struct AST_parameter_register *last_reg_of_list_AST_param_reg = NULL;

// -- Registro de nodos de tipos
struct AST_type_register *list_AST_type_reg = NULL;

// -- Ultimo registro efectuado en el registro de nodos de tipos
struct AST_type_register *last_reg_of_list_AST_type_reg = NULL;

// -- Registro de nodos de subprogramas
struct AST_subprogram_register *list_AST_subprog_reg = NULL;

// -- Ultimo registro efectuado en el registro de nodos de subprogramas
struct AST_subprogram_register *last_reg_of_list_AST_subprog_reg = NULL;

// -- Registro de nodos de proceso
struct AST_process_register *list_AST_proc_reg = NULL;

// -- Ultimo registro efectuado en el registro de nodos de proceso
struct AST_process_register *last_reg_of_list_AST_proc_reg = NULL;

// -- Registro de cadenas de caracteres reconocidas
struct string_register *list_str_reg = NULL;

// -- Ultimo registro efectuado en el registro de cadenas
struct string_register *last_str_reg = NULL;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE REGISTROS (GENERAL) -----

union AST_node_register create_AST_node_register(AST_node_register_t kind, union AST_node data){
    // -- Definir elemento de registro de nodo
    union AST_node_register AST_node_reg;

    // -- Decidir tipo de registro de nodo
    switch (kind)
    {
    case AST_NODE_REG_DECLARATION:
        struct AST_declaration_register *decl_reg = malloc(sizeof(*decl_reg));

        if(!decl_reg){
            AST_node_reg.decl_reg = NULL;
            return AST_node_reg;
        }

        decl_reg->decl = data.decl; decl_reg->next = NULL;
        AST_node_reg.decl_reg = decl_reg;
        break;

    case AST_NODE_REG_EXPRESSION:
        struct AST_expression_register *expr_reg = malloc(sizeof(*expr_reg));

        if(!expr_reg){
            AST_node_reg.expr_reg = NULL;
            return AST_node_reg;
        }

        expr_reg->expr = data.expr; expr_reg->next = NULL;
        AST_node_reg.expr_reg = expr_reg;
        break;

    case AST_NODE_REG_STATEMENT:
        struct AST_statement_register *stmt_reg = malloc(sizeof(*stmt_reg));

        if(!stmt_reg){
            AST_node_reg.stmt_reg = NULL;
            return AST_node_reg;
        }

        stmt_reg->stmt = data.stmt; stmt_reg->next = NULL;
        AST_node_reg.stmt_reg = stmt_reg;
        break;

    case AST_NODE_REG_PARAMETER:
        struct AST_parameter_register *param_reg = malloc(sizeof(*param_reg));

        if(!param_reg){
            AST_node_reg.param_reg = NULL;
            return AST_node_reg;
        }

        param_reg->param = data.param; param_reg->next = NULL;
        AST_node_reg.param_reg = param_reg;
        break;

    case AST_NODE_REG_TYPE:
        struct AST_type_register *type_reg = malloc(sizeof(*type_reg));

        if(!type_reg){
            AST_node_reg.type_reg = NULL;
            return AST_node_reg;
        }

        type_reg->type = data.type; type_reg->next = NULL;
        AST_node_reg.type_reg = type_reg;
        break;

    case AST_NODE_REG_SUBPROGRAM:
        struct AST_subprogram_register *subprog_reg = malloc(sizeof(*subprog_reg));

        if(!subprog_reg){
            AST_node_reg.subprog_reg = NULL;
            return AST_node_reg;
        }

        subprog_reg->subprog = data.subprog; subprog_reg->next = NULL;
        AST_node_reg.subprog_reg = subprog_reg;
        break;

    case AST_NODE_REG_PROCESS:
        struct AST_process_register *proc_reg = malloc(sizeof(*proc_reg));

        if(!proc_reg){
            AST_node_reg.proc_reg = NULL;
            return AST_node_reg;
        }

        proc_reg->proc = data.proc; proc_reg->next = NULL;
        AST_node_reg.proc_reg = proc_reg;
        break;
    
    default:
        break;
    }

    return AST_node_reg;
}


// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE REGISTROS (DECLARATION) -----

struct AST_declaration_register * create_AST_declaration_reg(struct declaration *decl){
    // -- Comprobar que hay nodo
    if(!decl)
        return NULL;

    // -- Crear valor de dato
    union AST_node data; data.decl = decl;

    // -- Llamar a constructor de registros de nodos
    union AST_node_register reg = create_AST_node_register( AST_NODE_REG_DECLARATION,data);

    return reg.decl_reg;
}

int add_declaration_to_register(struct declaration *decl){
    // -- Comprobar que hay declaracion
    if(!decl)
        return REG_OPERATION_FAILURE;

    // -- Crear registro
    struct AST_declaration_register * reg = create_AST_declaration_reg(decl);

    // -- Comprobar creacion de registro
    if(!reg)
        return REG_OPERATION_FAILURE;

    // --- Insertar en la lista de registros
    if(!list_AST_decl_reg){
        // -- Insertar en la cabeza de registro
        list_AST_decl_reg = reg;
        // -- Ultimo registro efectuado: cola de registro
        last_reg_of_list_AST_decl_reg = list_AST_decl_reg;
    }
    else{
        // -- Insertar al final de la lista
        last_reg_of_list_AST_decl_reg->next = reg;
        // -- Actualizar ultimo registro efectuado
        last_reg_of_list_AST_decl_reg = last_reg_of_list_AST_decl_reg->next;
    }

    return REG_OPERATION_SUCCESS;
}

void free_AST_declaration_register(){
    struct AST_declaration_register *current_AST_reg = list_AST_decl_reg;
    while(current_AST_reg){
        // Obtener siguiente en la lista
        struct AST_declaration_register * next = current_AST_reg->next;

        // Liberar contenido
        free_declaration(current_AST_reg->decl);

        // Liberar registro
        free(current_AST_reg);

        // Apuntar al siguiente de la lista
        current_AST_reg = next;
    }

    list_AST_decl_reg = NULL;
    last_reg_of_list_AST_decl_reg = NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE REGISTROS (EXPRESIONES) -----

struct AST_expression_register * create_AST_expression_reg(struct expression *expr){
    // -- Comprobar que hay nodo
    if(!expr)
        return NULL;

    // -- Crear valor de dato
    union AST_node data; data.expr = expr;

    // -- Llamar a constructor de registros de nodos
    union AST_node_register reg = create_AST_node_register( AST_NODE_REG_EXPRESSION,data);

    return reg.expr_reg;
}

int add_expression_to_register(struct expression *expr){
    // -- Comprobar que hay expresion
    if(!expr)
        return REG_OPERATION_FAILURE;

    // -- Crear registro
    struct AST_expression_register * reg = create_AST_expression_reg(expr);

    // -- Comprobar creacion de registro
    if(!reg)
        return REG_OPERATION_FAILURE;

    // --- Insertar en la lista de registros
    if(!list_AST_expr_reg){
        // -- Insertar en la cabeza de registro
        list_AST_expr_reg = reg;
        // -- Ultimo registro efectuado: cola de registro
        last_reg_of_list_AST_expr_reg = list_AST_expr_reg;
    }
    else{
        // -- Insertar al final de la lista
        last_reg_of_list_AST_expr_reg->next = reg;
        // -- Actualizar ultimo registro efectuado
        last_reg_of_list_AST_expr_reg = last_reg_of_list_AST_expr_reg->next;
    }

    return REG_OPERATION_SUCCESS;
}

void free_AST_expression_register(){
    struct AST_expression_register *current_AST_reg = list_AST_expr_reg;
    while(current_AST_reg){
        // Obtener siguiente en la lista
        struct AST_expression_register * next = current_AST_reg->next;

        // Liberar contenido
        free_expression(current_AST_reg->expr);

        // Liberar registro
        free(current_AST_reg);

        // Apuntar al siguiente de la lista
        current_AST_reg = next;
    }

    list_AST_expr_reg = NULL;
    last_reg_of_list_AST_expr_reg = NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE REGISTROS (SENTENCIAS) -----

struct AST_statement_register * create_AST_statement_reg(struct statement *stmt){
    // -- Comprobar que hay nodo
    if(!stmt)
        return NULL;

    // -- Crear valor de dato
    union AST_node data; data.stmt = stmt;

    // -- Llamar a constructor de registros de nodos
    union AST_node_register reg = create_AST_node_register( AST_NODE_REG_STATEMENT,data);

    return reg.stmt_reg;
}

int add_statement_to_register(struct statement *stmt){
    // -- Comprobar que hay sentencia
    if(!stmt)
        return REG_OPERATION_FAILURE;
    
        // -- Crear registro
    struct AST_statement_register * reg = create_AST_statement_reg(stmt);

    // -- Comprobar creacion de registro
    if(!reg)
        return REG_OPERATION_FAILURE;

    // --- Insertar en la lista de registros
    if(!list_AST_stmt_reg){
        // -- Insertar en la cabeza de registro
        list_AST_stmt_reg = reg;
        // -- Ultimo registro efectuado: cola de registro
        last_reg_of_list_AST_stmt_reg = list_AST_stmt_reg;
    }
    else{
        // -- Insertar al final de la lista
        last_reg_of_list_AST_stmt_reg->next = reg;
        // -- Actualizar ultimo registro efectuado
        last_reg_of_list_AST_stmt_reg = last_reg_of_list_AST_stmt_reg->next;
    }

    return REG_OPERATION_SUCCESS;
}

void free_AST_statement_register(){
    struct AST_statement_register *current_AST_reg = list_AST_stmt_reg;
    while(current_AST_reg){
        // Obtener siguiente en la lista
        struct AST_statement_register * next = current_AST_reg->next;

        // Liberar contenido
        free_statement(current_AST_reg->stmt);

        // Liberar registro
        free(current_AST_reg);

        // Apuntar al siguiente de la lista
        current_AST_reg = next;
    }

    list_AST_stmt_reg = NULL;
    last_reg_of_list_AST_stmt_reg = NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE REGISTROS (PARAMETROS) -----

struct AST_parameter_register * create_AST_parameter_reg(struct parameter *param){
    // -- Comprobar que hay nodo
    if(!param)
        return NULL;

    // -- Crear valor de dato
    union AST_node data; data.param = param;

    // -- Llamar a constructor de registros de nodos
    union AST_node_register reg = create_AST_node_register( AST_NODE_REG_PARAMETER,data);

    return reg.param_reg;
}

int add_parameter_to_register(struct parameter *param){
    // -- Comprobar que hay parametro
    if(!param)
        return REG_OPERATION_FAILURE;

    // -- Crear registro
    struct AST_parameter_register * reg = create_AST_parameter_reg(param);

    // -- Comprobar creacion de registro
    if(!reg)
        return REG_OPERATION_FAILURE;

    // --- Insertar en la lista de registros
    if(!list_AST_param_reg){
        // -- Insertar en la cabeza de registro
        list_AST_param_reg = reg;
        // -- Ultimo registro efectuado: cola de registro
        last_reg_of_list_AST_param_reg = list_AST_param_reg;
    }
    else{
        // -- Insertar al final de la lista
        last_reg_of_list_AST_param_reg->next = reg;
        // -- Actualizar ultimo registro efectuado
        last_reg_of_list_AST_param_reg = last_reg_of_list_AST_param_reg->next;
    }

    return REG_OPERATION_SUCCESS;
    
}

void free_AST_parameter_register(){
    struct AST_parameter_register *current_AST_reg = list_AST_param_reg;
    while(current_AST_reg){
        // Obtener siguiente en la lista
        struct AST_parameter_register * next = current_AST_reg->next;

        // Liberar contenido
        free_parameter(current_AST_reg->param);

        // Liberar registro
        free(current_AST_reg);

        // Apuntar al siguiente de la lista
        current_AST_reg = next;
    }

    list_AST_param_reg = NULL;
    last_reg_of_list_AST_param_reg = NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE REGISTROS (TIPOS) -----

struct AST_type_register * create_AST_type_reg(struct type *type){
    // -- Comprobar que hay nodo
    if(!type)
        return NULL;

    // -- Crear valor de dato
    union AST_node data; data.type = type;

    // -- Llamar a constructor de registros de nodos
    union AST_node_register reg = create_AST_node_register( AST_NODE_REG_TYPE,data);

    return reg.type_reg;
}

int add_type_to_register(struct type *type){
    // -- Comprobar que hay tipo
    if(!type)
        return REG_OPERATION_FAILURE;

    // -- Crear registro
    struct AST_type_register * reg = create_AST_type_reg(type);

    // -- Comprobar creacion de registro
    if(!reg)
        return REG_OPERATION_FAILURE;

    // --- Insertar en la lista de registros
    if(!list_AST_type_reg){
        // -- Insertar en la cabeza de registro
        list_AST_type_reg = reg;
        // -- Ultimo registro efectuado: cola de registro
        last_reg_of_list_AST_type_reg = list_AST_type_reg;
    }
    else{
        // -- Insertar al final de la lista
        last_reg_of_list_AST_type_reg->next = reg;
        // -- Actualizar ultimo registro efectuado
        last_reg_of_list_AST_type_reg = last_reg_of_list_AST_type_reg->next;
    }

    return REG_OPERATION_SUCCESS;
}

void free_AST_type_register(){
    struct AST_type_register *current_AST_reg = list_AST_type_reg;
    while(current_AST_reg){
        // Obtener siguiente en la lista
        struct AST_type_register * next = current_AST_reg->next;

        // Liberar contenido
        free_type(current_AST_reg->type);

        // Liberar registro
        free(current_AST_reg);

        // Apuntar al siguiente de la lista
        current_AST_reg = next;
    }

    list_AST_type_reg = NULL;
    last_reg_of_list_AST_type_reg = NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE REGISTROS (SUBPROGRAMAS) -----

struct AST_subprogram_register * create_AST_subprogram_reg(struct subprogram *subprog){
    // -- Comprobar que hay nodo
    if(!subprog)
        return NULL;

    // -- Crear valor de dato
    union AST_node data; data.subprog = subprog;

    // -- Llamar a constructor de registros de nodos
    union AST_node_register reg = create_AST_node_register( AST_NODE_REG_SUBPROGRAM,data);

    return reg.subprog_reg;
}

int add_subprogram_to_register(struct subprogram *subprog){
    // -- Comprobar que hay subprograma
    if(!subprog)
        return REG_OPERATION_FAILURE;

    // -- Crear registro
    struct AST_subprogram_register * reg = create_AST_subprogram_reg(subprog);

    // -- Comprobar creacion de registro
    if(!reg)
        return REG_OPERATION_FAILURE;

    // --- Insertar en la lista de registros
    if(!list_AST_subprog_reg){
        // -- Insertar en la cabeza de registro
        list_AST_subprog_reg = reg;
        // -- Ultimo registro efectuado: cola de registro
        last_reg_of_list_AST_subprog_reg = list_AST_subprog_reg;
    }
    else{
        // -- Insertar al final de la lista
        last_reg_of_list_AST_subprog_reg->next = reg;
        // -- Actualizar ultimo registro efectuado
        last_reg_of_list_AST_subprog_reg = last_reg_of_list_AST_subprog_reg->next;
    }

    return REG_OPERATION_SUCCESS;
}

void free_AST_subprogram_register(){
    struct AST_subprogram_register *current_AST_reg = list_AST_subprog_reg;
    while(current_AST_reg){
        // Obtener siguiente en la lista
        struct AST_subprogram_register * next = current_AST_reg->next;

        // Liberar contenido
        free_subprogram(current_AST_reg->subprog);

        // Liberar registro
        free(current_AST_reg);

        // Apuntar al siguiente de la lista
        current_AST_reg = next;
    }

    list_AST_subprog_reg = NULL;
    last_reg_of_list_AST_subprog_reg = NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE REGISTROS (PROCESOS) -----

struct AST_process_register * create_AST_process_reg(struct process *proc){
    // -- Comprobar que hay nodo
    if(!proc)
        return NULL;

    // -- Crear valor de dato
    union AST_node data; data.proc = proc;

    // -- Llamar a constructor de registros de nodos
    union AST_node_register reg = create_AST_node_register( AST_NODE_REG_PROCESS,data);

    return reg.proc_reg;
}


int add_process_to_register(struct process *proc){
    // -- Comprobar que hay proceso
    if(!proc)
        return REG_OPERATION_FAILURE;

    // -- Crear registro
    struct AST_process_register * reg = create_AST_process_reg(proc);

    // -- Comprobar creacion de registro
    if(!reg)
        return REG_OPERATION_FAILURE;

    // --- Insertar en la lista de registros
    if(!list_AST_proc_reg){
        // -- Insertar en la cabeza de registro
        list_AST_proc_reg = reg;
        // -- Ultimo registro efectuado: cola de registro
        last_reg_of_list_AST_proc_reg = list_AST_proc_reg;
    }
    else{
        // -- Insertar al final de la lista
        last_reg_of_list_AST_proc_reg->next = reg;
        // -- Actualizar ultimo registro efectuado
        last_reg_of_list_AST_proc_reg = last_reg_of_list_AST_proc_reg->next;
    }

    return REG_OPERATION_SUCCESS;
}

void free_AST_process_register(){
    struct AST_process_register *current_AST_reg = list_AST_proc_reg;
    while(current_AST_reg){
        // Obtener siguiente en la lista
        struct AST_process_register * next = current_AST_reg->next;

        // Liberar contenido
        free_process(current_AST_reg->proc);

        // Liberar registro
        free(current_AST_reg);

        // Apuntar al siguiente de la lista
        current_AST_reg = next;
    }

    list_AST_proc_reg = NULL;
    last_reg_of_list_AST_proc_reg = NULL;
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE REGISTROS (STRING) -----

struct string_register * create_string_register(char * str){
    // -- Crear registro
    struct string_register * reg = malloc(sizeof(*reg));

    // -- Comprobar creacion del registro
    if(!reg)
        return NULL;

    // -- Copiar puntero de cadena de caracteres
    reg->str = str;
    // -- Inicializar puntero a siguiente nodo
    reg->next = NULL;

    // -- Retornar registro
    return reg;
}

int add_string_to_register(char * str){
    if(!str)
        return REG_OPERATION_FAILURE;

    // -- Crear registro
    struct string_register *new_reg = create_string_register(str);

    // -- Comprobar creacion de registro
    if(!new_reg)
        return REG_OPERATION_FAILURE;

    // -- Realizar insercion en el registro
    if(!list_str_reg){
        list_str_reg  = new_reg;
        // -- Ultimo registro efectuado: cabeza de registro
        last_str_reg = list_str_reg;
    }
    else{
        // -- Anexar al final del ultimo registro efectuado
        last_str_reg->next = new_reg;
        // -- Actualizar Ultimo registro efectuado
        last_str_reg = last_str_reg->next;
    }

    return REG_OPERATION_SUCCESS;
}

char * get_last_str_reg(){
    return last_str_reg->str;
}

void free_string_register(){
    // -- Comprobar si el registro dispone de datos
    if(!list_str_reg)
        return;

    // -- Definir apuntador de registros
    struct string_register * current_register = list_str_reg;
    // -- Recorrer el registro
    while(current_register){
        // -- Almecenar puntero a siguiente elemento
        struct string_register * next = current_register->next;

        // -- Liberar cadena de caracteres registrada
        if(current_register->str)
            free(current_register->str);

        // -- Liberar nodo
        free(current_register);

        // -- Nodo actual <-> Siguiente
        current_register = next;
    }

    // -- Devolver a NULL ambos punteros de registro
    list_str_reg = NULL;
    last_str_reg = NULL;
}