# ========================================================================================
# UNIVERSIDAD DE GRANADA - TRABAJO DE FIN DE GRADO (23/24)
# ========================================================================================
# PROYECTO: SIMULADOR DE SISTEMAS CONCURRENTES Y DISTRIBUIDOS
# ========================================================================================
# Autor: Daniel Perez Ruiz
# Tutor: Carlos Ureña Almagro
# ========================================================================================
# Version: 0.0.1
# ========================================================================================

# -- Definicion del shell a utilizar
SHELL := /bin/bash

# -- Deteccion de OS
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	DISTRIBUTION := $(shell cat /etc/os-release | grep -o '^ID=.*' | cut -d= -f2-)
	# -- Detectar SO Linux (Ubuntu)
    ifeq ($(DISTRIBUTION), ubuntu)
        PACKAGE_MANAGER:=apt
        UPDATE_OPTION:=$(PACKAGE_MANAGER) update
        INSTALL_OPTION:=$(PACKAGE_MANAGER) install -y
        REMOVE_OPTION:=$(PACKAGE_MANAGER) remove -y
        AUTOREMOVE_OPTION:=$(PACKAGE_MANAGER) autoremove -y
        CHECK_PACKAGES_V1 = dpkg -l $(1) 2>/dev/null | grep -qw 'ii'
        CHECK_PACKAGES_V2 = dpkg -s $(1) >/dev/null 2>&1
    endif
endif

.PHONY: backup build_bin_dir clean_bin_dir build_obj_dir clean_obj_dir update_packages

# ========================================================================================
# DEFINICION DE VARIABLES
# ========================================================================================

# -- Variables referentes a las dependencias del proyecto
DPKG_ARCHITECTURE=`dpkg --print-architecture`
VERSION_DISTRIBUTION_LINUX=`. /etc/os-release && echo "$$VERSION_CODENAME"`

TEX_DEPENDENCIES=texlive texlive-lang-spanish texlive-fonts-extra
COMPILER_DEPENDENCIES=gcc flex libfl-dev bison
TEST_DEPENDENCIES=libcmocka-dev cppcheck

# -- Variables referentes a informe tex
TEX_DIR=tex
TEX_GEN_FILES='.*\.\(aux\|log\|pdf\|dvi\|toc\|out\|bbl\|blg\|lot\|lof\)'

# -- Variables referentes a copias de seguridad locales
BACKUP_EXT_FILE:=.zip
BACKUP_NAME:=lamport
BACKUP_FILE:=$(BACKUP_NAME)$(BACKUP_EXT_FILE)
DIR_BACKUP:=$(HOME)

# -- Variables referentes a directorios de fuentes
HEADER_DIR:=include
SOURCE_DIR:=src
TEST_DIR:=test
BIN_DIR:=bin
OBJ_DIR:=obj
EXAMPLES_DIR:=examples
INDEX_DIRS:=$(HEADER_DIR) $(SOURCE_DIR) $(TEST_DIR)

# -- Variables referentes a macros
BISON_HEADER_MACRO:=BISON_HEADER

# -- Variables referentes a compilacion/comprobacion de ficheros
GXX:=gcc
CFLAGS:=-Wall -Wextra
UNDEFINED_MACROS:=-U$(BISON_HEADER_MACRO)
INCFLAGS:=-I$(HEADER_DIR) -I$(SOURCE_DIR)/ -I$(HEADER_DIR)/$(TEST_DIR) -I$(SOURCE_DIR)/$(TEST_DIR)
LDCMOCKA:=-lcmocka
LDFLEX:=-lfl
LDBISON:=-ly
LDFLAGS:=$(LDFLEX) $(LDBISON) $(LDCMOCKA)
LINTER:=cppcheck
TEST_PREFIX:=test_
TEST_COMMON_FUNCTIONS_PREFIX:=common_functions

# -- Variables de extensiones
SOURCE_EXT:=.c
HEADER_EXT:=.h
TEST_EXT:=.c
LEXER_EXT:=.l
BISON_EXT:=.y
LAMPORT_EXT:=.lmp

