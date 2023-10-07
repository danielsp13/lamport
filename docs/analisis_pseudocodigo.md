## ANÁLISIS DE PSEUDOCÓDIGO DE LA ASIGNATURA DE SCD 

En este documento se encuentra el análisis del pseudocódigo que se propone en las transparencias de la asignatura de *Sistemas Concurrentes y Distribuidos (SCD)*, de donde se han extraído ejemplos que han servido de base para la obtención de la expresión de la sintaxis del lenguaje.

Los ejemplos considerados se encuentran en: [ejemplos pseudocodigo SCD](ejemplos_pseudocodigo.md).

****

#### Contenido de este documento

De este análisis realizado se ha obtenido la siguiente información, imprescindible para el avance en el desarrollo del compilador:

* **[Sintaxis del Lenguaje](#sintaxis-bnf)** : Ha sido definida utilizando la [Notación de Backus-Naur (BNF)](https://www.cs.umsl.edu/~janikow/cs4280/bnf.pdf).
* **[Tabla de prioridad de operadores](#prioridad-operadores)** : Para evitar ambigüedades y definir correctamente el orden de evaluación de expresiones, siguiendo, por ejemplo, el enfoque utilizado en el [lenguaje C](https://en.cppreference.com/w/c/language/operator_precedence).
* **[Tabla de Tokens](#tabla-tokens)** : Esencial para el funcionamiento del analizador léxico, para definir y reconocer los diferentes tipos de tokens que pueden aparecer en el código fuente.
* **[Descripción semántica del Lenguaje](#semantic-lamport)** : Para dar coherencia a las instrucciones del lenguaje, es necesario definir ciertas reglas 

****

#### <a name="sintaxis-bnf"></a> Sintaxis del lenguaje Lamport utilizando la notación BNF

~~~bash
# Definicion de reglas de sintaxis de creacion de programas
<program> ::= "program" <identifier> [<declarations>] (<subprogram>)* <process>+
# Definion de reglas de sintaxis de creacion de declaraciones de variable
# Las declaraciones de variables se pueden encontrar:
#  --- Al principio de un programa: variables globales
#  --- Al principio de un subprograma: variables locales
#  --- Al principio de un proceso: variables locales
<declarations> ::= ("var" <identifier> ":" <type> [":=" <expression>] ";")+
# Definicion de reglas de sintaxis de creacion de tipos
# Los tipos pueden ser:
#  --- Atómicos (básicos) : INTEGER, REAL, CHAR, STRING, BOOLEAN
#  --- Compuestos : ARRAY [size].
#  --- Especiales : SEMAPHORE, DPROCESS
<type> ::= <basic-type-or-array>
	| <special-type>

<basic-type-or-array> ::= <basic-type>
	| "array" "[" <expression> "]" <basic-type>

<special-type> ::= "semaphore"
	| "dprocess"

<basic-type> ::= "integer"
	| "real"
	| "char"
	| "string"
	| "boolean"
# Definicion de reglas de sintaxis de creacion de subprogramas
# Los subprogramas pueden ser:
#  --- Funciones : retornan tipo de dato (o basicos, o ARRAY)
#  --- Procedimientos : no retornan datos (funciones void)
<subprogram> ::= <procedure-definition>
	| <function-definition>

<procedure-definition> ::= "procedure" <identifier> "(" <parameters> ")" ";"
	[<declarations>] <block-statements-begin-end>
	
<procedure-function> ::= "function" <identifier> "(" <parameters> ")" ":" <basic-type-or-array>
	";" [<declarations>] <block-statements-function>
# Definicion de reglas de sintaxis de creacion de parametros
# Los parametros son listas de identificadores seguidos de un tipo de dato
<parameters> ::= [<parameter> ["," <parameters>]]
<parameter> ::= <identifier> ":" <basic-type-or-array>
# Definicion de reglas de sintaxis de creacion de procesos
# Los procesos pueden ser:
#   --- Normales (Single).
#	--- Vectorizados. Definen una serie de procesos con base en un indexador
<process> ::= "process" <identifier> [ "[" <identifier> : <expression>
 	".." <expression> "]" ] ";" [<declarations>] <block-statements-process>
# Definicion de reglas de sintaxis de sentencias
# Las diferentes sentencias disponibles para el lenguaje son:
#   --- Bloque de sentencias BEGIN/END
#   --- Bloque de sentencias COBEGIN/COEND
#   --- Bloque de sentencias ATOMICAS
#   --- Asignacion
#   --- Bucle for
#   --- Bucle while
#   --- If/else
#   --- Fork
#   --- Join
#   --- Llamada a procedimiento
#   --- Impresion de contenido (print)
<block-statements-begin-end> ::= "begin" (<statement>)+ "end"
<block-statements-cobegin-coend> ::= "cobegin" (<statement>)+ "coend"
<block-statements-atomic> ::= "<<" (statement)+ ">>"
<block-statements-function> ::= "begin" (<statement>)+ <return-statement> "end"
<block-statements-process> ::= <block-statements-begin-end>
	| <block-statements-cobegin-coend>
	
<statement> ::= <assignment-statement>
	| <while-statement>
	| <for-statement>
	| <if-statement>
	| <procedure-call-statement>
	| <block-statements-atomic>
	| <fork-statement>
	| <join-statement>
	| <print-statement>
	
<assignment-statement> ::= <identifier> ["[" <expression> "]"] ":=" <expression> ";"
<while-statement> ::= "while" <expression> "do" <block-statements-begin-end>
<for-statement> ::= "for" <identifier> ":=" <expression> "to" <expression> "do"
 	<block-statements-begin-end>
<if-statement> ::= "if" <expression> "then" <block-statements-begin-end>
	["else" <block-statements-begin-end>]
<procedure-call-statement> ::= <identifier> "(" <arguments> ")" ";"
<fork-statement> ::= "fork" <identifier> ";"
<join-statement> ::= "join" <identifier> ";"

<print-statement> ::= "print" "(" <print-list> ")" ";"
<print-list> ::= <expression> ("," <expression>)*

<return-statement> ::= "return" <expression> ";"
# Definicion de reglas de sintaxis de expresiones
# Las diferentes expresiones disponibles para el lenguaje son:
#   --- binarias (<expression> simbolo <expresion>)
#   --- unarias  (simbolo <expression>)
# 	--- literales (INTEGER, REAL, CHAR, STRING, BOOLEAN)
#   --- identificador (variable de tipo básico/ARRAY)
# 	--- llamada a función
#   --- expresion entre parentesis
<expression> ::= <term> <binary-operator> <expression>
	| <unary-operator> <term>
	| <term>

<term> ::= <identifier> ["[" <expression> "]"]
	| <literal-expression>
	| <function-call-expression>
	| "(" <expression> ")"
	
<literal-expression> ::= <integer-literal>
	| <real-literal>
	| <string-literal>
	| <char-literal>
	| <boolean-literal>
	
<integer-literal> ::= <digit>+
<boolean-literal> ::= "true" | "false"
<string-literal> ::= cualquier secuencia de caracteres del juego de caracteres
	en uso, con comillas dobles al inicio y al final
<char-literal> ::= cualquier caracter del juego de caracteres
 	en uso, con comilla simple al inicio y al final
<real-literal> ::= <integer-literal> "." <integer-literal>
<identifier> ::= <letter> (<leter-or-digit>)*
<letter-or-digit> ::= <letter> | <digit>
<letter> ::= [a-zA-Z]
<digit> ::= [0-9]

<function-call-expression> ::= <identifier> "(" <arguments> ")"

<binary-operator> ::= "*" | "/" | "+" | "-" | "%" |
 	| ">" | "<" | "<=" | ">=" | "==" | "!="
	| "and" | "or"
<unary-operator> ::= "-" | "not"
# Definicion de reglas de sintaxis de generacion de argumentos
<arguments> ::= [<expression> ["," <arguments>]]
~~~



****

#### <a name="prioridad-operadores"></a> Tabla de prioridades de operadores

| Precedencia |                 Operador                 |                   Descripción                    | Asociatividad |
| :---------: | :--------------------------------------: | :----------------------------------------------: | :-----------: |
|      1      |                    -                     |               menos<br />(unario)                |  Izda-a-Dcha  |
|      2      |             /<br />*<br />%              | Multiplicación, división y módulo<br />(binario) |  Izda-a-Dcha  |
|      3      |                 +<br />-                 |           Suma y resta<br />(binario)            |  Izda-a-Dcha  |
|      4      | <<br /><=<br />><br />>=<br />==<br />!= |     Operadores de comparación<br />(binario)     |  Izda-a-Dcha  |
|      5      |                   not                    |          Negación lógica<br />(unario)           |  Dcha-a-Izda  |
|      6      |                   and                    |         Conjunción lógica<br />(binario)         |  Izda-a-Dcha  |
|      7      |                    or                    |         Disyunción lógica<br />(binario)         |  Izda-a-Dcha  |

****

#### <a name="tabla-tokens"></a> Tabla de Tokens

| NUM  |      TOKEN      |                     DESCRIPCIÓN INFORMAL                     |             PATRÓN             |       EJEMPLO       |
| :--: | :-------------: | :----------------------------------------------------------: | :----------------------------: | :-----------------: |
| 258  |    S_PROGRAM    |         Palabra reservada para iniciar el programa.          |           "program"            |       program       |
| 259  |      S_VAR      |          Palabra reservada para declarar variables.          |             "var"              |         var         |
| 260  |    T_INTEGER    |            Palabra reservada para el tipo entero.            |           "integer"            |       integer       |
| 261  |    T_BOOLEAN    |           Palabra reservada para el tipo boolean.            |           "boolean"            |       boolean       |
| 262  |     T_CHAR      |           Palabra reservada para el tipo carácter.           |             "char"             |        char         |
| 263  |    T_STRING     |     Palabra reservada para el tipo cadena de caracteres.     |            "string"            |       string        |
| 264  |     T_REAL      |             Palabra reservada para el tipo real.             |             "real"             |        real         |
| 265  |     T_ARRAY     |          Palabra reservada para declarar un vector.          |            "array"             |        array        |
| 266  |   T_SEMAPHORE   |           Palabra reservada para el tipo semáforo.           |          "semaphore"           |      semaphore      |
| 267  |   T_DPROCESS    |     Palabra reservada para declarar un proceso dinámico      |           "dprocess"           |      dprocess       |
| 268  |    S_PROCESS    |    Palabra reservada para indicar el inicio de un proceso    |           "process"            |       process       |
| 269  |   S_PROCEDURE   | Palabra reservada para indicar el inicio de un procedimiento. |          "procedure"           |      procedure      |
| 270  |   S_FUNCTION    |   Palabra reservada para indicar el inicio de una función    |           "function"           |      function       |
| 271  |     RETURN      |   Palabra reservada para indicar el retorno de una función   |            "return"            |       return        |
| 272  |     B_BEGIN     |    Palabra reservada para indicar el inicio de un bloque.    |            "begin"             |        begin        |
| 273  |      B_END      |     Palabra reservada para indicar el fin de un bloque.      |             "end"              |         end         |
| 274  |    B_COBEGIN    | Palabra reservada para indicar el inicio de un bloque paralelo. |           "cobegin"            |       cobegin       |
| 275  |     B_COEND     | Palabra reservada para indicar el fin de un bloque paralelo. |            "coend"             |        coend        |
| 276  |     S_FORK      |       Palabra reservada para indicar inicio del fork.        |             "fork"             |        fork         |
| 277  |      JOIN       |      Palabra reservada para sincronización de dprocess       |             "join"             |        join         |
| 278  |       IF        |       Palabra reservada para estructura de control if.       |              "if"              |         if          |
| 279  |      THEN       |         Palabra reservada para condición then de if.         |             "then"             |        then         |
| 280  |      ELSE       |         Palabra reservada para condición else de if.         |             "else"             |        else         |
| 281  |      WHILE      |     Palabra reservada para estructura de control while.      |            "while"             |        while        |
| 282  |       DO        |         Palabra reservada para el bucle do de while.         |              "do"              |         do          |
| 283  |       FOR       |      Palabra reservada para estructura de control for.       |             "for"              |         for         |
| 284  |       TO        |       Palabra reservada para indicar límite bucle for.       |              "to"              |         to          |
| 285  |      IDENT      |    Identificador de variables, funciones, procedimientos.    | \[a-zA-Z\]([a-zA-Z] \| [0-9])* | x, aux, sum, proc1B |
| 286  |     LITERAL     |        Secuencia de caracteres entre comillas dobles.        |            ^".*?"$             |    "Hola Mundo!"    |
| 287  |    L_INTEGER    |                       Literal entero.                        |           ^-?[0-9]+$           |      2, -31, 0      |
| 288  |     L_REAL      |                      Literal flotante.                       |     ^-?[0-9]+(\.[0-9]+)?$      |  2.71, -6, -4.1314  |
| 289  | L_BOOLEAN_TRUE  |              Literal booleano.<br />(verdadero)              |             "true"             |        true         |
| 290  | L_BOOLEAN_FALSE |                Literal booleano.<br />(falso)                |            "false"             |        false        |
| 291  |     L_CHAR      |               Carácter entre comillas simples.               |             ^'.'$              |    'A', '4', '?'    |
| 292  |    OP_ASSIGN    |                   Operador de asignación.                    |              ":="              |         :=          |
| 293  |    OP_REL_LT    |          Operador de comparación<br />(menor que).           |              "<"               |          <          |
| 294  |    OP_REL_GT    |          Operador de comparación<br />(mayor que).           |              ">"               |          >          |
| 295  |   OP_REL_LTE    |      Operador de comparación<br />(menor o igual que).       |              "<="              |         <=          |
| 296  |   OP_REL_GTE    |      Operador de comparación<br />(mayor o igual que).       |              ">="              |         >=          |
| 297  |    OP_REL_EQ    |          Operador de comparación<br />(igual que).           |              "=="              |         ==          |
| 298  |   OP_REL_NEQ    |         Operador de comparación<br />(distinto que)          |              "!="              |         !=          |
| 299  |     OP_NOT      |                  Operador negación lógica.                   |             "not"              |         not         |
| 300  |     OP_AND      |                 Operador conjunción lógica.                  |             "and"              |         and         |
| 301  |      OP_OR      |                 Operación disyunción lógica.                 |              "or"              |         or          |
| 302  |     OP_SUM      |                        Operador suma                         |              "+"               |          +          |
| 303  |    OP_MINUS     |                        Operador resta                        |              "-"               |          -          |
| 304  |     OP_MULT     |                   Operador multiplicación                    |              "*"               |          *          |
| 305  |     OP_DIV      |                      Operador división                       |              "/"               |          /          |
| 306  |     OP_MOD      |                       Operador módulo                        |              "%"               |          %          |
| 307  |    PAR_IZDO     |                    Paréntesis izquierdo.                     |              "("               |          (          |
| 308  |    PAR_DCHO     |                     Paréntesis derecho.                      |              ")"               |          )          |
| 309  |   CORCH_IZDO    |                     Corchete izquierdo.                      |              "["               |          [          |
| 310  |   CORCH_DCHO    |                      Corchete derecho.                       |              "]"               |          ]          |
| 311  |     DELIM_C     |                     Delimitador (coma).                      |              ","               |          ,          |
| 312  |    DELIM_PC     |                 Delimitador (punto y coma).                  |              ";"               |          ;          |
| 313  |    DELIM_2P     |                  Delimitador (dos puntos).                   |              ":"               |          :          |
| 314  |     DELIM_P     |                     Delimitador (punto).                     |              "."               |          .          |
| 315  |    DELIM_ARR    |                Delimitador de size de array.                 |              ".."              |         ..          |
| 316  |    ATOM_INI     |             Delimitador inicio sección atómica.              |              "<<"              |         <<          |
| 317  |    ATOM_FIN     |               Delimitador fin sección atómica.               |              ">>"              |         >>          |

Para la designación de las clases de los tokens, se ha decidido utilizar un convenio en el prefijo donde:

* *S_* delimita aquellos símbolos que indican el inicio de un evento (programa, procedimiento, función...).
* *T_* delimita aquellos símbolos relacionados con el tipo de dato (integer, real, array,...).
* *B_* delimita aquellos símbolos relacionados con un bloque (inicio, fin).
* *L_* delimita aquellos símbolos relacionados con literales (literal entero, flotante, booleano, char,...).
* *OP_* delimita aquellos símbolos que son operadores (binarios, de comparación,...).

****

#### <a name="semantic-lamport"></a> Descripción semántica del lenguaje

En lenguaje **Lamport** se puede describir como _inseguro_, _estático_ y _explícito_. Esto quiere decir que:

* ***Inseguro***: En un lenguaje de programación no seguro, se permiten escribir programas válidos que pueden tener un comportamiento indefinido que viola la estructura básica del programa. Esto por ejemplo se puede ver en los accesos a un ARRAY, donde si tiene tamaño 100 y se accede a una posición fuera de ese rango, compilará, pero puede que su comportamiento será indecible.
* ***Estático***: La comprobación de tipos se realiza en tiempo de compilación. Cuando llegue el momento de traducir el código a binario, no será necesario mantener información del tipo de dato de cada variable, subprograma o parámetro, porque todas las operaciones se habrán verificado y determinado como seguras.
* ***Explícito***: El programador es responsable de indicar los tipos de variables o de otros elementos de código explícitamente.

Con respecto a los tipos de dato del lenguaje Lamport:

* **Tipos básicos (atómicos):**
  * `integer` : entero con signo de 32 bits.
  * `real`  : número flotante con signo de 32 bits.
  * `char` : caracteres ASCII.
  * `string` : cadena de caracteres ASCII, terminados en "\0".
  * `boolean` : símbolos *true* y *false*.
* **Tipos compuestos:**
  * `array [size] basic-type` : array de tamaño *size* y de tipo atómico *basic-type*.

Finalmente, con respecto a las reglas de validación de operaciones:

* Sólo se puede asignar un único valor a un variable al mismo tiempo. Definir dos asignaciones diferentes, efectivamente, son dos operaciones distintas.
* Un parámetro de función sólo acepta un un valor al mismo tiempo.
* En un subprograma función, el tipo de dato que devuelve debe coincidir con el tipo de dato de su sentencia de retorno `return-statement`. Además, esta sentencia `return` debe ser **la última que aparezca en el cuerpo de una función.**
* Los operadores de comparación de igualdad `!=` y `==` pueden aceptar cualquier tipo de dato *básico*.
* Los operadores de comparación `<`, `>`, `<=`, `>=` sólo aceptan o números enteros `integer` o reales `real` en ambos miembros de la comparación, y además, deben coincidir en tipo.
* Los operadores aritméticos `+`, `-`, `*`, `/`, sólo aceptan números enteros `integer` o reales `real` en ambos miembros de la comparación, y además, deben coincidir en tipo. Es decir, no se pueden aplicar a `integer` y `real` simultáneamente.
* El operador aritmético `%` sólo acepta números enteros `integer`.
