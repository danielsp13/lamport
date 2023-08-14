/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file test_lexer_recon_tokens.c
 * @author Daniel Perez Ruiz
 * @brief Tests del analizador lexico : reconocimiento de tokens literales
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

//Inlcuir analizador lexico implementado
#include "lexer.c"
#include "token_type.h"

// ==================================================================================

// DEFINICION DE FUNCIONES AUXILIARES PARA EL TEST

/**
 * @brief Funcion de reconocimiento de tokens
 * @param str_test : Cadena de caracteres a escanear por el lexer
 * @param expected_token : Token esperado de la devolucion del escaneo del lexer
 */
static void reconocer_token(const char* str_test, TokenType expected_token);

// ==================================================================================

// DEFINICION DE FUNCIONES DE TEST

static void test_program_token(void **state);
static void test_var_token(void **state);
static void test_integer_type_token(void **state);
static void test_boolean_type_token(void **state);
static void test_char_type_token(void **state);
static void test_string_type_token(void **state);
static void test_real_type_token(void **state);
static void test_semaphore_type_token(void **state);
static void test_dprocess_type_token(void **state);
static void test_process_token(void **state);
static void test_procedure_token(void **state);
static void test_function_token(void **state);
static void test_return_token(void **state);
static void test_begin_token(void **state);
static void test_end_token(void **state);
static void test_cobegin_token(void **state);
static void test_coend_token(void **state);
static void test_fork_token(void **state);
static void test_join_token(void **state);
static void test_if_token(void **state);
static void test_then_token(void **state);
static void test_else_token(void **state);
static void test_while_token(void **state);
static void test_do_token(void **state);
static void test_for_token(void **state);
static void test_to_token(void **state);
static void test_true_token(void **state);
static void test_false_token(void **state);
static void test_op_assign_token(void **state);
static void test_op_lt_token(void **state);
static void test_op_lte_token(void **state);
static void test_op_gt_token(void **state);
static void test_op_gte_token(void **state);
static void test_op_eq_token(void **state);
static void test_op_neq_token(void **state);
static void test_sum_token(void **state);
static void test_minus_token(void **state);
static void test_mult_token(void **state);
static void test_div_token(void **state);
static void test_mod_token(void **state);
static void test_not_token(void **state);
static void test_and_token(void **state);
static void test_or_token(void **state);
static void test_par_izdo_token(void **state);
static void test_par_dcho_token(void **state);
static void test_corch_izdo_token(void **state);
static void test_corch_dcho_token(void **state);
static void test_delim_c_token(void **state);
static void test_delim_pc_token(void **state);
static void test_delim_2p_token(void **state);
static void test_delim_p_token(void **state);
static void test_delim_arr_token(void **state);
static void test_atom_ini_token(void **state);
static void test_atom_fin_token(void **state);

// ==================================================================================
// ==================================================================================


