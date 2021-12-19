CC=gcc
AR=ar
FLAGS=-g -Wall

all: stringProg

#creat libraries
libmystring.a:ex3.o 
	$(AR) -rcs libmystring.a ex3.o 

ex3.o: ex3.c ex3.h
	$(CC) $(FLAGS) -c ex3.c 


stringProg: main.o libmystring.a
	$(CC) $(FLAGS) -o stringProg main.o libmystring.a

main.o: main.c ex3.h
	$(CC) $(FLAGS) -c main.c



.PHONY: clean all

clean:
	rm -f *.o *.a *.so main ex3
 