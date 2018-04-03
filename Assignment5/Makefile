CSOURCES = caesar.cpp test_caesar.cpp
DSOURCES = date.cpp test_date.cpp
HEADERS = caesar.hpp date.hpp
COBJECTS = $(CSOURCES:.cpp=.o)
DOBJECTS = $(DSOURCES:.cpp=.o)

RM = rm
CC = g++
CPPFLAGS = -std=c++11

%.o: %.c
	$(CC) -c $(CPPFLAGS) $<

all: caesar date

caesar: $(COBJECTS)
	$(CC) -o $@ $(COBJECTS)

date: $(DOBJECTS)
	$(CC) -o $@ $(DOBJECTS)


clean:
	$(RM) caesar $(COBJECTS) $(DOBJECTS)
