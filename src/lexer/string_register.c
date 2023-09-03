/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file string_register.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para manejo
 * de reconocimiento de cadenas de caracteres en el parser y lexer
 */

#include "lexer/string_register.h"

// ===============================================================

// ----- USO DE VARIABLES GLOBAL DE REGISTRO -----

// Variable global encargada de registrar todas las cadenas de caracteres reconocidas
struct StringRegister * string_register = NULL;

// Variable global encargada de almacenar el ultimo registro efectuado
struct StringRegister * last_string_register = NULL;

// ===============================================================

// ----- IMPLEMNTACION DE FUNCIONES DE GESTION DE REGISTRO -----

struct StringRegister * create_string_register(char * str){
    // -- Crear registro
    struct StringRegister * reg = malloc(sizeof(*reg));

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
    // -- Comprobar si el registro esta inicializado
    if(!string_register){
        // -- Inicializar registro
        string_register = create_string_register(str);

        // -- Volver a verificar
        if(!string_register)
            return STRING_REGISTER_FAILURE;

        // -- Ultimo registro efecturdo <-> cabecera de registro
        last_string_register = string_register;

        // -- Retornar exito
        return STRING_REGISTER_SUCCESS;
    }

    // -- Si ya hay elementos, definir un nuevo registro
    struct StringRegister * new_reg = create_string_register(str);

    // -- Anexar al final del ultimo elemento considerado
    last_string_register->next = new_reg;

    // -- Ultimo registro efectuado <-> nuevo registro
    last_string_register = new_reg;


    // -- Retornar exito
    return STRING_REGISTER_SUCCESS;
}

void free_string_register(){
    // -- Comprobar si el registro dispone de datos
    if(!string_register)
        return;

    // -- Definir apuntador de registros
    struct StringRegister * current_register = string_register;
    // -- Recorrer el registro
    while(current_register){
        // -- Almecenar puntero a siguiente elemento
        struct StringRegister * next = current_register->next;

        // -- Liberar cadena de caracteres registrada
        if(current_register->str)
            free(current_register->str);

        // -- Liberar nodo
        free(current_register);

        // -- Nodo actual <-> Siguiente
        current_register = next;
    }

    // -- Devolver a NULL ambos punteros de registro
    string_register = NULL;
    last_string_register = NULL;
}

void print_string_register(){
    // -- Comprobar si hay registros
    if(!string_register){
        printf(" --> <NONE>\n");
        return;
    }

    // -- Seleccionar nodo actual
    struct StringRegister * current_register = string_register;

    // -- Recorrer lista enlazada
    while (current_register){
        // -- Imprimir
        printf(" --> Registro: %s\n", current_register->str);

        // -- Ir a siguiente registro
        current_register = current_register->next;
    }
    
}