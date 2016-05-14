#!/bin/bash

# Austin Chen (azc2rc) 4/28/2016
# Makefile

CXX=clang++
CXXFLAGS=-Wall -g

OFILES=graph.o edge.o student.o swapper.o maxFlowFinder.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~

edge.o: edge.cpp edge.h
graph.o: graph.cpp graph.h edge.h
maxFlowFinder.o: maxFlowFinder.cpp maxFlowFinder.h graph.h edge.h
student.o: student.cpp student.h
swapper.o: swapper.cpp student.h graph.h edge.h maxFlowFinder.h
