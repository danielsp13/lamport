# ========================================================================================
# UNIVERSIDAD DE GRANADA - TRABAJO DE FIN DE GRADO (23/24)
# ========================================================================================
# PROYECTO: SIMULADOR DE SISTEMAS CONCURRENTES Y DISTRIBUIDOS
# ========================================================================================
# Autor: Daniel Perez Ruiz
# Tutor: Carlos Ureña Almagro
# ========================================================================================
# Version: 0.0.8
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

.PHONY: backup build_bin_dir clean_bin_dir build_obj_dir clean_obj_dir clean_log_dir update_packages
.PHONY: make_compile_msg compile_lexer_msg compile_parser_msg compile_ast_msg compile_error_msg compile_lmp_utils_msg compile_ir_msg

# ========================================================================================
# DEFINICION DE VARIABLES
# ========================================================================================

# -- Variables referentes a las dependencias del proyecto
DPKG_ARCHITECTURE=`dpkg --print-architecture`
VERSION_DISTRIBUTION_LINUX=`. /etc/os-release && echo "$$VERSION_CODENAME"`

TEX_DEPENDENCIES=texlive texlive-lang-spanish texlive-fonts-extra
COMPILER_DEPENDENCIES=gcc g++ flex libfl-dev bison parallel
TEST_DEPENDENCIES=cppcheck valgrind

# -- Variables referentes a compilacion/comprobacion de ficheros
CFLAGS:=-Wall -Wextra
UNDEFINED_MACROS=-D$(LEXER_TESTS_MACRO)

INCLUDE_FLAGS=-I$(HEADER_DIR) -I$(SOURCE_DIR)

LDCMOCKA:=-lcmocka
LDFLEX:=-lfl
LDBISON:=-ly
LDFLAGS:=$(LDFLEX) $(LDBISON) $(LDCMOCKA)
LINTER:=cppcheck
TEST_PREFIX:=test_

# -- Variables referentes a macros
LEXER_TESTS_MACRO:=LEXER_TEST

# -- Variables referentes a informe tex
TEX_DIR=tex
TEX_GEN_FILES='.*\.\(aux\|log\|pdf\|dvi\|toc\|out\|bbl\|blg\|lot\|lof\)'

# -- Variables de extensiones
SOURCE_C_EXT:=.c
HEADER_C_EXT:=.h
SOURCE_CPLUS_EXT:=.cpp
HEADER_CPLUS_EXT:=.hpp
TEST_EXT:=.c
FLEX_EXT:=.l
BISON_EXT:=.y
OBJ_EXT:=.o
LAMPORT_EXT:=.lmp

# -- Variables referentes a copias de seguridad locales
BACKUP_EXT_FILE:=.zip
BACKUP_NAME:=lamport
BACKUP_FILE:=$(BACKUP_NAME)$(BACKUP_EXT_FILE)
DIR_BACKUP:=$(HOME)

# -- Variables referentes a directorios de fuentes
HEADER_DIR:=include
SOURCE_DIR:=src
BIN_DIR:=bin
OBJ_DIR:=obj
TEST_DIR:=test
LOG_DIR:=log
EXAMPLES_DIR:=examples
INDEX_DIRS=$(HEADER_MODULES_DIR) $(SOURCE_MODULES_DIR)
HEADER_MODULES_DIR=$(HEADER_LEXER) $(HEADER_PARSER) $(HEADER_AST) $(HEADER_SEMANTIC) $(HEADER_ERROR) $(HEADER_IR) $(HEADER_LMP_UTILS) $(HEADER_LVM)
SOURCE_MODULES_DIR=$(SOURCE_LEXER) $(SOURCE_PARSER) $(SOURCE_AST) $(SOURCE_SEMANTIC) $(SOURCE_ERROR) $(SOURCE_IR) $(SOURCE_LMP_UTILS) $(SOURCE_LVM)

# -- Variables referentes a modulos
LEXER_MODULE:=lexer
PARSER_MODULE:=parser
AST_MODULE:=AST
SEMANTIC_MODULE:=semantic
ERROR_MODULE:=error
LMP_UTILS_MODULE:=lmp_utils
IR_MODULE:=IR
TEST_UTILS_MODULE:=test_utils
LVM_MODULE:=LVM

