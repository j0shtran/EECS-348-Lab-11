CC = g++
CFLAGS = -Wall

all: exercise1 exercise2 exercise3 exercise4 exercise5

exercise1: exercise1.cpp 
	$(CC) $(CFLAGS) exercise1.cpp -o exercise1 

exercise2: exercise2.cpp
	$(CC) $(CFLAGS) exercise2.cpp -o exercise2

exercise3: exercise3.cpp
	$(CC) $(CFLAGS) exercise3.cpp -o exercise3

exercise4: exercise4.cpp
	$(CC) $(CFLAGS) exercise4.cpp -o exercise4

exercise5: exercise5.cpp
	$(CC) $(CFLAGS) exercise5.cpp -o exercise5

clean:
	rm rf *.o -f exercise1 exercise2 exercise3 exercise4 exercise5
