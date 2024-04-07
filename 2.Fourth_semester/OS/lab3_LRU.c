#include <stdio.h>
#include <limits.h>

// Function to find the index of the least recently used page in frames
int findLRUIndex(int frames[], int num_frames, int last_used[]) {
    int min_index = 0;
    int min_value = INT_MAX,i;
    for (i = 0; i < num_frames; i++) {
        if (last_used[i] < min_value) {
            min_value = last_used[i];
            min_index = i;
        }
    }
    return min_index;
}
// Function to simulate the LRU (Least Recently Used) page replacement algorithm
int lru(int page_requests[], int num_requests, int frame_size) {
    int page_faults = 0;
    int frames[frame_size];
    int last_used[frame_size];
    int i;
    // Initialize frames with -1 indicating an empty frame
    for ( i = 0; i < frame_size; i++) {
        frames[i] = -1;
        last_used[i] = INT_MAX; // Initialize last used time to infinity
    }
    // Iterate over each page request
    for ( i = 0; i < num_requests; i++) {
        int page = page_requests[i];
        int found = 0;
        int j;
        // Check if the page is already present in any of the frames
        for ( j = 0; j < frame_size; j++) {
            if (frames[j] == page) {
                found = 1;
                last_used[j] = i; // Update the last used time for the page
                break;
            }
        }

        // If the page is not found in any frame, it's a page fault
        if (!found) {
            page_faults++;
            int lru_index = findLRUIndex(frames, frame_size, last_used);
            frames[lru_index] = page; // Replace the least recently used page
            last_used[lru_index] = i; // Update the last used time for the page
        }
    }
    return page_faults; // Return the total number of page faults
}

int main() {
    int frame_size, num_requests,i,j;
    // Asking the user to input the frame size
    printf("Enter the frame size: ");
    scanf("%d", &frame_size);
    // Asking the user to input the number of page requests
    printf("Enter the number of page requests: ");
    scanf("%d", &num_requests);
    int page_requests[num_requests];
    // Asking the user to input each page request individually
    printf("Enter the page requests:\n");
    for ( i = 0; i < num_requests; i++) {
        scanf("%d", &page_requests[i]);
    }
    // Calling the LRU function and printing the total number of page faults
    printf("Total page faults using LRU: %d\n", lru(page_requests, num_requests, frame_size));
    return 0;
}

