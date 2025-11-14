DEMOTARGET=main

main: main.o
	gcc main.o -o main -lX11

main.o: main.c
	gcc -c main.c -o main.o

all:
	make clean && make main

run:
	make all && ./main

clean:
	-rm -r -f   $(DEMOTARGET) *.o