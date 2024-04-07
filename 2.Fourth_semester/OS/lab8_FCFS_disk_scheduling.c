#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total seek time using FCFS algorithm
int calculateSeekTimeFCFS(int requests[], int num_requests, int head) {
    int seek_count = 0;
    int current_track, distance,i;

    // Traverse the pending requests in the order they arrived
    for (i = 0; i < num_requests; i++) {
        current_track = requests[i];

        // Calculate seek time as the absolute difference between current head position and request
        distance = abs(head - current_track);

        // Increase the total seek time
        seek_count += distance;

        // Update the head position to the current request
        head = current_track;
    }

    return seek_count;
}

int main() {
    int num_requests, head_position;

    // Getting the number of pending requests from the user
    printf("Enter the number of pending requests: ");
    scanf("%d", &num_requests);

    // Getting the pending requests from the user
    int requests[num_requests],i;
    printf("Enter the pending requests:\n");
    for (i = 0; i < num_requests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    // Getting the current head position from the user
    printf("Enter the current head position: ");
    scanf("%d", &head_position);

    // Calculating the total seek time using FCFS algorithm
    int total_seek_time = calculateSeekTimeFCFS(requests, num_requests, head_position);

    // Printing the total seek time
    printf("\nTotal Seek Time using FCFS: %d\n", total_seek_time);

    return 0;
}

