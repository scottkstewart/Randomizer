CC=gcc

exec: main.o
	$(CC) -o Randomize main.o
