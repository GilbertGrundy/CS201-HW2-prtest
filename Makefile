# Makefile for prtest

CC = gcc
CFLAGS = -g -std=c99 -Wall

prtest: prtest.c
	$(CC) $(CFLAGS) -o prtest prtest.c

clean:
	-rm -f prtest
