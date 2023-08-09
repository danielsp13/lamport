/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file test_lexer_recon_ficheros.c
 * @author Daniel Perez Ruiz
 * @brief Tests del analizador lexico : reconocimiento de ficheros
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

//Incluir analizador lexico
#include "lexer.c"

//Incluir funciones comunes
#include "common_functions.h"

// -- Macro que define la ruta donde se encuentran los ficheros de pruebas
#define EXAMPLES_PATH "examples/programs"
#define EXAMPLES_RESULT_PATH "examples/programs/tokens"
#define LMP_EXT ".lmp"
#define TXT_EXT ".txt"
// -- Macros que definen los nombres de ficheros de pruebas
#define LAMPORT_P1_FILE "program1"
#define LAMPORT_P2_FILE "program2"
#define LAMPORT_P3_FILE "program3"
#define LAMPORT_P4_FILE "program4"
#define LAMPORT_P5_FILE "program5"
#define LAMPORT_P6_FILE "program6"
#define LIST_TOKENS_PREFIX "list_tokens_"

// ==================================================================================

// DEFINICION DE FUNCIONES AUXILIARES

/**
 * @brief Dado un fichero del lenguaje lamport, extrae sus tokens
 * @param file : Nombre del fichero del lenguaje lamport
 * @return puntero a buffer con los tokens
 */
Buffer* obtener_tokens_programa(const char* file);

/**
 * @brief Dado un fichero que contiene lista de tokens de un programa, se abre el fichero
 * y se almacena en un buffer
 * @param file : Nombre del fichero que contiene los tokens
 * @return puntero a buffer con la informacion
 */
Buffer* obtener_lista_tokens_esperada(const char* file);

/**
 * @brief Dados el buffer de tokens reconocidos del lexer y el esperado, se comparan sus
 * resultados uno por uno
 * @param tokens_lexer : lista de tokens extraidos del analizador lexico
 * @param tokens_expected : Lista de tokens esperados
 */
void comparar_resultados_lexer(Buffer* tokens_lexer, Buffer* tokens_expected);

// ==================================================================================

// DEFINICION DE FUNCIONES DE TEST

static void test_scan_program1_lamport(void **state);
static void test_scan_program2_lamport(void **state);
static void test_scan_program3_lamport(void **state);
static void test_scan_program4_lamport(void **state);
static void test_scan_program5_lamport(void **state);
static void test_scan_program6_lamport(void **state);


// ==================================================================================


int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_scan_program1_lamport),
        cmocka_unit_test(test_scan_program2_lamport),
        cmocka_unit_test(test_scan_program3_lamport),
        cmocka_unit_test(test_scan_program4_lamport),
        cmocka_unit_test(test_scan_program5_lamport),
        cmocka_unit_test(test_scan_program6_lamport),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

// ==================================================================================

// IMPLEMENTACION DE FUNCIONES AUXILIARES

Buffer* obtener_tokens_programa(const char* file){
    // -- Crear buffers y obtener lineas de codigo
    Buffer* buff_programa = crear_buffer();
    leer_fichero(file,buff_programa,0);
    const char * programa = zip_buffer(buff_programa);
    destruir_buffer(buff_programa);
    
    Buffer* buff_tokens = crear_buffer();
    
    // -- Escanear el buffer
    YY_BUFFER_STATE buffer = yy_scan_string(programa);

    int token;
    while((token = yylex()) != 0){
        char token_string[10]; sprintf(token_string,"%d",token);
        strcpy(buff_tokens->lines[buff_tokens->total_lines], token_string);
        buff_tokens->total_lines++;
    }

    yy_delete_buffer(buffer);

    return buff_tokens;
}

Buffer* obtener_lista_tokens_esperada(const char* file){
    // -- Crear buffer y obtener tokens esperados
    Buffer* buff_expected_tokens = crear_buffer();
    leer_fichero(file,buff_expected_tokens,1);

    return buff_expected_tokens;
}

void comparar_resultados_lexer(Buffer* tokens_lexer, Buffer* tokens_expected){
    // -- Asertar primero que se ha leido la misma cantidad de tokens
    //assert_int_equal(tokens_lexer->total_lines,tokens_expected->total_lines);
    // -- Si se afirma, el siguiente caso es comprobar cada token
    for(int i=0; i<tokens_lexer->total_lines; i++){
        assert_string_equal(tokens_lexer->lines[i],tokens_expected->lines[i]);
    }
}


// ==================================================================================

// IMPLEMENTACION DE FUNCIONES DE TEST

