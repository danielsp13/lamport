/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file instruction.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para generacion
 * de codigo intermedio [IR] lineal
 */

#include "IR/instruction.h"

// ===============================================================

// ----- DEFINICION DE VARIABLES GLOBALES -----   

// Variable para definir ID de etiquetas de salto (contador)
unsigned long CURRENT_JMP_LABEL_ID = 0;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE ASISTENCIA DE GESTION DE INSTRUCCIONES IR LINEAL -----

char * generate_IR_instruction_jmp_label_ID(){
    const unsigned int BUFF_SIZE = 3;
    char buff[BUFF_SIZE]; memset(buff, 0, sizeof(buff));

    // -- Construir etiqueta en buffer
    sprintf(buff,"L%ld",++CURRENT_JMP_LABEL_ID);

    // -- Construir cadena en memoria dinamica
    char * label = strndup(buff, strlen(buff));

    if(!label)
        return NULL;

    // -- Retornar mensaje
    return label;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE INSTRUCCIONES IR LINEAL -----

struct IR_instruction * create_IR_instruction(IR_instruction_type_t kind){
    // -- Reservar memoria para la instruccion
    struct IR_instruction * instr = malloc(sizeof(*instr));

    // -- Asignar tipo de instruccion
    instr->kind = kind;
    instr->kind_str = NULL;

    switch (instr->kind)
    {
    case IR_BIN_OP_SUM:
    {
        instr->kind_str = strdup("undefined");
        break;
    }
    
    default:
        break;
    }

    // -- Comprobar asignacion de tipo exitosa
    if(!instr->kind_str){
        free(instr);
        return NULL;
    }

    // -- Inicializar operandos de instruccion
    instr->op_left = NULL;
    instr->op_right = NULL;
    instr->op_result = NULL;

    // -- Inicializar etiquetas de salto
    instr->jmp_label = NULL;

    // -- Retornar instruccion
    return instr;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE LIBERACION DE INSTRUCCIONES IR LINEAL -----

void free_IR_instruction(struct IR_instruction * instr){
    if(!instr)
        return;

    // -- Liberar tipo de instruccion
    if(instr->kind_str){
        free(instr->kind_str);
        instr->kind_str = NULL;
    }

    // -- Liberar operandos
    if(instr->op_left){
        free_IR_operand(instr->op_left);
        instr->op_left = NULL;
    }

    if(instr->op_right){
        free_IR_operand(instr->op_right);
        instr->op_right = NULL;
    }

    if(instr->op_result){
        free_IR_operand(instr->op_result);
        instr->op_result = NULL;
    }

    // -- Liberar etiqueta de salto
    if(instr->jmp_label){
        free(instr->jmp_label);
        instr->jmp_label = NULL;
    }

    // -- Liberar nodo
    free(instr);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE IMPRESION DE INSTRUCCIONES IR LINEAL -----

void print_IR_instruction(struct IR_instruction * instr){
    if(!instr)
        return;

    // -- Imprimir etiqueta de salto (si existe)
    if(instr->jmp_label){
        printf("%s",instr->jmp_label);
    }
    // -- Imprimir instruccion en otro caso
    else{
        // -- Imprimir tipo de instruccion
        printf("%s ", instr->kind_str);

        // -- Imprimir operando izquierdo, si existe
        if(instr->op_left){
            print_IR_operand(instr->op_left);
        }

        // -- Imprimir operando derecho, si existe
        if(instr->op_right){
            printf(", ");
            print_IR_operand(instr->op_right);
        }

        // -- Imprimir operando resultado, si existe
        if(instr->op_result){
            printf(" \t -> ");
            print_IR_operand(instr->op_result);
        }
    }

    // -- Imprimir salto de linea
    printf("\n");
}