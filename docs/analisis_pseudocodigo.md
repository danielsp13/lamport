## ANÁLISIS DE PSEUDOCÓDIGO DE LA ASIGNATURA DE SCD 

En este documento se encuentra el análisis del pseudocódigo que se propone en las transparencias de la asignatura de *Sistemas Concurrentes y Distribuidos (SCD)*, de donde se han extraído ejemplos que han servido de base para la obtención de la expresión de la sintaxis del lenguaje.

Los ejemplos considerados se encuentran en: [ejemplos pseudocodigo SCD](ejemplos_pseudocodigo.md).

****

#### Contenido de este documento

De este análisis realizado se ha obtenido la siguiente información, imprescindible para el avance en el desarrollo del compilador:

* **[Sintaxis del Lenguaje](#sintaxis-bnf)** : Ha sido definida utilizando la [Notación de Backus-Naur (BNF)](https://www.cs.umsl.edu/~janikow/cs4280/bnf.pdf).
* **[Tabla de prioridad de operadores](#prioridad-operadores)** : Para evitar ambigüedades y definir correctamente el orden de evaluación de expresiones, siguiendo, por ejemplo, el enfoque utilizado en el [lenguaje C](https://en.cppreference.com/w/c/language/operator_precedence).
* **[Tabla de Tokens](#tabla-tokens)** : Esencial para el funcionamiento del analizador léxico, para definir y reconocer los diferentes tipos de tokens que pueden aparecer en el código fuente.
* **[Descripción de las reglas de producción (Bison)](#sintaxis-bison)** : Para poder generar el analizador sintáctico, es necesario reajustar la sintaxis adaptando la notación BNF.

****

#### <a name="sintaxis-bnf"></a> Sintaxis del lenguaje Lamport utilizando la notación BNF

~~~bash
<program> ::= "program" <identifier> [<declarations>] (<subprogram>)* <process>+
<declarations> ::= ("var" <identifier> ":" <type> [:= <expression>] ";")+
<subprogram> ::= <procedure-definition>
	| <function-definition>
<type> ::= "integer"
	| "boolean"
	| "char"
	| "string"
	| "real"
 	| "array" "[" <expression> "]" <type>
 	| "semaphore"
 	| "dprocess"
<process> ::= "process" <identifier> [ "[" <identifier> : <expression>
 	".." <expression> "]" ] ";" [<declarations>] <block-statement>
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
	| <print-statement>
<cobegin-statement> ::= "cobegin" (<statement>)+ "coend"
<fork-statement> ::= "fork" <identifier> <statement>
<atomic-statement> ::= "<<" (<statement>)+ ">>"
<assignment-statement> ::= <identifier> ["[" <expression> "]"] ":=" <expression> ";"
<while-statement> ::= "while" <expression> "do" <block-statement>
<for-statement> ::= "for" <identifier> ":=" <expression> "to" <expression> "do"
 	<block-statement>
<if-statement> ::= "if" <expression> "then" <block-statement>
	["else" <block-statement>]
<procedure-invocation> ::= <identifier> "(" <arguments> ")" ";"
<function-invocation> ::= <identifier> "(" <arguments> ")"
<arguments> ::= [<expression> ["," <arguments>]]
<return-statement> ::= "return" <expression> ";"
<print-statement> ::= "print" "(" <print-list> ")" ";"
<print-list> ::= <expression> ("," <expression>)*
<expression> ::= <term> <binary-operator> <expression>
	| <unary-operator> <term>
	| <term>
<term> ::= <identifier> ["[" <expression> "]"]
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
<identifier> ::= <letter> (<leter-or-digit>)*
<letter-or-digit> ::= <letter> | <digit>
<letter> ::= [a-zA-Z]
<digit> ::= [0-9]
<binary-operator> ::= "*" | "/" | "+" | "-" | "%" |
 	| ">" | "<" | "<=" | ">=" | "==" | "!="
	| "and" | "or"
<unary-operator> ::= "-" | "not"
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

#### <a name="sintaxis-bison"></a> Descripción de las reglas de producción (Bison)

~~~C
// -- Regla de generacion de programa completo
program:
    S_PROGRAM identifier opt-declarations opt-subprograms program-process
    ;

// -- Reglas de generacion de declaraciones del programa
opt-declarations:
    declarations
    | /* epsilon */
    ;

declarations:
    S_VAR list-variable-declarations
    ;

list-variable-declarations:
    variable-declaration
    | list-variable-declarations variable-declaration
    ;

variable-declaration:
    identifier DELIM_2P type variable-assignation DELIM_PC
    ;

variable-assignation:
    OP_ASSIGN expression
    | /* epsilon */
    ;

// -- Reglas de generacion de subprogramas del programa
opt-subprograms:
    list-subprograms
    | /* epsilon */
    ;

list-subprograms:
    subprogram
    | list-subprograms subprogram
    ;

subprogram:
    procedure-definition
    | function-definition
    ;

// -- Reglas de generacion de procesos del programa
program-process:
    process
    | program-process process
    ;

process:
    S_PROCESS identifier array-of-process DELIM_PC opt-declarations block-statement
    ;

array-of-process:
    CORCH_IZDO identifier DELIM_2P L_INTEGER DELIM_ARR L_INTEGER CORCH_DCHO
    | /* epsilon */
    ;

// -- Reglas de generacion de tipos de dato
type:
    T_INTEGER
    | T_BOOLEAN
    | T_CHAR
    | T_STRING
    | T_REAL
    | T_ARRAY CORCH_IZDO expression CORCH_DCHO type
    | T_SEMAPHORE
    | T_DPROCESS
    ;

// -- Reglas de generacion de definicion de funciones y procedimientos
procedure-definition:
    S_PROCEDURE identifier PAR_IZDO opt-parameters PAR_DCHO opt-declarations block-statement
    ;

function-definition:
    S_FUNCTION identifier PAR_IZDO opt-parameters PAR_DCHO DELIM_2P type DELIM_PC opt-declarations block-statement
    ;

opt-parameters:
    list-parameters
    | /* epsilon */
    ;

list-parameters:
    parameter
    | list-parameters DELIM_C parameter
    ;

parameter:
    identifier DELIM_2P type
    ;

// -- Reglas de generacion de sentencias
list-statements:
    statement
    | list-statements statement
    ;

statement:
    block-statement
    | cobegin-statement
    | assignment-statement
    | while-statement
    | for-statement
    | if-statement
    | procedure-invocation
    | fork-statement
    | atomic-statement
    | return-statement
    ;

block-statement:
    B_BEGIN list-statements B_END
    ;

cobegin-statement:
    B_COBEGIN list-statements B_COEND
    ;

assignment-statement:
    identifier array-assignment-statement OP_ASSIGN expression DELIM_PC
    ;

array-assignment-statement:
    CORCH_IZDO expression CORCH_DCHO
    | /* epsilon */
    ;

while-statement:
    WHILE expression DO block-statement
    ;

for-statement:
    FOR identifier OP_ASSIGN expression TO expression DO block-statement
    ;

if-statement:
    IF expression THEN block-statement
    | IF expression THEN block-statement ELSE block-statement
    ;

fork-statement:
    S_FORK identifier statement
    ;

atomic-statement:
    ATOM_INI list-statements ATOM_FIN
    ;

return-statement:
    RETURN expression DELIM_PC
    ;

// -- Reglas de generacion de invocaciones de funciones y procedimientos
procedure-invocation:
    identifier PAR_IZDO opt-parameters PAR_DCHO DELIM_PC
    ;

function-invocation:
    identifier PAR_IZDO opt-parameters PAR_DCHO
    ;

// -- Reglas de generacion de expresiones
expression:
    term binary-operator expression
    | unary-operator term
    | term
    ;

term:
    identifier
    | literal
    | function-invocation
    | PAR_IZDO expression PAR_DCHO
    ;
    
// -- Reglas de generacion de literales
literal:
    LITERAL
    | L_INTEGER
    | L_BOOLEAN_TRUE
    | L_BOOLEAN_FALSE
    | L_CHAR
    | L_REAL
    ;

identifier:
    IDENT
    ;

// -- Reglas de generacion de operadores binarios y unarios
binary-operator:
    OP_MULT
    | OP_DIV
    | OP_SUM
    | OP_MINUS
    | OP_MOD
    | OP_REL_GT
    | OP_REL_LT
    | OP_REL_GTE
    | OP_REL_LTE
    | OP_REL_EQ
    | OP_REL_NEQ
    | OP_AND
    | OP_OR
    ;

unary-operator:
    OP_MINUS
    | OP_NOT
    ;
~~~

