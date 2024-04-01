APP_DIR ?= ~/Documents/Github/quadratic_equation_solver
APP := quad-solver

CC ?= gcc
QEMU_USER ?= qemu-x86_64
CFLAGS ?= -O3 -Wall -Wextra -Werror
LFLAGS ?= -static
DEBUG_FLAGS ?= -DEBUG -O0 -Og -Wall -Wextra -Werror

BUILD_DIR := ./build
SRC_DIR := ./sources
INC_DIR := ./include
#SRCS := $(shell find $(SRC_DIR) -name *.c)
#OBJS := $(addsuffix .o,$(basename $(SRCS)))
OBJS := $(BUILD_DIR)/main.o $(BUILD_DIR)/quadratic_equation_solver.o \
	   $(BUILD_DIR)/quadratic_equation_tests.o $(BUILD_DIR)/floating_point_math.o
.DEFAULT_GOAL := main

_build_dir:
	@mkdir -p $(BUILD_DIR)

run: main
	$(BUILD_DIR)/$(APP)

main: _build_dir $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -lm -o $(BUILD_DIR)/$(APP)

$(BUILD_DIR)/main.o: main.c $(INC_DIR)/quadratic_equation_solver.h $(INC_DIR)/quadratic_equation_tests.h
	$(CC) -I $(INC_DIR) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/quadratic_equation_solver.o: $(SRC_DIR)/quadratic_equation_solver.c \
						$(INC_DIR)/quadratic_equation_solver.h
	$(CC) -I $(INC_DIR) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/quadratic_equation_tests.o: $(SRC_DIR)/quadratic_equation_tests.c \
						$(INC_DIR)/quadratic_equation_tests.h
	$(CC) -I $(INC_DIR) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/floating_point_math.o: $(SRC_DIR)/floating_point_math.c $(INC_DIR)/floating_point_math.h
	$(CC) -I $(INC_DIR) -c $(CFLAGS) $< -o $@

debug: main.c $(SRC_DIR)/$(wildcard *.c)
	$(CC) -I $(INC_DIR) $(DEBUG_FLAGS) $^ -o $(BUILD_DIR)/debug

run-qemu: main
	$(QEMU_USER) $(BUILD_DIR)/$(APP)

start-container:
	docker start cpp 

enter: 
	docker exec -it cpp bash
	
build-docker: start-container enter run-qemu	
	cd $(APP_DIR) \
	CC=/opt/sc-dt/riscv-gcc/bin/riscv64-unknown-linux-gnu-gcc \
	QEMU_USER=/opt/sc-dt/tools/bin/qemu-riscv64 

.PHONY: clean valgrind

clean:
	rm -r $(BUILD_DIR)

valgrind:
	valgrind ./$(APP)
