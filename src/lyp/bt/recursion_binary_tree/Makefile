all : demo

demo : main.o queue.o bt.o queue.h bt.h 
	gcc -g -Wall main.o queue.o bt.o -o demo

queue.o : queue.h queue.c
	gcc -c queue.c -o queue.o

bt.o : bt.c bt.h
	gcc -c bt.c -o bt.o

main.o : main.c bt.h 
	gcc -c main.c -o main.o

clean :
	@rm -f demo *.o
