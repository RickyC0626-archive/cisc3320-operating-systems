#include <iostream>

#include "disk_scheduler.h"

int main(int argc, char *argv[])
{
    int head = NUM_CYLINDERS / 2;

    try
    {
        if(argc > 2) throw std::string("Usage: ") + argv[0] + " [head]";
        if(argc == 2) head = std::stoi(argv[1]);

        DiskScheduler ds;
        int choice;

        printf("1. FCFS (First Come First Serve)\n");
        printf("2. SSTF (Shortest Seek Time First)\n");
        printf("3. SCAN (Elevator)\n");
        printf("4. C-SCAN (Circular Scan)\n");
        printf("5. LOOK (Advanced Elevator)\n");
        printf("6. C-LOOK (Circular LOOK)\n");
        printf("Pick a disk scheduling algorithm: ");
        std::cin >> choice;

        printf("\nHead: %d\n", head);
        printf("%d initial requests\n", NUM_REQUESTS);

        switch(choice)
        {
            case 1:
                printf("\nFCFS (First Come First Serve)\n=========================\n");
                ds.fcfs(head);
                break;
            case 2:
                printf("\nSSTF (Shortest Seek Time First)\n=========================\n");
                ds.sstf(head);
                break;
            case 3:
                printf("\nSCAN (Elevator)\n=========================\n");
                ds.scan(head);
                break;
            case 4:
                printf("\nC-SCAN (Circular SCAN)\n=========================\n");
                ds.cscan(head);
                break;
            case 5:
                printf("\nLOOK (Advanced Elevator)\n=========================\n");
                ds.look(head);
                break;
            case 6:
                printf("\nC-LOOK (Circular LOOK)\n=========================\n");
                ds.clook(head);
                break;
            default:
                break;
        }

        return 0;
    }
    catch(std::string message)
    {
        std::cerr << message << '\n';
    }
}