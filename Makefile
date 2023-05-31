TARGET: deb

include ./linear_list/src/Linear_list_Makefile.mk
include ./queue/src/Queue_Makefile.mk
include ./stack/src/Stack_Makefile.mk

nagra_main.o: nagra_main.c
	gcc -c nagra_main.c -o nagra_main.o

libll.a: linear_list/src/linear_list.o queue/src/queue.o stack/src/stack.o
	@echo "Please select a data structure:"
	@echo "1. LinkedList"
	@echo "2. Stack"
	@echo "3. Queue"
	read choice; \
	case $$choice in \
		1) ar rs linear_list/lib/libll.a linear_list/src/linear_list.o ;; \
		2) ar rs queue/lib/libqueue.a queue/src/queue.o ;; \
		3) ar rs stack/lib/libstack.a stack/src/stack.o ;; \
		*) echo "Invalid choice." ;; \
	esac

# This part is not working--------
deb: nagra_main.o libll.a queue/src/queue.o stack/src/stack.o
	gcc -g nagra_main.o -o deb -L . linear_list/lib/libll.a queue/src/queue.o stack/src/stack.o -lm

clean:
	rm nagra_main.o 
	rm deb
	rm linear_list/src/linear_list.o
	rm queue/src/queue.o
	rm stack/src/stack.o
	rm linear_list/lib/libll.a
	rm queue/lib/libqueue.a
	rm stack/lib/libstack.a