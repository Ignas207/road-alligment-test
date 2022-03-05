CFLAGS = -g3 -Wall -Wextra -Wconversion -IC
CC = gcc

all: main road_alligment spng
		$(CC) $(CFLAGS) -o testing main.o road_alligment.o 
		

main:
		$(CC) -c $(CFLAGS) -o main.o testing_thing.c

road_alligment:
		$(CC) -c $(CFLAGS) -o road_alligment.o road_alligment.c

spng:
	$(CC) -c $(CFLAGS) -o spng.o ./spng.c

