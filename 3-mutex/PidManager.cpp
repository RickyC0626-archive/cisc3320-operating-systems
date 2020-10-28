/**
 * Contains implementations for the PID manager functions
 *
 * @file PidManager.cpp
 * @author Ricky Chon
 */

#include "PidManager.h"

int PidManager::allocate_map()
{
    // Populate the array with initial values of 0 to make all PIDs available
    for(int i = 0; i < pid_map.size(); i++)
    {
        pid_map[i] = 0;

        // If we've reached the end of the array and there were
        // no failures until this point, we can return 1 for success
        if(i == pid_map.size() - 1) return 1;
    }
    return -1;
}

int PidManager::allocate_pid()
{
    // Allocate a PID to the first vacant spot
    for(int i = 0; i < pid_map.size(); i++)
    {
        if(pid_map[i] == 0)
        {
            mtx.lock();
            pid_map[i] = 1;
            mtx.unlock();
            return i + MIN_PID;
        }
    }
    return -1;
}

void PidManager::release_pid(int pid)
{
    if(pid >= MIN_PID && pid <= MAX_PID)
    {
        mtx.lock();
        pid_map[pid - MIN_PID] = 0;
        mtx.unlock();
    }
}