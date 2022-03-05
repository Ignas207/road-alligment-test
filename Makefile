CFLAGS = -g3 -Wall -Wextra -Wconversion 
CC = gcc

all: main road_alligment
		$(CC) $(CFLAGS) -o testing main.o road_alligment.o 
		

main:
		$(CC) -c $(CFLAGS) -o main.o testing_thing.c

road_alligment:
		$(CC) -c $(CFLAGS) -o road_alligment.o road_alligment.c

