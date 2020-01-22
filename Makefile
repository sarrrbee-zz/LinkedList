CC = gcc
INCLUDES = 
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS = 

mylist-test: mylist-test.o libmylist.a

mylist-test.o: mylist-test.c mylist.h

libmylist.a: mylist.o
	ar rc libmylist.a mylist.o
	ranlib libmylist.a

mylist.o: mylist.c mylist.h

.PHONY: clean
clean: 
	rm -f *.o a.out core main mylist-test

.PHONY: all
all: clean main

