#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>

// Test que no hace nada
static void test_nothing(void **state) {
    (void) state; // Evitar el warning de parámetro no utilizado
}

// Test que siempre falla
static void test_fail(void **state) {
    assert_true(0); // Esta aserción siempre fallará
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_nothing),
        cmocka_unit_test(test_fail),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
