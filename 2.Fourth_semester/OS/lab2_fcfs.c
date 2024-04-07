#include <stdio.h>

// Function to implement First Come First Serve (FCFS) page replacement algorithm
int fcfs(int page_requests[], int num_requests, int frame_size) {
	int page_faults = 0;
    	int frames[frame_size];
	int i, j, k;

   	 // Initializing frames with -1 indicating an empty frame
   	 for (i = 0; i < frame_size; i++)
        		frames[i] = -1;

	 j = 0;

    	// Iterating over each page request
    	for (i = 0; i < num_requests; i++) {
        		int page = page_requests[i];
        		int found = 0;

        		// Checking if the page is already present in any of the frames
        		for (k = 0; k < frame_size; k++) {
            			if (frames[k] == page) {
                			found = 1;
                			break;
            			}
        		}

        		// If the page is not found in any frame, it's a page fault
        		if (!found) {
            			page_faults++;
            			frames[j] = page; // Replace the page at the current frame position
            			j = (j + 1) % frame_size; // Increment the frame position using circular fashion
        		}
    	}

    	return page_faults; // Return the total number of page faults
}

int main() {
    	int frame_size, num_requests,i;

    	// Asking the user to input the frame size
    	printf("Enter the frame size: ");
    	scanf("%d", &frame_size);

    	// Asking the user to input the number of page requests
    	printf("Enter the number of page requests: ");
    	scanf("%d", &num_requests);

    	int page_requests[num_requests];
    
    	// Asking the user to input each page request individually
    	printf("Enter the page requests:\n");
    	for (i = 0; i < num_requests; i++) {
    		scanf("%d", &page_requests[i]);
    	}

    	// Calling the FCFS function and printing the total number of page faults
    	printf("Total page faults using FCFS: %d\n", fcfs(page_requests, num_requests, frame_size));

    	return 0;
}

