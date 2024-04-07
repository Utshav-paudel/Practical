#include <stdio.h>

// Function to calculate average turnaround time and waiting time for SJF scheduling algorithm
void calculateAverageTimes(int burst_time[], int num_processes) {
    int waiting_time[num_processes], turnaround_time[num_processes], completion_time[num_processes],i;
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Calculate completion time for each process
    completion_time[0] = burst_time[0];
    for (i = 1; i < num_processes; i++) {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
    }

    // Calculate waiting time for each process
    for (i = 0; i < num_processes; i++) {
        waiting_time[i] = completion_time[i] - burst_time[i];
        total_waiting_time += waiting_time[i];
    }

    // Calculate turnaround time for each process
    for (i = 0; i < num_processes; i++) {
        turnaround_time[i] = completion_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = total_waiting_time / num_processes;
    float avg_turnaround_time = total_turnaround_time / num_processes;

    // Print the results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int num_processes,i,j;

    // Getting the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    int burst_time[num_processes];
    // Getting burst times for each process from the user
    printf("Enter burst time for each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Sorting burst times in ascending order using bubble sort
    for (i = 0; i < num_processes - 1; i++) {
        for (j = 0; j < num_processes - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                // Swap burst times
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
            }
        }
    }
    // Calculating and printing average waiting time and average turnaround time
    calculateAverageTimes(burst_time, num_processes);

    return 0;
}

