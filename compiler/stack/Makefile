all: libstack.a

linkedlist.o: linkedlist.c linkedlist.h ../hash_table/hash_table.h
	gcc -c linkedlist.c -o linkedlist.o

libstack.a: stack.o linkedlist.o ../hash_table/hash_table.o
	ar rcs libstack.a linkedlist.o ../hash_table/hash_table.o stack.o

../hash_table/hash_table.o: ../hash_table/hash_table.c ../hash_table/hash_table.h
	gcc -c ../hash_table/hash_table.c -o ../hash_table/hash_table.o

stack.o: stack.c stack.h
	gcc -c stack.c -o stack.o

clean:
	rm -f *.out *.o *.a