int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_program_token),
        cmocka_unit_test(test_var_token),
        cmocka_unit_test(test_integer_type_token),
        cmocka_unit_test(test_boolean_type_token),
        cmocka_unit_test(test_char_type_token),
        cmocka_unit_test(test_string_type_token),
        cmocka_unit_test(test_real_type_token),
        cmocka_unit_test(test_semaphore_type_token),
        cmocka_unit_test(test_dprocess_type_token),
        cmocka_unit_test(test_process_token),
        cmocka_unit_test(test_procedure_token),
        cmocka_unit_test(test_function_token),
        cmocka_unit_test(test_return_token),
        cmocka_unit_test(test_begin_token),
        cmocka_unit_test(test_end_token),
        cmocka_unit_test(test_cobegin_token),
        cmocka_unit_test(test_coend_token),
        cmocka_unit_test(test_fork_token),
        cmocka_unit_test(test_join_token),
        cmocka_unit_test(test_if_token),
        cmocka_unit_test(test_then_token),
        cmocka_unit_test(test_else_token),
        cmocka_unit_test(test_while_token),
        cmocka_unit_test(test_do_token),
        cmocka_unit_test(test_for_token),
        cmocka_unit_test(test_to_token),
        cmocka_unit_test(test_true_token),
        cmocka_unit_test(test_false_token),
        cmocka_unit_test(test_op_assign_token),
        cmocka_unit_test(test_op_lt_token),
        cmocka_unit_test(test_op_lte_token),
        cmocka_unit_test(test_op_gt_token),
        cmocka_unit_test(test_op_gte_token),
        cmocka_unit_test(test_op_eq_token),
        cmocka_unit_test(test_op_neq_token),
        cmocka_unit_test(test_sum_token),
        cmocka_unit_test(test_minus_token),
        cmocka_unit_test(test_mult_token),
        cmocka_unit_test(test_div_token),
        cmocka_unit_test(test_mod_token),
        cmocka_unit_test(test_not_token),
        cmocka_unit_test(test_and_token),
        cmocka_unit_test(test_or_token),
        cmocka_unit_test(test_delim_c_token),
        cmocka_unit_test(test_delim_pc_token),
        cmocka_unit_test(test_delim_2p_token),
        cmocka_unit_test(test_delim_p_token),
        cmocka_unit_test(test_delim_arr_token),
        cmocka_unit_test(test_atom_ini_token),
        cmocka_unit_test(test_atom_fin_token),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

// ==================================================================================
// ==================================================================================

// ==================================================================================

// IMPLEMENTACION DE FUNCIONES AUXILIARES

static void reconocer_token(const char* str_test, TokenType expected_token){
    YY_BUFFER_STATE buffer = yy_scan_string(str_test);
    int token = yylex();
    assert_int_equal(token, expected_token);
    yy_delete_buffer(buffer);
}


// ==================================================================================

// IMPLEMENTACION DE FUNCIONES DE TEST

static void test_program_token(void **state){
    (void) state;  // Descartamos el puntero de estado
    reconocer_token("program", S_PROGRAM);
}

static void test_var_token(void **state){
    (void) state;
    reconocer_token("var", S_VAR);
}

static void test_integer_type_token(void **state){
    (void) state;
    reconocer_token("integer", T_INTEGER);
}

static void test_boolean_type_token(void **state){
    (void) state;
    reconocer_token("boolean", T_BOOLEAN);
}

static void test_char_type_token(void **state){
    (void) state;
    reconocer_token("char", T_CHAR);
}

static void test_string_type_token(void **state){
    (void) state;
    reconocer_token("string", T_STRING);
}

static void test_real_type_token(void **state){
    (void) state;
    reconocer_token("real", T_REAL);
}

static void test_semaphore_type_token(void **state){
    (void) state;
    reconocer_token("semaphore", T_SEMAPHORE);
}

static void test_dprocess_type_token(void **state){
    (void) state;
    reconocer_token("dprocess", T_DPROCESS);
}

static void test_process_token(void **state){
    (void) state;
    reconocer_token("process", S_PROCESS);
}

static void test_procedure_token(void **state){
    (void) state;
    reconocer_token("procedure", S_PROCEDURE);
}

static void test_function_token(void **state){
    (void) state;
    reconocer_token("function", S_FUNCTION);
}

static void test_return_token(void **state){
    (void) state;
    reconocer_token("return", RETURN);
}

static void test_begin_token(void **state){
    (void) state;
    reconocer_token("begin", B_BEGIN);
}

static void test_end_token(void **state){
    (void) state;
    reconocer_token("end", B_END);
}

static void test_cobegin_token(void **state){
    (void) state;
    reconocer_token("cobegin", B_COBEGIN);
}

static void test_coend_token(void **state){
    (void) state;
    reconocer_token("coend", B_COEND);
}

static void test_fork_token(void **state){
    (void) state;
    reconocer_token("fork", S_FORK);
}

