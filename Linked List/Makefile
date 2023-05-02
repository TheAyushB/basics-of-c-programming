# CC = gcc
# # CFLAGS = -Wall -Werror -std=c99

# EXECUTABLE = program

# SOURCES = nagra_main.c linear_list.c
# HEADERS = linear_list.h
# OBJECTS = $(SOURCES:.c=.o)

# all: $(EXECUTABLE)

# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# $(OBJECTS): $(SOURCES) $(HEADERS)
# 	$(CC) $(CFLAGS) -c $(SOURCES)

# clean:
# 	rm -f $(EXECUTABLE) $(OBJECTS)
##################################################################
# Define variables for the source files
SRC = nagra_main.c linear_list.c
STACK_SRC = nagra_main.c stack.c
QUEUE_SRC = nagra_main.c queue.c

# Define variables for the compiler and linker options
CC = gcc
# CFLAGS = -Wall -Wextra -Wpedantic
LDFLAGS =

# Define variables for the user's choice
DATASTRUCTURE = LINEAR_LIST

# Define targets for each option
linear: $(SRC:.c=.o)
	$(CC) $(LDFLAGS) $^ -o $@

stack: $(STACK_SRC:.c=.o)
	$(CC) $(LDFLAGS) $^ -o $@

queue: $(QUEUE_SRC:.c=.o)
	$(CC) $(LDFLAGS) $^ -o $@

# Define a target for cleaning up object and executable files
clean:
	rm -f *.o linear stack queue

# Define rules for compiling each source file
%.o: %.c
	$(CC) $(CFLAGS) -D$(DATASTRUCTURE)_DEFAULT -c $< -o $@
