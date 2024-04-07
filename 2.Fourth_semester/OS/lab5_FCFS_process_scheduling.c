#include <stdio.h>

// Function to calculate average turnaround time and waiting time for FCFS scheduling algorithm
void calculateAverageTimes(int burst_time[], int num_processes) {
    int waiting_time[num_processes], turnaround_time[num_processes],i;
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Waiting time for the first process is always 0
    waiting_time[0] = 0;

    // Calculate waiting time for each process
    for (i = 1; i < num_processes; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        total_waiting_time += waiting_time[i];
    }

    // Calculate turnaround time for each process
    for (i = 0; i < num_processes; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
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
    int num_processes,i;
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
    // Calculating and printing average waiting time and average turnaround time
    calculateAverageTimes(burst_time, num_processes);
    return 0;
}

