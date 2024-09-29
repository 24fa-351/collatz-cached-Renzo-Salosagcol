CC = gcc

all: main

main: main.c
	$(CC) -o main main.c config.o

config.o: config.c
	$(CC) -c config.c -o config.o

clean:
	rm @(EXEFILES)

test: main
	bash test.sh