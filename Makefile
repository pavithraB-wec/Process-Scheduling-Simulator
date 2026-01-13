CC = gcc
CFLAGS = -Wall

all:
	$(CC) $(CFLAGS) src/*.c -o scheduler

clean:
	rm -f scheduler
