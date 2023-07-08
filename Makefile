scanner.out: scanner.c main.o
	gcc scanner.c main.o -o scanner.out

scanner.c: scanner.flex token.h
	flex -o scanner.c scanner.flex

main.o: main.c token.h
	gcc -c main.c -o main.o

clean:
	rm -f *.o *.out scanner.c