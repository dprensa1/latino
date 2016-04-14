#Latino

[![Join the chat at https://gitter.im/primitivorm/latino](https://badges.gitter.im/primitivorm/latino.svg)](https://gitter.im/primitivorm/latino?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

![latino sublime](https://raw.githubusercontent.com/primitivorm/latino/master/SublimeTextSyntax/latino_sublime.png "latino sublime")

Este proyecto nace de la necesidad de incrementar la educación de nivel básico (primaria y secundaria)
debido a que los niños tienen la capacidad de entender la lógica a muy temprana edad y es en esta edad
cuando más aprenden, esto motivará a los niños y jovenes por interesarse en el mundo del desarrollo de aplicaciones.

¿Y por que un lenguaje de programación más?
Si es bien sabido que ya hay muchos lenguajes de programación; pero no tenemos un lenguaje para programar
con sintaxis en español, y entonces ¿por qué no hacer uno?

¿Cuantos de ustedes no batallaron con el inglés?
¿Cúal seria la ventaja si no tuvieras que preocuparte por aprender javascript, html, css y mysql para desarrollar tus paginas web?

Pues bien si este proyecto suena ambicioso, realmente les puedo decir que dependerá de la participación de todos nosotros para que esto sea posible.

A continuación menciono las principales caracteristas de este proyecto:

1. Simplicidad: La sintaxis debera de ser lo más natural posible al lenguaje español.
2. Sencillo de aprender: Al ser simple aprenderas más rápido este nuevo lenguaje.
3. Libre: Cualquiera puede descargar el código fuente del lenguaje, extender las librerias basicas y crear sus propias librerias si asi lo desea. Y para que todos podamos difrutar de Latino, subir a este repositorio los cambios y/o nuevas funcionalidades.
4. Lenguaje de alto nivel: Cuando escribas código no tendrás que preocuparte por detalles de bajo nivel, como manejar la memoria empleada en tu programa.
5. Portable: Cuando escribas tus programas en “latino” podras ejecutarlo en cualquier plataforma.
6. Orientado a Objetos: Permitirá programación orientada a procedimientos así como orientada a objetos.

El lenguaje deberá de ser de código abierto bajo la licencia del MIT por ser la menos restrictiva:
http://opensource.org/licenses/MIT

Leer LICENSE.txt
### Requiere:
* bison 3.04
* flex 2.5.39
* cmake 3.3.1
* gcc 4.9.3 (Linux) / Visual Studio Community Edition o CodeBlocks (Windows)

###COMPILAR

#####Linux
ir al directorio latino/ y ejecutar

```
$cmake .
$make
```

#####Windows
1. Instale cmake desde https://cmake.org/
2. Inicie cmake
3. Elija la ruta que contiene su carpeta latino
4. Elija la ruta en donde se generar la solucion de Visual Studio latino/build
5. Clic en el botón configurar (Configure)
6. Clic en el botón generar (Generate)
7. Abrir la solucion en Visual Studio generada en la ruta latino/build/ y compile

#####Tambien puede compilar el proyecto con CodeBlocks http://www.codeblocks.org/
1. Abra el proyecto latino.cbp y compile

#####Cualquier aportación o sugerencia es bienvenida.
