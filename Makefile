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

main.o: ./src/main.c ./src/common.h 
	$(CC) $(FLAGS) $(OFLAGS) ./src/main.c -c

eig_power.o: ./src/eig_power.c ./src/eig_power.h ./src/common.h
	$(CC) $(FLAGS) $(OFLAGS) ./src/eig_power.c -c 

unittest: eig_power.o ./test/unittest.c ./src/common.h
	$(CC) $(FLAGS) $(OFLAGS) eig_power.o ./test/unittest.c -o unittest $(CUNIT)

clean:
	rm -f *.o power_method unittest cachegrind.* *.h~ *.c~ Makefile~



##################################################################################################
# RUN TESTS
##################################################################################################

test: unittest
	./unittest

mem_test: unittest
	$(VALGRIND) ./unittest
