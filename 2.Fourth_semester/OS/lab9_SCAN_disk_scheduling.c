#include <stdio.h>
#include <stdlib.h>
// Function to calculate the total seek time using SCAN algorithm
int calculateSeekTimeSCAN(int requests[], int num_requests, int head, char direction) {
    int seek_count = 0;
    int current_track = head;
    int i, j;
    int min_track = 0;
    int max_track = 199;
    int found = 0;
    // Sort the requests in ascending order
    for (i = 0; i < num_requests - 1; i++) {
        for (j = 0; j < num_requests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    // SCAN algorithm for the right direction
    if (direction == 'r') {
        // Move right until the end of the disk
        for (i = 0; i < num_requests; i++) {
            if (requests[i] >= head) {
                found = 1;
                break;
            }
        }
        // Calculate seek time for right direction
        if (found == 1) {
            for (j = i; j < num_requests; j++) {
                seek_count += abs(requests[j] - current_track);
                current_track = requests[j];
            }
        }
        // Go to the end of the disk
        seek_count += abs(max_track - current_track);
        // Go back to the starting position
        current_track = max_track;

        // Continue moving left from the starting position
        for (j = num_requests - 1; j >= 0; j--) {
            seek_count += abs(requests[j] - current_track);
            current_track = requests[j];
        }
    }
    // SCAN algorithm for the left direction
    else if (direction == 'l') {
        // Move left until the start of the disk
        for (i = num_requests - 1; i >= 0; i--) {
            if (requests[i] <= head) {
                found = 1;
                break;
            }
        }
        // Calculate seek time for left direction
        if (found == 1) {
            for (j = i; j >= 0; j--) {
                seek_count += abs(requests[j] - current_track);
                current_track = requests[j];
            }
        }
        // Go to the beginning of the disk
        seek_count += abs(min_track - current_track);
        // Go back to the starting position
        current_track = min_track;
        // Continue moving right from the starting position
        for (j = 0; j < num_requests; j++) {
            seek_count += abs(requests[j] - current_track);
            current_track = requests[j];
        }
    }
    return seek_count;
}

int main() {
    int num_requests, head_position,i;
    char direction;
    // Getting the number of pending requests from the user
    printf("Enter the number of pending requests: ");
    scanf("%d", &num_requests);
    // Getting the pending requests from the user
    int requests[num_requests];
    printf("Enter the pending requests:\n");
    for (i = 0; i < num_requests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    // Getting the current head position from the user
    printf("Enter the current head position: ");
    scanf("%d", &head_position);

    // Getting the direction of movement from the user (r = right, l = left)
    printf("Enter the direction of movement (r for right, l for left): ");
    scanf(" %c", &direction);

    // Calculating the total seek time using SCAN algorithm
    int total_seek_time = calculateSeekTimeSCAN(requests, num_requests, head_position, direction);

    // Printing the total seek time
    printf("\nTotal Seek Time using SCAN: %d\n", total_seek_time);

    return 0;
}

