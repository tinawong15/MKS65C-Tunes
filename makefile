all: list.o main.o
	gcc list.o main.o

list.o: list.c list.h
	gcc -c list.c

main.o: main.c list.h
	gcc -c main.c

run:
	./a.out
