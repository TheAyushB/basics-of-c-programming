# # CC = gcc
# # # CFLAGS = -Wall -Werror -std=c99

# # EXECUTABLE = program

# # SOURCES = nagra_main.c linear_list.c
# # HEADERS = linear_list.h
# # OBJECTS = $(SOURCES:.c=.o)

# # all: $(EXECUTABLE)

# # $(EXECUTABLE): $(OBJECTS)
# # 	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# # $(OBJECTS): $(SOURCES) $(HEADERS)
# # 	$(CC) $(CFLAGS) -c $(SOURCES)

# # clean:
# # 	rm -f $(EXECUTABLE) $(OBJECTS)
# ##################################################################
# # Define variables for the source files
# SRC = nagra_main.c linear_list.c
# STACK_SRC = nagra_main.c stack.c
# QUEUE_SRC = nagra_main.c queue.c

# # Define variables for the compiler and linker options
# CC = gcc
# # CFLAGS = -Wall -Wextra -Wpedantic
# LDFLAGS =

# # Define variables for the user's choice
# DATASTRUCTURE = LINEAR_LIST

# # Define targets for each option
# linear: $(SRC:.c=.o)
# 	$(CC) $(LDFLAGS) $^ -o $@

# stack: $(STACK_SRC:.c=.o)
# 	$(CC) $(LDFLAGS) $^ -o $@

# queue: $(QUEUE_SRC:.c=.o)
# 	$(CC) $(LDFLAGS) $^ -o $@

# # Define a target for cleaning up object and executable files
# clean:
# 	rm -f *.o linear stack queue

# # Define rules for compiling each source file
# %.o: %.c
# 	$(CC) $(CFLAGS) -D$(DATASTRUCTURE)_DEFAULT -c $< -o $@




CC = gcc
#CFLAGS = -Wall -Wextra
LDFLAGS = -lpthread

SOURCES = app/nagra_main.c src/linear_list.c src/stack.c src/queue.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = app

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	@echo "Please select a data structure:"
	@echo "1. LinkedList"
	@echo "2. Stack"
	@echo "3. Queue"
	read choice
	case $choice in
		1) ./app src/linear_list ;;
		2) ./app src/stack ;;
		3) ./app src/queue ;;
		*) echo "Invalid choice." ;;
	esac

clean:
	rm -f $(OBJECTS) $(TARGET)


#MinGW32-make
#MinGW32-make run