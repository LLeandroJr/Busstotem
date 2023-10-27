CC=g++
FLAGS=-std=c++ -Wall -Wextra

all: main.o ForwardList.o List.o
	$(CC) $(FLAGS) main.o ForwardList.o List.o -o main | .\main

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

ForwardList: ForwardList.cpp
	$(CC) $(FLAGS) -c ForwardList.cpp

List.0: List.cpp
	$(CC) $(FLAGS) -c List.cpp