## ANÁLISIS DE PSEUDOCÓDIGO DE LA ASIGNATURA DE SCD 

En este documento se encuentra el análisis del pseudocódigo que se propone en las transparencias de la asignatura de *Sistemas Concurrentes y Distribuidos (SCD)*, de donde se han extraído ejemplos que han servido de base para la obtención de la expresión de la sintaxis del lenguaje.

Los ejemplos considerados se encuentran en: [ejemplos pseudocodigo SCD](ejemplos_pseudocodigo.md).

****

#### Contenido de este documento

De este análisis realizado se ha obtenido la siguiente información, imprescindible para el avance en el desarrollo del compilador:

* **[Sintaxis del Lenguaje](#sintaxis-bnf)** : Ha sido definida utilizando la [Notación de Backus-Naur (BNF)](https://www.cs.umsl.edu/~janikow/cs4280/bnf.pdf).
* **[Tabla de prioridad de operadores](#prioridad-operadores)** : Para evitar ambigüedades y definir correctamente el orden de evaluación de expresiones, siguiendo, por ejemplo, el enfoque utilizado en el [lenguaje C](https://en.cppreference.com/w/c/language/operator_precedence).
* **[Tabla de Tokens](#tabla-tokens)** : Esencial para el funcionamiento del analizador léxico, para definir y reconocer los diferentes tipos de tokens que pueden aparecer en el código fuente.

****

#### Sintaxis del lenguaje Lamport utilizando la notación BNF {#sintaxis-bnf}

~~~bash
<program> ::= "program" <identifier> [<declarations>] (<subprogram>)* <process>+
<declarations> ::= "var" (<variable> ":" <type> [:= <expression>] ";")+
<subprogram> ::= <procedure-definition>
	| <function-definition>
<type> ::= "integer"
	| "boolean"
	| "char"
	| "string"
	| "real"
 	| "array" "[" <size-array> "]" <type>
 	| "semaphore"
 	| "dprocess"
<size-array> ::= <expression>
<process> ::= "process" <identifier> [ "[" <identifier> : <integer-literal>
 	".." <integer-literal> "]" ] ";" [<declarations>] <block-statement>
<block-statement> ::= "begin" (<statement>)+ "end"
<procedure-definition> ::= "procedure" <identifier> "(" <parameters> ")"
[<declarations>] <block-statement>
<function-definition> ::= "function" <identifier> "(" <parameters> ")" ":" <type>
 	";" [<declarations>] <block-statement>
<parameters> ::= [<parameter> ["," <parameters>]]
<parameter> ::= <identifier> ":" <type>
<statement> ::= <assignment-statement>
 	| <while-statement>
	| <for-statement>
	| <if-statement>
	| <procedure-invocation>
	| <block-statement>
	| <cobegin-statement>
	| <fork-statement>
	| <atomic-statement>
	| <return-statement>
<fork-statement> ::= "fork" <identifier> <statement>
<atomic-statement> ::= "<<" (<statement>)+ ">>"
<assignment-statement> ::= <variable> ["[" <expression> "]"] ":=" <expression> ";"
<while-statement> ::= "while" <expression> "do" <block-statement>
<for-statement> ::= "for" <variable> ":=" <expression> "to" <expression> "do"
 	<block-statement>
<if-statement> ::= "if" <expression> "then" <block-statement>
	["else" <block-statement>]
<procedure-invocation> ::= <identifier> "(" <arguments> ")" ";"
<function-invocation> ::= <identifier> "(" <arguments> ")"
<return-statement> ::= "return" <expression> ";"
<arguments> ::= <expression> ["," <expression>]
<expression> ::= <term> <binary-operator> <expression>
	| <unary-operator> <term>
<term> ::= <variable>
	| <literal>
	| <function-invocation>
	| "(" <expression> ")"
<literal> ::= <integer-literal>
	| <boolean-literal>
	| <string-literal>
	| <char-literal>
	| <real-literal>
<integer-literal> ::= <digit>+
<boolean-literal> ::= "true" | "false"
<string-literal> ::= cualquier secuencia de caracteres del juego de caracteres
	en uso, con comillas dobles al inicio y al final
<char-literal> ::= cualquier caracter del juego de caracteres
 	en uso, con comilla simple al inicio y al final
<real-literal> ::= <integer-literal> "." <integer-literal>
<variable> ::= <identifier>
<identifier> ::= <letter> (<leter-or-digit>)*
<letter-or-digit> ::= <letter> | <digit>
<letter> ::= [a-zA-Z]
<digit> ::= [0-9]
<binary-operator> ::= "*" | "/" | "+" | "-"
 	| ">" | "<" | "<=" | ">=" | "==" | "!="
	| "and" | "or"
<unary-operator> ::= "-" | "not"
~~~



#### Tabla de prioridades de operadores {#prioridad-operadores}

| Precedencia |                 Operador                 |               Descripción                | Asociatividad |
| :---------: | :--------------------------------------: | :--------------------------------------: | :-----------: |
|      1      |                    -                     |           menos<br />(unario)            |  Izda-a-Dcha  |
|      2      |                 /<br />*                 | Multiplicación y división<br />(binario) |  Izda-a-Dcha  |
|      3      |                 +<br />-                 |       Suma y resta<br />(binario)        |  Izda-a-Dcha  |
|      4      | <<br /><=<br />><br />>=<br />==<br />!= | Operadores de comparación<br />(binario) |  Izda-a-Dcha  |
|      5      |                   not                    |      Negación lógica<br />(unario)       |  Dcha-a-Izda  |
|      6      |                   and                    |     Conjunción lógica<br />(binario)     |  Izda-a-Dcha  |
|      7      |                    or                    |     Disyunción lógica<br />(binario)     |  Izda-a-Dcha  |



#### Tabla de Tokens {#tabla-tokens}

|    TOKEN    |                     DESCRIPCIÓN INFORMAL                     |                   PATRÓN                   |       EJEMPLO       |
| :---------: | :----------------------------------------------------------: | :----------------------------------------: | :-----------------: |
|  S_PROGRAM  |         Palabra reservada para iniciar el programa.          |                 "program"                  |       program       |
|    S_VAR    |          Palabra reservada para declarar variables.          |                   "var"                    |         var         |
|  T_INTEGER  |            Palabra reservada para el tipo entero.            |                 "integer"                  |       integer       |
|  T_BOOLEAN  |           Palabra reservada para el tipo boolean.            |                 "boolean"                  |       boolean       |
|   T_CHAR    |           Palabra reservada para el tipo carácter.           |                   "char"                   |        char         |
|  T_STRING   |     Palabra reservada para el tipo cadena de caracteres.     |                  "string"                  |       string        |
|   T_REAL    |             Palabra reservada para el tipo real.             |                   "real"                   |        real         |
|   T_ARRAY   |          Palabra reservada para declarar un vector.          |                  "array"                   |        array        |
| T_SEMAPHORE |           Palabra reservada para el tipo semáforo.           |                "semaphore"                 |      semaphore      |
| T_DPROCESS  |     Palabra reservada para declarar un proceso dinámico      |                 "dprocess"                 |      dprocess       |
|  S_PROCESS  |    Palabra reservada para indicar el inicio de un proceso    |                 "process"                  |       process       |
| S_PROCEDURE | Palabra reservada para indicar el inicio de un procedimiento. |                "procedure"                 |      procedure      |
| S_FUNCTION  |   Palabra reservada para indicar el inicio de una función    |                 "function"                 |      function       |
|   RETURN    |   Palabra reservada para indicar el retorno de una función   |                  "return"                  |       return        |
|   B_BEGIN   |    Palabra reservada para indicar el inicio de un bloque.    |                  "begin"                   |        begin        |
|    B_END    |     Palabra reservada para indicar el fin de un bloque.      |                   "end"                    |         end         |
|  B_COBEGIN  | Palabra reservada para indicar el inicio de un bloque paralelo. |                 "cobegin"                  |       cobegin       |
|   B_COEND   | Palabra reservada para indicar el fin de un bloque paralelo. |                  "coend"                   |        coend        |
|   S_FORK    |       Palabra reservada para indicar inicio del fork.        |                   "fork"                   |        fork         |
|     IF      |       Palabra reservada para estructura de control if.       |                    "if"                    |         if          |
|    THEN     |         Palabra reservada para condición then de if.         |                   "then"                   |        then         |
|    ELSE     |         Palabra reservada para condición else de if.         |                   "else"                   |        else         |
|    WHILE    |     Palabra reservada para estructura de control while.      |                  "while"                   |        while        |
|     DO      |         Palabra reservada para el bucle do de while.         |                    "do"                    |         do          |
|     FOR     |      Palabra reservada para estructura de control for.       |                   "for"                    |         for         |
|     TO      |       Palabra reservada para indicar límite bucle for.       |                    "to"                    |         to          |
|    IDENT    |    Identificador de variables, funciones, procedimientos.    |       \[a-zA-Z\]([a-zA-Z] \| [0-9])*       | x, aux, sum, proc1B |
|   LITERAL   |        Secuencia de caracteres entre comillas dobles.        |                  ^".*?"$                   |    "Hola Mundo!"    |
|  L_INTEGER  |                       Literal entero.                        |                 ^-?[0-9]+$                 |      2, -31, 0      |
|   L_REAL    |                      Literal flotante.                       |           ^-?[0-9]+(\.[0-9]+)?$            |  2.71, -6, -4.1314  |
|  L_BOOLEAN  |                      Literal booleano.                       |             "true" \| "false"              |     true, false     |
|   L_CHAR    |               Carácter entre comillas simples.               |                   ^'.'$                    |    'A', '4', '?'    |
|  OP_ASSIGN  |                   Operador de asignación.                    |                    ":="                    |         :=          |
|   OP_REL    |                   Operador de comparación.                   | "<" \| ">" \| "<=" \| ">=" \| "==" \| "!=" |        <, ==        |
|   OP_NOT    |                  Operador negación lógica.                   |                   "not"                    |         not         |
|   OP_AND    |                 Operador conjunción lógica.                  |                   "and"                    |         and         |
|    OP_OR    |                 Operación disyunción lógica.                 |                    "or"                    |         or          |
|  PAR_IZDO   |                    Paréntesis izquierdo.                     |                    "("                     |          (          |
|  PAR_DCHO   |                     Paréntesis derecho.                      |                    ")"                     |          )          |
| CORCH_IZDO  |                     Corchete izquierdo.                      |                    "["                     |          [          |
| CORCH_DCHO  |                      Corchete derecho.                       |                    "]"                     |          ]          |
|   DELIM_C   |                     Delimitador (coma).                      |                    ","                     |          ,          |
|  DELIM_PC   |                 Delimitador (punto y coma).                  |                    ";"                     |          ;          |
|  DELIM_2P   |                  Delimitador (dos puntos).                   |                    ":"                     |          :          |
|  DELIM_ARR  |                Delimitador de size de array.                 |                    ".."                    |         ..          |
|  ATOM_INI   |             Delimitador inicio sección atómica.              |                    "<<"                    |         <<          |
|  ATOM_FIN   |               Delimitador fin sección atómica.               |                    ">>"                    |         >>          |

Para la designación de las clases de los tokens, se ha decidido utilizar un convenio en el prefijo donde:

* *S_* delimita aquellos símbolos que indican el inicio de un evento (programa, procedimiento, función...).
* *T_* delimita aquellos símbolos relacionados con el tipo de dato (integer, real, array,...).
* *B_* delimita aquellos símbolos relacionados con un bloque (inicio, fin).
* *L_* delimita aquellos símbolos relacionados con literales (literal entero, flotante, booleano, char,...).
* *OP_* delimita aquellos símbolos que son operadores (binarios, de comparación,...).
