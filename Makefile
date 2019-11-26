all: parse.o
	gcc -o parse.out parse.o

parse.o: parse.c
	gcc -c parse.c

clean:
	rm -f *.o *.out parse

run:
	./parse.out
