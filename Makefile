#
# Makefile for rt-cpp
# Author: earacena
#

CXX    = g++
CFLAGS = -g -Wall -pedantic --std=c++17 -pthread
INC    = -I
LIBS   = -L
LINK	 = 

OBJS   = src/main.cpp src/Sphere.cpp src/HittableList.cpp src/Vec3.cpp 
EXEC   = rt

all:
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS) $(LINK) $(INC) $(CFLAGS)

run:
	./rt 1600 16 9 12 4 > image.ppm

clean:
	rm rt image.ppm
