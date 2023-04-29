TARGET: deb 	

linear_list.o: linear_list.c
	gcc -c linear_list.c -o linear_list.o

nagra_main.o: nagra_main.c
	gcc -c nagra_main.c -o nagra_main.o

libll.a: linear_list.o
	ar rs libll.a linear_list.o

deb: nagra_main.o libll.a
	gcc -g nagra_main.o -o deb -L . libll.a -lm

clean:
	rm nagra_main.o 
	rm linear_list.o
	rm deb
	rm libll.a
