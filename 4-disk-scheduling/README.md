# Disk Scheduling
Disk scheduling is done by operating systems to schedule I/O requests arriving for the disk.

**Importance of disk scheduling:**
- Multiple I/O requests may arrive by different processes and only one I/O request can be served at a time by the disk controller. Thus other I/O requests need to wait in the waiting queue and need to be scheduled.
- Two or more requests may be far from each other and can result in greater disk arm movement.
- Hard drives are one of the slowest parts of the computer system and thus need to be accessed in an efficient manner.

## Installation
- Run `make` or `make ds`
- Run executable `./ds [head]`
    - Default head value: `NUM_CYLINDERS / 2`
- Remove object files with `make clean`
- Remove object files and executable with `make clean-all`

## Some Disk Scheduling Algorithms
- [FCFS (First Come First Serve)](#fcfs-first-come-first-serve)
- [SSTF (Shortest Seek Time First)](#sstf-shortest-seek-time-first)
- [SCAN (Elevator)](#scan-elevator)
- [C-SCAN (Circular SCAN)](#c-scan-circular-scan)
- [LOOK (Advanced Elevator)](#look-advanced-elevator)
- [C-LOOK (Circular LOOK)](#c-look-circular-look)

### FCFS (First Come First Serve)
Simplest of all disk scheduling algorithms. Requests are addressed in the order they arrive in the disk queue.

**Advantages:**
- Every request gets a fair chance
- No indefinite postponement

**Disadvantages:**
- Does not try to optimize seek time
- May not provide the best possible service

### SSTF (Shortest Seek Time First)
The tracks which are closer to the current disk head position should be serviced first in order to *minimize the seek operations*.

**Advantages:**
- Average reponse time decreases
- Throughput increases

**Disadvantages:**
- Overhead to calculate seek time in advance
- Can cause starvation for a request if it has higher seek time as compared to incoming requests
- High variance of response time as SSTF favors only some requests

### SCAN (Elevator)
Head starts from one end of the disk and moves towards the other end, servicing requests in between one by one and reach the other end. Then the direction of the head is reversed and the process continues as head continously scan back and forth to access the disk. So, this algorithm works as an elevator and hence is known as the **elevator algorithm**. As a result, the requests at midrange are serviced more frequently and those arrive behind the disk arm will have to wait.

**Advantages:**
- High throughput
- Low variance of response time
- Average response time

**Disadvantages:**
- Long waiting time for requests at locations just visited by disk arm

### C-SCAN (Circular SCAN)
In SCAN, the disk arm scans the path that has already been scanned, after reversing its direction. So, it may be possible that too many requests are waiting at the other end, or there may be zero or few requests pending at the scanned area.

Instead of reversing the disk arm direction, C-SCAN goes to the other end of the disk and starts servicing the requests from there. So, the disk arm moves in a circular fashion.

**Advantages:**
- Provides more uniform wait time compared to SCAN

### LOOK (Advanced Elevator)
LOOK is an advanced version of SCAN. It services requests similarly to the SCAN algorithm, while it also "looks" ahead to see if there are more tracks that need to be serviced. If there are no pending requests in the moving direction, the head reverses the direction and starts servicing requests in the opposite direction.

**Advantages:**
- Better seek time than the other algorithms above

### C-LOOK (Circular LOOK)
C-LOOK is an enhanced version of SCAN and LOOK. The head services requests only in one direction until all requests in this direction have been serviced, then jumps back to the farthest request in the other direction and service the remaining requests.

**Advantages:**
- Avoids wasting seek time by not going to the end of disk
- Provides uniform servicing