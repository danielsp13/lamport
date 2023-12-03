# Trabajo de Fin de Grado

## *Lamport: Simulador de Sistemas Concurrentes y Distribuidos*

### Autor: *Daniel Pérez Ruiz*

### Tutor: *Carlos Ureña Almagro*

****

### :card_index_dividers: Contenidos del README

En el siguiente índice se resumen los contenidos principales de este README:

* :question: **[Resumen del proyecto](#lamport-resume)** : Describe los objetivos y el propósito de este proyecto.
* :book: **[Documentación del proyecto](#lamport-doc)** : Resume cómo obtener la documentación del proyecto en TeX.
* :star: **[Recomendaciones](#lamport-recommends)** : Algunas indicaciones y sugerencias para una mejor experiencia.
* :shell: **[Instalación de dependencias y verificación](#lamport-install)** : Indica cómo se realiza la gestión de dependencias del proyecto mediante el `Makefile` implementado para ello.
* :building_construction: **[Construcción del compilador](#lamport-compile)** : Indica cómo construir el proyecto completo para su uso.
*  :whale2: **[Uso del compilador en contenedor Docker](#lamport-docker)** : Indica cómo ejecutar el compilador utilizando el contenedor Docker que lo contiene.
* :white_check_mark: **[Testeo de módulos](#lamport-test)** : Indica cómo realizar pruebas sobre el código implementado.

****

### :question: <a name="lamport-resume"></a> Resumen del proyecto

***Lamport*** es un lenguaje de programación para la simulación de sistemas concurrentes y distribuidos. Utiliza una máquina virtual para la ejecución de las instrucciones, por lo que su uso no necesita de una arquitectura hardware específica.

Su nombre es en honor al informático Leslie Lamport, una de las mayores eminencias en el campo de la programación concurrente, y que dentro de las muchas contribuciones que realizó uno muy notorio es la introducción de un sistema lógico formal para la verificación de las propiedades de los sistemas concurrentes, denominado: **Lógica Temporal de Acciones.**

En este repositorio se encuentra el código fuente del compilador en tiempo de ejecución (*Just-In-Time*) desarrollado, así como el estudio teórico del trabajo de Lamport en la materia de verificación.

****

### :book: <a name="lamport-doc"></a> Documentación del proyecto

:star: *Novedad:* Ahora puede acceder directamente a la documentación final del proyecto en el PDF del directorio `tex/`. 

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

### :star: <a name="lamport-recommends"></a> Recomendaciones

Para poder tener una mejor experiencia en el uso del compilador Lamport, puede considerar alguna de estas dos alternativas:

1. Utilizar un entorno Linux para la instalación de dependencias y compilación del compilador.
2. Utilizar el contenedor virtual Docker mediante el script proporcionado. Este contenedor contiene todas las dependencias integradas, por lo que lo único que se necesita es tener docker instalado en el sistema, compatible con Windows, Linux y Mac.



****

### :shell: <a name="lamport-install"></a> Instalación y verificación de dependencias

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

# Instala dependencias sólo de tests sobre compilador
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

# Desinstala dependencias sólo del compilador
$ make uninstall_compiler_dependencies

# Desinstala dependencias sólo de tests sobre compilador
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

# Muestra las versiones instaladas de las dependencias del compilador
$ make version_compiler_dependencies

# Muestra las versiones instaladas de las dependencias de tests sobre compilador
$ make version_tests_dependencies
~~~



****

 ### :building_construction: <a name="lamport-compile"></a> Construcción del compilador

Para poder utilizar el compilador desarrollado para el lenguaje de lamport, hay que compilar todos los módulos implementados.



Para constuir el compilador completo:

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

 ### :whale2: <a name="lamport-docker"></a> Uso del compilador en contenedor Docker

Este proyecto dispone  de un `Dockerfile` que construye un contenedor virtual con todas las dependencias necesarias para el funcionamiento del compilador, aislándolo del SO por completo.



:warning: **Nota:** Es imprescindible tener Docker instalado en el sistema, puede instalarlo con la orden:

~~~bash
$ make install_virtualenv_dependencies
~~~



Para construir y ejecutar el compilador dockerizado, utilice el script de la siguiente forma:

~~~bash
$ ./lmp_docker.sh <fichero_lamport.lmp>
~~~

Esto hará que se ejecute directamente el compilador desde el contenedor de la misma manera que si se compilara de la forma tradicional.



Para eliminar el contenedor docker construido:

~~~bash
$ make rmi_docker
~~~



****

### :white_check_mark: <a name="lamport-test"></a> Testeo de módulos

En este proyecto se ha utilizado una herramienta de análisis ([cppcheck](https://cppcheck.sourceforge.io/)) para analizar las clases en búsqueda de errores / fallos que el compilador no es capaz de detectar.



Si desea comprobar la sintaxis y lanzar un análisis (sin compilación) de todas las clases:

~~~bash
$ make check
~~~
