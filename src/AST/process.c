/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file process.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO procesos
 */

#include "AST/process.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (PROCESOS) -----

struct process * create_process(process_t kind, char *name_process, struct declaration *declarations, struct statement *statements, unsigned long line){
    struct process *proc = malloc(sizeof(*proc));

    // -- Comprobar reserva de memoria exitosa
    if(!proc)
        return NULL;

    // -- Asignar tipo de proceso
    proc->kind = kind;

    // -- Asignar tipo de proceso (str)
    switch (proc->kind){
    case PROCESS_SINGLE:
        proc->kind_str = strdup("individual process");
        break;
    
    case PROCESS_VECTOR:
        proc->kind_str = strdup("vector process");
        break;

    default:
        proc->kind_str = NULL;
        break;
    }
    // -- Comprobar asignacion de tipo de proceso (str) exitoso
    if(!proc->kind_str){
        // -- Liberar memoria reservada para el proceso
        free(proc);
        return NULL;
    }

    // -- Asignar nombre de proceso
    proc->name_process = strdup(name_process);
    // -- Comprobar asignacion de nombre exitosa
    if(!proc->name_process){
        // -- Liberar memoria reservada para el proceso
        free(proc);
        return NULL;
    }

    // -- Asignar declaraciones del proceso
    proc->declarations = declarations;
    // -- Asignar sentencias del proceso
    proc->statements = statements;

    // -- Asignar identificador de indexacion de vector de procesos (NULL)
    proc->index_identifier = NULL;
    // -- Asignar expresion de inicio de rango de vector de procesos (NULL)
    proc->index_start = NULL;
    // -- Asignar expresion de fin de rango de vector de procesos (NULL)
    proc->index_end = NULL;

    // -- Asignar puntero a siguiente proceso (NULL)
    proc->next = NULL;

    // -- Asignar referencia a simbolo de tabla de simbolos (id de proceso) (NULL) 
    proc->symb_process = NULL;
    // -- Asignar referencia a simbolo de tabla de simbolos (id de indice de proceso) (NULL)
    proc->symb_index = NULL;

    // -- Asignar linea donde se definio el proceso
    proc->line = line;

    // -- Retornar proceso creado e inicializado
    return proc;
}

struct process * create_process_single(char *name_process, struct declaration *declarations, struct statement *statements, unsigned long line){
    // -- Retornar proceso creado e inicializado
    return create_process(PROCESS_SINGLE, name_process, declarations, statements, line);
}

struct process * create_process_vector(char *name_process, struct declaration *declarations, struct statement *statements, char *index_identifier, struct expression *index_start, struct expression *index_end, unsigned long line){
    struct process * proc = create_process(PROCESS_VECTOR, name_process, declarations, statements, line);

    // -- Comprobar creacion del proceso exitosa
    if(!proc)
        return NULL;

    // -- Asignar identificador de indexacion de vector de procesos (NULL)
    proc->index_identifier = strdup(index_identifier);

    // -- Comprobar asignacion de id de indexacion exitoso
    if(!proc->index_identifier){
        // -- Liberar memoria reservada para el proceso
        free(proc);
        return NULL;
    }

    // -- Asignar expresion de inicio de rango de vector de procesos
    proc->index_start = index_start;
    // -- Asignar expresion de inicio de rango de vector de procesos
    proc->index_end = index_end;

    // -- Asegurar que ni el inicio ni el fin de rango son nulos
    if(!proc->index_start || !proc->index_end){
        // -- Liberar memoria reservada para el proceso
        free(proc);
        return NULL;
    }

    // -- Retornar proceso creado e inicializado
    return proc;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO PROCESOS) -----

void free_list_process(struct process *process_list){
    struct process *current_process = process_list;
    while(current_process){
        // -- Seleccionar siguiente en la lista
        struct process *next = current_process->next;
        // -- Liberar nodo
        free_process(current_process);
        // -- Nodo actual -> siguiente
        current_process = next;
    }
}

