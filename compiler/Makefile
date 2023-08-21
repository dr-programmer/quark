quark: parser.o structures.o scanner.o main.o scope.o stack_do symbol_make LLVM/codegen.o
	gcc -o quark parser.o structures.o scanner.o main.o scope.o symbol/symbol.o LLVM/codegen.o -Lstack -lstack

parser.o: parser.c
	gcc -c parser.c -o parser.o

parser.c: parser.y structures.h colors.h
	bison --defines=token.h --output=parser.c --graph=parser.dot -v parser.y

structures.o: structures.c structures.h
	gcc -c structures.c -o structures.o

scanner.o: scanner.c
	gcc -c scanner.c -o scanner.o

scanner.c: scanner.l token.h
	flex -o scanner.c scanner.l

main.o: main.c error.h colors.h structures.h
	gcc -c main.c -o main.o

scope.o: scope.c scope.h
	gcc -c scope.c -o scope.o

stack_do:
	cd stack; make; cd ..

stack_wipe:
	cd stack; make clean; cd ..

symbol_make:
	cd symbol; make; cd ..

symbol_wipe:
	cd symbol; make clean; cd ..

LLVM/codegen.o: LLVM/codegen.h LLVM/codegen.c
	gcc -c LLVM/codegen.c -o LLVM/codegen.o

clean: symbol_wipe stack_wipe
	rm -f *.out *.o scanner.c parser.c token.h *.dot *.output quark *.s