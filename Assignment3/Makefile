SOURCES = reversi.c
HEADERS = othello.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

reversi: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

tests: test-othello

test-reversi: test-reversi.o reversi.o
	$(CC) -o $@ test-reversi.o reversi.o $(LIBS)

test-reversi: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

test-test: test.o reversi.o
	$(CC) -o $@ test.o reversi.o  $(LIBS)

clean: 
	$(RM) reversi $(OBJECTS) test-*
