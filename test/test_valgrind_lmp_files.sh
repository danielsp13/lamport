#!/bin/bash
# Nombre : test_valgrind_lmp_files.sh
# Autor : Daniel Perez Ruiz
# Fecha : 20 de Septiembre de 2023
# Descripcion : Ejecuta tests de valgrind sobre ficheros lamport
# Uso: ./test_valgrind_lmp_files

# ==========================================================================

# -- DEFINCION DE VARIABLES

# >>> Ruta donde se encuentra el ejecutable
COMPILER_DIR="bin"
COMPILER_NAME="lmp"
COMPILER="$COMPILER_DIR/$COMPILER_NAME"

# >>> Directorio donde se encuentran los ficheros
LMP_FILES_DIR="$1"

# >>> Forma de ejecucion de valgrind
ERR_VALGRIND_EXIT_CODE=20
VALGRIND_OPTIONS="--leak-check=full --error-exitcode=$ERR_VALGRIND_EXIT_CODE"

# >>> Variable contadora de fugas y de exitos
TOTAL_MEM_LEAKS=0
TOTAL_SUCCESS=0

# >>> Cabecera para notifiacion de errores
ERR_MSG_HEADER="[ERROR]: "

# >>> Codigo de salida de error de script
ERR_SCRIPT_EXIT_CODE=1
OK_SCRIPT_EXIT_CODE=0

# ==========================================================================

# -- FUNCIONES DE ASISTENCIA AL TESTEO

# -- Descripcion: funcion que comprueba si el compilador existe
# -- Arg 1 : Nombre de compilador
function test_compiler_exists(){
	# -- Obtener nombre de compilador
	local COMPILER_TARGET=$1
	
	# -- Comprobar existencia del compilador
	if ! [ -f $COMPILER_TARGET ]; then
		print_error_msg "$ERR_MSG_HEADER el compilador especificado ($COMPILER_TARGET) no existe.";
		exit $ERR_SCRIPT_EXIT_CODE;
	fi
}

# -- Descripcion: funcion que comprueba si el directorio donde se encuentran los ficheros de prueba existe
# -- Arg 1 : Nombre de directorio
function test_lmp_files_dir_exists(){
	# -- Obtener nombre de directorio
	local LMP_FILES_DIR_TARGET=$1
	
	# -- Comprobar existencia del directorio
	if ! [ -d $LMP_FILES_DIR_TARGET ]; then
		print_error_msg "$ERR_MSG_HEADER el directorio especificado ($LMP_FILES_DIR_TARGET) no existe.";
		exit $ERR_SCRIPT_EXIT_CODE;
	fi
}

# -- Descripcion : funcion que realiza test de fuga de memoria sobre compilador utilizando fichero de codigo de prueba
# -- Arg 1 : Nombre de compilador
# -- Arg 2 : Nombre de fichero de prueba
function test_mem_leaks_using_lmp_file(){
	# -- Obtener nombre de compilador
	local COMPILER_TARGET=$1
	# -- Obtener nombre de fichero lamport de prueba
	local LMP_FILE_TARGET=$2
	
	# -- Comprobar existencia de fichero
	if ! [ -f $LMP_FILE_TARGET ]; then
		print_error_msg "$ERR_MSG_HEADER el fichero lamport de prueba especificado ($LMP_FILE_TARGET) no existe/no es valido."
		exit $ERR_SCRIPT_EXIT_CODE;
	else
		echo "Comprobando fugas de memoria en ($COMPILER_TARGET) con fichero de prueba: ($LMP_FILE_TARGET)"
		echo "MEM CHECK............."
		valgrind $VALGRIND_OPTIONS $COMPILER_TARGET $LMP_FILE_TARGET &> /dev/null
		
		if [ $? -eq $ERR_VALGRIND_EXIT_CODE ]; then
			print_error_msg ".......... [ERROR]"
			((TOTAL_MEM_LEAKS++))
		else
			print_success_msg ".......... [OK]"
			((TOTAL_SUCCESS++))
		fi
	fi
}

# ==========================================================================

# -- FUNCION DE TESTEO

function exec_test_mem_leaks_using_dir(){
	# -- Obtener nombre de directorio
	local LMP_FILES_DIR_TARGET=$1
	# -- Obtener nombre de compilador
	local COMPILER_TARGET=$2
	
	# -- Ejecutar pruebas de testeo de memoria
	for LMP_FILE in "$LMP_FILES_DIR_TARGET"/*; do
		if [ -f $LMP_FILE ]; then
			test_mem_leaks_using_lmp_file $COMPILER_TARGET $LMP_FILE
			echo;
		fi
	done
	
	# -- Obtener resultados
	printf "Total de pruebas completadas sin fugas de memoria: "
	print_success_msg "$TOTAL_SUCCESS pruebas"
	printf "Total de pruebas completadas con fugas de memoria: "
	print_error_msg  "$TOTAL_MEM_LEAKS pruebas"
	echo
	
	if [ ${TOTAL_MEM_LEAKS} -eq 0 ]; then
		exit $OK_SCRIPT_EXIT_CODE;
	else
		exit $ERR_SCRIPT_EXIT_CODE;
	fi
}

# ==========================================================================

# -- FUNCIONES ADICIONALES

# -- Descripcion: recibe un mensaje e imprime su salida de color rojo
# -- Arg 1 : Mensaje
function print_error_msg(){
	local MSG_TARGET=$1
	local RED_COLOR='\033[1;31m'
	local RESET_COLOR='\033[0m'
	
	echo -e "${RED_COLOR}${MSG_TARGET}${RESET_COLOR}"
}

# -- Descripcion: recibe un mensaje e imprime su salida de color verde
# -- Arg 1 : Mensaje
function print_success_msg(){
	local MSG_TARGET=$1
	local GREEN_COLOR='\033[1;32m'
	local RESET_COLOR='\033[0m'
	
	echo -e "${GREEN_COLOR}${MSG_TARGET}${RESET_COLOR}"
}

# ==========================================================================

# -- SCRIPT DE TESTEO

# 0.A Comprobar que existe compilador
test_compiler_exists $COMPILER

# 0.B Comprobar que existe directorio
test_lmp_files_dir_exists $LMP_FILES_DIR

# 1. Ejecutar tests de memoria
exec_test_mem_leaks_using_dir $LMP_FILES_DIR $COMPILER
