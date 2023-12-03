#!/bin/bash
# Nombre : lmp_docker.sh
# Autor : Daniel Perez Ruiz
# Fecha : 15 de Octubre de 2023
# Descripcion : Ejecuta el contenedor Docker para ejecutar el fichero lamport
# Uso: ./lmp_docker.sh <fichero.lmp>


# ==========================================================================

# ==========================================================================

# -- PASO 1 : Comprobar numero de argumentos
if [ $# -lt 1 ]; then
	echo $0 : Un compilador del lenguaje lamport.
	echo Version de interprete: 1.0.1-alpha
	echo Autor: Daniel Perez Ruiz
	echo
	echo "Uso: $0 <fichero.lmp>"
	exit 1
fi

# -- Ejecutar contenedor docker
make run_docker LMP_FILE=$1

