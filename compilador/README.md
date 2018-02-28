# Compilador
 
El archivo `calculator.c` es un programa sencillo, que suma
dos números y los imprime en pantalla; así y todo compilarlo 
requiere un montón de pasos intermedios. Estos pasos los podemos 
clasificar en 4:

1. Pre-procesador: `make preprocessing`
2. Compilacion I: `make assembler`
3. Compilacion II: `make object`
4. Linkeo: `make executable`

Ejecutando cada una de las instrucciones de `make` van a poder
construir cada uno de los pasos intermedios.

Ejercicios:

En un archivo de texto `respuestas.md`:

1. Escriban qué esperan de cada uno de los pasos
2. ¿Qué agregó el preprocesador?
3. Identificar en la rutina de assembler las funciones
4. Explicar qué quieren decir los símbolos que se crean en el objeto
5. ¿En qué se diferencian los símbolos del objeto y del ejecutable?

(siéntanse libres, si quieren, de usar la sintaxis markdown. no hace falta)

1)
a) make preprocessing: me genera un archivo .pp_c que contiene todos los includes y macros que necesita el main.c (en este
caso el calculator.c)
b) make assembler: me genera un archivo calculator.asm que contiene el programa calculator.c traducido a lenguaje assembler
c) make object: me genera un binario (calculator.o) que la computadora puede entender, es cercano a assembler
d) make executable: se encarga de linkear los objetos generados en el paso anterior y las librerias que necesiten. Las librerias vienen a llenar los espacios vacíos que quedaron en el código hasta ahora, y se pueden agregar de dos formas distintas, 
de manera estática, cuando se copia y pega la parte que necesito en el archivo, o de manera dinámica, asignando un espacio de
memoria en la RAM (NO EN EL PROGRAMA), al cual el programa accede cuando lo necesita.  
genera un nuevo archivo .e que ya puedo ejecutar y realizar la tarea que quiero. 

2)
El prepocesador agregó el calculator.h que incluye el main. A su vez el calculator.h incluye a stdio.h que tiene todas las 
funciones específicas de C, por lo tanto en el archivo calculator.pp_c aparecen todos estos includes y macros.

3)
Las funciones definidas dentro de calculator.asm son dos: el main y add_numbers. También está la función printf que no está 
definida dentro del assembler pero que la utiliza con un call.

4) y 5)
En el objeto aparecen dos símbolos, "T", para add_numbers y main, y "U" para print_f. "T" viene de text e implica que es
código que se puede ejecutar. "U" viene de undefined y no lo puedo ejecutar porque aún no está definido. Cuando genere el
ejecutable, voy a linkear los objetos con la libreria stdio.h de C y ahí va a dejar de estar indefinido el printf. Hasta ese
momento, el programa no sabe lo que es. Cuando generamos el ejecutable el printf sigue indefinido pero ahora con una dirección
para buscarlo (@@GLIB_2.2.5). Sigue siendo indefinido para el programa, pero es capaz de llamar a quién lo puede resolver.


