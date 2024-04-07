#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory using Worst Fit strategy
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int i, j;

    // Initialize all allocations to -1, indicating no allocation
    for (i = 0; i < n; i++)
        allocation[i] = -1;

    // Iterate through each process
    for (i = 0; i < n; i++) {
        // Find the worst fit block for the current process
        int worstFitIdx = -1;
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstFitIdx == -1 || blockSize[j] > blockSize[worstFitIdx])
                    worstFitIdx = j;
            }
        }

        // Allocate the current process to the worst fit block if found
        if (worstFitIdx != -1) {
            allocation[i] = worstFitIdx;
            blockSize[worstFitIdx] -= processSize[i];
        }
    }

    // Print the allocation details
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int m, n,i; // Number of memory blocks and processes
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int blockSize[m], processSize[n]; // Arrays to store memory block sizes and process sizes
    printf("Enter the size of memory blocks:\n");
    for (i = 0; i < m; i++) {
        printf("Memory Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the size of processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    worstFit(blockSize, m, processSize, n); // Call the Worst Fit function
    return 0;
}

