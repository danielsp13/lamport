# ========================================================================================
# UNIVERSIDAD DE GRANADA - TRABAJO DE FIN DE GRADO (23/24)
# ========================================================================================
# PROYECTO: SIMULADOR DE SISTEMAS CONCURRENTES Y DISTRIBUIDOS
# ========================================================================================
# Autor: Daniel Perez Ruiz
# Tutor: Carlos Ureña Almagro
# ========================================================================================

# -- Definicion del shell a utilizar
SHELL := /bin/bash

# -- Designacion de reglas internas
.PHONY: backup build_bin_dir

# ========================================================================================
# DEFINICION DE VARIABLES
# ========================================================================================

# -- Variables referentes a las dependencias del proyecto
PACKAGE_MANAGER=apt

TEX_DEPENDENCIES=texlive texlive-lang-spanish texlive-fonts-extra
COMPILER_DEPENDENCIES=gcc flex
TEST_DEPENDENCIES=libcmocka-dev cppcheck

# -- Variables referentes a informe tex
TEX_DIR=tex
TEX_GEN_FILES='.*\.\(aux\|log\|pdf\|dvi\|toc\|out\|bbl\|blg\|lot\|lof\)'

# -- Variables referentes a copias de seguridad locales
BACKUP_EXT_FILE = .zip
BACKUP_NAME = lamport
BACKUP_FILE = $(BACKUP_NAME)$(BACKUP_EXT_FILE)
DIR_BACKUP = $(HOME)

# -- Variables referentes a directorios de fuentes
HEADER_DIR = include
SOURCE_DIR = src
TEST_DIR = test
BIN_DIR = bin
INDEX_DIRS=$(HEADER_DIR) $(SOURCE_DIR) $(TEST_DIR)

# -- Variables referentes a compilacion/comprobacion de ficheros
GXX = gcc
CFLAGS = -Wall -Wextra -I$(HEADER_DIR)
LDFLAGS := -lcmocka
LINTER = cppcheck

# -- Variables de ficheros
INDEX_FILES=dummy
TEST_PREFIX = test_


# -- Variables de extensiones
SOURCE_EXT = .c
HEADER_EXT = .h
TEST_EXT = .c

# -- Variables cosmeticas
COLOR_RED := $(shell echo -e "\033[1;31m")
COLOR_GREEN := $(shell echo -e "\033[1;32m")
COLOR_YELLOW := $(shell echo -e "\033[1;33m")
COLOR_BLUE := $(shell echo -e "\033[1;34m")
COLOR_PURPLE := $(shell echo -e "\033[1;35m")
COLOR_BOLD := $(shell echo -e "\033[1m")
COLOR_RESET := $(shell echo -e "\033[0;0m")
COLOR_RESET_BOLD := $(COLOR_RESET)$(COLOR_BOLD)

# ========================================================================================
# DEFINICION DE REGLAS PRINICPALES (ALL/CLEAN)
# ========================================================================================

# -- Elimina todos los ficheros que se hayan generado usando el Makefile
clean: clean_tex clean_tests
	@if [ -z "$(wildcard $(BIN_DIR)/*)" ]; then \
		echo; echo "$(COLOR_BLUE)Eliminando directorio $(COLOR_PURPLE)$(BIN_DIR)/$(COLOR_BLUE)...$(COLOR_RESET)"; \
		rmdir $(BIN_DIR) 2>/dev/null || true; \
		echo "$(COLOR_GREEN)Directorio $(COLOR_PURPLE)$(BIN_DIR)/$(COLOR_GREEN) eliminado correctamente!"; \
	fi
		

# ========================================================================================
# DEFINICION DE REGLAS DE GESTION INTERNA
# ========================================================================================

