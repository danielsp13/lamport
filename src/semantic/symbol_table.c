/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file symbol_table.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para creacion y mantenimiento
 * de una tabla de simbolos
 */

#include "semantic/symbol_table.h"

// ===============================================================

// ----- USO DE VARIABLE GLOBAL TABLA DE SIMBOLOS (SYMBOL_TABLE) -----

// Variable global encargada de definir la tabla de simbolos
struct scope_stack * symbol_table = NULL;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE TABLA DE SIMBOLOS -----

int initialize_symbol_table(){
    // -- Crear nueva pila de tablas hash
    symbol_table = create_scope_stack();

    // -- Comprobar que no es nulo
    if(!symbol_table)
        return SYMB_TABLE_INIT_FAILURE;
    
    // -- Retornar exito de operacion
    return SYMB_TABLE_OPERATION_SUCCESS;
}

int push_scope_to_symbol_table(){
    // -- Comprobar que la tabla de simbolos esta inicializada
    if(!symbol_table)
        return SYMB_TABLE_PUSH_SCOPE_FAILURE;

    // -- Crear nuevo scope
    scope * new_scope = create_scope();

    // -- Comprobar que se ha creado un nuevo scope
    if(!new_scope)
        return SYMB_TABLE_PUSH_SCOPE_FAILURE;

    // -- Crear nuevo nodo para insercion en la tabla
    struct node_stack * new_node = create_node_stack(new_scope);

    // -- Comprobar que se ha creado un nuevo nodo
    if(!new_node)
        return SYMB_TABLE_PUSH_SCOPE_FAILURE;

    // -- Finalmente, realizar insercion
    push_scope_stack(symbol_table,new_node);

    // -- Retornar exito de operacion
    return SYMB_TABLE_OPERATION_SUCCESS;
}

int remove_current_scope_from_symbol_table(){
    // -- Comprobar que la tabla de simbolos esta inicializada
    if(!symbol_table)
        return SYMB_TABLE_POP_SCOPE_FAILURE;

    // -- Realizar pop
    pop_scope_stack(symbol_table);

    // -- Retornar exito de operacion
    return SYMB_TABLE_OPERATION_SUCCESS;
}

int scope_level(){
    // -- Comprobar que la tabla de simbolos esta inicializada
    if(!symbol_table)
        return SYMB_TABLE_SCOPE_LEVEL_FAILURE;

    // -- Retornar numero de scopes
    get_size_scope_stack(symbol_table);
}

scope * get_current_scope(){
    // -- Comprobar que la tabla de simbolos esta inicializada
    if(!symbol_table)
        return NULL;

    // -- Retornar el scope actual
    return symbol_table->top->scope;
}

scope * get_scope_from_index(unsigned int index){
    // -- Comprobar que la tabla de simbolos esta inicializada
    if(!symbol_table)
        return NULL;

    // -- Obtener numero de scopes existentes
    const unsigned int total_scopes = get_size_scope_stack(symbol_table);
    unsigned int current_scope = total_scopes;

    // -- Comprobar si indice esta fuera de los limites
    if(index < 0 || index > total_scopes)
        return NULL;

    // -- Recorrer la pila (del tope hacia el fondo)
    struct node_stack * current_node = symbol_table->top;
    while(index != current_scope && index != 0 && current_node){
        // -- Ir a siguiente nodo
        current_node = current_node->next;

        // -- Decrementar nodo actual
        current_scope--;
    }

    // -- Si nodo actual es nulo, no se han encontrado coincidencias correspondientes al indice
    if(!current_node)
        return NULL;

    // -- Retornar scope
    return current_node->scope;
}

int bind_symbol_to_scope(struct symbol * symb){
    // -- Comprobar que simbolo y tabla de simbolos existen
    if(!symbol_table || !symb)
        return SYMB_TABLE_BIND_SYMBOL_FAILURE;

    // -- Comprobar que la pila no esta vacia
    if(empty_scope_stack(symbol_table))
        return SYMB_TABLE_BIND_SYMBOL_FAILURE;

    // -- Realizar insercion de simbolo en scope actual
    insert_symbol_into_scope(symbol_table->top->scope, symb);

    // -- Retornar operacion exitosa
    return SYMB_TABLE_OPERATION_SUCCESS;
}

struct symbol * lookup_symbol_from_current_scope(char * name){
    // -- Comprobar que nombre y tabla de simbolos existen
    if(!symbol_table || !name)
        return NULL;

    // -- Comprobar que la tabla de simbolos no esta vacia
    if(empty_scope_stack(symbol_table))
        return NULL;

    // -- Retornar exito/fracaso de busqueda en el scope actual
    return get_symbol_from_scope(symbol_table->top->scope,name);
}

struct symbol * lookup_symbol_from_specific_scope(char * name, int index){
    // -- Comprobar que nombre y tabla de simbolos existen
    if(!symbol_table || !name)
        return NULL;

    // -- Obtener scope asociado al indice
    scope * target_scope = get_scope_from_index(index);

    // -- Comprobar si se ha encontrado un scope candidato
    if(!target_scope)
        return NULL;

    // -- Retornar exito/fracaso de busqueda en el scope especifico
    return get_symbol_from_scope(target_scope, name);
}

struct symbol * lookup_symbol_from_all_scopes(char * name){
    // -- Comprobar que nombre y tabla de simbolos existen
    if(!symbol_table || !name)
        return NULL;

    // -- Obtener total de scopes actuales
    const unsigned int total_scopes = scope_level();

    // -- Variable para obtencion de simbolo a buscar
    struct symbol * target_symbol = NULL;

    // -- Recorrer todos los scopes
    for(unsigned int i=0; i<total_scopes; i++){
        target_symbol = lookup_symbol_from_specific_scope(name, i);

        // -- Comprobar si no es nulo, y en ese caso, retornar
        if(target_symbol)
            return target_symbol;
    }

    // -- Retornar NULL, pues no se habra encontrado ninguna coincidencia
    return NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE LIBERACION DE TABLA DE SIMBOLOS -----

int free_symbol_table(){
    // -- Comprobar existencia de la tabla de simbolos
    if(!symbol_table)
        return SYMB_TABLE_FREE_FAILURE;

    // -- Llamar a liberar la pila
    free_scope_stack(symbol_table);

    // -- Retornar exito
    return SCOPE_OPERATION_SUCCESS;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE IMPRESION DE TABLA DE SIMBOLOS -----

void print_symbol_table(){
    const char *IDENT_ARROW = "-----";
    
    // -- Comprobar existencia de tabla de simbolos
    if(!symbol_table)
        return;

    // -- Llamar a impresion de pila
    printf(" %s CONTENIDO DE LA TABLA DE SIMBOLOS: \n", IDENT_ARROW);
    print_scope_stack(symbol_table);
}