/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file common_functions.h
 * @author Daniel Perez Ruiz
 * @brief Implementación de funciones comunes a todos los ficheros de testeo
 */

//=============================================================================================

#include "test/common_functions.h"

Buffer* crear_buffer(){
    Buffer* buff = malloc(sizeof(Buffer));

    if(!buff){
        printf(">>> [ERROR] : No se pudo crear el buffer.\n");
        return NULL;
    }
    buff->total_lines = 0;

    return buff;
}


void destruir_buffer(Buffer* buff){
    if(buff){
        free(buff);
    }
}

int leer_fichero(const char* filename, Buffer* buff, int remove_newline){
    if(!buff){
        printf(">>> [ERROR] : Buffer no valido.\n");
        return -1;
    }

    FILE* f = fopen(filename,"r");
    if(!f){
        printf(">>> [ERROR] : No se pudo abrir el fichero [%s].\n",filename);
        return -1;
    }
    
    while(fgets(buff->lines[buff->total_lines],sizeof(buff->lines[0]),f) != NULL){
        if(remove_newline){
            char* newline = strchr(buff->lines[buff->total_lines], '\n');
            if (newline) {
                *newline = '\0';
            }
        }
        buff->total_lines++;

        if(buff->total_lines >= BUFF_MAX_LINES){
            break;
        }
    }

    fclose(f);

    return buff->total_lines;
}

char* zip_buffer(Buffer* buff){
    // -- Calcular el size necesario para reservar memoria
    size_t total_size = 0;
    for (int i=0; i < buff->total_lines; i++) {
        total_size += strlen(buff->lines[i]) + 1;
    }
    
    char* zipped_buffer = (char*)malloc(total_size);

    if (zipped_buffer == NULL) {
        printf(">>> [ERROR] : Fallo en la reserva de memoria para comprimir buffer. Saliendo.");
        exit(EXIT_FAILURE);
    }

    // -- Iniciar el buffer
    zipped_buffer[0] = '\0';

    // -- Comprimir buffer
    for(int i=0; i<buff->total_lines; i++){
        strcat(zipped_buffer,buff->lines[i]);
        strcat(zipped_buffer,"\n");
    }

    // -- Finalizar en nulo
    strcat(zipped_buffer,"\0");

    return zipped_buffer;
}


