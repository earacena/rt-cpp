#
# Makefile for rt-cpp
# Author: earacena
#

CXX    = g++
CFLAGS = -g -Wall -pedantic --std=c++17
INC    = -I
LIBS   = -L

OBJS   = src/main.cpp 
EXEC   = rt

all:
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS) $(INC)

run:
	./rt 1000 1000 > image.ppm

clean:
	rm rt image.ppm