static void test_scan_program1_lamport(void **state){
    (void) state;  // Descartamos el puntero de estado
    char target_file[2048]; sprintf(target_file,"%s/%s%s",EXAMPLES_PATH,LAMPORT_P1_FILE,LMP_EXT);
    char target_file_tokens_expected[2048]; sprintf(target_file_tokens_expected,"%s/%s%s%s",EXAMPLES_RESULT_PATH,LIST_TOKENS_PREFIX,LAMPORT_P1_FILE,TXT_EXT);
    
    Buffer* tokens_programa = obtener_tokens_programa(target_file);
    Buffer* tokens_esperados = obtener_lista_tokens_esperada(target_file_tokens_expected);

    comparar_resultados_lexer(tokens_programa,tokens_esperados);
}

static void test_scan_program2_lamport(void **state){
    (void) state;  // Descartamos el puntero de estado
    char target_file[2048]; sprintf(target_file,"%s/%s%s",EXAMPLES_PATH,LAMPORT_P2_FILE,LMP_EXT);
    char target_file_tokens_expected[2048]; sprintf(target_file_tokens_expected,"%s/%s%s%s",EXAMPLES_RESULT_PATH,LIST_TOKENS_PREFIX,LAMPORT_P2_FILE,TXT_EXT);
    
    Buffer* tokens_programa = obtener_tokens_programa(target_file);
    Buffer* tokens_esperados = obtener_lista_tokens_esperada(target_file_tokens_expected);

    comparar_resultados_lexer(tokens_programa,tokens_esperados);
}

static void test_scan_program3_lamport(void **state){
    (void) state;  // Descartamos el puntero de estado
    char target_file[2048]; sprintf(target_file,"%s/%s%s",EXAMPLES_PATH,LAMPORT_P3_FILE,LMP_EXT);
    char target_file_tokens_expected[2048]; sprintf(target_file_tokens_expected,"%s/%s%s%s",EXAMPLES_RESULT_PATH,LIST_TOKENS_PREFIX,LAMPORT_P3_FILE,TXT_EXT);
    
    Buffer* tokens_programa = obtener_tokens_programa(target_file);
    Buffer* tokens_esperados = obtener_lista_tokens_esperada(target_file_tokens_expected);

    comparar_resultados_lexer(tokens_programa,tokens_esperados);
}

static void test_scan_program4_lamport(void **state){
    (void) state;  // Descartamos el puntero de estado
    char target_file[2048]; sprintf(target_file,"%s/%s%s",EXAMPLES_PATH,LAMPORT_P4_FILE,LMP_EXT);
    char target_file_tokens_expected[2048]; sprintf(target_file_tokens_expected,"%s/%s%s%s",EXAMPLES_RESULT_PATH,LIST_TOKENS_PREFIX,LAMPORT_P4_FILE,TXT_EXT);
    
    Buffer* tokens_programa = obtener_tokens_programa(target_file);
    Buffer* tokens_esperados = obtener_lista_tokens_esperada(target_file_tokens_expected);

    comparar_resultados_lexer(tokens_programa,tokens_esperados);
}

static void test_scan_program5_lamport(void **state){
    (void) state;  // Descartamos el puntero de estado
    char target_file[2048]; sprintf(target_file,"%s/%s%s",EXAMPLES_PATH,LAMPORT_P5_FILE,LMP_EXT);
    char target_file_tokens_expected[2048]; sprintf(target_file_tokens_expected,"%s/%s%s%s",EXAMPLES_RESULT_PATH,LIST_TOKENS_PREFIX,LAMPORT_P5_FILE,TXT_EXT);
    
    Buffer* tokens_programa = obtener_tokens_programa(target_file);
    Buffer* tokens_esperados = obtener_lista_tokens_esperada(target_file_tokens_expected);

    comparar_resultados_lexer(tokens_programa,tokens_esperados);
}

static void test_scan_program6_lamport(void **state){
    (void) state;  // Descartamos el puntero de estado
    char target_file[2048]; sprintf(target_file,"%s/%s%s",EXAMPLES_PATH,LAMPORT_P6_FILE,LMP_EXT);
    char target_file_tokens_expected[2048]; sprintf(target_file_tokens_expected,"%s/%s%s%s",EXAMPLES_RESULT_PATH,LIST_TOKENS_PREFIX,LAMPORT_P6_FILE,TXT_EXT);
    
    Buffer* tokens_programa = obtener_tokens_programa(target_file);
    Buffer* tokens_esperados = obtener_lista_tokens_esperada(target_file_tokens_expected);

    comparar_resultados_lexer(tokens_programa,tokens_esperados);
}