# -- Variables referentes a directorios de modulos (cabeceras)
HEADER_LEXER:=$(HEADER_DIR)/$(LEXER_MODULE)
HEADER_PARSER:=$(HEADER_DIR)/$(PARSER_MODULE)
HEADER_AST:=$(HEADER_DIR)/$(AST_MODULE)
HEADER_SEMANTIC:=$(HEADER_DIR)/$(SEMANTIC_MODULE)
HEADER_ERROR:=$(HEADER_DIR)/$(ERROR_MODULE)
HEADER_LMP_UTILS:=$(HEADER_DIR)/$(LMP_UTILS_MODULE)
HEADER_IR:=$(HEADER_DIR)/$(IR_MODULE)
HEADER_TEST_UTILS:=$(HEADER_DIR)/$(TEST_UTILS_MODULE)
HEADER_LVM:=$(HEADER_DIR)/$(LVM_MODULE)

# -- Variables referentes a directorios de modulos (sources)
SOURCE_LEXER:=$(SOURCE_DIR)/$(LEXER_MODULE)
SOURCE_PARSER:=$(SOURCE_DIR)/$(PARSER_MODULE)
SOURCE_AST:=$(SOURCE_DIR)/$(AST_MODULE)
SOURCE_SEMANTIC:=$(SOURCE_DIR)/$(SEMANTIC_MODULE)
SOURCE_ERROR:=$(SOURCE_DIR)/$(ERROR_MODULE)
SOURCE_LMP_UTILS:=$(SOURCE_DIR)/$(LMP_UTILS_MODULE)
SOURCE_IR:=$(SOURCE_DIR)/$(IR_MODULE)
SOURCE_TEST_UTILS:=$(SOURCE_DIR)/$(TEST_UTILS_MODULE)
SOURCE_LVM:=$(SOURCE_DIR)/$(LVM_MODULE)

# -- Variables de ficheros
TOKEN_TYPE_NAME:=token
LMP_MAIN_NAME:=lmp
TEST_VALGRIND_SCRIPT=test_valgrind_multiple_lmp_files.sh
EXCLUDE_CHECK_FILES="$(LEXER_MODULE)$(FLEX_EXT) $(LEXER_MODULE)$(SOURCE_C_EXT) $(PARSER_MODULE)$(BISON_EXT) $(PARSER_MODULE)$(SOURCE_C_EXT)"

# -- Indice de ficheros
INDEX_LEXER_FILES:=lexer
INDEX_PARSER_FILES:=parser parser_register
INDEX_AST_FILES:=AST declaration statement expression type parameter subprogram process print_assistant
INDEX_SEMANTIC_FILES:=symbol scope scope_stack symbol_table name_resolution type_checking
INDEX_ERROR_FILES:=error error_syntax error_semantic error_manager
INDEX_LMP_UTILS_FILES:=lmp_io lmp_analysis lmp_ir lmp_logging lmp_tasker lmp_lvm_launcher
INDEX_IR_FILES:=literal variable table ir_optimizer instruction_table ir_reg_manager ir_printer ir_translator_decl ir_translator_stmt ir_translator_expr ir_translator_proc ir_translator_subprog ir_translator_assistant ir_builder
INDEX_LVM_FILES:=memory_block memory initializer page_table register register_table stack_block CPU LVM

# -- Indice de ficheros (obj)
INDEX_OBJ_LEXER_FILES:=$(addsuffix $(OBJ_EXT), $(INDEX_LEXER_FILES))
INDEX_OBJ_PARSER_FILES:=$(addsuffix $(OBJ_EXT), $(INDEX_PARSER_FILES))
INDEX_OBJ_AST_FILES:=$(addsuffix $(OBJ_EXT), $(INDEX_AST_FILES))
INDEX_OBJ_SEMANTIC_FILES:=$(addsuffix $(OBJ_EXT), $(INDEX_SEMANTIC_FILES))
INDEX_OBJ_ERROR_FILES:=$(addsuffix $(OBJ_EXT),$(INDEX_ERROR_FILES))
INDEX_OBJ_LMP_UTILS_FILES:=$(addsuffix $(OBJ_EXT), $(INDEX_LMP_UTILS_FILES))
INDEX_OBJ_IR_FILES:=$(addsuffix $(OBJ_EXT), $(INDEX_IR_FILES))
INDEX_OBJ_LVM_FILES:=$(addsuffix $(OBJ_EXT), $(INDEX_LVM_FILES))

