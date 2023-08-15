#include <stdio.h>

// Number of processes and resources
#define N 5
#define M 3

// Function to find the need of each process
void calculateNeed(int need[N][M], int max[N][M], int allocation[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
}

// Banker's Algorithm
int isSafe(int processes[], int available[], int max[][M], int allocation[][M]) {
    int need[N][M];
    calculateNeed(need, max, allocation);

    int work[M];
    for (int i = 0; i < M; i++) {
        work[i] = available[i];
    }

    int finish[N] = {0};
    int safeSeq[N];
    int count = 0;

    while (count < N) {
        int found = 0;
        for (int i = 0; i < N; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < M; j++) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == M) {
                    for (int k = 0; k < M; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("System is not in safe state\n");
            return 0;
        }
    }

    printf("System is in safe state\nSafe sequence: ");
    for (int i = 0; i < N - 1; i++) {
        printf("P%d -> ", safeSeq[i]);
    }
    printf("P%d\n", safeSeq[N - 1]);
    return 1;
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int available[] = {3, 3, 2};
    int max[N][M] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };
    int allocation[N][M] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    isSafe(processes, available, max, allocation);

    return 0;
}

