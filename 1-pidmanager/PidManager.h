/**
 * Contains the necessary definitions and function prototypes for a PID manager,
 * including the appropriate access modifiers and documentation
 *
 * @file PidManager.h
 * @author Ricky Chon
 */

#include <array>
#include "PidConstants.h"

// Include guard to prevent multiple inclusions of this header file
// Include once, ignore all other inclusions
#ifndef PIDMANAGER_H
#define PIDMANAGER_H

/**
 * Manages the allocation and release of PIDs
 */
class PidManager
{
    private:
        /**
         * Bitmap representing the availability of PIDs
         *
         * A value of 0 at the index (PID) would indicate availability
         * A value of 1 at the index would indicate unavailability
         */
        std::array<int, MAX_PID - MIN_PID> pid_map;
    public:
        /**
         * Creates and initializes a data structure for representing PIDs
         *
         * @return -1 if unsuccessful, 1 if successful
         */
        int allocate_map();

        /**
         * Allocates and returns a PID
         *
         * @return the PID if successful,
         * -1 if unable to allocate a PID (all PIDs are in use)
         */
        int allocate_pid();

        /**
         * Releases a PID
         *
         * @param pid ID of the process to be released
         */
        void release_pid(int pid);
};

#endif /* PIDMANAGER_H */