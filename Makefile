### THIS IS A BASIC MAKEFILE TEMPLATE
### COPY INTO ANY PROJECT AND ADJUST IT TO YOUR NEEDS

# compile with gcc
CC=gcc

# Compiler options:
#
# -pg is used for profiling (gprof)
CFLAGS = -g

# Linker options:
#
# -lm: link with the math library
LDFLAGS += -lm

# set the name of the executable file to compile here
PROGRAM = main

### REMOVE THE HASHTAGS BELOW AND CHANGE FILE NAMES APPROPRIATELY:

# OBJS = main.o ANY_HEADER_FILE.o
# TEST_OBJS = test.o ANY_HEADER_FILE.o

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROGRAM)

$(LAB): $(LAB_OBJS)
	$(CC) $(CFLAGS) $(LAB_OBJS) $(LDFLAGS) -o $(LAB)

clean:
	rm -f $(PROGRAM) $(OBJS) $(LAB) $(LAB_OBJS)
run:
	./main
v:
	valgrind ./main