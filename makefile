# Compiler and flags
CC = g++
CFLAGS = -Wall -O2 -std=c++11

# Executable names
CREATE_EXEC = create
BRUTEFORCE_EXEC = bruteforce
DIVIDECONQUER_EXEC = divideconquer

# Source files
CREATE_SRC = create.cpp
BRUTEFORCE_SRC = bruteforce.cpp
DIVIDECONQUER_SRC = DivideAndConquer.cpp

# Object files
CREATE_OBJ = $(CREATE_SRC:.c=.o)
BRUTEFORCE_OBJ = $(BRUTEFORCE_SRC:.c=.o)
DIVIDECONQUER_OBJ = $(DIVIDECONQUER_SRC:.c=.o)

# Targets
all: $(CREATE_EXEC) $(BRUTEFORCE_EXEC) $(DIVIDECONQUER_EXEC)

$(CREATE_EXEC): $(CREATE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BRUTEFORCE_EXEC): $(BRUTEFORCE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(DIVIDECONQUER_EXEC): $(DIVIDECONQUER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CREATE_EXEC) $(BRUTEFORCE_EXEC) $(DIVIDECONQUER_EXEC) *.o

.PHONY: all clean
