TARGET: stack.o

stack.o: stack/src/stack.c
	gcc -c stack/src/stack.c -o stack/src/stack.o
