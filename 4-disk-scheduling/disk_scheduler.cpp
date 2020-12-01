/**
 * Implementation for disk scheduler
 *
 * @file disk_scheduler.cpp
 * @author Ricky Chon
 */

#include <iostream>
#include <math.h>
#include <algorithm>

#include "disk_scheduler.h"

void DiskScheduler::fcfs(int head)
{
    int total_head_movement = 0;
    int distance, curr_track;

    for(int i = 0; i < NUM_REQUESTS; i++)
    {
        curr_track = requests[i];

        // Calculate absolute distance
        distance = abs(curr_track - head);

        // Increase total head movement
        total_head_movement += distance;

        // Accessed track is now new head
        head = curr_track;
    }

    printf("Total amount of head movement: %d\n", total_head_movement);

    if(requests.size() <= 25)
    {
        printf("Seek sequence is: ");

        // Seek sequence should be exactly the same as requests sequence
        for(auto req : requests)
            printf("%d ", req);
        printf("\n");
    }
}

void DiskScheduler::sstf(int head)
{
    int total_head_movement = 0;
    int curr_track;
    bool serviced[NUM_CYLINDERS];
    std::vector<int> seek_sequence;

    // Loop through all requests
    for(int i = 0; i < NUM_REQUESTS; i++)
    {
        // Index of the closest track
        int short_index = 0;
        // Distance of closest track
        int shortest_dist = NUM_CYLINDERS - 1;

        // Now find the request that has the shortest distance relative to head
        for(int j = 0; j < NUM_REQUESTS; j++)
        {
            if(abs(head - requests[j]) < shortest_dist && !serviced[j])
            {
                short_index = j;
                shortest_dist = abs(head - requests[j]);
            }
        }

        // Now we can flag the index of track as serviced
        serviced[short_index] = true;
        curr_track = requests[short_index];

        // Append current track to seek sequence
        seek_sequence.push_back(curr_track);

        // Increase total head movement
        total_head_movement += shortest_dist;

        // Accessed track is now new head
        head = curr_track;
    }

    printf("Total amount of head movement: %d\n", total_head_movement);

    if(requests.size() <= 25)
    {
        printf("Seek sequence is: ");

        for(auto req : seek_sequence)
            printf("%d ", req);
        printf("\n");
    }
}

void DiskScheduler::scan(int head)
{
    int total_head_movement = 0;
    int distance, curr_track;
    std::string direction = "left";
    std::vector<int> left_vals, right_vals;
    std::vector<int> seek_sequence;

    // Append end values to be visited before reversing direction
    if(direction == "left") left_vals.push_back(0);
    else if(direction == "right") right_vals.push_back(NUM_CYLINDERS - 1);

    for(int i = 0; i < NUM_REQUESTS; i++)
    {
        if(requests[i] < head) left_vals.push_back(requests[i]);
        if(requests[i] > head) right_vals.push_back(requests[i]);
    }

    // Sort left and right vectors
    std::sort(left_vals.begin(), left_vals.end());
    std::sort(right_vals.begin(), right_vals.end());

    // Run loop twice, once for left and once for right
    // For this program both iterations will be enough to service all requests
    int run = 2;
    while(run--)
    {
        if(direction == "left")
        {
            for(int i = left_vals.size() - 1; i >= 0; i--)
            {
                curr_track = left_vals[i];

                // Append current track to seek sequence
                seek_sequence.push_back(curr_track);

                // Calculate absolute distance
                distance = abs(curr_track - head);

                // Increase total head movement
                total_head_movement += distance;

                // Accessed track is now new head
                head = curr_track;
            }
            direction = "right";
        }
        else if(direction == "right")
        {
            for(int i = 0; i < right_vals.size(); i++)
            {
                curr_track = right_vals[i];

                // Append current track to seek sequence
                seek_sequence.push_back(curr_track);

                // Calculate absolute distance
                distance = abs(curr_track - head);

                // Increase total head movement
                total_head_movement += distance;

                // Accessed track is now new head
                head = curr_track;
            }
            direction = "left";
        }
    }

    printf("Total amount of head movement: %d\n", total_head_movement);

    if(requests.size() <= 25)
    {
        printf("Seek sequence is: ");

        for(auto req : seek_sequence)
            printf("%d ", req);
        printf("\n");
    }
}

