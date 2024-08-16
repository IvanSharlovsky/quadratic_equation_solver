# Quadratic equation solver

## Education project that provides quadratic equation solver app

## This project implements

- ### 7 Unit-tests to check the correct math operation

- ### Smart valid input control system

## How to build and run

- ### Open terminal in app directory

- ### Print `make build` to build app

- ### Print `make run` to build and run app

- ### Print `make debug` to build app with debug options

- ### Print `make qemu-run` to run app with qemu-x86_64 as default

- ### Print `make build-docker` to build app in Docker container

    - #### You need existing Docker container with toolchain for this target

### Also you can change CC, QEMU-USER, CFLAGS, LFLAGS, DEBUG_FLAGS, CONTAINER values in command line before or after `make [target]`

### Default values:

`CC ?= gcc`

`QEMU_USER ?= qemu-x86_64`

`CFLAGS ?= -O3 -Wall -Wextra -Werror`

`LFLAGS ?= -static`

`DEBUG_FLAGS ?= -DEBUG -O0 -Og -Wall -Wextra -Werror`

`CONTAINER ?= rv_tools_quad`
