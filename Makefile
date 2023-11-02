CC=gcc
CFLAGS=-Wall -Wextra -Werror
SOURCES=sources/main.c sources/quadratic_equation_solver.c sources/quadratic_equation_tests.c sources/floating_point_math.c
##OBJECTS=main.o quadratic_equation_solver.o quadratic_equation_tests.o floating_point_math.o
#OBJECTS=$(SOURCES:.c=.o)

##main: $(OBJECTS)
##	$(CC) $(OBJECTS) -o main -lm
##
##$(OBJECTS): $(SOURCES)
##	$(CC) -c $(CFLAGS) $(SOURCES)

main:
	$(CC) $(CFLAGS) $(SOURCES) -o main -lm

clean:
	rm -f *.o main

debug:
	valgrind ./main