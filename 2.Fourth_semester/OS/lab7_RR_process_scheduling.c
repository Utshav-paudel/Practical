#include <stdio.h>

#define MAX_PROCESSES 10

// Function to simulate the Round Robin (RR) process scheduling algorithm
void roundRobin(int burst_time[], int num_processes, int time_quantum) {
    int remaining_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES] = {0};
    int turnaround_time[MAX_PROCESSES] = {0};
    int i,j;
    // Initialize remaining time with burst times
    for ( i = 0; i < num_processes; i++) {
        remaining_time[i] = burst_time[i];
    }

    int current_time = 0; // Current time in the simulation
    int completed_processes = 0; // Number of completed processes

    // Simulate RR scheduling until all processes are completed
    while (completed_processes < num_processes) {
        // Traverse each process in a round-robin manner
        for ( i = 0; i < num_processes; i++) {
            if (remaining_time[i] > 0) {
                // Execute the process for the time quantum or remaining time, whichever is smaller
                int execution_time = (remaining_time[i] < time_quantum) ? remaining_time[i] : time_quantum;

                // Update current time and remaining time for the process
                current_time += execution_time;
                remaining_time[i] -= execution_time;

                // Update waiting time for other processes
                for (j = 0; j < num_processes; j++) {
                    if (j != i && remaining_time[j] > 0) {
                        waiting_time[j] += execution_time;
                    }
                }

                // If process is completed, calculate turnaround time
                if (remaining_time[i] == 0) {
                    turnaround_time[i] = current_time;
                    completed_processes++;
                }
            }
        }
    }

    // Calculate total waiting time and turnaround time
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (i = 0; i < num_processes; i++) {
        total_waiting_time += waiting_time[i];
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
    int num_processes, time_quantum,i;

    // Getting the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Getting the burst times for each process from the user
    int burst_time[MAX_PROCESSES];
    printf("Enter burst time for each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Getting the time quantum from the user
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    // Calling the Round Robin function to simulate the algorithm and calculate average turnaround time and waiting time
    roundRobin(burst_time, num_processes, time_quantum);

    return 0;
}

