/*
The MIT License (MIT)

Copyright (c) 2015 - Latino

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef _LATINO_H_
#define _LATINO_H_

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdarg.h>
#include <float.h>

#include "ast.h"
#include "vm.h"

/** \file latino.h
*
* Contiene los macros, definiciones y funciones generales para Latino
*
*/

/** Determina si el sistema es GNU */
#if defined(__GNUC__) && ((__GNUC__ * 100 + __GNUC_MINOR__) >= 302) && \
defined(__ELF__)
#define LAT_FUNC __attribute__((visibility("hidden"))) extern
#define lnsprintf(s, l, f, i) snprintf(s, l, f, i)
#include <dlfcn.h>
#include <unistd.h>
#else
/* Visual Leak Detector for Visual C++ */
//#include <vld.h>
#define LAT_FUNC extern
#define lnsprintf(s, l, f, i) _snprintf(s, l, f, i)
#endif

/** Version mayor de Latino */
#define LAT_VERSION_MAYOR "0"
/** Version menor de Latino */
#define LAT_VERSION_MENOR "4"
/** Version de Latino */
#define LAT_VERSION "Latino " LAT_VERSION_MAYOR "." LAT_VERSION_MENOR
/** Derechos de Latino */
#define LAT_DERECHOS LAT_VERSION "\nTodos los derechos reservados (C) 2015-2016. Latinoamerica"

/** Afirmar (asset), sirve para testear una condicion */
#define lat_afirmar(cond) ((void)(false && (cond)))

/** Indica si se desea debuguear el parser de bison */
extern int debug;

/** Tamanio maximo de instrucciones bytecode de una funcion */
#define MAX_BYTECODE_FUNCTION (1024 * 10)
/** Tamanio maximo de memoria virtual permitida */
#define MAX_VIRTUAL_MEMORY (1024 * 10)
/** Tamanio maximo de una cadena para ser almacenada en HASH TABLE */
#define MAX_STR_INTERN 64
/** Tamanio maximo de una cadena almacenada dinamicamente */
#define MAX_STR_LENGTH (1024*2)
/** Tamanio maximo de la pila de la maquina virtual */
#define MAX_STACK_SIZE 255

/** Interface con flex */
typedef struct YYLTYPE {
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;

/** Establece que se definio una interface con Flex */
#define YYLTYPE_IS_DECLARED 1

/** No se requiere cabecera unistd.h */
#define YY_NO_UNISTD_H 1

/** Analiza una cadena como expresion
  *
  * \param expr: cadena a analizar
  * \return ast: Nodo AST
  *
  */
ast* lat_analizar_expresion(char* expr);

/** Analiza un archivo
  *
  * \param path: Ruta del archivo a analizar
  * \return ast: Nodo AST
  *
  */
ast* lat_analizar_archivo(char* path);

#endif /* _LATINO_H_ */
