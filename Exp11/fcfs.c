#include <stdio.h>
#include <stdlib.h>

int abs(int a) {
    return a >= 0 ? a : -a;
}

int main() {
    int n; // Number of disk I/O requests
    int head; // Initial position of the disk head
    int requests[100]; // Array to store disk I/O requests
    int seekSequence[100]; // Array to store the order of requests processed

    printf("Enter the number of disk I/O requests: ");
    scanf("%d", &n);

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the disk I/O requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("\nProcessing requests using FCFS:\n");

    int totalSeekTime = 0;
    seekSequence[0] = head; // Start from the initial position
    totalSeekTime += abs(requests[0] - head);

    for (int i = 1; i < n; i++) {
        seekSequence[i] = requests[i - 1];
        totalSeekTime += abs(requests[i] - requests[i - 1]);
    }

    printf("Order of requests processed:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", seekSequence[i]);
    }

    printf("\nTotal seek time: %d\n", totalSeekTime);

    return 0;
}