INDEX_OBJ_FILES:=$(INDEX_OBJ_LEXER_FILES) $(INDEX_OBJ_PARSER_FILES) $(INDEX_OBJ_AST_FILES) $(INDEX_OBJ_SEMANTIC_FILES) $(INDEX_OBJ_ERROR_FILES) $(INDEX_OBJ_LMP_FILES) $(INDEX_OBJ_IR_FILES) $(INDEX_OBJ_LVM_FILES)

# -- Indice de ficheros (source)
INDEX_SOURCE_LEXER_FILES:=$(addprefix $(SOURCE_LEXER)/, $(addsuffix $(SOURCE_C_EXT), $(INDEX_LEXER_FILES)))
INDEX_SOURCE_PARSER_FILES:=$(addprefix $(SOURCE_PARSER)/, $(addsuffix $(SOURCE_C_EXT), $(INDEX_PARSER_FILES)))
INDEX_SOURCE_AST_FILES:=$(addprefix $(SOURCE_AST)/, $(addsuffix $(SOURCE_C_EXT), $(INDEX_AST_FILES)))
INDEX_SOURCE_SEMANTIC_FILES:=$(addprefix $(SOURCE_SEMANTIC)/, $(addsuffix $(SOURCE_C_EXT), $(INDEX_SEMANTIC_FILES)))
INDEX_SOURCE_ERROR_FILES:=$(addprefix $(SOURCE_ERROR)/, $(addsuffix $(SOURCE_C_EXT), $(INDEX_ERROR_FILES)))
INDEX_SOURCE_LMP_UTILS_FILES:=$(addprefix $(SOURCE_LMP_UTILS)/, $(addsuffix $(SOURCE_CPLUS_EXT), $(INDEX_LMP_UTILS_FILES)))
INDEX_SOURCE_IR_FILES:=$(addprefix $(SOURCE_IR)/, $(addsuffix $(SOURCE_CPLUS_EXT), $(INDEX_IR_FILES)))
INDEX_SOURCE_LVM_FILES:=$(addprefix $(SOURCE_LVM)/, $(addsuffix $(SOURCE_CPLUS_EXT), $(INDEX_LVM_FILES)))
 
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

define compile_objects_skeleton
	@{ \
		N_FILES_EXPECTED=$(words $(3)) ; \
		echo "$(COLOR_BOLD)>>> Compilando archivos objeto de modulo: $(COLOR_BLUE)$(5)$(COLOR_RESET_BOLD) [$$N_FILES_EXPECTED ficheros detectados] ... $(COLOR_RESET)" ;\
		N_FILES_COMPILED=0 ;\
		for F in $(3); do \
			echo "$(COLOR_YELLOW) ---> Compilando: $(COLOR_PURPLE)$(SOURCE_DIR)/$(4)$$F$(2)$(COLOR_YELLOW) ...$(COLOR_RESET)" ; \
			$(1) $(INCLUDE_FLAGS) -c $(SOURCE_DIR)/$(4)$$F$(2) -o $(OBJ_DIR)/$$F.o $(6) ; \
			if [ -f $(OBJ_DIR)/$$F.o ]; then \
				echo "$(COLOR_GREEN) ---> Codigo objeto de: $(COLOR_PURPLE)$(OBJ_DIR)/$$F.o$(COLOR_GREEN) generado exitosamente!! $(COLOR_RESET)" ; \
				N_FILES_COMPILED=$$(( N_FILES_COMPILED + 1 )) ; \
			fi ; \
		done; \
		echo "$(COLOR_BOLD)>>> Modulo: $(COLOR_BLUE)$(5)$(COLOR_RESET_BOLD) compilado exitosamente!! [$$N_FILES_COMPILED ficheros] $(COLOR_RESET)" ;\
	}
endef

