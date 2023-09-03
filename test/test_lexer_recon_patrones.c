/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file test_lexer_recon_patrones.c
 * @author Daniel Perez Ruiz
 * @brief Tests del analizador lexico : reconocimiento de patrones
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

//Incluir analizador lexico
#include "lexer/lexer.c"

//Incluir funciones comunes
#include "test_utils/common_functions.h"

// -- Macro que define la ruta donde se encuentran los ficheros de pruebas
#define EXAMPLES_PATH "examples/test_tokens/"
// -- Macros que definen los nombres de ficheros de pruebas
#define IDENT_FILE "ident.txt"
#define LITERAL_FILE "literal.txt"
#define LITERAL_CHAR_FILE "literal_char.txt"
#define LITERAL_INTEGER_FILE "literal_integer.txt"
#define LITERAL_REAL_FILE "literal_real.txt"
#define IGNORE_COMMENTS_FILE "comentarios.txt"

// ==================================================================================

// DEFINICION DE FUNCIONES AUXILIARES

/**
 * @brief Funcion de reconocimiento de tokens
 * @param str_test : Cadena de caracteres a escanear por el lexer
 * @param expected_token : Token esperado de la devolucion del escaneo del lexer
 */
void reconocer_token(const char* str_test, int expected_token);

/**
 * @brief Funcion de reconocimiento de tokens. Lee desde un fichero la lista de lexemas a probar
 * @param file : Nombre del fichero que contiene los lexemas
 * @param expected_token : Token esperado de la devolucion del escaneo del lexer
 */
void reconocer_token_desde_fichero(const char* file, int expected_token);

// ==================================================================================


// DEFINICION DE FUNCIONES DE TEST

static void test_ident_token(void **state);
static void test_literal_token(void **state);
static void test_literal_integer_token(void **state);
static void test_literal_real_token(void **state);
static void test_literal_char_token(void **state);
static void test_ignore_comments(void **state);

// ==================================================================================

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_ident_token),
        cmocka_unit_test(test_literal_token),
        cmocka_unit_test(test_literal_integer_token),
        cmocka_unit_test(test_literal_real_token),
        cmocka_unit_test(test_literal_char_token),
        cmocka_unit_test(test_ignore_comments)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

// ==================================================================================

// IMPLEMENTACION DE FUNCIONES AUXILIARES

void reconocer_token(const char* str_test, int expected_token){
    YY_BUFFER_STATE buffer = yy_scan_string(str_test);
    int token = yylex();
    assert_int_equal(token, expected_token);
    yy_delete_buffer(buffer);
}

void reconocer_token_desde_fichero(const char* file, int expected_token){
    Buffer* buff = crear_buffer();
    leer_fichero(file,buff,0);

    for(int i=0; i<buff->total_lines; i++)
        reconocer_token(buff->lines[i],expected_token);
}

// ==================================================================================

// IMPLEMENTACION DE FUNCIONES DE TEST

static void test_ident_token(void **state){
    (void) state;  // Descartamos el puntero de estado
    char target_file[1024]; sprintf(target_file,"%s/%s",EXAMPLES_PATH,IDENT_FILE);
    reconocer_token_desde_fichero(target_file,IDENT);
}

static void test_literal_token(void **state){
    (void) state;  // Descartamos el puntero de estado
    char target_file[1024]; sprintf(target_file,"%s/%s",EXAMPLES_PATH,LITERAL_FILE);
    reconocer_token_desde_fichero(target_file,LITERAL);
}

static void test_literal_integer_token(void **state){
    (void) state;
    char target_file[1024]; sprintf(target_file,"%s/%s",EXAMPLES_PATH,LITERAL_INTEGER_FILE);
    reconocer_token_desde_fichero(target_file,L_INTEGER);
}

static void test_literal_real_token(void **state){
    (void) state;
    char target_file[1024]; sprintf(target_file,"%s/%s",EXAMPLES_PATH,LITERAL_REAL_FILE);
    reconocer_token_desde_fichero(target_file,L_REAL);
}

static void test_literal_char_token(void **state){
    (void) state;
    char target_file[1024]; sprintf(target_file,"%s/%s",EXAMPLES_PATH,LITERAL_CHAR_FILE);
    reconocer_token_desde_fichero(target_file,L_CHAR);
}

static void test_ignore_comments(void **state){
    (void) state;
    char target_file[1024]; sprintf(target_file,"%s/%s",EXAMPLES_PATH,IGNORE_COMMENTS_FILE);
    reconocer_token_desde_fichero(target_file,L_INTEGER);
}
