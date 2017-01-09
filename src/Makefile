# Makefile for data-structures-c
# ******************************************************
# Parameters to control Makefile operation

CC=gcc
CFLAGS=-Wall -ansi

# ******************************************************
# Entries to bring the executable up to date

main: main.o node.o 
	$(CC) $(CFLAGS) -o main main.o node.o

main.o: main.c node.h
	$(CC) $(CFLAGS) -c main.c

node.o: node.c node.h
	$(CC) $(CFLAGS) -c node.c
