#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Function to compare jobs based on profit (used for sorting)
int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

// Function to find the maximum profit job sequence
void findMaxProfitJobSequence(struct Job jobs[], int n) {
    // Sort the jobs based on profit (in non-increasing order)
    qsort(jobs, n, sizeof(struct Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Create an array to store the scheduled jobs
    int* schedule = (int*)malloc(maxDeadline * sizeof(int));

    // Initialize the schedule array with -1 to represent empty slots
    for (int i = 0; i < maxDeadline; i++) {
        schedule[i] = -1;
    }

    // Fill the schedule array with jobs
    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline;
        // Find the latest available slot before the deadline
        while (deadline > 0 && schedule[deadline - 1] != -1) {
            deadline--;
        }
        // If a slot is available before the deadline, assign the job to it
        if (deadline > 0) {
            schedule[deadline - 1] = jobs[i].id;
            maxProfit += jobs[i].profit;
        }
    }

    // Print the scheduled job sequence and maximum profit
    printf("Scheduled Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (schedule[i] != -1) {
            printf("%d ", schedule[i]);
        }
    }
    printf("\nMaximum Profit: %d\n", maxProfit);

    free(schedule);
}

int main() {
    // Example usage
    struct Job jobs[] = {
        {1, 2, 20},
        {2, 2, 15},
        {3, 1, 10},
        {4, 3, 5},
        {5, 3, 1}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    findMaxProfitJobSequence(jobs, n);

    return 0;
}
