CC=gcc

all:
	$(CC) main.c quadratic_equation_solver.c -o main

clean:
	rm -f main

debug:
	valgrind ./main