parser.out: parser.c scanner.o main.o expr.o
	gcc parser.c scanner.o main.o expr.o -o parser.out -lm

parser.c: parser.y colors.h expr.h
	bison --defines=token.h --output=parser.c -v parser.y

scanner.o: scanner.c
	gcc -c scanner.c -o scanner.o

scanner.c: scanner.l token.h
	flex -o scanner.c scanner.l

main.o: main.c token.h colors.h expr.h
	gcc -c main.c -o main.o

expr.o: expr.c expr.h colors.h
	gcc -c expr.c -o expr.o

clean:
	rm -f *.out *.o scanner.c parser.c token.h *.output