void DiskScheduler::cscan(int head)
{
    int total_head_movement = 0;
    int distance, curr_track;
    std::vector<int> left_vals, right_vals;
    std::vector<int> seek_sequence;

    // Append end values to be visited before reversing direction
    left_vals.push_back(0);
    right_vals.push_back(NUM_CYLINDERS - 1);

    for(int i = 0; i < NUM_REQUESTS; i++)
    {
        if(requests[i] < head) left_vals.push_back(requests[i]);
        if(requests[i] > head) right_vals.push_back(requests[i]);
    }

    // Sort left and right vectors
    std::sort(left_vals.begin(), left_vals.end());
    std::sort(right_vals.begin(), right_vals.end());

    // Service the requests to the right of head
    for(int i = 0; i < right_vals.size(); i++)
    {
        curr_track = right_vals[i];

        // Append current track to seek sequence
        seek_sequence.push_back(curr_track);

        // Calculate absolute distance
        distance = abs(curr_track - head);

        // Increase total head movement
        total_head_movement += distance;

        // Accessed track is now new head
        head = curr_track;
    }

    // Jump to the beginning
    head = 0;

    // Service the requests to the left of head
    for(int i = 0; i < left_vals.size(); i++)
    {
        curr_track = left_vals[i];

        // Append current track to seek sequence
        seek_sequence.push_back(curr_track);

        // Calculate absolute distance
        distance = abs(curr_track - head);

        // Increase total head movement
        total_head_movement += distance;

        // Accessed track is now new head
        head = curr_track;
    }

    printf("Total amount of head movement: %d\n", total_head_movement);

    if(requests.size() <= 25)
    {
        printf("Seek sequence is: ");

        for(auto req : seek_sequence)
            printf("%d ", req);
        printf("\n");
    }
}

void DiskScheduler::look(int head)
{
    int total_head_movement = 0;
    int distance, curr_track;
    std::string direction = "left";
    std::vector<int> left_vals, right_vals;
    std::vector<int> seek_sequence;

    for(int i = 0; i < NUM_REQUESTS; i++)
    {
        if(requests[i] < head) left_vals.push_back(requests[i]);
        if(requests[i] > head) right_vals.push_back(requests[i]);
    }

    // Sort left and right vectors
    std::sort(left_vals.begin(), left_vals.end());
    std::sort(right_vals.begin(), right_vals.end());

    // Run loop twice, once for left and once for right
    // For this program both iterations will be enough to service all requests
    int run = 2;
    while(run--)
    {
        if(direction == "left")
        {
            for(int i = left_vals.size() - 1; i >= 0; i--)
            {
                curr_track = left_vals[i];

                // Append current track to seek sequence
                seek_sequence.push_back(curr_track);

                // Calculate absolute distance
                distance = abs(curr_track - head);

                // Increase total head movement
                total_head_movement += distance;

                // Accessed track is now new head
                head = curr_track;
            }
            direction = "right";
        }
        else if(direction == "right")
        {
            for(int i = 0; i < right_vals.size(); i++)
            {
                curr_track = right_vals[i];

                // Append current track to seek sequence
                seek_sequence.push_back(curr_track);

                // Calculate absolute distance
                distance = abs(curr_track - head);

                // Increase total head movement
                total_head_movement += distance;

                // Accessed track is now new head
                head = curr_track;
            }
            direction = "left";
        }
    }

    printf("Total amount of head movement: %d\n", total_head_movement);

    if(requests.size() <= 25)
    {
        printf("Seek sequence is: ");

        for(auto req : seek_sequence)
            printf("%d ", req);
        printf("\n");
    }
}

void DiskScheduler::clook(int head)
{
    int total_head_movement = 0;
    int distance, curr_track;
    std::vector<int> left_vals, right_vals;
    std::vector<int> seek_sequence;

    for(int i = 0; i < NUM_REQUESTS; i++)
    {
        if(requests[i] < head) left_vals.push_back(requests[i]);
        if(requests[i] > head) right_vals.push_back(requests[i]);
    }

    // Sort left and right vectors
    std::sort(left_vals.begin(), left_vals.end());
    std::sort(right_vals.begin(), right_vals.end());

    // Service the requests to the right of head
    for(int i = 0; i < right_vals.size(); i++)
    {
        curr_track = right_vals[i];

        // Append current track to seek sequence
        seek_sequence.push_back(curr_track);

        // Calculate absolute distance
        distance = abs(curr_track - head);

        // Increase total head movement
        total_head_movement += distance;

        // Accessed track is now new head
        head = curr_track;
    }

    // Jump to the first request of left_vals
    total_head_movement += abs(head - left_vals[0]);
    head = left_vals[0];

    // Service the requests to the left of head
    for(int i = 0; i < left_vals.size(); i++)
    {
        curr_track = left_vals[i];

        // Append current track to seek sequence
        seek_sequence.push_back(curr_track);

        // Calculate absolute distance
        distance = abs(curr_track - head);

        // Increase total head movement
        total_head_movement += distance;

        // Accessed track is now new head
        head = curr_track;
    }

    printf("Total amount of head movement: %d\n", total_head_movement);

    if(requests.size() <= 25)
    {
        printf("Seek sequence is: ");

        for(auto req : seek_sequence)
            printf("%d ", req);
        printf("\n");
    }
}