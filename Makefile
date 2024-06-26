APP := quad-solver

CC ?= gcc
QEMU_USER ?= qemu-x86_64
CFLAGS ?= -O3 -Wall -Wextra -Werror
LFLAGS ?= -static
DEBUG_FLAGS ?= -DEBUG -O0 -Og -Wall -Wextra -Werror
CONTAINER ?= rv_tools_quad

BUILD_DIR := ./build
SRC_DIR := ./sources
INC_DIR := ./include
#SRCS := $(shell find $(SRC_DIR) -name *.c)
#OBJS := $(addsuffix .o,$(basename $(SRCS)))
OBJS := $(BUILD_DIR)/main.o $(BUILD_DIR)/quadratic_equation_solver.o \
	   $(BUILD_DIR)/quadratic_equation_tests.o $(BUILD_DIR)/floating_point_math.o
.DEFAULT_GOAL := build

_build_dir:
	@mkdir -p $(BUILD_DIR)

run: build
	$(BUILD_DIR)/$(APP)

build: _build_dir $(OBJS)
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

debug: _build_dir main.c $(wildcard $(SRC_DIR)/*.c) $(wildcard $(INC_DIR)/*.h)
	$(CC) -I $(INC_DIR) $(DEBUG_FLAGS) main.c $(wildcard $(SRC_DIR)/*.c) $(wildcard $(INC_DIR)/*.h) -lm \
	-o $(BUILD_DIR)/$@

run-qemu: build
	$(QEMU_USER) $(BUILD_DIR)/$(APP)

start-container:
	docker start $(CONTAINER)
	
build-docker: start-container 	
	docker exec -t $(CONTAINER) bash -c "make build CC=$(CC)"

.PHONY: clean valgrind build-docker start-container run build

clean:
	rm -r $(BUILD_DIR)

valgrind:
	valgrind ./$(APP)
