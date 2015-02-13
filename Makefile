YACC = bison
LEX = flex
TARGET = bin/latino
CFLAGS = -g -Wall
LIBS =
CC = gcc

#ifeq (Windows_NT,$(OS))
#TARGET:=$(TARGET).exe
#endif

TESTS=$(wildcard ejemplos/*.lat)

all : $(TARGET)

.PHONY : all

test : all
	$(TARGET) $(TESTS)

.PHONY : test

src/parse.c : src/parse.y
	$(YACC) -osrc/parse.c src/parse.y

src/lex.c : src/lex.l
	$(LEX) -osrc/lex.c -i src/lex.l

src/parse.o : src/parse.c
	$(CC) -g -c src/parse.c -o src/parse.o

src/latino.o : src/latino.c src/latino.h
	$(CC) -g -c src/latino.c -o src/latino.o

src/cmath.o : src/cmath.c src/latino.h
	$(CC) -g -c src/cmath.c -o src/cmath.o

src/lex.o : src/lex.c
	$(CC) -g -c src/lex.c -o src/lex.o

$(TARGET) : src/parse.o src/latino.o src/lex.o src/cmath.o
	mkdir -p "$$(dirname $(TARGET))"
	$(CC) $(CFLAGS) src/parse.o src/latino.o src/lex.o src/cmath.o -o $(TARGET) $(LIBS)

clean :
	rm -f src/*.o
.PHONY : clean
