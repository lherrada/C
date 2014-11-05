GCC=gcc
CFLAGS=-c -Wall

all: myls

myls: ls.c 
	$(GCC) -Wall -o $@ $<

#getcwd.o: getcwd.c 
#	$(GCC) -o $@ $< $(CFLAGS)

#pwd.o: pwd.c
#	$(GCC) $(CFLAGS) $< 

clean:
	rm -f *.o myls
