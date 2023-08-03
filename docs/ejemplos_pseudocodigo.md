### EJEMPLOS DE PSEUDOCÓDIGO DE LA ASIGNATURA DE SCD

En este documento se recopilan algunos ejemplos de resolución en código de problemas propuestos en la asignatura de *Sistemas Concurrentes y Distribuidos (SCD)*. El objetivo fundamental es extraer información de dichos ejemplos para posteriormente conseguir la definición de la sintaxis y semántica del lenguaje, tabla de tokens, entre otras cosas.

****

#### Contenido de este documento

Se enumeran a continuación los diferentes ejemplos que se han considerado para el posterior análisis realizado:

* **[Ejemplo 1](#scd-ejemplo1)** : TEMA 1 - Página 34 (Paradigma del Productor-Consumidor).
* **[Ejemplo 2](#scd-ejemplo2)** : TEMA 1 - Página 39 (Prueba simple de programa concurrente).
* **[Ejemplo 3](#scd-ejemplo3)** : TEMA 1 - Página 32 (Instrucciones compuestas atómicas).
* **[Ejemplo 4](#scd-ejemplo4)** : TEMA 1 - Página 26 (Creación de procesos no estructurada: fork-join)
* **[Ejemplo 5](#scd-ejemplo5)** : TEMA 1 - Ejercicio 1 de la relación.
* **[Ejemplo 6](#scd-ejemplo6)** : TEMA 1 - Ejercicio 6 de la relación.

****

#### <a name="scd-ejemplo1"></a> Ejemplo de pseudocódigo 1 

**Descripción:** Se muestran dos procesos cooperantes en los cuales uno (con rol de productor) genera una secuencia de valores (por ejemplo, valores enteros), y el otro (con rol de consumidor) utiliza cada uno de esos valores.

**Código:** Aquí se muestra el programa.

~~~pascal
var x : integer; {contiene cada valor producido}
{Proceso productor: calcula 'x'}
process Productor;
var a : integer; {no compartida}
begin
  while true do begin
    {calcular un valor}
    a := ProducirValor();
    {escribir en mem. compartida}
    x := a; {sentencia E}
  end
end
{Proceso consumidor: lee 'x'}
process Consumidor;
var b : integer;
begin
  while true do begin
    {leer de mem. compartida}
    b := x; {sentencia L}
    {utilizar el valor leido}
    UsarValor(b);
  end
end
~~~

**Comentarios:** Podemos observar las siguientes cuestiones acerca del lenguaje:

1. Permite escribir comentarios, que son como los que se realizan en el lenguaje `Pascal`, donde se delimitan por corchetes `{}`.
2. Permite definir procesos con la palabra `process` y un nombre identificativo.
3. Permite definir variables globales al comienzo de la sección de un programa, como es el caso de la primera linea: `var x : integer;`.
4. Cada bloque de código se delimita por dos palabras: `begin` y `end`.
5. Se permiten definir variables locales al proceso, como por ejemplo la variable `a` del proceso `Productor`: `var a : integer;`
6. Se permiten bucles `while`, estableciendo una condición de verdad.
7. Se permiten invocar funciones con, o sin parámetros: `ProducirValor();`, `UsarValor(b);`

****

#### <a name="scd-ejemplo2"></a> Ejemplo de pseudocódigo 2 

**Descripción:** Representa un proceso concurrente llamado "P" que realiza dos operaciones secuenciales en la variable entera "x"

**Código:** Aquí se muestra el programa.

~~~pascal
process P;
var x : integer := 0;
cobegin
  x = x+1 ; x = x+2;
coend
~~~

**Comentarios:** Podemos observar las siguientes cuestiones acerca del lenguaje:

1. Permite definir un proceso concurrente delimitando el bloque de código con las palabras `cobegin`, `coend`.

****

#### <a name="scd-ejemplo3"></a> Ejemplo de pseudocódigo 3 

**Descripción:** Representa una sección de código con instrucciones atómicas que realizan operaciones concurrentes en la variable "x".

**Código:** Aquí se muestra el programa.

~~~pascal
{instr. atómicas}
begin
  x := 0;
  cobegin
    < x := x+1 >
    < x := x-1 >
  coend
end
~~~

**Comentarios:** Podemos observar las siguientes cuestiones acerca del lenguaje:

1. Permite definir instrucciones atómicas utilizando los delimitadores `<>`.

****

#### <a name="scd-ejemplo4"></a> Ejemplo de pseudocódigo 4 

**Descripción:** Consiste en dos procedimientos (P1 y P2) que se ejecutan de forma concurrente y utilizan construcciones propias de la concurrencia (fork y join).

**Código:** Aquí se muestra el programa.

~~~pascal
procedure P1;
begin
  A;
  fork P2;
  B;
  join P2;
  C;
end

procedure P2;
begin
  D;
end;
~~~

**Comentarios:** Podemos observar las siguientes cuestiones acerca del lenguaje:

1. Permite definir procedimientos utilizando la palabra `procedure` seguido de una identificación.
2. Permite realizar ejecuciones concurrentes entre procedimientos utilizando la palabras `fork`.
3. Permite realizar sincronizaciones entre procesos concurrentes (que han sido paralelizados utilizando `fork`), utilizando la palabra `join`.

****

#### <a name="scd-ejemplo5"></a> Ejemplo de pseudocódigo 5 

**Descripción:** Representa una simulación concurrente de dos procesos, "P1" y "P2", que operan en una variable compartida "x". 

**Código:** Aquí se muestra el programa.

~~~pascal
{ variables compartidas}
var x : integer := 0;

process P1;
  var i : integer;
begin
  for i := 1 to 2 do begin
    x := x+1;
  end
end

process P2;
  var j : integer;
begin
  for j := 1 to 2 do begin
    x := x+1;
  end
end
~~~

**Comentarios:** Podemos observar las siguientes cuestiones acerca del lenguaje:

1. Permite definir bucles `for`, considerando un inicio, y un final.

****

#### <a name="scd-ejemplo6"></a> Ejemplo de pseudocódigo 6 

**Descripción:** Proporciona dos procedimientos para ordenar elementos en un rango especificado utilizando el método de burbuja y copiar (sobre un subconjunto de elementos) entre dos arrays de números enteros.

**Código:** Aquí se muestra el programa.

~~~pascal
var a,b : array[1..2*n] of integer; {n es una constante predefinida}

procedure Sort( s,t : integer );
  var i,j : integer;
begin
  for i := s to t do
    for j := s+1 to t do
      if a[i] < a[j] then
        swap(a[i], b[j]);
end

procedure Copiar( o,s,t : integer );
  var d : integer;
begin
  for d := 0 to t-s do
    b[o+d] := a[s+d];
end
~~~

**Comentarios:** Podemos observar las siguientes cuestiones acerca del lenguaje:

1. Permite definir arrays de datos de un tamaño elegido por el programador (es decir, permite definir tamaños de arrays mediante expresiones).
2. Permite definir procedimientos con parámetros (a continuación de la identificación de dicho procedimiento).
3. Permite definir estructuras `if / else`, realizando comparaciones entre elementos.
4. Permite acceder a elementos dentro de un array con el operador `[ ]`, incluyendo expresiones.