# -- Variables de ficheros
LEXER_NAME:=lexer
PARSER_NAME:=parser
AST_NAME:=AST
EXCLUDE_CHECK_FILES="$(FLEX_LEXER_SRC) $(LEXER_SRC) $(BISON_PARSER_SRC) $(PARSER_SRC)"

# -- Variables de ficheros (tests)
INDEX_TEST_LEXER_FILES:=$(TEST_PREFIX)$(LEXER_NAME)_recon_tokens $(TEST_PREFIX)$(LEXER_NAME)_recon_patrones $(TEST_PREFIX)$(LEXER_NAME)_errores $(TEST_PREFIX)$(LEXER_NAME)_recon_ficheros
INDEX_TEST_COMMON_FILES:=$(TEST_COMMON_FUNCTIONS_PREFIX)

# -- Variables de ficheros (src)
FLEX_LEXER_SRC:=$(LEXER_NAME)$(LEXER_EXT)
LEXER_SRC:=$(LEXER_NAME)$(SOURCE_EXT)
BISON_PARSER_SRC:=$(PARSER_NAME)$(BISON_EXT)
PARSER_SRC:=$(PARSER_NAME).tab$(SOURCE_EXT)
PARSER_HEADER:=$(PARSER_NAME).tab$(HEADER_EXT)
AST_HEADER:=$(AST_NAME)$(HEADER_EXT)
AST_SOURCE:=$(AST_NAME)$(SOURCE_EXT)

INDEX_LEXER_FILES:=$(LEXER_NAME)
INDEX_PARSER_FILES:=$(PARSER_NAME).tab $(LEXER_NAME) $(AST_NAME)
INDEX_AST_FILES:=$(AST_NAME)

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
# DEFINICION DE MACROS SKELETON
# ========================================================================================

define install_dependencies_skeleton
	@{ \
		echo "$(COLOR_BLUE)Instalando dependencias de $(1)...$(COLOR_RESET)" ; \
		$(foreach DEP,$(2), \
		    if ! $(call $(3),$(DEP)) ; then \
		        echo "$(COLOR_YELLOW) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_YELLOW) no está instalado. Instalando... $(COLOR_RESET)"; \
		        sudo $(INSTALL_OPTION) $(DEP); \
		    else \
		        echo " ---> $(COLOR_PURPLE)$(DEP)$(COLOR_RESET_BOLD) ya se encuentra instalado en el sistema.$(COLOR_RESET)"; \
		    fi; \
        ) \
	}
endef

define uninstall_dependencies_skeleton
	@{ \
		echo "$(COLOR_BLUE)Desinstalando dependencias de $(1)...$(COLOR_RESET)" ; \
		$(foreach DEP,$(2), \
			if $(call $(3),$(DEP)); then \
				echo "$(COLOR_BOLD) ---> Desinstalando $(COLOR_PURPLE)$(DEP)$(COLOR_RESET)...$(COLOR_RESET)"; \
			    sudo $(REMOVE_OPTION) $(DEP) && sudo $(AUTOREMOVE_OPTION); \
			else \
			    echo "$(COLOR_YELLOW) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_YELLOW) NO! se encuentra instalado en el sistema.$(COLOR_RESET)"; \
			fi; \
	    ) \
	}
endef

define version_dependencies_skeleton
	@{ \
		echo "$(COLOR_BLUE)Versión instalada de las dependencias de $(1):$(COLOR_RESET)" ; \
		$(foreach DEP,$(2), \
			if $(call $(3),$(DEP)); then \
				dpkg -s $(DEP) | grep '^Version:' | awk '{print " ---> Versión de $(COLOR_PURPLE)$(DEP)$(COLOR_RESET): ", $$2}'; \
			else \
				echo "$(COLOR_YELLOW) ---> $(COLOR_PURPLE)$(DEP)$(COLOR_YELLOW) NO! se encuentra instalado en el sistema.$(COLOR_RESET)"; \
			fi; \
		) \
	}
