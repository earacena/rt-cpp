#
# Makefile for rt-cpp
# Author: earacena
#

CXX    = g++
CFLAGS = -g -Wall -pedantic --std=c++17
INC    = -I
LIBS   = -L

OBJS   = src/main.cpp src/Sphere.cpp src/HittableList.cpp 
EXEC   = rt

all:
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS) $(INC)

run:
	./rt 1600 16 9 > image.ppm

clean:
	rm rt image.ppm
