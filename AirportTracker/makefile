#This defines all the commands for compiling an executable file named airport_test
airport_test: main.c process.o llist.o airport.o
	gcc -g main.c process.o llist.o airport.o -o airport_test

process.o: process.c process.h airport.h list.h
	gcc -g -c process.c

llist.o: llist.c list.h airport.h
	gcc -g -c llist.c
	
airport.o: airport.c airport.h
	gcc -g -c airport.c 

#This defines the command for cleaning up all files generated
clean: 
	/bin/rm -f *.o airport_test