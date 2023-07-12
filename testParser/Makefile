parser.out: parser.c scanner.o main.o
	gcc parser.c scanner.o main.o -o parser.out

parser.c: parser.y
	bison --defines=token.h --output=parser.c -v parser.y

scanner.o: scanner.c
	gcc -c scanner.c -o scanner.o

scanner.c: scanner.l token.h
	flex -o scanner.c scanner.l

main.o: main.c token.h
	gcc -c main.c -o main.o

clean:
	rm -f *.out *.o scanner.c parser.c token.h *.output