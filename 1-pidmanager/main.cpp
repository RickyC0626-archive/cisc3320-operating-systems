/**
 * Driver to test PidManager functionalities
 *
 * @file main.cpp
 * @author Ricky Chon
 */

#include "PidManager.h"
#include "Diagnostics.h"

void success_all();

Diagnostics d;

int main()
{
    success_all();

    return 0;
}

void success_all()
{
    PidManager manager;

    printf("Test Successful Routes\n====================\n");

    printf("\nAllocate map for use\n");
    d.output_result(PidAction::MapAllocation, manager.allocate_map());

    printf("\nAllocate a PID to be used\n");
    int PID = manager.allocate_pid();
    d.output_result(PidAction::PidAllocation, PID);

    printf("\nRelease the first PID\n");
    manager.release_pid(PID);
    d.output_result(PidAction::PidRelease, PID);

    // Allocate PID 4000 times
    for(int i = 0; i < 4000; i++)
    {
        manager.allocate_pid();
    }

    printf("\nRelease PID 3456\n");
    manager.release_pid(3456);
    d.output_result(PidAction::PidRelease, 3456);

    printf("\nAllocate a PID again to fill up the first vacant spot\n");
    int PID3 = manager.allocate_pid();
    d.output_result(PidAction::PidAllocation, PID3);
}