OBJS = main.o board.o move.o
SOURCE = main.c board.c move.c
OUT	= chess
CC = gcc
FLAGS = -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	rm -f $(OBJS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

board.o: board.c
	$(CC) $(FLAGS) board.c 

move.o: move.c
	$(CC) $(FLAGS) move.c 

clean:
	rm -f $(OBJS) $(OUT)

