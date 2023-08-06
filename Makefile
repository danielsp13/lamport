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
.PHONY: backup

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

# ========================================================================================
# DEFINICION DE REGLA PRINICPAL (ALL)
# ========================================================================================

# ========================================================================================
# DEFINICION DE REGLAS DE GESTION INTERNA
# ========================================================================================


backup:
	@echo "Generando copia de seguridad..."
	@rm -f $(DIR_BACKUP)/$(BACKUP_FILE)
	@zip -r $(DIR_BACKUP)/$(BACKUP_FILE) ./*
	@echo "Copia de seguridad creada en $(DIR_BACKUP)/$(BACKUP_FILE)"

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
	@echo "Instalando dependencias TeX del proyecto..."
	@$(foreach DEP,$(TEX_DEPENDENCIES), \
        if ! dpkg -l $(DEP) 2>/dev/null | grep -qw 'ii' ; then \
            echo " ---> $(DEP) no está instalado. Instalando..."; \
            sudo $(PACKAGE_MANAGER) update && sudo $(PACKAGE_MANAGER) install -y $(DEP); \
        else \
            echo " ---> $(DEP) ya se encuentra instalado en el sistema."; \
        fi; \
    )
	
# -- Desinstala todas las dependencias relacionadas con el informe TFG
uninstall_tex_dependencies:
	@echo "Desinstalando dependencias TeX del proyecto..."
	@$(foreach DEP,$(TEX_DEPENDENCIES), \
        if dpkg -s $(DEP) >/dev/null 2>&1; then \
        	echo " ---> Desinstalando $(DEP)..."; \
            sudo $(PACKAGE_MANAGER) remove -y $(DEP) && sudo $(PACKAGE_MANAGER) autoremove -y; \
        else \
            echo " ---> $(DEP) NO! se encuentra instalado en el sistema."; \
        fi; \
    )

# -- Muestra la version de todas las dependencias relacionadas con el informe TFG
version_tex_dependencies:
	@echo "Versión instalada de las dependencias TeX del proyecto:"
	@$(foreach DEP,$(TEX_DEPENDENCIES), \
        if dpkg -l $(DEP) 2>/dev/null | grep -qw 'ii'; then \
            dpkg -s $(DEP) | grep '^Version:' | awk '{print " ---> Versión de $(DEP): ", $$2}'; \
        else \
            echo " ---> $(DEP) NO! se encuentra instalado en el sistema."; \
        fi; \
    )

# ----------------------------------------------------------------------------------------

# -- Instala todas las dependencias relacionadas con el compilador
install_compiler_dependencies:
	@echo "Instalando dependencias para la construcción del compilador..."
	@$(foreach DEP,$(COMPILER_DEPENDENCIES), \
        if ! dpkg -s $(DEP) >/dev/null 2>&1; then \
            echo " ---> $(DEP) no está instalado. Instalando..."; \
            sudo $(PACKAGE_MANAGER) update && sudo $(PACKAGE_MANAGER) install -y $(DEP); \
        else \
            echo " ---> $(DEP) ya se encuentra instalado en el sistema."; \
        fi; \
    )
	
# -- Desinstala todas las dependencias relacionadas con el compilador
uninstall_compiler_dependencies:
	@echo "Desinstalando dependencias para la construcción del compilador..."
	@$(foreach DEP,$(COMPILER_DEPENDENCIES), \
        if dpkg -s $(DEP) >/dev/null 2>&1; then \
        	echo " ---> Desinstalando $(DEP)..."; \
            sudo $(PACKAGE_MANAGER) remove -y $(DEP) && sudo $(PACKAGE_MANAGER) autoremove -y; \
        else \
            echo " ---> $(DEP) NO! se encuentra instalado en el sistema."; \
        fi; \
    )
	
# -- Muestra la versión de todas las dependencias relacionadas con el compilador
version_compiler_dependencies:
	@echo "Versión instalada de las dependencias para la construcción del compilador:"
	@$(foreach DEP,$(COMPILER_DEPENDENCIES), \
        if dpkg -s $(DEP) >/dev/null 2>&1; then \
            dpkg -s $(DEP) | grep '^Version:' | awk '{print " ---> Versión de $(DEP): ", $$2}'; \
        else \
            echo " ---> $(DEP) NO! se encuentra instalado en el sistema."; \
        fi; \
    )
    
# ----------------------------------------------------------------------------------------

# -- Instala todas las dependencias relacionadas con los tests del compilador
install_tests_dependencies:
	@echo "Instalando dependencias para realizacion de tests sobre compilador..."
	@$(foreach DEP,$(TEST_DEPENDENCIES), \
        if ! dpkg -s $(DEP) >/dev/null 2>&1; then \
            echo " ---> $(DEP) no está instalado. Instalando..."; \
            sudo $(PACKAGE_MANAGER) update && sudo $(PACKAGE_MANAGER) install -y $(DEP); \
        else \
            echo " ---> $(DEP) ya se encuentra instalado en el sistema."; \
        fi; \
    )
	
# -- Desinstala todas las dependencias relacionadas con el compilador
uninstall_tests_dependencies:
	@echo "Desinstalando dependencias para realizacion de tests sobre compilador..."
	@$(foreach DEP,$(TEST_DEPENDENCIES), \
        if dpkg -s $(DEP) >/dev/null 2>&1; then \
        	echo " ---> Desinstalando $(DEP)..."; \
            sudo $(PACKAGE_MANAGER) remove -y $(DEP) && sudo $(PACKAGE_MANAGER) autoremove -y; \
        else \
            echo " ---> $(DEP) NO! se encuentra instalado en el sistema."; \
        fi; \
    )
	
# -- Muestra la versión de todas las dependencias relacionadas con el compilador
version_tests_dependencies:
	@echo "Versión instalada de las dependencias para realizacion de tests sobre compilador:"
	@$(foreach DEP,$(TEST_DEPENDENCIES), \
        if dpkg -s $(DEP) >/dev/null 2>&1; then \
            dpkg -s $(DEP) | grep '^Version:' | awk '{print " ---> Versión de $(DEP): ", $$2}'; \
        else \
            echo " ---> $(DEP) NO! se encuentra instalado en el sistema."; \
        fi; \
    )
    
# ========================================================================================
# DEFINICION DE REGLAS DE GESTION DE INFORME TEX
# ========================================================================================

# -- Compila el informe tex
build_tex: install_tex_dependencies
	@make -C $(TEX_DIR)

# -- Elimina todos los ficheros generados por el makefile de tex
clean_tex:
	@echo "Limpiando archivos de informe TeX..."
	@find $(TEX_DIR) -type f -regex $(TEX_GEN_FILES) -delete
	@echo "Archivos del informe TeX eliminados correctamente!"

