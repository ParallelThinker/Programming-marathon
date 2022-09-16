FLAGS= -fopenmp -pg -O3 -Wall
OUT=primetest
CC=gcc

all: primetest

primetest: primetest.c
	$(CC) primetest.c $(FLAGS) -lm -o $(OUT)

clean:
	rm $(OUT)
