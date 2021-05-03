output: main.o stack_ctr.o
	gcc main.o stack_ctr.o -o output

main.o: main.c
	gcc -c main.c

stack_ctr.o: stack_ctr.c stack_ctr.h
	gcc -c stack_ctr.c

clean:
	del *.o

run:
	.\output