endef

define compile_skeleton
	@{ \
		COMPILATION_MODE="$(4)"; \
		if [ "$$COMPILATION_MODE" = "multiple" ]; then \
			N_FILES_EXPECTED=1; \
			echo "$(COLOR_BOLD)>>> Compilando fuentes de modulo: $(COLOR_PURPLE)$(2)$(COLOR_RESET_BOLD) [$$N_FILES_EXPECTED ficheros detectados] ... $(COLOR_RESET)" ;\
			N_FILES_COMPILED=0 ;\
		    LIST_OF_SOURCES=""; \
			for F in $(1); do \
				LIST_OF_SOURCES="$$LIST_OF_SOURCES $(SOURCE_DIR)/$$F$(SOURCE_EXT)"; \
			done; \
			echo "$(COLOR_YELLOW) ---> Compilando $(COLOR_GREEN)$(SOURCE_DIR)/$(5)$(SOURCE_EXT)$(COLOR_YELLOW) ...$(COLOR_RESET)" ; \
			$(GXX) $(INCFLAGS) $$LIST_OF_SOURCES -o $(BIN_DIR)/$(5) $(3) ; \
			if [ -f $(BIN_DIR)/$(5) ]; then \
				echo "$(COLOR_GREEN) ---> $(COLOR_PURPLE)$(SOURCE_DIR)/$$F$(SOURCE_EXT)$(COLOR_GREEN) compilado exitosamente!! $(COLOR_RESET)" ; \
				N_FILES_COMPILED=$$(( N_FILES_COMPILED + 1 )) ; \
			fi ; \
			echo "$(COLOR_BOLD)>>> Modulo: $(COLOR_PURPLE)$(2)$(COLOR_RESET_BOLD) compilado exitosamente!! [$$N_FILES_COMPILED ficheros] $(COLOR_RESET)" ;\
		else \
			N_FILES_EXPECTED=$(words $(1)) ; \
			echo "$(COLOR_BOLD)>>> Compilando fuentes de modulo: $(COLOR_PURPLE)$(2)$(COLOR_RESET_BOLD) [$$N_FILES_EXPECTED ficheros detectados] ... $(COLOR_RESET)" ;\
			N_FILES_COMPILED=0 ;\
			for F in $(1); do \
				echo "$(COLOR_YELLOW) ---> Compilando $(COLOR_GREEN)$(SOURCE_DIR)/$$F$(SOURCE_EXT)$(COLOR_YELLOW) ...$(COLOR_RESET)" ; \
				$(GXX) $(INCFLAGS) $(SOURCE_DIR)/$$F$(SOURCE_EXT) -o $(BIN_DIR)/$$F $(3) ; \
				if [ -f $(BIN_DIR)/$$F ]; then \
					echo "$(COLOR_GREEN) ---> $(COLOR_PURPLE)$(SOURCE_DIR)/$$F$(SOURCE_EXT)$(COLOR_GREEN) compilado exitosamente!! $(COLOR_RESET)" ; \
					N_FILES_COMPILED=$$(( N_FILES_COMPILED + 1 )) ; \
				fi ; \
			done; \
			echo "$(COLOR_BOLD)>>> Modulo: $(COLOR_PURPLE)$(2)$(COLOR_RESET_BOLD) compilado exitosamente!! [$$N_FILES_COMPILED ficheros] $(COLOR_RESET)" ;\
		fi; \
	}
endef

