TARGET: linear_list.o

linear_list.o: linear_list/src/linear_list.c
	gcc -c linear_list/src/linear_list.c -o linear_list/src/linear_list.o