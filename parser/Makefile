parser.out: parser.c structures.o scanner.o main.o
	gcc parser.c structures.o scanner.o main.o -o parser.out

parser.c: parser.y structures.h colors.h
	bison --defines=token.h --output=parser.c --graph=parser.dot -v parser.y

structures.o: structures.c structures.h
	gcc -c structures.c -o structures.o

scanner.o: scanner.c
	gcc -c scanner.c -o scanner.o

scanner.c: scanner.l token.h
	flex -o scanner.c scanner.l

main.o: main.c error.h colors.h
	gcc -c main.c -o main.o

clean:
	rm -f *.out *.o scanner.c parser.c token.h *.dot *.output