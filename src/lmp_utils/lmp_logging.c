/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_logging.c
 * @author Daniel Perez Ruiz
 * @brief Gestor de registro de eventos de lamport
 */

#include "lmp_utils/lmp_logging.h"

// ===============================================================

// ----- VARIABLES GLOBALES DE LOGGING -----

// Variable que contiene el fichero de registro de eventos
FILE * LMP_LOGGING_EVENTS_FILE = NULL;

// Variable que contiene el fichero de registro de Errores
FILE * LMP_LOGGING_ERRORS_FILE = NULL;

// Variable que contiene el fichero de registro de AST
FILE * LMP_LOGGING_AST_FILE = NULL;

// Variable que contiene el fichero de registro de IR
FILE * LMP_LOGGING_IR_FILE = NULL;

// ===============================================================

// ----- VARIABLES GLOBALES DE GESTION -----

// Variable que contiene el nombre del directorio donde se guardaran los ficheros de logging
const char * LMP_LOGGING_DIR = "log";

// Variable que contiene el nombre del directorio donde se almacenara el registro de eventos
const char * LMP_EVENTS_DIR = "log/events";

// Variable que contiene el nombre del directorio donde se almacenaran los errores encontrados
const char * LMP_ERRORS_DIR = "log/errors";

// Variable que contiene el nombre del directorio donde se almacenara el AST del programa
const char * LMP_AST_DIR = "log/AST";

// Variable que contiene el nombre del directorio donde se almacenara la representacion intermedia del programa
const char * LMP_IR_DIR = "log/IR";

// Variable que contiene el nombre de la extension de fichero de logging
const char * LMP_LOGGING_FILE_EXT = ".log";

// Variable que contiene el nombre de cabecera de fichero de logging de eventos
const char * LMP_LOGGING_FILE_EVENTS_HEADER = "log_events_";

// Variable que contiene el nombre de cabecera de fichero de logging de errores
const char * LMP_LOGGING_FILE_ERRORS_HEADER = "log_errors_";

// Variable que contiene el nombre de cabecera de fichero de logging de AST
const char * LMP_LOGGING_FILE_AST_HEADER = "log_ast_";

// Variable que contiene el nombre de cabecera de fichero de logging de IR
const char * LMP_LOGGING_FILE_IR_HEADER = "log_ir_";

// Variable que contiene el nombre de fichero que se va a crear para los registros
char * LMP_LOGGING_NAME_FILE = NULL;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE DIRECTORIOS -----

int create_dir(const char * dirname){
    // -- Definir permisos de directorio
    mode_t mode_dir = 0733; // rwx-wx-wx

    // -- Intentar crear el directorio
    int result = mkdir(dirname,mode_dir);

    // -- Comprobar resultado
    if(result != 0){
        return LMP_LOGGING_FAILURE;
    }

    // -- Retornar resultado correcto
    return LMP_LOGGING_SUCCESS;
}

int check_dir(const char * dirname){
    // -- Obtener estructura para obtener informacion de directorio
    struct stat dir_info;

    // -- Obtener informacion
    int result = stat(dirname,&dir_info);

    // -- Verificar
    if(result != 0){
        return 0;
    }

    // -- Comprobar ademas si es directorio
    if(!S_ISDIR(dir_info.st_mode)){
        return 0;
    }

    // -- Retornar exito
    return 1;
}

int lmp_create_logging_dir(char *lmp_file){
    // -- Comprobar existencia de fichero lamport a analizar
    if(!lmp_file)
        return LMP_LOGGING_FAILURE;

    // -- Asignar nombre de fichero a buffer
    if(assign_name_file_to_buff(lmp_file) < LMP_LOGGING_SUCCESS)
        return LMP_LOGGING_FAILURE;

    if(!check_dir(LMP_LOGGING_DIR)){
        // -- Crear directorio de logging
        return create_dir(LMP_LOGGING_DIR);
    }
    
    return LMP_LOGGING_SUCCESS;
}

int lmp_create_logging_events_dir(){
    if(!check_dir(LMP_EVENTS_DIR)){
        return create_dir(LMP_EVENTS_DIR);
    }

    return LMP_LOGGING_SUCCESS;
}

int lmp_create_logging_errors_dir(){
    if(!check_dir(LMP_ERRORS_DIR)){
        return create_dir(LMP_ERRORS_DIR);
    }

    return LMP_LOGGING_SUCCESS;
}

