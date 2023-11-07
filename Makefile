CC=gcc
CFLAGS=-c -Wall -Wextra -Werror 
SOURCES=sources/main.c sources/quadratic_equation_solver.c sources/quadratic_equation_tests.c sources/floating_point_math.c 
OBJECTS=main.o quadratic_equation_solver.o quadratic_equation_tests.o floating_point_math.o
#OBJECTS=$(SOURCES:.c=.o)

main: $(OBJECTS)
	$(CC) $(OBJECTS) -lm -o main

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f *.o main

debug:
	valgrind ./main