
CC = gcc
FLAGS = -pedantic -g -Wall -fopenmp 
OFLAGS = 

OBJECTS = lu_factor.o main.o
CUNIT = -lcunit
VALGRIND = valgrind --leak-check=full
CACHEGRIND = valgrind --tool=cachegrind --cache-sim=no --branch-sim=yes

##################################################################################################
# BUILD
##################################################################################################

lu: $(OBJECTS)
	$(CC) $(FLAGS) $(OFLAGS) $(OBJECTS) -o lu

main.o: ./src/main.c ./src/common.h 
	$(CC) $(FLAGS) $(OFLAGS) ./src/main.c -c

lu_factor.o: ./src/lu_factor.c ./src/lu_factor.h ./src/common.h
	$(CC) $(FLAGS) $(OFLAGS) ./src/lu_factor.c -c 

unittest: lu_factor.o ./test/unittest.c ./src/common.h
	$(CC) $(FLAGS) $(OFLAGS) lu_factor.o ./test/unittest.c -o unittest $(CUNIT)

clean:
	rm -f *.o lu unittest cachegrind.* *.h~ *.c~ Makefile~ *.sh~



##################################################################################################
# RUN TESTS
##################################################################################################

S = 3
P = 1
N = 4

run: lu
	./lu $(S) $(P) $(N)

test: unittest
	./unittest

mem_test: unittest
	$(VALGRIND) ./unittest

mem_main: lu
	$(VALGRIND) ./lu 9 0 1

cache: lu
	$(CACHEGRIND) ./lu 9 0 1

gprof:
	make clean
	make -s OFLAGS="-pg"
	./lu 1000 0 1
	gprof lu gmon.out


