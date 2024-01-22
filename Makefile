# makefile to build object files from source files within the src directory

# compiler
CC = gcc

# archiver
AR = ar

# compiler flags
CFLAGS = -shared

# libraries for test target:
# should later use ecraft-config when it will be available
LIBS = -Lsrc -lecraft-cli -Lsrc/cstory -lcstory-cli \
	$(shell ncurses6-config --cflags --libs) -ltermbox

# include path
INC = include

# include directories
INCLUDE = -I$(INC)

# macro
MACRO = -D_CRAFT=1

# header files
HEADERS = src/ecraft.h src/cstory/cstory.h

# phony target
.PHONY: all clean clean-all

# default
all:
	-$(MAKE) -C src
	-$(MAKE) -C src/cstory

# test dynamic library
test:
	@$(CC) $(INCLUDE) $(MACRO) tests/test.c $(LIBS) -o tests/$@ \
	-Wl,-rpath=$(shell pwd)/src,-rpath=$(shell pwd)/src/cstory
	@tests/$@

# test static library
test-static:
	@$(CC) -static tests/test.c $(LIBS) -o tests/$@
	@./tests/$@

# clean generated object files
clean:
	-$(MAKE) -C src clean
	-$(MAKE) -C src/cstory clean

# clean up all generated files
clean-all: clean
	-$(MAKE) -C src clean-all
	-$(MAKE) -C src/cstory clean-all
	@-rm -fv tests/test tests/test-static
