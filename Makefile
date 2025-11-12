CC = g++
CFLAGS = -Wall

all: exercise1

exercise1: exercise1.cpp 
	$(CC) $(CFLAGS) exercise1.cpp -o exercise1 

clean:
	rm rf *.o -f exercise1
