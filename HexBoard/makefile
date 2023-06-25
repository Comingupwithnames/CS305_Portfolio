#This defines all the commands for compiling an executable file named find_path
find_path: main.c load.o hexboard.o
	gcc -g -o find_path main.c load.o hexboard.o 

load.o: load.c load.h hexboard.h hexcell.h 
	gcc -g -c load.c

hexboard.o: hexboard.c hexboard.h hexcell.h load.h 
	gcc -g -c hexboard.c 
	
#This defines the command for cleaning up all files generated
clean: 
	/bin/rm -f *.o find_path