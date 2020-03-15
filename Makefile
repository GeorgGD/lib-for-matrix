CC = gcc
FLAGS = -pedantic -g -Wall
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
	rm -f *.o lu unittest cachegrind.* *.h~ *.c~ Makefile~



##################################################################################################
# RUN TESTS
##################################################################################################

test: unittest
	./unittest

mem_test: unittest
	$(VALGRIND) ./unittest
