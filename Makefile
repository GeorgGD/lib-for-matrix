CC = gcc
FLAGS = -pedantic -g -Wall
OFLAGS = 

OBJECTS = eig_power.o main.o
CUNIT = -lcunit
VALGRIND = valgrind --leak-check=full
CACHEGRIND = valgrind --tool=cachegrind --cache-sim=no --branch-sim=yes

##################################################################################################
# BUILD
##################################################################################################

power_method: $(OBJECTS)
	$(CC) $(FLAGS) $(OFLAGS) $(OBJECTS) -o power_method

main.o: main.c
	$(CC) $(FLAGS) $(OFLAGS) main.c -c

eig_power.o: eig_power.c eig_power.h
	$(CC) $(FLAGS) $(OFLAGS) eig_power.c -c 

unittest: eig_power.o unittest.c
	$(CC) $(FLAGS) $(OFLAGS) eig_power.o unittest.c -o unittest $(CUNIT)

clean:
	rm -f *.o power_method unittest test cachegrind.*



##################################################################################################
# RUN TESTS
##################################################################################################

test: unittest
	./unittest

mem_test: unittest
	$(VALGRIND) ./unittest
