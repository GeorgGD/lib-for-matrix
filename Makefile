CC = gcc
FLAGS = -O3 -march=native -g -Wall -pthread
OFLAGS = 

OBJECTS = eig_power.o
CUNIT = -lcunit
VALGRIND = valgrind --leak-check=full
CACHEGRIND = valgrind --tool=cachegrind --cache-sim=no --branch-sim=yes

##################################################################################################
# BUILD
##################################################################################################

power_method: $(OBJECTS)
	$(CC) $(FLAGS) $(OFLAGS) $(OBJECTS) -o power_method

eig_power.o: eig_power.c
	$(CC) $(FLAGS) $(OFLAGS) eig_power.c -c 
clean:
	rm -f *.o power_method unittest cachegrind.*



##################################################################################################
# RUN TESTS
##################################################################################################