backup:
	@echo "$(COLOR_BLUE)Generando copia de seguridad...$(COLOR_RESET)"
	@rm -f $(DIR_BACKUP)/$(BACKUP_FILE)
	@zip -r $(DIR_BACKUP)/$(BACKUP_FILE) ./*
	@echo "$(COLOR_GREEN)Copia de seguridad creada en $(COLOR_PURPLE)$(DIR_BACKUP)/$(BACKUP_FILE)$(COLOR_RESET)"
	
build_bin_dir:
	@mkdir -p $(BIN_DIR)

# ========================================================================================
# DEFINICION DE OTRAS REGLAS
# ========================================================================================

# -- Muestra en terminal la informacion general del proyecto
author:
	@echo "UNIVERSIDAD DE GRANADA : TRABAJO DE FIN DE GRADO"
	@echo " -- Nombre de proyecto: Lamport. Simulador de Sistemas Concurrentes y Distribuidos"
	@echo " -- Autor: Daniel Pérez Ruiz"
	@echo " -- Tutor: Carlos Ureña Almagro"
	@echo " -- Version: 0.0.0"

# -- Muestra las diferentes opciones de Makefile
help:
	@echo "-- TAREAS DE MAKEFILE --"
	@printf "%-30s %s\n" "make" "*No definido todavia*"
	@printf "%-30s %s\n" "make author" "Muestra informacion acerca del TFG (autoria)."
	@printf "%-30s %s\n" "make help" "Muestra este menu de opciones."
	@printf "%-30s %s\n" "make install_dependencies" "Instala todas las dependencias del proyecto (TeX, compilador, tests)."
	@printf "%-30s %s\n" "make uninstall_dependencies" "Desinstala todas las dependencias del proyecto (TeX, compilador, tests)."
	@printf "%-30s %s\n" "make version_dependencies" "Muestra la versión de las dependencias instaladas."
	@printf "%-30s %s\n" "make check" "Analiza el codigo de los fuentes comprobando errores de sintaxis, warnings de estilo, etc."
	@printf "%-30s %s\n" "make test" "Compila y ejecuta los tests sobre los fuentes del proyecto."
	@printf "%-30s %s\n" "make clean" "Elimina todos los ficheros binarios compilados o generados por el Makefile."


# ========================================================================================
# DEFINICION DE REGLAS DE GESTION DE DEPENDENCIAS
# ========================================================================================

# -- Instala todas las dependencias del proyecto
install_dependencies: install_tex_dependencies install_compiler_dependencies install_tests_dependencies

# -- Desinstala todas las dependencias del proyecto
uninstall_dependencies: uninstall_tex_dependencies uninstall_compiler_dependencies uninstall_tests_dependencies

# -- Muestra la versión de todas las dependencias del proyecto
version_dependencies: version_tex_dependencies version_compiler_dependencies version_tests_dependencies

# ----------------------------------------------------------------------------------------

# -- Instala todas las dependencias relacionadas con informe TFG
install_tex_dependencies:
	@echo "$(COLOR_BLUE)Instalando dependencias TeX del proyecto...$(COLOR_RESET)"
	@$(foreach DEP,$(TEX_DEPENDENCIES), \
        if ! dpkg -l $(DEP) 2>/dev/null | grep -qw 'ii' ; then \
            echo "$(COLOR_BOLD) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_RESET_BOLD) no está instalado. Instalando... $(COLOR_RESET)"; \
            sudo $(PACKAGE_MANAGER) update && sudo $(PACKAGE_MANAGER) install -y $(DEP); \
        else \
            echo " ---> $(COLOR_PURPLE)$(DEP)$(COLOR_RESET) ya se encuentra instalado en el sistema."; \
        fi; \
    )
	
# -- Desinstala todas las dependencias relacionadas con el informe TFG
uninstall_tex_dependencies:
	@echo "$(COLOR_BLUE)Desinstalando dependencias TeX del proyecto...$(COLOR_RESET)"
	@$(foreach DEP,$(TEX_DEPENDENCIES), \
        if dpkg -l $(DEP) 2>/dev/null | grep -qw 'ii'; then \
        	echo "$(COLOR_BOLD) ---> Desinstalando $(COLOR_PURPLE)$(DEP)$(COLOR_RESET)...$(COLOR_RESET)"; \
            sudo $(PACKAGE_MANAGER) remove -y $(DEP) && sudo $(PACKAGE_MANAGER) autoremove -y; \
        else \
            echo "$(COLOR_YELLOW) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_YELLOW) NO! se encuentra instalado en el sistema.$(COLOR_RESET)"; \
        fi; \
    )

# -- Muestra la version de todas las dependencias relacionadas con el informe TFG
version_tex_dependencies:
	@echo "$(COLOR_BLUE)Versión instalada de las dependencias TeX del proyecto:$(COLOR_RESET)"
	@$(foreach DEP,$(TEX_DEPENDENCIES), \
        if dpkg -l $(DEP) 2>/dev/null | grep -qw 'ii'; then \
            dpkg -s $(DEP) | grep '^Version:' | awk '{print " ---> Versión de $(COLOR_PURPLE)$(DEP)$(COLOR_RESET): ", $$2}'; \
        else \
            echo "$(COLOR_YELLOW) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_YELLOW) NO! se encuentra instalado en el sistema.$(COLOR_RESET)"; \
        fi; \
    )

# ----------------------------------------------------------------------------------------

# -- Instala todas las dependencias relacionadas con el compilador
install_compiler_dependencies:
	@echo "$(COLOR_BLUE)Instalando dependencias para la construcción del compilador...$(COLOR_RESET)"
	@$(foreach DEP,$(COMPILER_DEPENDENCIES), \
        if ! dpkg -s $(DEP) >/dev/null 2>&1; then \
            echo "$(COLOR_BOLD) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_RESET_BOLD) no está instalado. Instalando... $(COLOR_RESET)"; \
            sudo $(PACKAGE_MANAGER) update && sudo $(PACKAGE_MANAGER) install -y $(DEP); \
        else \
            echo " ---> $(COLOR_PURPLE)$(DEP)$(COLOR_RESET) ya se encuentra instalado en el sistema."; \
        fi; \
    )
	
# -- Desinstala todas las dependencias relacionadas con el compilador
uninstall_compiler_dependencies:
	@echo "$(COLOR_BLUE)Desinstalando dependencias para la construcción del compilador...$(COLOR_RESET)"
	@$(foreach DEP,$(COMPILER_DEPENDENCIES), \
        if dpkg -s $(DEP) >/dev/null 2>&1; then \
        	echo "$(COLOR_BOLD) ---> Desinstalando $(COLOR_PURPLE)$(DEP)...$(COLOR_RESET)"; \
            sudo $(PACKAGE_MANAGER) remove -y $(DEP) && sudo $(PACKAGE_MANAGER) autoremove -y; \
        else \
            echo "$(COLOR_YELLOW) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_YELLOW) NO! se encuentra instalado en el sistema.$(COLOR_RESET)"; \
        fi; \
    )
	
# -- Muestra la versión de todas las dependencias relacionadas con el compilador
version_compiler_dependencies:
	@echo "$(COLOR_BLUE)Versión instalada de las dependencias para la construcción del compilador:$(COLOR_RESET)"
	@$(foreach DEP,$(COMPILER_DEPENDENCIES), \
        if dpkg -s $(DEP) >/dev/null 2>&1; then \
            dpkg -s $(DEP) | grep '^Version:' | awk '{print " ---> Versión de $(COLOR_PURPLE)$(DEP)$(COLOR_RESET): ", $$2}'; \
        else \
            echo "$(COLOR_YELLOW) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_YELLOW) NO! se encuentra instalado en el sistema.$(COLOR_RESET)"; \
        fi; \
    )
    
# ----------------------------------------------------------------------------------------

# -- Instala todas las dependencias relacionadas con los tests del compilador
install_tests_dependencies:
	@echo "$(COLOR_BLUE)Instalando dependencias para realizacion de tests sobre compilador...$(COLOR_RESET)"
	@$(foreach DEP,$(TEST_DEPENDENCIES), \
        if ! dpkg -s $(DEP) >/dev/null 2>&1; then \
            echo "$(COLOR_BOLD) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_RESET_BOLD) no está instalado. Instalando... $(COLOR_RESET)"; \
            sudo $(PACKAGE_MANAGER) update && sudo $(PACKAGE_MANAGER) install -y $(DEP); \
        else \
            echo " ---> $(COLOR_PURPLE)$(DEP)$(COLOR_RESET) ya se encuentra instalado en el sistema."; \
        fi; \
    )
	
# -- Desinstala todas las dependencias relacionadas con el compilador
uninstall_tests_dependencies:
	@echo "$(COLOR_BLUE)Desinstalando dependencias para realizacion de tests sobre compilador...$(COLOR_RESET)"
	@$(foreach DEP,$(TEST_DEPENDENCIES), \
        if dpkg -s $(DEP) >/dev/null 2>&1; then \
        	echo "$(COLOR_BOLD) ---> Desinstalando $(COLOR_PURPLE)$(DEP)$(COLOR_RESET)...$(COLOR_RESET)"; \
            sudo $(PACKAGE_MANAGER) remove -y $(DEP) && sudo $(PACKAGE_MANAGER) autoremove -y; \
        else \
            echo "$(COLOR_YELLOW) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_YELLOW) NO! se encuentra instalado en el sistema.$(COLOR_RESET)"; \
        fi; \
    )
	
# -- Muestra la versión de todas las dependencias relacionadas con el compilador
version_tests_dependencies:
	@echo "$(COLOR_BLUE)Versión instalada de las dependencias para realizacion de tests sobre compilador:$(COLOR_RESET)"
	@$(foreach DEP,$(TEST_DEPENDENCIES), \
        if dpkg -s $(DEP) >/dev/null 2>&1; then \
            dpkg -s $(DEP) | grep '^Version:' | awk '{print " ---> Versión de $(COLOR_PURPLE)$(DEP)$(COLOR_RESET): ", $$2}'; \
        else \
            echo "$(COLOR_YELLOW) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_YELLOW) NO! se encuentra instalado en el sistema.$(COLOR_RESET)"; \
        fi; \
    )
    
# ========================================================================================
# DEFINICION DE REGLAS DE GESTION DE INFORME TEX
# ========================================================================================

# -- Compila el informe tex
build_tex: install_tex_dependencies
	@echo "$(COLOR_BLUE)Compilando informe TeX...$(COLOR_RESET)"
	@make -C $(TEX_DIR)
	@echo "$(COLOR_GREEN)Informe TeX compilado exitosamente en $(TEX_DIR)/ $(COLOR_RESET)"

# -- Elimina todos los ficheros generados por el makefile de tex
clean_tex:
	@echo "$(COLOR_BLUE)Limpiando archivos de informe TeX...$(COLOR_RESET)"
	@find $(TEX_DIR) -type f -regex $(TEX_GEN_FILES) -delete
	@echo "$(COLOR_GREEN)Archivos del informe TeX eliminados correctamente!$(COLOR_RESET)"
	
# ========================================================================================
# DEFINICION DE REGLAS DE COMPILACION DE FICHEROS DE TESTS
# ========================================================================================

# -- Compila los ficheros de tests
compile_tests: install_tests_dependencies compile_test_dummy
    
compile_test_dummy: build_bin_dir
	@echo; echo "$(COLOR_YELLOW) ---> Compilando $(COLOR_GREEN)$(TEST_DIR)/$(TEST_PREFIX)dummy$(TEST_EXT)$(COLOR_YELLOW) ...$(COLOR_RESET)"
	@$(GXX) $(CFLAGS) $(TEST_DIR)/$(TEST_PREFIX)dummy$(TEST_EXT) -o $(BIN_DIR)/$(TEST_PREFIX)dummy $(LDFLAGS)
	
clean_tests:
	@echo "$(COLOR_BLUE)Limpiando ficheros de tests compilados...$(COLOR_RESET)"
	@rm -f $(BIN_DIR)/$(TEST_PREFIX)*
	@echo "$(COLOR_GREEN)Archivos ficheros de tests compilados eliminados exitosamente!$(COLOR_RESET)"

# ========================================================================================
# DEFINICION DE REGLAS DE TESTEO DE FUENTES
# ========================================================================================

# -- Comprueba la sintaxis de los fuentes del proyecto
check: install_tests_dependencies
	@printf "$(COLOR_BLUE)\nRealizando comprobacion sobre fuentes del proyecto...\n$(COLOR_RESET)"
	@$(foreach DIR,$(INDEX_DIRS), \
        if [ -z "$(wildcard $(DIR)/*)" ]; then \
			printf "$(COLOR_RED) ---> [!!] No hay fuentes en $(COLOR_PURPLE)$(DIR)/$(COLOR_RESET)"; echo;\
		else \
			printf "$(COLOR_YELLOW) ---> Comprobando la sintaxis de las cabeceras en $(COLOR_PURPLE)$(DIR)/$(COLOR_YELLOW) ...$(COLOR_RESET)"; echo; \
			$(GXX) -fsyntax-only $(DIR)/*; \
			printf "$(COLOR_YELLOW) ---> Comprobando errores/bugs de las cabeceras en $(COLOR_PURPLE)$(DIR)/$(COLOR_YELLOW) ...$(COLOR_RESET)"; echo; \
			$(LINTER) $(DIR)/*; \
		fi; \
    )
    
test: install_tests_dependencies compile_tests
	@printf "$(COLOR_BLUE)\nEjecutando tests sobre fuentes del proyecto...\n$(COLOR_RESET)"
	@$(foreach F,$(INDEX_FILES), \
		echo "$(COLOR_YELLOW) ---> Ejecutando test: $(COLOR_PURPLE)$(TEST_PREFIX)$(F)$(COLOR_YELLOW) ... $(COLOR_RESET)"; \
        ./$(BIN_DIR)/$(TEST_PREFIX)$(F) ; \
        echo ; \
    )
