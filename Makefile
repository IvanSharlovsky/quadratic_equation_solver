CC=gcc

all:
	$(CC) main.c quadratic_equation_solver.c quadratic_equation_tests.c floating_point_math.c -o main -lm

clean:
	rm -f main

debug:
	valgrind ./main