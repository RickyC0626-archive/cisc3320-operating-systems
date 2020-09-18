/**
 * Driver to test PidManager functionalities
 *
 * @file main.cpp
 * @author Ricky Chon
 */

#include "PidManager.h"
#include "Diagnostics.h"

Diagnostics d;
PidManager manager;

int main()
{
    printf("Allocate map for use\n");
    d.output_result(PidAction::MapAllocation, manager.allocate_map());

    printf("\nAllocate a PID to be used\n");
    int PID = manager.allocate_pid();
    d.output_result(PidAction::PidAllocation, PID);

    printf("\nRelease a PID\n");
    manager.release_pid(PID);
    d.output_result(PidAction::PidRelease, PID);

    return 0;
}