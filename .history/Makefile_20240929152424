all: main

main: main.c
	gcc -o main main.c

config: config.c
	gcc -mconsole -o config config.c

clean:
	rm main

test: main
	bash test.sh