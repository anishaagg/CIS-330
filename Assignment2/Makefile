SOURCES = triangle1.c triangle2.c main.c
HEADERS = triangle.h 
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm
RM = rm
CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

tests: test-triangle

test-triangle: test-triangle.o triangle1.o
	$(CC) -o $@ test-triangle.o triangle1.o $(LIBS)

test-triangle: test-triangle.o triangle2.o
	$(CC) -o $@ test-triangle.o triangle2.o $(LIBS)

test-main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

test-test: test.o triangle.o 
	$(CC) -o $@ test.o triangle.o  $(LIBS)

clean: 
	$(RM) main $(OBJECTS) test-*