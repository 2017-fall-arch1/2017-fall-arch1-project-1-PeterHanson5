



all: main

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

main: employ.o main.o
	cc -o $@ $^

employ.o: employ.c employ.h
	cc -c $(CFLAGS) employ.c

main.o: main.c employ.h
	cc -c $(CFLAGS) main.c

clean:
	rm -f *.o main

demo: main
	(echo first; echo "second line"; echo "third and last") | ./main