static void test_join_token(void **state){
    (void) state;
    reconocer_token("join", JOIN);
}

static void test_if_token(void **state){
    (void) state;
    reconocer_token("if", IF);
}

static void test_then_token(void **state){
    (void) state;
    reconocer_token("then", THEN);
}

static void test_else_token(void **state){
    (void) state;
    reconocer_token("else", ELSE);
}

static void test_while_token(void **state){
    (void) state;
    reconocer_token("while", WHILE);
}

static void test_do_token(void **state){
    (void) state;
    reconocer_token("do", DO);
}

static void test_for_token(void **state){
    (void) state;
    reconocer_token("for", FOR);
}

static void test_to_token(void **state){
    (void) state;
    reconocer_token("to", TO);
}

static void test_true_token(void **state){
    (void) state;
    reconocer_token("true", L_BOOLEAN_TRUE);
}

static void test_false_token(void **state){
    (void) state;
    reconocer_token("false", L_BOOLEAN_FALSE);
}

static void test_op_assign_token(void **state){
    (void) state;
    reconocer_token(":=", OP_ASSIGN);
}

static void test_op_lt_token(void **state){
    (void) state;
    reconocer_token("<", OP_REL_LT);
}

static void test_op_lte_token(void **state){
    (void) state;
    reconocer_token("<=", OP_REL_LTE);
}

static void test_op_gt_token(void **state){
    (void) state;
    reconocer_token(">", OP_REL_GT);
}

static void test_op_gte_token(void **state){
    (void) state;
    reconocer_token(">=", OP_REL_GTE);
}

static void test_op_eq_token(void **state){
    (void) state;
    reconocer_token("==", OP_REL_EQ);
}

static void test_op_neq_token(void **state){
    (void) state;
    reconocer_token("!=", OP_REL_NEQ);
}

static void test_sum_token(void **state){
    (void) state;
    reconocer_token("+", OP_SUM);
}

static void test_minus_token(void **state){
    (void) state;
    reconocer_token("-", OP_MINUS);
}

static void test_mult_token(void **state){
    (void) state;
    reconocer_token("*", OP_MULT);
}

static void test_div_token(void **state){
    (void) state;
    reconocer_token("/", OP_DIV);
}

static void test_mod_token(void **state){
    (void) state;
    reconocer_token("%", OP_MOD);
}

static void test_not_token(void **state){
    (void) state;
    reconocer_token("not", OP_NOT);
}

static void test_and_token(void **state){
    (void) state;
    reconocer_token("and", OP_AND);
}

static void test_or_token(void **state){
    (void) state;
    reconocer_token("or", OP_OR);
}

static void test_par_izdo_token(void **state){
    (void) state;
    reconocer_token("(", PAR_IZDO);
}

static void test_par_dcho_token(void **state){
    (void) state;
    reconocer_token(")", PAR_DCHO);
}

static void test_corch_izdo_token(void **state){
    (void) state;
    reconocer_token("[", CORCH_IZDO);
}

static void test_corch_dcho_token(void **state){
    (void) state;
    reconocer_token("]", CORCH_DCHO);
}

static void test_delim_c_token(void **state){
    (void) state;
    reconocer_token(",", DELIM_C);
}

static void test_delim_pc_token(void **state){
    (void) state;
    reconocer_token(";", DELIM_PC);
}

static void test_delim_2p_token(void **state){
    (void) state;
    reconocer_token(":", DELIM_2P);
}

static void test_delim_arr_token(void **state){
    (void) state;
    reconocer_token("..", DELIM_ARR);
}

static void test_delim_p_token(void **state){
    (void) state;
    reconocer_token(".", DELIM_P);
}

static void test_atom_ini_token(void **state){
    (void) state;
    reconocer_token("<<", ATOM_INI);
}

static void test_atom_fin_token(void **state){
    (void) state;
    reconocer_token(">>", ATOM_FIN);
}
