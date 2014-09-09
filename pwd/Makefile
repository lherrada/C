GCC=gcc
CFLAGS=-c -Wall

all: mypwd

mypwd: getcwd.o pwd.o
	$(GCC) -Wall -o $@ $^

getcwd.o: getcwd.c 
	$(GCC) -o $@ $< $(CFLAGS)

pwd.o: pwd.c
	$(GCC) $(CFLAGS) $< 

clean:
	rm -f *.o mypwd

