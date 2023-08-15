#include <stdio.h>


void read(int np, int nr, int a[np][nr], const char *var) {
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            printf("Enter %s resources for p%d %d: ", var, i,j);
            scanf("%d", &a[i][j]);
        }
    }
}

void print(int np, int nr, int a[np][nr]) {
    for (int i = 0; i < nr; i++) {
        char alphabet = (char)('A' + i);
        printf("%c\t", alphabet);
    }

    printf("\n\n");

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Function to find the need of each process
void calculateNeed(int N,int M,int need[N][M], int max[N][M], int allocation[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Banker's Algorithm
int isSafe(int N,int M,int processes[], int available[], int max[][M], int allocation[][M]) {
    int need[N][M];
    calculateNeed(N,M,need, max, allocation);
    
     int work[M];
    for (int i = 0; i < M; i++) {
        work[i] = available[i];
    }

    int finish[N];
    for (int i = 0; i < N; i++) finish[i]=0;
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
    int N,M;
    printf("Enter no of processes: ");
    scanf("%d",&N);
    printf("Enter no of resources: ");
    scanf("%d",&M);
    int processes[] = {0, 1, 2, 3, 4};
    int max[N][M];
    int allocation[N][M];
    int available[M];

    read(N, M, max, "maximum");
    read(N, M, allocation, "allocation");

    printf("\nMaximum Matrix:\n");
    print(N, M, max);

    printf("Enter the available resource: ");
    for (int i = 0; i < M; i++) {
        scanf("%d",&available[i]);
    }
    printf("\nAllocation Matrix:\n");
    print(N, M, allocation);

    isSafe(N,M,processes, available, max, allocation);

    return 0;
}

