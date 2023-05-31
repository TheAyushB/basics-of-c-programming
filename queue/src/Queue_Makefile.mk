TARGET: queue.o

queue.o: queue/src/queue.c
	gcc -c queue/src/queue.c -o queue/src/queue.o