define compile_objects_skeleton
	@{ \
		N_FILES_EXPECTED=$(words $(1)) ; \
		echo "$(COLOR_BOLD)>>> Compilando archivos objeto de modulo: $(COLOR_PURPLE)$(3)$(COLOR_RESET_BOLD) [$$N_FILES_EXPECTED ficheros detectados] ... $(COLOR_RESET)" ;\
		N_FILES_COMPILED=0 ;\
		for F in $(1); do \
			echo "$(COLOR_YELLOW) ---> Compilando $(COLOR_GREEN)$(SOURCE_DIR)/$(2)$$F$(SOURCE_EXT)$(COLOR_YELLOW) ...$(COLOR_RESET)" ; \
			$(GXX) $(INCFLAGS) -c $(SOURCE_DIR)/$(2)$$F$(SOURCE_EXT) -o $(OBJ_DIR)/$$F.o $(4) ; \
			if [ -f $(OBJ_DIR)/$$F.o ]; then \
				echo "$(COLOR_GREEN) ---> $(COLOR_PURPLE)$(OBJ_DIR)/$$F.o$(COLOR_GREEN) compilado exitosamente!! $(COLOR_RESET)" ; \
				N_FILES_COMPILED=$$(( N_FILES_COMPILED + 1 )) ; \
			fi ; \
		done; \
		echo "$(COLOR_BOLD)>>> Modulo: $(COLOR_PURPLE)$(3)$(COLOR_RESET_BOLD) compilado exitosamente!! [$$N_FILES_COMPILED ficheros] $(COLOR_RESET)" ;\
	}
endef

