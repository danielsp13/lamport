#!/bin/bash
# Nombre : test_valgrind_unique_lmp_files.sh
# Autor : Daniel Perez Ruiz
# Fecha : 7 de Octubre de 2023
# Descripcion : Ejecuta test de valgrind sobre un fichero lamport
# Uso: ./test_valgrind_unique_lmp_files.sh <fichero.lmp>

# ==========================================================================

# -- DEFINCION DE VARIABLES

# >>> Ruta donde se encuentra el ejecutable
INTERPRETER_DIR="bin"
INTERPRETER_NAME="lmp"
INTERPRETER="$INTERPRETER_DIR/$INTERPRETER_NAME"

# >>> Fichero
LMP_FILE="$1"

# >>> Forma de ejecucion de valgrind
ERR_VALGRIND_EXIT_CODE=20
VALGRIND_OPTIONS="--leak-check=full --error-exitcode=$ERR_VALGRIND_EXIT_CODE"

# >>> Cabecera para notifiacion de errores
ERR_MSG_HEADER="[ERROR]: "

# >>> Codigo de salida de error de script
ERR_SCRIPT_EXIT_CODE=1
OK_SCRIPT_EXIT_CODE=0

# ==========================================================================

# -- FUNCIONES DE ASISTENCIA AL TESTEO

# -- Descripcion: funcion que comprueba si el interprete existe
# -- Arg 1 : Nombre de interprete
function test_interpreter_exists(){
	# -- Obtener nombre de interprete
	local INTERPRETER_TARGET=$1
	
	# -- Comprobar existencia del interprete
	if ! [ -f $INTERPRETER_TARGET ]; then
		print_error_msg "$ERR_MSG_HEADER el interprete especificado ($INTERPRETER_TARGET) no existe.";
		exit $ERR_SCRIPT_EXIT_CODE;
	fi
}

# -- Descripcion : funcion que realiza test de fuga de memoria sobre interprete utilizando fichero de codigo de prueba
# -- Arg 1 : Nombre de interprete
# -- Arg 2 : Nombre de fichero de prueba
function test_mem_leaks_using_lmp_file(){
	# -- Obtener nombre de interprete
	local INTERPRETER_TARGET=$1
	# -- Obtener nombre de fichero lamport de prueba
	local LMP_FILE_TARGET=$2
	
	# -- Comprobar existencia de fichero
	if ! [ -f $LMP_FILE_TARGET ]; then
		print_error_msg "$ERR_MSG_HEADER el fichero lamport de prueba especificado ($LMP_FILE_TARGET) no existe/no es valido."
		exit $ERR_SCRIPT_EXIT_CODE;
	else
		echo "Comprobando fugas de memoria en ($INTERPRETER_TARGET) con fichero de prueba: ($LMP_FILE_TARGET)"
		echo "MEM CHECK............."
		valgrind $VALGRIND_OPTIONS $INTERPRETER_TARGET $LMP_FILE_TARGET &> /dev/null
		
		if [ $? -eq $ERR_VALGRIND_EXIT_CODE ]; then
			print_error_msg ".......... [ERROR]"
		else
			print_success_msg ".......... [OK]"
		fi
		echo
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

# 0.A Comprobar que existe interprete
test_interpreter_exists $INTERPRETER

# 1. Ejecutar tests de memoria
test_mem_leaks_using_lmp_file $INTERPRETER $LMP_FILE
