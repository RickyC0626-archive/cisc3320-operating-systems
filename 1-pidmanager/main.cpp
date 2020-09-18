/**
 * Driver to test PidManager functionalities
 *
 * @file main.cpp
 * @author Ricky Chon
 */

#include <cstdlib>
#include "PidManager.h"

PidManager manager;

int main()
{
    printf("Allocate map for use\n");
    int mapSuccess = manager.allocate_map();

    if(mapSuccess == -1)
    {
        printf("Unsuccessful PID map allocation\n");
        exit(1);
    }
    else printf("PID map allocated successfully\n");

    printf("\nAllocate a PID to be used\n");
    int PID = manager.allocate_pid();

    if(PID == -1)
    {
        printf("Unsuccessful PID allocation\n");
        exit(1);
    }
    else printf("PID %d allocated successfully\n", PID);

    printf("\nRelease a PID\n");
    manager.release_pid(PID);

    printf("PID %d released\n", PID);

    return 0;
}