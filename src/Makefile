#
# Makefile for rt-cpp
# Author: earacena
#

CXX    = g++
CFLAGS = -g -Wall -pedantic --std=c++17
INC    = -I
LIBS   = -L

OBJS   = main.cpp 
EXEC   = rt

all:
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS) $(INC)

run:
	./rt > image.ppm

clean:
	rm rt image.ppm