void free_process(struct process *proc){
    // -- Si NULL, simplemente devolver
    if(!proc)
        return;

    // -- Liberar tipo de proceso (str)
    if(proc->kind_str){
        free(proc->kind_str);
        proc->kind_str = NULL;
    }

    // -- Liberar nombre de proceso
    if(proc->name_process){
        free(proc->name_process);
        proc->name_process = NULL;
    }

    // -- Liberar declaraciones de proceso
    if(proc->declarations){
        free_list_declarations(proc->declarations);
        proc->declarations = NULL;
    }

    // -- Liberar sentencias de proceso
    if(proc->statements){
        free_list_statements(proc->statements);
        proc->statements = NULL;
    }

    // -- Comprobar tipo de proceso para definir mas liberaciones
    switch (proc->kind)
    {
    case PROCESS_VECTOR:
        // -- Liberar identificador de indexacion de proceso
        free(proc->index_identifier);
        proc->index_identifier = NULL;

        // -- Liberar rango de inicio
        free_expression(proc->index_start);
        proc->index_start = NULL;

        // -- Liberar rango de fin
        free_expression(proc->index_end);
        proc->index_end = NULL;

        // -- Liberar referencia a simbolo de la tabla de simbolos (id de indice en caso de vector)
        free_symbol(proc->symb_index);
        proc->symb_index = NULL;

        break;
    
    default:
        break;
    }

    // -- Liberar referencia a simbolo de la tabla de simbolos (id de proceso)
    if(proc->symb_process){
        free_symbol(proc->symb_process);
        proc->symb_process = NULL;
    }
        

    // -- Liberar nodo
    free(proc);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO PROCESO) -----

void print_AST_process(struct process *process_list, unsigned int depth){
    // -- Determinar identacion de nodo
    char * IDENT_NODE_BRANCH = build_identation_branch(depth);
    char * IDENT_NODE = build_identation_spaces(depth);
    // -- Determinar profundidad del siguiente nodo
    const unsigned int NEXT_NODE_DEPTH = depth+2;

    // -- Si NULL, simplemente devolver
    if(!process_list){
        printf("%s%s %s\n",IDENT_NODE_BRANCH, IDENT_ARROW, NULL_NODE_MSG);
        
        // -- Liberar memoria utilizada para la identacion
        free(IDENT_NODE); IDENT_NODE = NULL; 
        free(IDENT_NODE_BRANCH); IDENT_NODE_BRANCH = NULL;

        return;
    }

    struct process *current_process = process_list;
    while(current_process){
        // -- Imprimir nombre y tipo de proceso
        printf("%s%s %c NOMBRE DE PROCESO: [%s] DE TIPO: [%s]\n", IDENT_NODE_BRANCH, IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL, current_process->name_process, current_process->kind_str);
        // -- Imprimir informacion adicional de proceso (si es necesario)
        switch (current_process->kind)
        {
        case PROCESS_VECTOR:
            printf("%s%s %c INDEXADOR DE VECTOR DE PROCESOS: [%s]\n", IDENT_NODE_BRANCH, IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL, current_process->index_identifier);
            printf("%s%s %c RANGO DE INICIO DEL VECTOR: \n", IDENT_NODE_BRANCH, IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_process->index_start,NEXT_NODE_DEPTH);
            printf("%s%s %c RANGO DE FIN DEL VECTOR: \n", IDENT_NODE_BRANCH, IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL);
            print_AST_expressions(current_process->index_end,NEXT_NODE_DEPTH);
            break;
        
        default:
            break;
        }

        printf("\n");

        // -- Imprimir declaraciones de proceso
        printf("%s%s %c DECLARACIONES DE PROCESO:\n", IDENT_NODE_BRANCH, IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL);
        print_AST_declarations(current_process->declarations,NEXT_NODE_DEPTH);

        printf("\n");

        // -- Imprimir sentencias de proceso
        printf("%s%s %c SENTENCIAS DE PROCESO:\n", IDENT_NODE_BRANCH, IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL);
        print_AST_statements(current_process->statements,NEXT_NODE_DEPTH);

        printf("\n");

        // Ir al siguiente proceso
        current_process = current_process->next;
    }

    // -- Liberar memoria utilizada para la identacion
    free(IDENT_NODE); IDENT_NODE = NULL; 
    free(IDENT_NODE_BRANCH); IDENT_NODE_BRANCH = NULL;
}