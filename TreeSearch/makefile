#define the compiler-executable path

COMPILE_SWITCHES = -g
COMPILE = gcc $(COMPILE_SWITCHES)
OFILES = cart.o retail_item.o fastLookup.o tree.o main.o

run: $(OFILES)
	$(COMPILE) -o run $(OFILES)

cart.o: cart.c cart.h retail_item.h
	$(COMPILE) -c cart.c

retail_item.o: retail_item.c retail_item.h
	$(COMPILE) -c retail_item.c

fastLookup.o: fastLookup.c cart.h fastLookup.h
	$(COMPILE) -c fastLookup.c

tree.o: tree.c retail_item.h cart.h tree.h
	$(COMPILE) -c tree.c

main.o: main.c retail_item.h cart.h fastLookup.h tree.h
	$(COMPILE) -c main.c

# this defines the command for cleaning up
# all generated files
clean:
	/bin/rm -f *.o run
