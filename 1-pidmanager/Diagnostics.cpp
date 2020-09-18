/**
 * Contains implementations for the Diagnostics functions
 *
 * @file Diagnostics.cpp
 * @author Ricky Chon
 */

#include <cstdlib>
#include "Diagnostics.h"
#include "PidConstants.h"

void Diagnostics::output_result(PidAction action, int testValue)
{
    switch(action)
    {
        case MapAllocation:
            if(testValue == -1)
            {
                printf("Unsuccessful PID map allocation\n");
                exit(1);
            }
            printf("PID map allocated successfully\n");
            break;
        case PidAllocation:
            if(testValue == -1)
            {
                printf("Unsuccessful PID allocation\n");
                exit(1);
            }
            printf("PID %d allocated successfully\n", testValue);
            break;
        case PidRelease:
            if(testValue < MIN_PID || testValue > MAX_PID)
            {
                printf("PID %d is out of range\n", testValue);
                exit(1);
            }
            printf("PID %d released\n", testValue);
            break;
        default:
            printf("Invalid Action\n");
            break;
    }
}