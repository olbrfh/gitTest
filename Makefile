DEMOTARGET=main

# GTK2 FLAGS
GTK_CFLAGS := $(shell pkg-config --cflags gtk+-2.0)
GTK_LIBS   := $(shell pkg-config --libs gtk+-2.0)

main: main.o
	g++ main.o -o $(DEMOTARGET) $(GTK_LIBS)

main.o: main.cpp
	g++ -c main.cpp -o main.o $(GTK_CFLAGS)

all:
	make clean && make main

run:
	make all && ./$(DEMOTARGET)

clean:
	-rm -r -f $(DEMOTARGET) *.o