define compile_lamport_skeleton
	@{ \
		N_FILES_EXPECTED=$(words $(2)) ; \
		echo "$(COLOR_BOLD)>>> Verificando dependencias de modulos para construir intérprete: $(COLOR_BLUE)$(3)$(COLOR_RESET_BOLD) [$$N_FILES_EXPECTED modulos requeridos] ... $(COLOR_RESET)" ;\
		N_FILES_CHECKED=0 ;\
		for FILE in $(2); do \
			echo "$(COLOR_YELLOW) ---> Comprobando existencia de [$$FILE] ...$(COLOR_RESET)" ; \
			if [ -f $(OBJ_DIR)/$$FILE ]; then \
				echo "$(COLOR_GREEN) ---> [$$FILE] existe, listo para su uso. $(COLOR_RESET)" ; \
				N_FILES_CHECKED=$$(( N_FILES_CHECKED + 1 )) ; \
			else \
				echo "$(COLOR_RED) ---> [$$FILE] NO existe. $(COLOR_RESET)" ; \
			fi ; \
		done; \
		echo ;\
		if [ $${N_FILES_CHECKED} -lt $${N_FILES_EXPECTED} ]; then \
			echo "$(COLOR_RED) ---> [ERROR] No se puede construir el intérprete de LAMPORT: Faltan dependencias de codigo objeto. $(COLOR_RESET)" ; \
			echo "$(COLOR_RED) ---> [ERROR] Se esperaban $(COLOR_RESET_BOLD)[$$N_FILES_EXPECTED] modulos $(COLOR_RED), se encontraron $(COLOR_RESET_BOLD)[$$N_FILES_CHECKED] modulos$(COLOR_RESET)." ; \
			exit 1; \
		fi; \
		echo ;\
		echo "$(COLOR_BOLD)>>> Construyendo intérprete: $(COLOR_BLUE)$(3)$(COLOR_RESET_BOLD) ... $(COLOR_RESET)" ;\
		$(1) $(INCLUDE_FLAGS) $(OBJ_DIR)/* $(SOURCE_DIR)/$(3)$(SOURCE_CPLUS_EXT) -o $(BIN_DIR)/$(3) $(LDFLEX); \
		if [ -f $(BIN_DIR)/$(3) ]; then \
			echo "$(COLOR_GREEN) ---> Intérprete $(COLOR_BLUE)$(3)$(COLOR_GREEN) construido exitosamente!! $(COLOR_RESET)" ; \
		else \
			echo "$(COLOR_RED) ---> [ERROR] El intérprete $(COLOR_BLUE)$(3)$(COLOR_RED) NO se ha podido construir!! $(COLOR_RESET)" ; \
			exit 1; \
		fi ; \
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

define parse_and_check_files_skeleton
	@{ \
		N_CHECKS_FAILED=0; \
		for DIR in $(2); do \
			echo "$(COLOR_BOLD)>>> Escaneando ficheros de $(COLOR_BLUE)$${DIR}/$(COLOR_RESET_BOLD) ... $(COLOR_RESET)" ; \
			if [ -z "$$(ls -A $$DIR)" ]; then \
				echo "$(COLOR_RED) ---> [!!] No hay fuentes en $(COLOR_PURPLE)$$DIR/$(COLOR_RESET)"; echo;\
			else \
				for FILE in $$DIR/*; do \
					if [ ! -d $$FILE ]; then \
						FILE_BASENAME=$$(basename $$FILE) ; \
						if ! echo $(3) | tr " " '\n' | grep -F -q -x "$$FILE_BASENAME"; then \
							echo "$(COLOR_YELLOW) ---> Comprobando la sintaxis de $(COLOR_PURPLE)$$FILE$(COLOR_YELLOW) ...$(COLOR_RESET)"; \
							$(1) $(INCLUDE_FLAGS) -fsyntax-only $$FILE; \
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

define compile_module_msg_skeleton
	@{ \
		N_FILES_EXPECTED=$(words $(1)) ; \
		echo "$(COLOR_BOLD)>>> Compilando archivos objeto de modulo: $(COLOR_BLUE)$(2)$(COLOR_RESET_BOLD) [$$N_FILES_EXPECTED ficheros detectados] ... $(COLOR_RESET)" ;\
	}
endef

define compile_unique_object_skeleton
	@{ \
		mkdir -p $(OBJ_DIR); \
		echo "$(COLOR_YELLOW) ---> Compilando: $(COLOR_PURPLE)$(2)$(COLOR_YELLOW) ...$(COLOR_RESET)" ; \
		$(1) $(INCLUDE_FLAGS) -c $(2) -o $(OBJ_DIR)/$(3) $(4) ; \
		if [ -f $(OBJ_DIR)/$(3) ]; then \
			echo "$(COLOR_GREEN) ---> Codigo objeto de: $(COLOR_PURPLE)$(OBJ_DIR)/$(3)$(COLOR_GREEN) generado exitosamente!! $(COLOR_RESET)" ; \
		fi ; \
	}
endef

define generate_object_rules
$(addprefix $(OBJ_DIR)/, $(3)): $(2)
	$(call compile_unique_object_skeleton,$(1),$(2),$(3),$(4))
endef

# ========================================================================================
# DEFINICION DE REGLAS PRINICPALES (ALL/CLEAN)
# ========================================================================================

make: make_compile_msg compile
	
make_compile_msg:
	@echo "$(COLOR_BLUE)CONSTRUYENDO INTÉRPRETE DE LAMPORT...$(COLOR_RESET)" && echo
	
parallel: compile_parallel

# -- Elimina todos los ficheros que se hayan generado usando el Makefile
clean:
	@make -s clean_tex && echo
	@make -s clean_logs && echo
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

clean_log_dir:
	$(call clean_dir_skeleton,$(LOG_DIR))
	
build_obj_dir:
	@mkdir -p $(OBJ_DIR)
	
clean_obj_dir:
	$(call clean_dir_skeleton,$(OBJ_DIR))
	
update_packages:
	@sudo $(UPDATE_OPTION)

# ========================================================================================
# DEFINICION DE REGLAS DE LIMPIEZA (CLEAN)
# ========================================================================================	


# -- Limpia los directorios de registro
clean_logs:
	@echo "$(COLOR_BLUE)Limpiando ficheros de logging...$(COLOR_RESET)"
	@rm -rf $(LOG_DIR)/* 2> /dev/null
	@echo "$(COLOR_GREEN)Archivos ficheros de logging eliminados exitosamente!$(COLOR_RESET)"
	@make -s clean_log_dir

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
	@echo " -- Version: 0.0.8"
	@echo "$(COLOR_RESET)"

# -- Muestra las diferentes opciones de Makefile
help:
	@echo "$(COLOR_BOLD)"
	@echo "-- TAREAS DE MAKEFILE --"
	@printf "%-30s %s\n" "make" "Constuye el intérprete de lamport"
	@printf "%-30s %s\n" "make parallel" "Constuye el intérprete de lamport en paralelo"
	@printf "%-30s %s\n" "make author" "Muestra informacion acerca del TFG (autoria)."
	@printf "%-30s %s\n" "make help" "Muestra este menu de opciones."
	@printf "%-30s %s\n" "make install_dependencies" "Instala todas las dependencias del proyecto (TeX, intérprete, tests)."
	@printf "%-30s %s\n" "make uninstall_dependencies" "Desinstala todas las dependencias del proyecto (TeX, intérprete, tests)."
	@printf "%-30s %s\n" "make version_dependencies" "Muestra la versión de las dependencias instaladas."
	@printf "%-30s %s\n" "make compile" "Compila todos los fuentes del proyecto."
	@printf "%-30s %s\n" "make check" "Analiza el codigo de los fuentes comprobando errores de sintaxis, warnings de estilo, etc."
	@printf "%-30s %s\n" "make tests" "Ejecuta tests automaticos de fugas de memoria en intérprete utilizando ficheros de prueba."
	@printf "%-30s %s\n" "make tests_parallel" "Ejecuta los mismos tests que la orden anterior pero en paralelo."
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

# -- Instala todas las dependencias relacionadas con el intérprete
install_compiler_dependencies:
	$(call install_dependencies_skeleton,"construccion de intérprete",$(COMPILER_DEPENDENCIES),CHECK_PACKAGES_V2)	

uninstall_compiler_dependencies:
	$(call uninstall_dependencies_skeleton,"construccion de intérprete",$(COMPILER_DEPENDENCIES),CHECK_PACKAGES_V2)	
    
version_compiler_dependencies:
	$(call version_dependencies_skeleton,"construccion de intérprete",$(COMPILER_DEPENDENCIES),CHECK_PACKAGES_V2)
    
# ----------------------------------------------------------------------------------------

# -- Instala todas las dependencias relacionadas con los tests del intérprete
install_tests_dependencies:
	$(call install_dependencies_skeleton,"tests sobre intérprete",$(TEST_DEPENDENCIES),CHECK_PACKAGES_V2)
	
# -- Desinstala todas las dependencias relacionadas con el intérprete
uninstall_tests_dependencies:
	$(call uninstall_dependencies_skeleton,"tests sobre intérprete",$(TEST_DEPENDENCIES),CHECK_PACKAGES_V2)

# -- Muestra la versión de todas las dependencias relacionadas con el intérprete
version_tests_dependencies:
	$(call version_dependencies_skeleton,"tests sobre intérprete",$(TEST_DEPENDENCIES),CHECK_PACKAGES_V2)
    
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
# DEFINICION DE REGLAS DE GENERACION DE FUENTES
# ========================================================================================

# -- Genera la fuente del analizador lexico a traves de flex
generate_lexer: $(SOURCE_LEXER)/$(LEXER_MODULE)$(FLEX_EXT)
	@echo "$(COLOR_BOLD)>>> Generando analizador lexico: $(COLOR_BLUE)$(SOURCE_LEXER)/$(LEXER_MODULE)$(FLEX_EXT)$(COLOR_RESET_BOLD) ...$(COLOR_RESET)"
	@flex -o $(SOURCE_LEXER)/$(LEXER_MODULE)$(SOURCE_C_EXT) $(SOURCE_LEXER)/$(LEXER_MODULE)$(FLEX_EXT)
	@echo "$(COLOR_BOLD)>>> Analizador lexico generado: $(COLOR_PURPLE)$(SOURCE_LEXER)/$(LEXER_MODULE)$(SOURCE_C_EXT)$(COLOR_RESET)"
	@echo
	
# -- Genera la fuente del analizador sintactico a traves de bison	
generate_parser: $(SOURCE_PARSER)/$(PARSER_MODULE)$(BISON_EXT)
	@echo "$(COLOR_BOLD)>>> Generando analizador sintactico: $(COLOR_BLUE)$(SOURCE_PARSER)/$(PARSER_MODULE)$(BISON_EXT)$(COLOR_RESET_BOLD) ...$(COLOR_RESET)"
	@bison --defines=$(HEADER_LEXER)/$(TOKEN_TYPE_NAME)$(HEADER_C_EXT) --output=$(SOURCE_PARSER)/$(PARSER_MODULE)$(SOURCE_C_EXT)  $(SOURCE_PARSER)/$(PARSER_MODULE)$(BISON_EXT) -Wcounterexamples
	@echo "$(COLOR_BOLD)>>> Analizador sintactico generado: $(COLOR_PURPLE)$(SOURCE_PARSER)/$(PARSER_MODULE)$(SOURCE_C_EXT)$(COLOR_RESET)"
	@echo "$(COLOR_BOLD)>>> Cabecera del Analizador sintactico generado: $(COLOR_PURPLE)$(HEADER_LEXER)/$(TOKEN_TYPE_NAME)$(HEADER_C_EXT)$(COLOR_RESET)"
	@echo
	
# ========================================================================================
# DEFINICION DE REGLAS DINAMICAS DE COMPILACION (OBJETOS)
# ========================================================================================

$(foreach src, $(INDEX_LEXER_FILES), \
	$(eval $(call generate_object_rules,gcc,$(SOURCE_LEXER)/$(src)$(SOURCE_C_EXT),$(addsuffix $(OBJ_EXT),$(src)),$(LDFLEX))))
	
$(foreach src, $(INDEX_PARSER_FILES), \
	$(eval $(call generate_object_rules,gcc,$(SOURCE_PARSER)/$(src)$(SOURCE_C_EXT),$(addsuffix $(OBJ_EXT),$(src)),$(LDFLEX))))
	
$(foreach src, $(INDEX_AST_FILES), \
	$(eval $(call generate_object_rules,gcc,$(SOURCE_AST)/$(src)$(SOURCE_C_EXT),$(addsuffix $(OBJ_EXT),$(src)))))
	
$(foreach src, $(INDEX_SEMANTIC_FILES), \
	$(eval $(call generate_object_rules,gcc,$(SOURCE_SEMANTIC)/$(src)$(SOURCE_C_EXT),$(addsuffix $(OBJ_EXT),$(src)))))
	
$(foreach src, $(INDEX_ERROR_FILES), \
	$(eval $(call generate_object_rules,gcc,$(SOURCE_ERROR)/$(src)$(SOURCE_C_EXT),$(addsuffix $(OBJ_EXT),$(src)))))
	
$(foreach src, $(INDEX_LMP_UTILS_FILES), \
	$(eval $(call generate_object_rules,g++ --std=c++17,$(SOURCE_LMP_UTILS)/$(src)$(SOURCE_CPLUS_EXT),$(addsuffix $(OBJ_EXT),$(src)))))
	
$(foreach src, $(INDEX_IR_FILES), \
	$(eval $(call generate_object_rules,g++ --std=c++17,$(SOURCE_IR)/$(src)$(SOURCE_CPLUS_EXT),$(addsuffix $(OBJ_EXT),$(src)))))
	
$(foreach src, $(INDEX_LVM_FILES), \
	$(eval $(call generate_object_rules,g++ --std=c++17,$(SOURCE_LVM)/$(src)$(SOURCE_CPLUS_EXT),$(addsuffix $(OBJ_EXT),$(src)))))

# ========================================================================================
# DEFINICION DE REGLAS DE COMPILACION (OBJETOS)
# ========================================================================================

compile: compile_sources compile_lamport
	@echo
	
compile_parallel:
	@echo "$(COLOR_BLUE)CONSTRUYENDO INTÉRPRETE DE LAMPORT [EN PARALELO]...$(COLOR_RESET)" && echo
	@echo compile_{lexer,parser,ast,semantic,error,lmp_utils,ir,lvm} | tr ' ' '\n' | parallel -j8 make -s
	@make -s compile_lamport

compile_lamport: build_bin_dir
	@echo
	$(call compile_lamport_skeleton,g++ -std=c++17,$(INDEX_OBJ_FILES),$(LMP_MAIN_NAME))
	
compile_sources: compile_lexer compile_parser compile_ast compile_error compile_semantic compile_ir compile_lvm compile_lmp_utils
	
# -- Genera codigo objeto para el analizador lexico
compile_lexer_msg:
	$(call compile_module_msg_skeleton,$(INDEX_LEXER_FILES),"analizador léxico")

compile_lexer: generate_lexer $(INDEX_SOURCE_LEXER_FILES) compile_lexer_msg $(addprefix $(OBJ_DIR)/, $(INDEX_OBJ_LEXER_FILES))
	@echo "$(COLOR_BOLD)>>> Compilación de módulo: $(COLOR_BLUE)analizador léxico$(COLOR_RESET_BOLD) terminada. $(COLOR_RESET)"
	@echo
	
# -- Genera codigo objeto para el analizador sintactico
compile_parser_msg:
	$(call compile_module_msg_skeleton,$(INDEX_PARSER_FILES),"analizador sintáctico")

compile_parser: generate_parser $(INDEX_SOURCE_PARSER_FILES) compile_parser_msg $(addprefix $(OBJ_DIR)/, $(INDEX_OBJ_PARSER_FILES))
	@echo "$(COLOR_BOLD)>>> Compilación de módulo: $(COLOR_BLUE)analizador sintáctico$(COLOR_RESET_BOLD) terminada. $(COLOR_RESET)"
	@echo
	
# -- Genera codigo objeto para el AST
compile_ast_msg:
	$(call compile_module_msg_skeleton,$(INDEX_AST_FILES),"Abstract Syntax Tree \(AST\)")

compile_ast: $(INDEX_SOURCE_AST_FILES) compile_ast_msg $(addprefix $(OBJ_DIR)/, $(INDEX_OBJ_AST_FILES))
	@echo "$(COLOR_BOLD)>>> Compilación de módulo: $(COLOR_BLUE)Abstract Syntax Tree (AST)$(COLOR_RESET_BOLD) terminada. $(COLOR_RESET)"
	@echo
	
# -- Genera codigo objeto para el analizador semantico
compile_semantic_msg:
	$(call compile_module_msg_skeleton,$(INDEX_SEMANTIC_FILES),"analizador semántico")

compile_semantic: $(INDEX_SOURCE_SEMANTIC_FILES) compile_semantic_msg $(addprefix $(OBJ_DIR)/, $(INDEX_OBJ_SEMANTIC_FILES))
	@echo "$(COLOR_BOLD)>>> Compilación de módulo: $(COLOR_BLUE)analizador semántico$(COLOR_RESET_BOLD) terminada. $(COLOR_RESET)"
	@echo
	
# -- Genera codigo objeto para el modulo de gestion de errores
compile_error_msg:
	$(call compile_module_msg_skeleton,$(INDEX_ERROR_FILES),"gestor de errores de análisis")

compile_error: $(INDEX_SOURCE_ERROR_FILES) compile_error_msg $(addprefix $(OBJ_DIR)/, $(INDEX_OBJ_ERROR_FILES))
	@echo "$(COLOR_BOLD)>>> Compilación de módulo: $(COLOR_BLUE)gestor de errores de análisis$(COLOR_RESET_BOLD) terminada. $(COLOR_RESET)"
	@echo
	
# -- Genera codigo objeto para las dependencias del intérprete Lamport
compile_lmp_utils_msg:
	$(call compile_module_msg_skeleton,$(INDEX_LMP_UTILS_FILES),"utilidades de intérprete lamport")

compile_lmp_utils: $(INDEX_SOURCE_LMP_UTILS_FILES) compile_lmp_utils_msg $(addprefix $(OBJ_DIR)/, $(INDEX_OBJ_LMP_UTILS_FILES))
	@echo "$(COLOR_BOLD)>>> Compilación de módulo: $(COLOR_BLUE)utilidades de intérprete lamport$(COLOR_RESET_BOLD) terminada. $(COLOR_RESET)"
	@echo
	
# -- Genera codigo objeto para el modulo de gestion de representacion intermedia de codigo
compile_ir_msg:
	$(call compile_module_msg_skeleton,$(INDEX_IR_FILES),"gestor de representación intermedia de código")

compile_ir: $(INDEX_SOURCE_IR_FILES) compile_ir_msg $(addprefix $(OBJ_DIR)/, $(INDEX_OBJ_IR_FILES))
	@echo "$(COLOR_BOLD)>>> Compilación de módulo: $(COLOR_BLUE)gestor de representación intermedia de código$(COLOR_RESET_BOLD) terminada. $(COLOR_RESET)"
	@echo

# -- Genera codigo objeto para el modulo de maquina virtual de lamport
compile_lvm_msg:
	$(call compile_module_msg_skeleton,$(INDEX_LVM_FILES),"Lamport Virtual Machine \(LVM\)")

compile_lvm: $(INDEX_SOURCE_LVM_FILES) compile_lvm_msg $(addprefix $(OBJ_DIR)/, $(INDEX_OBJ_LVM_FILES))
	@echo "$(COLOR_BOLD)>>> Compilación de módulo: $(COLOR_BLUE)Lamport Virtual Machine (LVM)$(COLOR_RESET_BOLD) terminada. $(COLOR_RESET)"
	@echo

# ========================================================================================
# DEFINICION DE REGLAS DE TESTEO DE FUENTES
# ========================================================================================

# -- Comprueba la sintaxis de los fuentes del proyecto
check:
	$(call parse_and_check_files_skeleton,"gcc",$(INDEX_DIRS),$(EXCLUDE_CHECK_FILES))
	
# -- Ejecuta tests automaticos de valgrind utilizando ficheros de prueba
tests:
	@echo "$(COLOR_BLUE)Realizando testeo de intérprete usando ficheros lamport correctos...$(COLOR_RESET)"
	@./$(TEST_DIR)/$(TEST_VALGRIND_SCRIPT) examples && echo
	@echo "$(COLOR_BLUE)Realizando testeo de intérprete usando ficheros lamport con errores sintacticos...$(COLOR_RESET)"
	@./$(TEST_DIR)/$(TEST_VALGRIND_SCRIPT) examples/errores/sintacticos && echo
	@echo "$(COLOR_BLUE)Realizando testeo de intérprete usando ficheros lamport con errores semanticos...$(COLOR_RESET)"
	@./$(TEST_DIR)/$(TEST_VALGRIND_SCRIPT) examples/errores/semanticos && echo

# -- Ejecuta tests automaticos de valgrind utilizando ficheros de prueba (ejecucion en paralelo)	
tests_parallel:
	@echo "$(COLOR_BLUE)Realizando testeo de intérprete usando ficheros lamport...$(COLOR_RESET)"
	@parallel ./$(TEST_DIR)/$(TEST_VALGRIND_SCRIPT) ::: examples examples/errores/sintacticos examples/errores/semanticos

# -- Ejecuta valgrind para realizar test de fugas de memoria utilizando un fichero
mem_check:
	@valgrind --leak-check=full $(BIN_DIR)/$(LMP_MAIN_NAME) $(LMP_FILE)
