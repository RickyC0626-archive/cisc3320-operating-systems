# Makefile for Disk Scheduling Program
# Author: Ricky Chon

# ds for Disk Scheduler
ds: main.o ds.o
	$(CXX) -o ds main.o disk_scheduler.o

main.o: main.cpp disk_scheduler.h disk_attributes.h
	$(CXX) -c main.cpp

ds.o: disk_scheduler.cpp disk_scheduler.h
	$(CXX) -c disk_scheduler.cpp

clean:
	rm *.o

clean-all:
	rm *.o ds