CC = g++
CFLAGS = -Wall

all: exercise1 exercise2

exercise1: exercise1.cpp 
	$(CC) $(CFLAGS) exercise1.cpp -o exercise1 

exercise2: exercise2.cpp
	$(CC) $(CFLAGS) exercise2.cpp -o exercise2

clean:
	rm rf *.o -f exercise1 exercise2
