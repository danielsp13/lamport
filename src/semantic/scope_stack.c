/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file scope_stack.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para creacion y mantenimiento
 * de una pila de tablas hash (scope)
 */

#include "semantic/scope_stack.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE UN NODO (NODE_STACK) -----

struct node_stack * create_node_stack(scope * scope){
    struct node_stack * node = malloc(sizeof(*node));

    // -- Comprobar reserva de memoria exitosa
    if(!node)
        return NULL;

    // -- Asignar scope
    node->scope = scope;
    // -- Asignar puntero a siguiente scope
    node->next = NULL;

    // -- Retornar nodo inicializado
    return node;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE UNA PILA (STACK) -----

struct scope_stack* create_scope_stack(){
    struct scope_stack* st = malloc(sizeof(*st));

    // -- Comprobar reserva de memoria exitosa
    if(!st)
        return NULL;

    // -- Asignar valor inicial de elementos de pila
    st->num_scopes = 0;
    // -- Asginar tope de pila inicial (NULL)
    st->top = NULL;

    // -- Retornar pila inicializada
    return st;
}

void push_scope_stack(struct scope_stack* st, struct node_stack * node){
    // -- Comprobar que la pila no es nula
    if(!st || !node)
        return;

    // -- Realizar insercion en la pila
    // -- Indicar como siguiente nodo del que se inserta, al antiguo tope
    node->next = st->top;

    // -- Agregar nuevo tope
    st->top = node;

    // -- Incrementar numero de scopes actuales
    st->num_scopes++;
}

void pop_scope_stack(struct scope_stack* st){
    // -- Comprobar que la pila no es nula
    if(!st)
        return;

    // -- Obtener el tope de la pila actual
    struct node_stack * top = get_top_scope_stack(st);

    // -- Tope actual sera el siguiente al nodo tope
    st->top = top->next;

    // -- Decrementar numero de scopes actuales
    st->num_scopes--;

    // -- Liberar tope de pila eliminado
    free_node_stack(top);
}

unsigned int get_size_scope_stack(struct scope_stack* st){
    // -- Comprobar que la pila no es nula
    if(!st)
        return -1;

    // -- Retornar numero de scopes
    return st->num_scopes;
}

struct node_stack * get_top_scope_stack(struct scope_stack* st){
    // -- Comprobar que la pila no es nula
    if(!st)
        return NULL;

    // -- Retornar tope de pila
    return st->top;
}

unsigned int empty_scope_stack(struct scope_stack* st){
    // -- Comprobar que la pila no es nula
    if(!st)
        return -1;

    // -- Comprobar que num_scopes es 0 y que no hay nada en el tope de pila
    return (st->num_scopes == 0) && (!st->top);
}


// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE LIBERACION DE UN NODO (NODE_STACK) -----

void free_node_stack(struct node_stack * node){
    // -- Comprobar que el nodo no es nulo
    if(!node)
        return;

    // -- Liberar scope
    free_scope(node->scope);
    node->scope = NULL;

    // -- Liberar nodo
    free(node);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE LIBERACION DE UNA PILA (STACK) -----

void free_scope_stack(struct scope_stack * st){
    // -- Comprobar que la pila no es nula
    if(!st)
        return;

    // -- Realizar pop de la pila hasta que no haya elementos
    while(st->top){
        pop_scope_stack(st);
    }

    // -- Liberar memoria para la pila
    free(st);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE IMPRESION DE UN NODO (NODE_STACK) -----

void print_node_stack(struct node_stack * node){
    const char *IDENT_ARROW = "---> ";

    // -- Comprobar que nodo no es nulo
    if(!node){
        // -- Comprobar que la pila no es nula
        printf(" %s <NONE> \n", IDENT_ARROW);
        return;
    }

    // -- Imprimir scope
    print_scope(node->scope);
}


// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE IMPRESION DE UNA PILA (STACK) -----

void print_scope_stack(struct scope_stack * st){
    const char *IDENT_ARROW = "--> ";
    const char *SEPARATOR = "=======================================================";

    // -- Comprobar que la pila no es nula
    if(!st){
        printf(" %s <NONE> \n", IDENT_ARROW);
        return;
    }

    // -- Imprimir tope de pila
    printf("%s\n", SEPARATOR);
    printf(" %s TOPE DE PILA!!!! \n",IDENT_ARROW);
    printf("%s\n", SEPARATOR);
    print_node_stack(st->top);
    printf("%s\n", SEPARATOR);

    // -- Imprimir resto de contenido
    printf("\n");
    printf("%s\n", SEPARATOR);
    printf(" %s RESTO DE CONTENIDO DE LA PILA \n",IDENT_ARROW);
    printf("%s\n", SEPARATOR);

    struct node_stack * current_node = st->top->next;
    while(current_node){
        printf("%s\n", SEPARATOR);
        print_node_stack(current_node);
        printf("%s\n", SEPARATOR);
        printf("\n");

        current_node = current_node->next;
    }

    printf("\n");
}