CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lSDL2
SRC = main.c
EXEC = main

all:
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(LIBS)

clean:
	rm -f $(EXEC)

run:
	./$(EXEC)