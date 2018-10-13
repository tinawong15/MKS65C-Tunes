all: list.o main.o library.o
	gcc list.o main.o library.o

list.o: list.c list.h
	gcc -c -g list.c

library.o: library.c library.h
	gcc -c -g library.c

main.o: main.c list.h
	gcc -c -g main.c

run:
	./a.out

debug-mac:
	lldb a.out

debug:
	gdb a.out

debug-mem:
	valgrind ./a.out
