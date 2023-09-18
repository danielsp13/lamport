/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file scope.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para creacion y mantenimiento
 * de un ambito (scope)
 */

#include "semantic/scope.h"


// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE ENTRADAS -----

entry * create_entry(char * key, struct symbol * value){
    entry * entry = malloc(sizeof(*entry));

    // -- Comprobar reserva de memoria exitosa
    if(!entry)
        return NULL;

    // -- Asignar llave de registro
    entry->key = strdup(key);
    // -- Comprobar asignacion de llave de registro existosa
    if(!entry->key){
        // -- Liberar memoria reservada a la entrada
        free(entry);
        return NULL;
    }

    // -- Asignar simbolo
    entry->value = value;

    // -- Asignar puntero a siguiente entrada (NULL)
    entry->next = NULL;

    // -- Retornar entrada creada e inicializada
    return entry;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE SCOPES -----

unsigned int hash(char * key){
    /**
     * La funcion hash utilizada se fundamenta en el metodo de Horner de
     * evaluacion de polinomios.
     * 
     * En nuestro caso, consideramos la cadena key de longitud n, donde disponemos
     * los caracteres en key[0] , key[1] , ... key[n-1].
     * 
     * Entonces la evaluacion seria de la siguiente manera
     * P(key) = key[0] + key[1]*base + key[2]*base^2 + ... + key[n-1]* base^(n-1)
     * 
     * Esa sera la forma de realizar la funcion hash
     */

    const unsigned int base = 31;                   ///< Base multiplicadora (usar numero primo reduce colisiones)
    const unsigned int key_length = strlen(key);    ///< Longitud de la llave

    unsigned long long hash = 0;                    ///< Hash

    // -- Aplicacion del metodo de horner
    for(unsigned int i=0; i<key_length; i++){
        hash = (hash * base) + key[i];
    }

    // -- Retornar el resultado del resto de hash entre el maximo size de tabla
    return hash % MAX_SCOPE_SIZE;
}

scope * create_scope(){
    scope * scope = malloc(sizeof(*scope));

    // -- Comprobar reserva de memoria exitosa
    if(!scope)
        return NULL;

    // -- Inicializar cada registro de la tabla a NULL
    for(unsigned int i=0; i<MAX_SCOPE_SIZE; i++)
        scope->table[i] = NULL;

    // -- Retornar scope creado e inicializado
    return scope;
}

int insert_symbol_into_scope(scope * scope, struct symbol * value){
    // -- Comprobar si el scope existe y esta inicializado
    if(!scope)
        return SCOPE_OPERATION_FAILURE;

    // -- Si existe, crear una nueva entrada para el simbolo
    entry * new_entry = create_entry(value->name, value);

    // -- Comprobar creacion de la entrada exitosa
    if(!new_entry)
        return SCOPE_OPERATION_FAILURE;

    // -- Obtener indice de tabla para la entrada
    unsigned int index = hash(new_entry->key);

    // -- Obtener entrada actual en esa posicion
    entry * current_entry = scope->table[index];

    // -- Si NULL, quiere decir que no hay colision, es el primer registro en ese indice
    if(!current_entry){
        // -- insertar nuevo registro en esa posicion
        scope->table[index] = new_entry;
    }
    // -- En caso contrario, se produjo colision, enlazar con la entrada actual ya existente en cabeza
    else{
        current_entry->next = new_entry;
    }

    // -- Retornar resultado exitoso de operacion
    return SCOPE_OPERATION_SUCCESS;
}

entry * get_slot_from_scope_using_index(scope * scope, unsigned int index){
    // -- Comprobar si el scope existe y esta inicializado
    if(!scope)
        return NULL;
    
    // -- Retornar la lista de entradas enlazadas correspondientes a ese slot
    return scope->table[index];
}

entry * get_slot_from_scope_using_key(scope * scope, char * key){
    // -- Comprobar si el scope y la llave existen y estan inicializados
    if(!scope || !key)
        return NULL;

    // -- Si existe, calcular indice de slot donde podria encontrarse mediante el hash de la llave
    unsigned int index = hash(key);

    // -- Retornar la lista de entradas enlazadas correspondientes a ese slot
    return get_slot_from_scope_using_index(scope, index);
}

entry * get_entry_from_scope(scope * scope, char * key){
    // -- Obtener la lista de entradas enlazadas correspondientes a ese slot
    entry * current_entry = get_slot_from_scope_using_key(scope, key);

    // -- Comprobar si la entrada actual es nula directamente
    if(!current_entry)
        return NULL;

    // -- En otro caso, recorrer
    while (current_entry){
        // -- Comprobar coincidencia
        if(strcmp(current_entry->key, key) == 0){
            // -- Retornar directamente la entrada
            return current_entry;
        }
        // -- En otro caso, comprobar siguiente
        current_entry = current_entry->next;
    }

    // -- Retornar NULL si no se obtuvo ninguna entrada
    return NULL;
}

struct symbol * get_symbol_from_scope(scope * scope, char * key){
    // -- Obtener la lista de entradas enlazadas correspondiente al slot al que pertenece la clave de registro
    entry * entry = get_entry_from_scope(scope, key);

    // -- Comprobar si la entrada es nula directamente
    if(!entry)
        return NULL;

    // -- En otro caso, retornar valor de simbolo 
    return entry->value;
}

void remove_symbol_from_scope(scope * scope, char * key){
    // -- Comprobar la existencia de entrada
    entry * target_entry = get_entry_from_scope(scope, key);

    // -- Comprobar si la entrada es nula directamente
    if(!target_entry)
        return;
    
    // -- Si se ha encontrado la tabla, realizar redimension del slot
    // -- Obtener indice de slot
    unsigned int index = hash(key);
    // -- Obtener primero el slot completo, a partir del indice de slot
    entry * current_entry = get_slot_from_scope_using_index(scope, index);
    
    // -- Caso 1: Si la entrada a eliminar se encuentra al principio del slot...
    if(current_entry == target_entry){
        // -- Indicar que la primera entrada del slot ahora sera la siguiente de la entrada a eliminar
        entry * first_entry = current_entry->next;

        // -- Apuntar ahora a nuevo slot sin la entrada eliminada
        scope->table[index] = first_entry;

        // -- Liberar memoria reservada para la entrada a eliminar
        free_entry(target_entry);

        // -- Retornar
        return;
    }

    // -- Caso 2: Si la entrada a eliminar se encuentra en alguna parte del slot
    while(current_entry){
        // -- Comprobar si el siguiente de la entrada actual, es la que se quiere eliminar
        if(current_entry->next == target_entry){
            // -- Recortar: ahora el siguiete del actual, sera el siguiente del que se elimina
            current_entry->next = target_entry->next;

            // -- Liberar memoria reservada para la entrada a eliminar
            free_entry(target_entry);

            // -- Retornar
            return;
        }
        // -- En otro caso, seguir recorriendo
        current_entry = current_entry->next;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE LIBERACION DE ENTRADAS -----

void free_list_entry(entry * list_entry){
    // -- Comprobar que la lista esta inicializada y creada
    if(!list_entry)
        return;

    // -- Recorrer la lista enlazada de entradas
    entry * current_entry = list_entry;
    while(current_entry){
        // -- Recuperar siguiente en la lista
        entry * next = current_entry->next;

        // -- Liberar entrada actual
        free_entry(current_entry);

        // -- entrada actual <-> siguiente en la lista
        current_entry = next;
    }
}

void free_entry(entry * entry){
    // -- Comprobar que entrada est inicializada y creada
    if(!entry)
        return;

    // -- Liberar key de entrada actual
    if(entry->key){
        free(entry->key);
        entry->key = NULL;
    }

    // -- Liberar simbolo de entrada actual
    if(entry->value){
        //free_symbol(entry->value);
        entry->value = NULL;
    }

    // -- Liberar entrada completa
    free(entry);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE LIBERACION DE SCOPES -----

void free_scope(scope * scope){
    // -- Comprobar que scope esta inicializado y creado
    if(!scope)
        return;

    // -- Recorrer todas las entradas de la tabla, y liberar cada una de ellas
    for(unsigned int i=0; i<MAX_SCOPE_SIZE; i++){
        // -- Liberar entradas asociadas al slot (si existe)
        if(scope->table[i]){
            free_list_entry(scope->table[i]);
            scope->table[i] = NULL;
        }
    }

    // -- Liberar scope
    free(scope);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE IMPRESION DE ENTRADAS -----

void print_list_entry(entry * list_entry, int index){
    const char *IDENT_ARROW = "--------> ";

    // -- Comprobar que la lista de entradas apunta a algo
    if(!list_entry){
        printf(" %s <NONE> \n", IDENT_ARROW);
        return;
    }

    // -- Imprimir lista de entradas
    printf(" %s CONTENIDO DE SLOT [%d] \n", IDENT_ARROW, index);
    entry * current_entry = list_entry;
    while(current_entry){
        // -- Imprimir entrada actual
        print_entry(current_entry);

        // -- Ir a la siguiente entrada
        current_entry = current_entry->next;
    }
}

void print_entry(entry * entry){
    const char *IDENT_ARROW = "-----> ";
    
    // -- Comprobar que entrada apunta a algo
    if(!entry){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }

    // -- Imprimir clave de registro
    printf(" %s CLAVE DE ENTRADA: [%s]\n", IDENT_ARROW, entry->key);
    // -- Imprimir simbolo
    printf(" %s SIMBOLO ALMACENADO DE ENTRADA: [%s]\n", IDENT_ARROW, entry->key);
    print_symbol(entry->value);
}


// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE IMPRESION DE SCOPES -----

void print_scope(scope * scope){
    const char *IDENT_ARROW = "-> ";

    // -- Comprobar que scope apunta a algo
    if(!scope){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }

    // -- Imprimir entradas de scope
    printf(" %s CONTENIDO DE SCOPE COMPLETO\n", IDENT_ARROW);
    for(unsigned int i=0; i<MAX_SCOPE_SIZE; i++){
        if(scope->table[i]){
            print_list_entry(scope->table[i], i);
            printf("\n");
        }
    }
}