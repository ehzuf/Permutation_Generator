permutation : function.o main.o
	cc -o permutation function.o main.o -lm

function.o : function.c function.h
	cc -c function.c

main.o : main.c function.h
	cc -c main.c -std=c99

clean :
	rm permutation function.o main.o