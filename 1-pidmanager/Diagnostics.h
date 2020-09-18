/**
 * Contains the necessary definitions and function prototypes to output
 * test results for driver code
 *
 * @file Diagnostics.h
 * @author Ricky Chon
 */

#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

enum PidAction { MapAllocation, PidAllocation, PidRelease };

/**
 * Contains helper functions for driver code testing
 */
class Diagnostics
{
    public:
        /**
         * Outputs helpful success or failure messages based on the input
         *
         * @param action The action conducted, represented by enum
         * @param testValue The value to test for
         */
        void output_result(PidAction action, int testValue);
};

#endif /* DIAGNOSTICS_H */