define compile_tests_skeleton
	@{ \
		N_TESTS_EXPECTED=$(words $(1)) ; \
		echo "$(COLOR_BOLD)>>> Compilando tests de $(COLOR_PURPLE)$(2)$(COLOR_RESET_BOLD) [$$N_TESTS_EXPECTED tests detectados] ... $(COLOR_RESET)" ;\
		N_TESTS_COMPILED=0 ;\
		for TEST in $(1); do \
			echo "$(COLOR_YELLOW) ---> Compilando $(COLOR_GREEN)$(TEST_DIR)/$$TEST$(TEST_EXT)$(COLOR_YELLOW) ...$(COLOR_RESET)" ; \
			$(GXX) $(4) $(INCFLAGS) $(OBJ_DIR)/* $(TEST_DIR)/$$TEST$(TEST_EXT) -o $(BIN_DIR)/$$TEST $(LDCMOCKA) $(3); \
			if [ -f $(BIN_DIR)/$$TEST ]; then \
				echo "$(COLOR_GREEN) ---> $(COLOR_PURPLE)$(TEST_DIR)/$$TEST$(TEST_EXT)$(COLOR_GREEN) compilado exitosamente!! $(COLOR_RESET)" ; \
				N_TESTS_COMPILED=$$(( N_TESTS_COMPILED + 1 )) ; \
			fi ; \
		done; \
		echo "$(COLOR_BOLD)>>> Tests de $(COLOR_PURPLE)$(2)$(COLOR_RESET_BOLD) compilados exitosamente!! [$$N_TESTS_COMPILED tests] $(COLOR_RESET)" ;\
	}
endef

define check_compiled_files_skeleton
	@{ \
		for F in $(1); do \
			if [ ! -f $(BIN_DIR)/$$F ]; then \
				make $(2) ; \
				echo ; \
				break ; \
			fi; \
		done; \
	}
endef

define exec_tests_skeleton
	@{ \
		N_TESTS=$(words $(2)) ; \
		echo "$(COLOR_BOLD)>>> Ejecutando tests sobre modulo: $(COLOR_YELLOW)$(1)$(COLOR_RESET_BOLD) [$$N_TESTS tests] ...$(COLOR_RESET)"; \
		N_TESTS_FAILED=0 ; \
		for TEST in $(2); do \
			echo "$(COLOR_YELLOW) ---> Ejecutando test: $(COLOR_PURPLE)$$TEST$(COLOR_YELLOW) ... $(COLOR_RESET)"; \
			./$(BIN_DIR)/$$TEST; \
			if [ $$? -ne 0 ]; then \
				N_TESTS_FAILED=$$((N_TESTS_FAILED + 1)); \
			fi; \
			echo ; \
		done; \
		echo "$(COLOR_BOLD)>>> Tests de $(COLOR_YELLOW)$(1)$(COLOR_RESET_BOLD) ejecutados exitosamente: [$$N_TESTS tests -> $$N_TESTS_FAILED tests fallados] ...$(COLOR_RESET)"; \
		if [ $${N_TESTS_FAILED} -gt 0 ]; then \
			exit 1; \
		fi; \
	}
endef

define parse_and_check_files_skeleton
	@{ \
		N_CHECKS_FAILED=0; \
		for DIR in $(1); do \
			echo "$(COLOR_BOLD)>>> Escaneando ficheros de $(COLOR_BLUE)$${DIR}/$(COLOR_RESET_BOLD) ... $(COLOR_RESET)" ; \
			if [ -z "$$(ls -A $$DIR)" ]; then \
				echo "$(COLOR_RED) ---> [!!] No hay fuentes en $(COLOR_PURPLE)$$DIR/$(COLOR_RESET)"; echo;\
			else \
				for FILE in $$DIR/*; do \
					if [ ! -d $$FILE ]; then \
						FILE_BASENAME=$$(basename $$FILE) ; \
						if ! echo $(2) | tr " " '\n' | grep -F -q -x "$$FILE_BASENAME"; then \
							echo "$(COLOR_YELLOW) ---> Comprobando la sintaxis de $(COLOR_PURPLE)$$FILE$(COLOR_YELLOW) ...$(COLOR_RESET)"; \
							$(GXX) $(INCFLAGS) -fsyntax-only $$FILE; \
							if [ $$? -ne 0 ]; then \
								N_CHECKS_FAILED=$$((N_CHECKS_FAILED + 1)); \
							fi; \
							echo "$(COLOR_YELLOW) ---> Comprobando errores/bugs de $(COLOR_PURPLE)$$FILE$(COLOR_YELLOW) ...$(COLOR_RESET)"; \
							$(LINTER) $$FILE; \
							if [ $$? -ne 0 ]; then \
								N_CHECKS_FAILED=$$((N_CHECKS_FAILED + 1)); \
							fi; \
							echo; \
						fi; \
					fi; \
				done; \
			fi; \
			echo; \
		done; \
		echo "$(COLOR_BOLD)>>> Fin del escaneo de directorios. [$${N_CHECKS_FAILED} comprobaciones fallidas] $(COLOR_RESET)" ; \
		if [ $${N_CHECKS_FAILED} -gt 0 ]; then \
			exit 1; \
		fi; \
	}
endef

define clean_dir_skeleton
	@{ \
		if [ -z "$(wildcard $(1)/*)" ] && [ -d $(1)/ ]; then \
			echo; echo "$(COLOR_BLUE)Eliminando directorio $(COLOR_PURPLE)$(1)/$(COLOR_BLUE)...$(COLOR_RESET)"; \
			rmdir $(1) 2>/dev/null || true; \
			echo "$(COLOR_GREEN)Directorio $(COLOR_PURPLE)$(1)/$(COLOR_GREEN) eliminado correctamente!$(COLOR_RESET)"; \
		fi ; \
	}
endef

# ========================================================================================
# DEFINICION DE REGLAS PRINICPALES (ALL/CLEAN)
# ========================================================================================

# -- Elimina todos los ficheros que se hayan generado usando el Makefile
clean:
	@make -s clean_tex && echo
	@make -s clean_tests && echo
	@make -s clean_objects && echo
	@make -s clean_binaries

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
	
clean_bin_dir:
	$(call clean_dir_skeleton,$(BIN_DIR))

clean_bin_dir_old:
	@if [ -z "$(wildcard $(BIN_DIR)/*)" ] && [ -d $(BIN_DIR)/ ]; then \
		echo; echo "$(COLOR_BLUE)Eliminando directorio $(COLOR_PURPLE)$(BIN_DIR)/$(COLOR_BLUE)...$(COLOR_RESET)"; \
		rmdir $(BIN_DIR) 2>/dev/null || true; \
		echo "$(COLOR_GREEN)Directorio $(COLOR_PURPLE)$(BIN_DIR)/$(COLOR_GREEN) eliminado correctamente!$(COLOR_RESET)"; \
	fi
	
build_obj_dir:
	@mkdir -p $(OBJ_DIR)
	
clean_obj_dir:
	$(call clean_dir_skeleton,$(OBJ_DIR))
	
update_packages:
	@sudo $(UPDATE_OPTION)

# ========================================================================================
# DEFINICION DE REGLAS DE LIMPIEZA (CLEAN)
# ========================================================================================	

# -- Limpia los ficheros de tests compilados
clean_tests:
	@echo "$(COLOR_BLUE)Limpiando ficheros de tests compilados...$(COLOR_RESET)"
	@-rm -f $(BIN_DIR)/$(TEST_PREFIX)* 2> /dev/null
	@echo "$(COLOR_GREEN)Archivos ficheros de tests compilados eliminados exitosamente!$(COLOR_RESET)"
	@make -s clean_bin_dir

# -- Limpia todos los ficheros compilados
clean_binaries:
	@echo "$(COLOR_BLUE)Limpiando ficheros compilados...$(COLOR_RESET)"
	@rm -f $(BIN_DIR)/*
	@echo "$(COLOR_GREEN)Archivos eliminados exitosamente!$(COLOR_RESET)"
	@make -s clean_bin_dir

# -- Limpia todos los ficheros objeto generados
clean_objects:
	@echo "$(COLOR_BLUE)Limpiando ficheros objeto...$(COLOR_RESET)"
	@rm -f $(OBJ_DIR)/*
	@echo "$(COLOR_GREEN)Archivos eliminados exitosamente!$(COLOR_RESET)"
	@make -s clean_obj_dir

# ========================================================================================
# DEFINICION DE OTRAS REGLAS
# ========================================================================================

# -- Muestra en terminal la informacion general del proyecto
author:
	@echo "$(COLOR_BOLD)"
	@echo "UNIVERSIDAD DE GRANADA : TRABAJO DE FIN DE GRADO"
	@echo " -- Nombre de proyecto: Lamport. Simulador de Sistemas Concurrentes y Distribuidos"
	@echo " -- Autor: Daniel Pérez Ruiz"
	@echo " -- Tutor: Carlos Ureña Almagro"
	@echo " -- Version: 0.0.0"
	@echo "$(COLOR_RESET)"

# -- Muestra las diferentes opciones de Makefile
help:
	@echo "$(COLOR_BOLD)"
	@echo "-- TAREAS DE MAKEFILE --"
	@printf "%-30s %s\n" "make" "*No definido todavia*"
	@printf "%-30s %s\n" "make author" "Muestra informacion acerca del TFG (autoria)."
	@printf "%-30s %s\n" "make help" "Muestra este menu de opciones."
	@printf "%-30s %s\n" "make install_dependencies" "Instala todas las dependencias del proyecto (TeX, compilador, tests)."
	@printf "%-30s %s\n" "make uninstall_dependencies" "Desinstala todas las dependencias del proyecto (TeX, compilador, tests)."
	@printf "%-30s %s\n" "make version_dependencies" "Muestra la versión de las dependencias instaladas."
	@printf "%-30s %s\n" "make compile" "Compila todos los fuentes del proyecto."
	@printf "%-30s %s\n" "make check" "Analiza el codigo de los fuentes comprobando errores de sintaxis, warnings de estilo, etc."
	@printf "%-30s %s\n" "make tests" "Compila y ejecuta los tests sobre los fuentes del proyecto."
	@printf "%-30s %s\n" "make clean" "Elimina todos los ficheros binarios compilados o generados por el Makefile."
	@echo "$(COLOR_RESET)"


# ========================================================================================
# DEFINICION DE REGLAS DE GESTION DE DEPENDENCIAS
# ========================================================================================

# -- Instala todas las dependencias del proyecto
install_dependencies: update_packages install_tex_dependencies install_source_dependencies

# -- Instala todas las dependencias relacionadas con el codigo fuente del proyecto
install_source_dependencies: update_packages install_compiler_dependencies install_tests_dependencies

# -- Desinstala todas las dependencias del proyecto
uninstall_dependencies: uninstall_tex_dependencies uninstall_compiler_dependencies uninstall_tests_dependencies

# -- Muestra la versión de todas las dependencias del proyecto
version_dependencies: version_tex_dependencies version_compiler_dependencies version_tests_dependencies

# ----------------------------------------------------------------------------------------

# -- Instala todas las dependencias relacionadas con informe TFG
install_tex_dependencies:
	$(call install_dependencies_skeleton,"TeX",$(TEX_DEPENDENCIES),CHECK_PACKAGES_V1)
	
# -- Desinstala todas las dependencias relacionadas con el informe TFG
uninstall_tex_dependencies:
	$(call uninstall_dependencies_skeleton,"TeX",$(TEX_DEPENDENCIES),CHECK_PACKAGES_V1)

# -- Muestra la version de todas las dependencias relacionadas con el informe TFG
version_tex_dependencies:
	$(call version_dependencies_skeleton,"TeX",$(TEX_DEPENDENCIES),CHECK_PACKAGES_V1)

# ----------------------------------------------------------------------------------------

# -- Instala todas las dependencias relacionadas con el compilador
install_compiler_dependencies:
	$(call install_dependencies_skeleton,"construccion de compilador",$(COMPILER_DEPENDENCIES),CHECK_PACKAGES_V2)	

uninstall_compiler_dependencies:
	$(call uninstall_dependencies_skeleton,"construccion de compilador",$(COMPILER_DEPENDENCIES),CHECK_PACKAGES_V2)	
    
version_compiler_dependencies:
	$(call version_dependencies_skeleton,"construccion de compilador",$(COMPILER_DEPENDENCIES),CHECK_PACKAGES_V2)
    
# ----------------------------------------------------------------------------------------

# -- Instala todas las dependencias relacionadas con los tests del compilador
install_tests_dependencies:
	$(call install_dependencies_skeleton,"tests sobre compilador",$(TEST_DEPENDENCIES),CHECK_PACKAGES_V2)
	
# -- Desinstala todas las dependencias relacionadas con el compilador
uninstall_tests_dependencies:
	$(call uninstall_dependencies_skeleton,"tests sobre compilador",$(TEST_DEPENDENCIES),CHECK_PACKAGES_V2)

# -- Muestra la versión de todas las dependencias relacionadas con el compilador
version_tests_dependencies:
	$(call version_dependencies_skeleton,"tests sobre compilador",$(TEST_DEPENDENCIES),CHECK_PACKAGES_V2)
    
# ========================================================================================
# DEFINICION DE REGLAS DE GESTION DE INFORME TEX
# ========================================================================================

# -- Compila el informe tex
build_tex: install_tex_dependencies
	@echo "$(COLOR_BLUE)Compilando informe TeX...$(COLOR_RESET)"
	@make -sC $(TEX_DIR)
	@echo "$(COLOR_GREEN)Informe TeX compilado exitosamente en $(TEX_DIR)/ $(COLOR_RESET)"

# -- Elimina todos los ficheros generados por el makefile de tex
clean_tex:
	@echo "$(COLOR_BLUE)Limpiando archivos de informe TeX...$(COLOR_RESET)"
	@find $(TEX_DIR) -type f -regex $(TEX_GEN_FILES) -delete
	@echo "$(COLOR_GREEN)Archivos del informe TeX eliminados correctamente!$(COLOR_RESET)"
	
# ========================================================================================
# DEFINICION DE REGLAS DE COMPILACION
# ========================================================================================

# -- Compila los fuentes del proyecto
compile:
	@echo "$(COLOR_BLUE)Compilando ficheros de fuentes del proyecto...$(COLOR_RESET)"
	@make -s compile_sources && echo
	@make -s compile_tests
	
compile_sources:
	@make -s compile_lexer && echo
	@make -s compile_parser && echo 

# -- Genera la fuente del analizador lexico a traves de flex
generate_lexer: $(SOURCE_DIR)/$(FLEX_LEXER_SRC)
	@echo "$(COLOR_BOLD)>>> Generando analizador lexico $(COLOR_GREEN)$(SOURCE_DIR)/$(FLEX_LEXER_SRC)$(COLOR_RESET_BOLD) ...$(COLOR_RESET)"
	@flex -o $(SOURCE_DIR)/$(LEXER_SRC) $(SOURCE_DIR)/$(FLEX_LEXER_SRC)
	@echo "$(COLOR_BOLD)>>> Analizador lexico generado: $(COLOR_PURPLE)$(SOURCE_DIR)/$(LEXER_SRC)$(COLOR_RESET)"
	
# -- Compila los fuentes del analizador lexico
compile_lexer: build_bin_dir build_obj_dir
	@make -s generate_lexer && echo
	$(call compile_skeleton, $(INDEX_LEXER_FILES), "analizador lexico", $(LDFLEX),"")

# -- Genera la fuente del analizador sintactico a traves de bison	
generate_parser:
	@echo "$(COLOR_BOLD)>>> Generando analizador sintactico $(COLOR_GREEN)$(SOURCE_DIR)/$(BISON_PARSER_SRC)$(COLOR_RESET_BOLD) ...$(COLOR_RESET)"
	@bison -d $(SOURCE_DIR)/$(BISON_PARSER_SRC)
	@mv $(PARSER_SRC) $(SOURCE_DIR)
	@mv $(PARSER_HEADER) $(HEADER_DIR)
	@echo "$(COLOR_BOLD)>>> Analizador sintactico generado: $(COLOR_PURPLE)$(SOURCE_DIR)/$(PARSER_SRC)$(COLOR_RESET)"
	@echo "$(COLOR_BOLD)>>> Cabecera del Analizador sintactico generado: $(COLOR_PURPLE)$(HEADER_DIR)/$(PARSER_HEADER)$(COLOR_RESET)"
	
# -- Compila los fuentes del analizador sintactico
compile_parser: build_bin_dir build_obj_dir
	@make -s generate_parser && echo
	$(call compile_skeleton, $(INDEX_PARSER_FILES),"analizador sintactico",$(LDFLEX),"multiple",$(PARSER_NAME))
	
	
# ========================================================================================
# DEFINICION DE REGLAS DE COMPILACION DE FICHEROS DE TESTS
# ========================================================================================

# -- Compila los ficheros de tests
compile_tests:
	@echo "$(COLOR_BLUE)Compilando ficheros de test sobre fuentes...$(COLOR_RESET)"	
	@make -s compile_tests_lexer
	
# -- Compila los ficheros de tests sobre modulo: lexer
compile_tests_lexer: build_bin_dir build_obj_dir
	$(call check_compiled_files_skeleton,$(INDEX_LEXER_FILES),"compile_lexer")
	$(call compile_objects_skeleton,$(INDEX_TEST_COMMON_FILES),"$(TEST_DIR)/","common tests resources",$(LDFLAGS))
	@echo
	$(call compile_tests_skeleton,$(INDEX_TEST_LEXER_FILES),"analizador lexico",$(LDFLEX) $(UNDEFINED_MACROS))
	@echo
	@make -s clean_objects

# ========================================================================================
# DEFINICION DE REGLAS DE TESTEO DE FUENTES
# ========================================================================================

# -- Comprueba la sintaxis de los fuentes del proyecto
check:
	$(call parse_and_check_files_skeleton,$(INDEX_DIRS),$(EXCLUDE_CHECK_FILES))

# -- Ejecuta los tests sobre los fuentes del proyecto
tests:
	@printf "$(COLOR_BLUE)\nEjecutando tests sobre fuentes del proyecto...\n$(COLOR_RESET)"
	@make -s test_lexer

# -- Ejecuta los tests sobre modulo: lexer
test_lexer: 
	$(call check_compiled_files_skeleton,$(INDEX_TEST_LEXER_FILES),compile_tests_lexer)
	$(call exec_tests_skeleton,lexer,$(INDEX_TEST_LEXER_FILES))
