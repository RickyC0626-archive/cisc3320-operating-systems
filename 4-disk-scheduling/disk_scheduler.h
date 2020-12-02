/**
 * Disk scheduling algorithms
 * - FCFS (First Come First Serve)
 * - SSTF (Shortest Seek Time First)
 * - SCAN (Elevator)
 * - C-SCAN (Circular SCAN)
 * - LOOK (Advanced Elevator)
 * - C-Look (Circular LOOK)
 *
 * @file disk_scheduler.h
 * @author Ricky Chon
 */

#include <vector>

#include "disk_attributes.h"

#ifndef DISK_SCHEDULER_H
#define DISK_SCHEDULER_H

class DiskScheduler
{
    private:
        /**
         * Requests of tracks to be serviced
         */
        std::vector<int> requests;

        /**
         * Populates requests vector with random requests
         */
        void genRandRequests(std::vector<int> &requests)
        {
            for(int i = 0; i < NUM_REQUESTS; i++)
            {
                requests.push_back(rand() % NUM_CYLINDERS);
            }
        }
    public:
        DiskScheduler() { genRandRequests(requests); }

        /**
         * @brief First Come First Serve: simplest of all disk scheduling algorithms.
         * Requests are addressed in the order they arrive in the disk queue.
         *
         * @param head Initial position of disk head
         */
        void fcfs(int head);

        /**
         * @brief Shortest Seek Time First: the tracks closest to the current disk
         * head position are serviced first in order to minimize seek operations
         *
         * @param head Initial position of disk head
         */
        void sstf(int head);

        /**
         * @brief Elevator algorithm: head starts from one end of the disk and
         * moves towards the other end, servicing requests in between one by one
         * until head reaches the end. Then, the direction of the head is reversed
         * and the process continues as head continuously scans back and forth
         * across the disk.
         *
         * @param head Initial position of disk head
         */
        void scan(int head);

        /**
         * @brief Circular SCAN: head starts from one end of the disk and move
         * towards other end. Unlike SCAN, C-SCAN doesn't reverse the head direction,
         * but goes to the other end of the disk and starts servicing the requests
         * from there.
         *
         * @param head Initial position of disk head
         */
        void cscan(int head);

        /**
         * @brief Advanced elevator: services requests similar to SCAN, but it
         * also looks ahead to see if there are more tracks that need to be serviced.
         * If there are no pending requests in the moving direction, the head
         * reverses the direction and starts servicing requests in the opposite direction.
         *
         * Prevents unnecessary traversal to end of disk.
         * 
         * @param head Initial position of disk head
         */
        void look(int head);

        /**
         * @brief Circular LOOK: a combination of CSCAN and LOOK. Prevents unneccesary
         * traversal to both ends of disk if there are no requests; the head will
         * jump to the other end of disk if it reaches the final request in one direction.
         *
         * @param head Initial position of disk head
         */
        void clook(int head);
};

#endif /* DISK_SCHEDULER_H */