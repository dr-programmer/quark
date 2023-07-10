scanner.out: scanner.c main.o
	gcc scanner.c main.o -o scanner.out

scanner.c: scanner.l token.h
	flex -o scanner.c scanner.l

main.o: main.c token.h
	gcc -c main.c -o main.o

clean:
	rm -f *.o *.out scanner.c