# Trabajo de Fin de Grado

## *Lamport: Simulador de Sistemas Concurrentes y Distribuidos*



### :bust_in_silhouette: Autor: *Daniel Pérez Ruiz*

### :busts_in_silhouette: Tutor: *Carlos Ureña Almagro*



****



### :question: Resumen del proyecto

:construction:



### :book: Documentación del proyecto

La documentación de este proyecto está redactada en `LaTeX`, en el directorio `docs/`. Para poder recuperar el informe, es necesario instalar el paquete `texlive` en la distribución donde se clone este repositorio.

En el `Makefile` del proyecto se han definido unas reglas para su construcción (siempre y cuando se encuentre en un sistema basado en Debian, o cualquiera que utilice el gestor de paquetes APT) .



Si desea construir el informe TeX ejecute la siguiente orden:

~~~bash
$ make build_tex
~~~

Esta orden además se encargará de instalar todas las dependencias en el sistema en caso de que no se encuentren. El resultado se encontrará dentro del directorio `docs/`con el nombre de archivo `proyecto.pdf`.



Si desea eliminar el informe TeX y todos los demás ficheros generados en la compilación:

~~~bash
$ make clean_tex
~~~



### :shell: Instalación y verificación

En este proyecto hay diferentes bibliotecas y programas que son necesarias para poder construir el compilador adecuadamente. Para ello, se han definido reglas en el `Makefile` que permiten la gestión de dichas dependencias:

Si desea instalar todas las dependencias del proyecto:

~~~bash
$ make install_dependencies
~~~

Otra opción podría ser la instalación por separado de las dependencias:

~~~bash
# Instala dependencias sólo para informe TeX
$ make install_tex_dependencies

# Instala dependencias sólo del compilador
$ make install_compiler_dependencies
~~~



Si desea desinstalar todas las dependencias del proyecto:

~~~bash
$ make uninstall_dependencies
~~~

Otra opción podría ser la desinstalación por separado de las dependencias:

~~~bash
# Desinstala dependencias sólo para informe TeX
$ make uninstall_tex_dependencies

# Desinstala dependencias sólo del compilador
$ make uninstall_compiler_dependencies
~~~



Si desea comprobar las versiones instaladas de las dependencias:

~~~bash
$ make version_dependencies
~~~

Otra opción podría ser la comprobación de versiones por separado:

~~~bash
# Muestra las versiones instaladas de las dependencias de TeX
$ make version_tex_dependencies

# Muestras las versiones instaladas de las dependencias del compilador
$ make version_compiler_dependencies
~~~



