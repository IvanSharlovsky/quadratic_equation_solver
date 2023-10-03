CC=gcc
CFLAGS=-c -Wall -Wextra
SOURCES=main.c quadratic_equation_solver.c quadratic_equation_tests.c floating_point_math.c
OBJECTS=$(SOURCES:.c=.o)

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main -lm

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f *.o main

debug:
	valgrind ./main