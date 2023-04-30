CC = gcc
# CFLAGS = -Wall -Werror -std=c99

EXECUTABLE = program

SOURCES = nagra_main.c linear_list.c
HEADERS = linear_list.h
OBJECTS = $(SOURCES:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

