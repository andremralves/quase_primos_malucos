main: main.c
	gcc -pthread -O2 -static -o main.out main.c -lm
