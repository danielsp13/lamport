## ESPECIFICACIÓN DE LENGUAJE DE REPRESENTACIÓN INTERMEDIA 

### AUTOR: Daniel Pérez Ruiz

### Fecha: Martes, 26 de Septiembre de 2023

En este documento se describe el lenguaje de representación intermedia utilizado para la fase final de simulación.

****

#### Contenido de este documento

En este documento se escribe la especificación de cada una de las instrucciones de representación intermedia:

|                         **INSTRUCCIÓN** | BREVE DESCRIPCIÓN                                            |
| --------------------------------------: | :----------------------------------------------------------- |
|           **[IR_OP_LOAD](#ir_op_load)** | Operación de carga de valor en registro.                     |
|         **[IR_OP_STORE](#ir_op_store)** | Operación de almacenamiento de valor <br />de registro en variable. |
|             **[IR_OP_ADD](#ir_op_add)** | Operación de suma aritmética.                                |
|             **[IR_OP_SUB](#ir_op_sub)** | Operación de resta aritmética.                               |
|           **[IR_OP_MULT](#ir_op_mult)** | Operación de multiplicación aritmética.                      |
|             **[IR_OP_DIV](#ir_op_div)** | Operación de división aritmética.                            |
|             **[IR_OP_MOD](#ir_op_mod)** | Operación de módulo aritmética.                              |
|             **[IR_OP_NEG](#ir_op_neg)** | Operación de negación aritmética.                            |
|             **[IR_OP_AND](#ir_op_and)** | Operación de conjunción lógica.                              |
|               **[IR_OP_OR](#ir_op_or)** | Operación de disyunción lógica.                              |
|             **[IR_OP_NOT](#ir_op_not)** | Operación de negación lógica.                                |
|       **[IR_OP_CMP_LT](#ir_op_cmp_lt)** | Operación de comparación (<)                                 |
|     **[IR_OP_CMP_LTE](#ir_op_cmp_lte)** | Operación de comparación (<=)                                |
|       **[IR_OP_CMP_GT](#ir_op_cmp_gt)** | Operación de de comparación (>)                              |
|     **[IR_OP_CMP_GTE](#ir_op_cmp_gte)** | Operación de comparación (>=)                                |
|       **[IR_OP_CMP_EQ](#ir_op_cmp_eq)** | Operación de comparación (==)                                |
|     **[IR_OP_CMP_NEQ](#ir_op_cmp_neq)** | Operación de comparación (!=)                                |
|             **[IR_OP_JMP](#ir_op_jmp)** | Operación de salto incondicional a etiqueta.                 |
|   **[IR_OP_JMP_TRUE](#ir_op_jmp_true)** | Operación de salto condicional (si verdadero) a etiqueta.    |
| **[IR_OP_JMP_FALSE](#ir_op_jmp_false)** | Operación de salto condicional (si falso) a etiqueta.        |
|           **[IR_OP_CALL](#ir_op_call)** | Operación de llamada a subprograma.                          |
|             **[IR_OP_RET](#ir_op_ret)** | Operación de retorno de un subprograma.                      |
|         **[IR_OP_PRINT](#ir_op_print)** | Operación de impresión a salida estándar.                    |
|                                         |                                                              |



****

#### <a name="ir_op_load"></a> Instrucción IR_OP_LOAD

**Funcionalidad:** Carga un valor de una variable en un registro.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_LOAD <registro_destino> <operando1>
~~~

* `<registro_destino>` : registro donde se almacenará el valor de la variable.
* `<operando1>` : Es una *variable*. Su valor se cargará en el registro de destino.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. El valor de `<operando1>` se carga en `<registro_destino>`.

**Ejemplo de uso:**

Suponiendo que `y` es una variable:

~~~bash
IR_OP_LOAD R1, y
~~~

**Comentarios adicionales:**

La representación a nivel de código de esta instrucción realmente contendrá en el operando un entero apuntador a una tabla de variables indexada donde se encuentra el nombre de dicha variable `y`.

****



#### <a name="ir_op_store"></a> Instrucción IR_OP_STORE

**Funcionalidad:** Almacena el valor de un registro en una variable.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_STORE <variable_destino> <operando1>
~~~

* `<variable_destino>` : variable en la que se almacenará el valor del registro.
* `<operando1>` : Es un *registro*. Su valor se almacenará en la variable de destino.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. El valor de `<operando1>` se almacena en `<variable_destino>`.

**Ejemplo de uso:**

Suponiendo que `x` es una variable:

~~~bash
IR_OP_STORE x, R0
~~~

**Comentarios adicionales:**

La representación a nivel de código de esta instrucción realmente contendrá en el operando un entero apuntador a una tabla de variables indexada donde se encuentra el nombre de dicha variable `x`.



****



#### <a name="ir_op_add"></a> Instrucción IR_OP_ADD

**Funcionalidad:** Realiza la adición aritmética de dos operandos y almacena el resultado en un registro de destino.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_ADD <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación aritmética.
* `<operando1>` : primer operando de la suma. Puede ser: *registro*, *literal*.
* `<operando2>` : segundo operando de la suma. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se suman `<operando1>` y `<operando2>` y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_ADD R0, R1, $2
~~~



****



#### <a name="ir_op_sub"></a> Instrucción IR_OP_SUB

**Funcionalidad:** Realiza la sustracción aritmética de dos operandos y almacena el resultado en un registro de destino.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_SUB <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación aritmética.
* `<operando1>` : primer operando de la resta. Puede ser: *registro*, *literal*.
* `<operando2>` : segundo operando de la resta. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se restan `<operando1>` y `<operando2>` y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_SUB R0, R1, $3.50
~~~



****



#### <a name="ir_op_mult"></a> Instrucción IR_OP_MULT

**Funcionalidad:** Realiza la multiplicación aritmética de dos operandos y almacena el resultado en un registro de destino.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_MULT <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación aritmética.
* `<operando1>` : primer operando de la multiplicación. Puede ser: *registro*, *literal*.
* `<operando2>` : segundo operando de la multiplicación. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se multiplican `<operando1>` y `<operando2>` y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_MULT R0, R1, R2
~~~



****



#### <a name="ir_op_div"></a> Instrucción IR_OP_DIV

**Funcionalidad:** Realiza la división aritmética de dos operandos y almacena el resultado en un registro de destino.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_DIV <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación aritmética.
* `<operando1>` : primer operando de la división. Puede ser: *registro*, *literal*.
* `<operando2>` : segundo operando de la división. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se dividen `<operando1>` y `<operando2>` y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_DIV R0, R1, R2
~~~



****



#### <a name="ir_op_mod"></a> Instrucción IR_OP_MOD

**Funcionalidad:** Realiza el módulo aritmético de dos operandos y almacena el resultado en un registro de destino.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_MOD <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación aritmética.
* `<operando1>` : primer operando del módulo. Puede ser: *registro*, *literal*.
* `<operando2>` : segundo operando del módulo. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se dividen `<operando1>` y `<operando2>` y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_MOD R0, 5, 2
~~~



****



#### <a name="ir_op_neg"></a> Instrucción IR_OP_NEG

**Funcionalidad:** Realiza la negación aritmética del operando y almacena el resultado en un registro.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_NEG <registro_destino> <operando1>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación aritmética.
* `<operando1>` : operando a negar. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se niega `<operando1>`  y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_NEG R0, R1
~~~



***



#### <a name="ir_op_and"></a> Instrucción IR_OP_AND

**Funcionalidad:** Realiza la conjunción lógica entre dos operandos y almacena el resultado en un registro.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_AND <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación lógica.
* `<operando1>` : operando 1 de la conjunción lógica. Puede ser: *registro*, *literal*.
* `<operando2>` : operando 2 de la conjunción lógica. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se realiza AND lógico entre `<operando1>` y `<operando2>` y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_AND R0, R1, $true
~~~



****



#### <a name="ir_op_or"></a> Instrucción IR_OP_OR

**Funcionalidad:** Realiza la disyunción lógica entre dos operandos y almacena el resultado en un registro.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_OR <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación lógica.
* `<operando1>` : operando 1 de la disyunción lógica. Puede ser: *registro*, *literal*.
* `<operando2>` : operando 2 de la disyunción lógica. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se realiza OR lógico entre `<operando1>` y `<operando2>` y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_OR R0, R1, R2
~~~



****



#### <a name="ir_op_not"></a> Instrucción IR_OP_NOT

**Funcionalidad:** Realiza la negación lógica de un operando y almacena el resultado en un registro.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_NOT <registro_destino> <operando1>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación lógica.
* `<operando1>` : operando de negación lógica. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se realiza NOT lógico de `<operando1>`  y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_NOT R0, R1
~~~



****



#### <a name="ir_op_cmp_lt"></a> Instrucción IR_OP_CMP_LT

**Funcionalidad:** Compara si un operando es menor que otro y almacena el resultado de la comparación en un registro. El resultado será o TRUE o FALSE.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_CMP_LT <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación de comparación.
* `<operando1>` : operando de comparación. Puede ser: *registro*, *literal*.
* `<operando2>` : operando de comparación. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se compara si `<operando1>` es menor que `<operando2>`  y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_CMP_LT R0, R1, $5
~~~



****



#### <a name="ir_op_cmp_lte"></a> Instrucción IR_OP_CMP_LTE

**Funcionalidad:** Compara si un operando es menor o igual que otro y almacena el resultado de la comparación en un registro. El resultado será o TRUE o FALSE.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_CMP_LTE <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación de comparación.
* `<operando1>` : operando de comparación. Puede ser: *registro*, *literal*.
* `<operando2>` : operando de comparación. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se compara si `<operando1>` es menor o igual que `<operando2>`  y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_CMP_LTE R0, R1, $5
~~~



***



#### <a name="ir_op_cmp_gt"></a> Instrucción IR_OP_CMP_GT

**Funcionalidad:** Compara si un operando es mayor que otro y almacena el resultado de la comparación en un registro. El resultado será o TRUE o FALSE.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_CMP_GT <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación de comparación.
* `<operando1>` : operando de comparación. Puede ser: *registro*, *literal*.
* `<operando2>` : operando de comparación. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se compara si `<operando1>` es mayor que `<operando2>`  y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_CMP_GT R0, R1, $5
~~~



****



#### <a name="ir_op_cmp_gte"></a> Instrucción IR_OP_CMP_GTE

**Funcionalidad:** Compara si un operando es mayor o igual que otro y almacena el resultado de la comparación en un registro. El resultado será o TRUE o FALSE.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_CMP_GTE <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación de comparación.
* `<operando1>` : operando de comparación. Puede ser: *registro*, *literal*.
* `<operando2>` : operando de comparación. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se compara si `<operando1>` es mayor o igual que `<operando2>`  y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_CMP_GTE R0, R1, $5
~~~



****



#### <a name="ir_op_cmp_eq"></a> Instrucción IR_OP_CMP_EQ

**Funcionalidad:** Compara si un operando es igual que otro y almacena el resultado de la comparación en un registro. El resultado será o TRUE o FALSE.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_CMP_EQ <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación de comparación.
* `<operando1>` : operando de comparación. Puede ser: *registro*, *literal*.
* `<operando2>` : operando de comparación. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se compara si `<operando1>` es igual que `<operando2>`  y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_CMP_EQ R0, R1, $5
~~~



****



#### <a name="ir_op_cmp_neq"></a> Instrucción IR_OP_CMP_NEQ

**Funcionalidad:** Compara si un operando es distinto que otro y almacena el resultado de la comparación en un registro. El resultado será o TRUE o FALSE.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_CMP_NEQ <registro_destino> <operando1> <operando2>
~~~

* `<registro_destino>`: registro donde se almacenará el resultado de la operación de comparación.
* `<operando1>` : operando de comparación. Puede ser: *registro*, *literal*.
* `<operando2>` : operando de comparación. Puede ser: *registro*, *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se compara si `<operando1>` es distinto que `<operando2>`  y el resultado se almacena en `<registro_destino>`.

**Ejemplo de uso:**

~~~
IR_OP_CMP_NEQ R0, R1, $5
~~~



****



#### <a name="ir_op_jmp"></a> Instrucción IR_OP_JMP

**Funcionalidad:** Realiza un salto incondicional a la etiqueta especificada.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_JMP <operando1>
~~~

* `<operando1>` : operando de salto. Es una *etiqueta* que indica la entrada de un bloque de instrucciones.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. La ejecución se desplaza inmediatamente a la instrucción marcada por `<operando1>`.

**Ejemplo de uso:**

~~~
IR_OP_JMP etq1
~~~



****



#### <a name="ir_op_jmp_true"></a> Instrucción IR_OP_JMP_TRUE

**Funcionalidad:** Realiza un salto condicional a la etiqueta especificada si el valor de un registro es verdadero.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_JMP_TRUE <operando1> <operando2>
~~~

* `<operando1>` : operando que contiene valor a evaluar (bool). Es un *registro*.
* `<operando2>` : operando de salto. Es una *etiqueta* que indica la entrada de un bloque de instrucciones.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. La ejecución se desplaza a la instrucción marcada por la etiqueta en `<operando2>` sólo si la evaluación del valor del registro en `<operando1>` es verdadero.

**Ejemplo de uso:**

~~~
IR_OP_JMP_TRUE R0, etq2
~~~



****



#### <a name="ir_op_jmp_false"></a> Instrucción IR_OP_JMP_FALSE

**Funcionalidad:** Realiza un salto condicional a la etiqueta especificada si el valor de un registro es falso.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_JMP_FALSE <operando1> <operando2>
~~~

* `<operando1>` : operando que contiene valor a evaluar (bool). Es un *registro*.
* `<operando2>` : operando de salto. Es una *etiqueta* que indica la entrada de un bloque de instrucciones.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. La ejecución se desplaza a la instrucción marcada por la etiqueta en `<operando2>` sólo si la evaluación del valor del registro en `<operando1>` es falso.

**Ejemplo de uso:**

~~~
IR_OP_JMP_FALSE R0, etq2
~~~



****



#### <a name="ir_op_call"></a> Instrucción IR_OP_CALL

**Funcionalidad:** Realiza una llamada a un subprograma.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_CALL <operando1>
~~~

* `<operando1>` : operando que indica el inicio de subprograma. Es una *etiqueta*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se guarda el contexto actual (dirección de retorno, registros,...).
2. La ejecución se desplaza al inicio del subprograma, indicado por el `<operando1>`

**Ejemplo de uso:**

~~~
IR_OP_CALL subprog_etq
~~~



****



#### <a name="ir_op_ret"></a> Instrucción IR_OP_RET

**Funcionalidad:** Realiza un retorno de un subprograma.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_RET
~~~

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se restaura el contexto guardado con anterioridad producido por una instrucción `IR_OP_CALL`.
2. Se desplaza la ejecución al punto justo después de la instrucción `IR_OP_CALL` realizada.

**Ejemplo de uso:**

~~~
IR_OP_RET
~~~



****



#### <a name="ir_op_print"></a> Instrucción IR_OP_PRINT

**Funcionalidad:** Imprime el valor de un registro o literal en la salida estándar.

**Argumentos:** La estructura de la instrucción es la siguiente:

~~~
IR_OP_PRINT <operando1>
~~~

* `<operando1>` : Operando de impresión con el valor que se desea imprimir. Es un *registro* o *literal*.

**Ejecución de la instrucción:**

Se realizan los siguientes pasos para la ejecución de la instrucción:

1. Se evalúa el valor de `<operando1>` .

**Ejemplo de uso:**

~~~
IR_OP_PRINT R0
IR_OP_PRINT $"hola"
~~~

