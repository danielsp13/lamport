# Trabajo de Fin de Grado

## *Lamport: Simulador de Sistemas Concurrentes y Distribuidos*

### :bust_in_silhouette: Autor: *Daniel Pérez Ruiz*

### :busts_in_silhouette: Tutor: *Carlos Ureña Almagro*

****

### :card_index_dividers: Contenidos del README

En el siguiente índice se resumen los contenidos principales de este README:

* :question: **[Resumen del proyecto](#lamport-resume)** : Describe los objetivos y el propósito de este proyecto.
* :book: **[Documentación del proyecto](#lamport-doc)** : Resume cómo obtener la documentación del proyecto en TeX.
* :shell: **[Instalación de dependencias y verificación](#lamport-install)** : Indica cómo se realiza la gestión de dependencias del proyecto mediante el `Makefile` implementado para ello.
* :building_construction: **[Construcción del intérprete](#lamport-compile)** : Indica cómo construir el proyecto completo para su uso.
*  :whale2: **[Uso del intérprete en contenedor Docker](#lamport-docker)** : Indica cómo ejecutar el intérprete utilizando el contenedor Docker que lo contiene.
* :white_check_mark: **[Testeo de módulos](#lamport-test)** : Indica cómo realizar pruebas sobre el código implementado.

****

### :question: <a name="lamport-resume"></a> Resumen del proyecto

***Lamport*** es un lenguaje de programación interpretado para la simulación de sistemas concurrentes y distribuidos. Utiliza una máquina virtual para la ejecución de las instrucciones, por lo que su uso no necesita de una arquitectura hardware específica.

Su nombre es en honor al informático Leslie Lamport, una de las mayores eminencias en el campo de la programación concurrente, y que dentro de las muchas contribuciones que realizó uno muy notorio es la introducción de un sistema lógico formal para la verificación de las propiedades de los sistemas concurrentes, denominado: **Lógica Temporal de Acciones.**

En este repositorio se encuentra el código fuente del intérprete desarrollado, así como el estudio teórico del trabajo de Lamport en la materia de verificación.

****

### :book: <a name="lamport-doc"></a> Documentación del proyecto

La documentación **completa** de este proyecto está redactada en `LaTeX`, en el directorio `tex/`. Para poder recuperar el informe, es necesario instalar el paquete `texlive` en la distribución donde se clone este repositorio.

En el `Makefile` del proyecto se han definido unas reglas para su construcción (siempre y cuando se encuentre en un sistema basado en Debian, o cualquiera que utilice el gestor de paquetes APT) .



Si desea construir el informe TeX ejecute la siguiente orden:

~~~bash
$ make build_tex
~~~

Esta orden además se encargará de instalar todas las dependencias en el sistema en caso de que no se encuentren. El resultado se encontrará dentro del directorio `tex/`con el nombre de archivo `proyecto.pdf`.



Si desea eliminar el informe TeX y todos los demás ficheros generados en la compilación:

~~~bash
$ make clean_tex
~~~



****

### :shell: <a name="lamport-install"></a> Instalación y verificación de dependencias

En este proyecto hay diferentes bibliotecas y programas que son necesarias para poder construir el intérprete adecuadamente. Para ello, se han definido reglas en el `Makefile` que permiten la gestión de dichas dependencias:

Si desea instalar todas las dependencias del proyecto:

~~~bash
$ make install_dependencies
~~~

Otra opción podría ser la instalación por separado de las dependencias:

~~~bash
# Instala dependencias sólo para informe TeX
$ make install_tex_dependencies

# Instala dependencias sólo del intérprete
$ make install_compiler_dependencies

# Instala dependencias sólo de tests sobre intérprete
$ make install_tests_dependencies
~~~



Si desea desinstalar todas las dependencias del proyecto:

~~~bash
$ make uninstall_dependencies
~~~

Otra opción podría ser la desinstalación por separado de las dependencias:

~~~bash
# Desinstala dependencias sólo para informe TeX
$ make uninstall_tex_dependencies

# Desinstala dependencias sólo del intérprete
$ make uninstall_compiler_dependencies

# Desinstala dependencias sólo de tests sobre intérprete
$ make uninstall_tests_dependencies
~~~



Si desea comprobar las versiones instaladas de las dependencias:

~~~bash
$ make version_dependencies
~~~

Otra opción podría ser la comprobación de versiones por separado:

~~~bash
# Muestra las versiones instaladas de las dependencias de TeX
$ make version_tex_dependencies

# Muestra las versiones instaladas de las dependencias del intérprete
$ make version_compiler_dependencies

# Muestra las versiones instaladas de las dependencias de tests sobre intérprete
$ make version_tests_dependencies
~~~



****

 ### :building_construction: <a name="lamport-compile"></a> Construcción del intérprete

Para poder utilizar el intérprete desarrollado para el lenguaje de lamport, hay que compilar todos los módulos implementados.



Para constuir el intérprete completo:

~~~bash
$ make compile
~~~

Esto hará que el ejecutable final se encuentre en el directorio `bin/`.



Puede además utilizar la orden de ejecución paralela, para reducir el tiempo:

~~~bash
$ make parallel
~~~

con el mismo efecto que la orden anterior.



Para eliminar todos los ficheros ejecutables generados:

~~~bash
$ make clean
~~~





****

 ### :whale2: <a name="lamport-docker"></a> Uso del intérprete en contenedor Docker

Este proyecto dispone  de un `Dockerfile` que construye un contenedor virtual con todas las dependencias necesarias para el funcionamiento del intérprete, aislándolo del SO por completo.



:warning: **Nota:** Es imprescindible tener Docker instalado en el sistema, puede instalarlo con la orden:

~~~bash
$ make install_virtualenv_dependencies
~~~



Para construir y ejecutar el intérprete dockerizado, utilice el script de la siguiente forma:

~~~bash
$ ./lmp_docker.sh <fichero_lamport.lmp>
~~~

Esto hará que se ejecute directamente el intérprete desde el contenedor de la misma manera que si se compilara de la forma tradicional.



Para eliminar el contenedor docker construido:

~~~bash
$ make rmi_docker
~~~



****

### :white_check_mark: <a name="lamport-test"></a> Testeo de módulos

En este proyecto se ha utilizado una herramienta de análisis ([cppcheck](https://cppcheck.sourceforge.io/)) para analizar las clases en búsqueda de errores / fallos que el intérprete no es capaz de detectar.



Si desea comprobar la sintaxis y lanzar un análisis (sin compilación) de todas las clases:

~~~bash
$ make check
~~~
