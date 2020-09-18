# Makefile for PidManager program
# Author: Ricky Chon

# Installation:
# - Run `make` or `make pidmang`
# - Clean object files with `make clean`
# - Clean object files and executable with `make clean-full`
# - Run executable `./pidmang`

# Implicit Variables:
# CXX variable defaults to g++ for C++ compilation
# CC variable defaults to cc for C compilation,
# but can be configured for other scripts like g++
# Example: CC = g++

# Target: pidmang
# Prereqs: main.o and PidManager.o
# Recipe: run linker on objects and create pidmang executable
pidmang: main.o PidManager.o
	$(CXX) -o pidmang main.o PidManager.o

# Target: main.o
# Prereqs: main.cpp and PidManager.h
# Recipe: compile main.cpp but don't run linker yet
main.o: main.cpp PidManager.h
	$(CXX) -c main.cpp

# Target: PidManager.o
# Prereqs: PidManager.cpp and PidManager.h
# Recipe: compile PidManager.cpp but don't run linker yet
PidManager.o: PidManager.cpp PidManager.h
	$(CXX) -c PidManager.cpp

# Cleans up object files
clean:
	rm *.o

# Cleans up all objects files and executable
clean-full:
	rm *.o pidmang