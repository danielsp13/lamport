#!/bin/bash
# Nombre : test_valgrind_multiple_lmp_files.sh
# Autor : Daniel Perez Ruiz
# Fecha : 7 de Octubre de 2023
# Descripcion : Ejecuta test de valgrind al directorio de ejemplos
# Uso: ./test_valgrind_multiple_lmp_files.sh <fichero.lmp>

# ==========================================================================

# -- Nombre de directorio
DIR="$1"
# -- Nombre de script de testeo
TEST_FILE="./test/test_valgrind_unique_lmp_file.sh"

# -- Orden de ejecucion
find $DIR -maxdepth 1 -type f | parallel -j 5 $TEST_FILE {}