int lmp_create_logging_AST_dir(){
    if(!check_dir(LMP_AST_DIR)){
        return create_dir(LMP_AST_DIR);
    }

    return LMP_LOGGING_SUCCESS;
}

int lmp_create_logging_IR_dir(){
    if(!check_dir(LMP_IR_DIR)){
        return create_dir(LMP_IR_DIR);
    }

    return LMP_LOGGING_SUCCESS;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE USO DE LOGGING -----

void lmp_initialize_logging(char *lmp_file){
    // -- Ejecutar operacion de logging
    const int OP_SUCCESS = lmp_create_logging_dir(lmp_file) == LMP_LOGGING_SUCCESS;

    if(!OP_SUCCESS){
        // -- Se puede gestionar este error de alguna manera, ahora no necesario
    }
}

void lmp_initialize_logging_events(){
    // -- Ejecutar operacion de logging
    int OP_SUCCESS = lmp_create_logging_events_dir() == LMP_LOGGING_SUCCESS;

    if(!OP_SUCCESS){
        // -- Se puede gestionar este error de alguna manera, ahora no necesario
        return;
    }

    // -- Ejecutar operacion de logging
    OP_SUCCESS = lmp_create_logging_events_file() == LMP_LOGGING_SUCCESS;

    if(!OP_SUCCESS){
        // -- Se puede gestionar este error de alguna manera, ahora no necesario
    }
}

void lmp_initialize_logging_errors(){
    // -- Ejecutar operacion de logging
    int OP_SUCCESS = lmp_create_logging_errors_dir() == LMP_LOGGING_SUCCESS;

    if(!OP_SUCCESS){
        // -- Se puede gestionar este error de alguna manera, ahora no necesario
        return;
    }

    // -- Ejecutar operacion de logging
    OP_SUCCESS = lmp_create_logging_errors_file() == LMP_LOGGING_SUCCESS;

    if(!OP_SUCCESS){
        // -- Se puede gestionar este error de alguna manera, ahora no necesario
        return;
    }

    // -- Imprimir errores
    if(get_total_error_syntax() > 0)
        lmp_print_error_syntax(LMP_LOGGING_ERRORS_FILE);
    
    if(get_total_error_semantic() > 0)
        lmp_print_error_syntax(LMP_LOGGING_ERRORS_FILE);
}

void lmp_initialize_logging_AST(){
    // -- Ejecutar operacion de logging
    int OP_SUCCESS = lmp_create_logging_AST_dir() == LMP_LOGGING_SUCCESS;

    if(!OP_SUCCESS){
        // -- Se puede gestionar este error de alguna manera, ahora no necesario
        return;
    }

    // -- Ejecutar operacion de logging
    OP_SUCCESS = lmp_create_logging_AST_file() == LMP_LOGGING_SUCCESS;

    if(!OP_SUCCESS){
        // -- Se puede gestionar este error de alguna manera, ahora no necesario
        return;
    }

    // -- Imprimir AST
    lmp_print_AST(LMP_LOGGING_AST_FILE);
}

void lmp_initialize_logging_IR(){
    // -- Ejecutar operacion de logging
    int OP_SUCCESS = lmp_create_logging_IR_dir() == LMP_LOGGING_SUCCESS;

    if(!OP_SUCCESS){
        // -- Se puede gestionar este error de alguna manera, ahora no necesario
        return;
    }

    // -- Ejecutar operacion de logging
    OP_SUCCESS = lmp_create_logging_IR_file() == LMP_LOGGING_SUCCESS;

    if(!OP_SUCCESS){
        // -- Se puede gestionar este error de alguna manera, ahora no necesario
        return;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE FICHEROS DE LOGGING -----

int assign_name_file_to_buff(char *namefile){
    // -- Comprobar existencia
    if(!namefile)
        return LMP_LOGGING_FAILURE;

    // -- Realizar procesamiento de cadena
    char *original_namefile = strdup(namefile);

    if(!original_namefile)
        return LMP_LOGGING_FAILURE;

    // -- Eliminar todas las '/' que existan
    char * processed_namefile = strrchr(original_namefile,'/');
    // -- Comprobar si habia
    if(processed_namefile){
        LMP_LOGGING_NAME_FILE = strdup(processed_namefile+1);
    }
    else{
        LMP_LOGGING_NAME_FILE = strdup(namefile);
    }

    // -- Liberar memoria utilizada
    free(original_namefile); original_namefile = NULL;

    // -- Retornar exito
    return LMP_LOGGING_SUCCESS;
}

void free_name_file_from_buff(){
    // -- Comprobar asignacion de buffer
    if(LMP_LOGGING_NAME_FILE){
        free(LMP_LOGGING_NAME_FILE);
        LMP_LOGGING_NAME_FILE = NULL;
    }
}

char * create_logging_name_file(const char * logging_dir,const char * logging_header){
    const unsigned int BUFF_SIZE = 2048;
    char buff[BUFF_SIZE]; memset(buff,0,sizeof(buff));

    // -- Crear nombre de fichero en buffer
    sprintf(buff,"%s/%s%s%s",logging_dir,logging_header,LMP_LOGGING_NAME_FILE,LMP_LOGGING_FILE_EXT);

    // -- Asignar a cadena en memoria dinamica
    char *namefile = strndup(buff,strlen(buff));

    // -- Comprobar asignacion de namefile
    if(!namefile)
        return NULL;

    // -- Retornar nombre de fichero
    return namefile;
}

int create_logging_file(char ** namefile, FILE ** f){
    int result = LMP_LOGGING_SUCCESS;

    // -- Comprobar existencia de nombre de fichero
    if(!namefile)
        return LMP_LOGGING_FAILURE;

    // -- Abrir fichero
    *f = fopen(*namefile,"w");

    // -- Comprobar exito en la creacion del fichero
    if(!(*f))
        result = LMP_LOGGING_FAILURE;

    // -- Liberar memoria de nombre
    free(*namefile); *namefile = NULL;

    return result;
}

int lmp_create_logging_events_file(){
    // -- Crear nombre de fichero
    char * logging_name = create_logging_name_file(LMP_EVENTS_DIR,LMP_LOGGING_FILE_EVENTS_HEADER);

    // -- Comprobar creacion de nombre
    if(!logging_name)
        return LMP_LOGGING_FAILURE;

    // -- Crear fichero
    return create_logging_file(&logging_name,&LMP_LOGGING_EVENTS_FILE);
}

int lmp_create_logging_errors_file(){
    // -- Crear nombre de fichero
    char * logging_name = create_logging_name_file(LMP_ERRORS_DIR,LMP_LOGGING_FILE_ERRORS_HEADER);

    // -- Comprobar creacion de nombre
    if(!logging_name)
        return LMP_LOGGING_FAILURE;

    // -- Crear fichero
    return create_logging_file(&logging_name,&LMP_LOGGING_ERRORS_FILE);   
}

int lmp_create_logging_AST_file(){
    // -- Crear nombre de fichero
    char * logging_name = create_logging_name_file(LMP_AST_DIR,LMP_LOGGING_FILE_AST_HEADER);

    // -- Comprobar creacion de nombre
    if(!logging_name)
        return LMP_LOGGING_FAILURE;

    // -- Crear fichero
    return create_logging_file(&logging_name,&LMP_LOGGING_AST_FILE); 
}

int lmp_create_logging_IR_file(){
    // -- Crear nombre de fichero
    char * logging_name = create_logging_name_file(LMP_IR_DIR,LMP_LOGGING_FILE_IR_HEADER);

    // -- Comprobar creacion de nombre
    if(!logging_name)
        return LMP_LOGGING_FAILURE;

    // -- Crear fichero
    return create_logging_file(&logging_name,&LMP_LOGGING_IR_FILE);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE LIBERACION -----

void free_logging_events_file(){
    if(LMP_LOGGING_EVENTS_FILE){
        // -- Cerrar fichero
        fclose(LMP_LOGGING_EVENTS_FILE);
        LMP_LOGGING_EVENTS_FILE = NULL;
    }
}

void free_logging_errors_file(){
    if(LMP_LOGGING_ERRORS_FILE){
        // -- Cerrar fichero
        fclose(LMP_LOGGING_ERRORS_FILE);
        LMP_LOGGING_ERRORS_FILE = NULL;
    }
}

void free_logging_AST_file(){
    if(LMP_LOGGING_AST_FILE){
        // -- Cerrar fichero
        fclose(LMP_LOGGING_AST_FILE);
        LMP_LOGGING_AST_FILE = NULL;
    }
}

void free_logging_IR_file(){
    if(LMP_LOGGING_IR_FILE){
        // -- Cerrar fichero
        fclose(LMP_LOGGING_IR_FILE);
        LMP_LOGGING_IR_FILE = NULL;
    }
}

void free_logging_files(){
    free_logging_events_file();
    free_logging_errors_file();
    free_logging_AST_file();
    free_logging_IR_file();
}

void lmp_free_logging(){
    free_logging_files();
    free_name_file_from_buff();
}