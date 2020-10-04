/**
 * Driver to test PidManager functionalities
 *
 * @file main.cpp
 * @author Ricky Chon
 */

#include <iostream>
#include "PidManager.h"
#include "Diagnostics.h"

void success_all();
void fail_pid_allocate();
void fail_pid_release();
void multithread_test();

Diagnostics d;

int main()
{
    int choice;

    printf("0. Test all successful\n");
    printf("1. Test failed PID allocation\n");
    printf("2. Test failed PID release\n");
    printf("3. Test multi-threading support\n");
    printf("Pick a test to run: ");
    std::cin >> choice;

    switch(choice)
    {
        case 0:
            success_all();
            break;
        case 1:
            fail_pid_allocate();
            break;
        case 2:
            fail_pid_release();
            break;
        case 3:
            multithread_test();
            break;
        default:
            break;
    }

    return 0;
}

void success_all()
{
    PidManager manager;

    printf("\n====================\nTest Successful Routes\n====================\n");

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

void fail_pid_allocate()
{
    PidManager manager;

    printf("\n====================\nFailed PID Allocation\n====================\n");

    printf("\nAllocate map for use\n");
    d.output_result(PidAction::MapAllocation, manager.allocate_map());

    // Allocate PID 4699 times
    for(int i = 0; i < 4699; i++)
    {
        manager.allocate_pid();
    }

    printf("\nAllocate the final PID\n");
    int PID = manager.allocate_pid();
    d.output_result(PidAction::PidAllocation, PID);

    printf("\nTry to allocate a PID again\n");
    int PID2 = manager.allocate_pid();
    d.output_result(PidAction::PidAllocation, PID2);
}

void fail_pid_release()
{
    PidManager manager;

    printf("\n====================\nFailed PID Release\n====================\n");

    printf("\nAllocate map for use\n");
    d.output_result(PidAction::MapAllocation, manager.allocate_map());

    printf("\nTry to release a PID that is out of range\n");
    manager.release_pid(7500);
    d.output_result(PidAction::PidRelease, 7500);
}

void multithread_test()
{

}