# Instructions
Write a program that implements the following disk-scheduling algorithms:
- FCFS (First Come First Serve)
- SSTF (Shortest Seek Time First)
- SCAN (Elevator)
- C-SCAN (Circular SCAN)
- LOOK (Advanced Elevator)
- C-LOOK (Circular LOOK)

Your program will service a disk drive with 5,000 cylinders numbered 0 - 4,999.

The program will generate a random series of 1,000 requests and service them according to three of the algorithms listed above. The program will be passed the initial position of the disk head as a parameter on the command line and report the total amount of head movement by each algorithm.