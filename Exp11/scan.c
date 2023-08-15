#include <stdio.h>
#include<stdlib.h>
int main() {
    int n,i; 
    int head,index,totalSeekTime;
    int requests[100];
    int seekSequence[100];
    int cylinders;
    printf("Enter the number of disk I/O requests: ");
    scanf("%d", &n);

    printf("Enter the disk I/O requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);
    

    printf("Enter no of cylinders: ");
    scanf("%d", &cylinders);

    printf("\nProcessing requests using FCFS:\n");
     
    for ( i = 1; i <= n; i++) {
        for (int j = 0; j < n-i ; j++) {
            if (requests[j]>requests[j+1]) {    
                int temp = requests[j];
                requests[j]=requests[j+1];
                requests[j+1]=temp;
            }
        }
    }
    
    for (i = 0; i < n; i++) {   
        if(head<requests[i]){
            index = i;
            break;
        }
    }
    printf("%d",head);

    for (i=index;i<n;i++) {
        printf("->%d",requests[i]);
        totalSeekTime += abs(requests[i] - head);
        head=requests[i];
    }
    totalSeekTime+=abs((cylinders-1)-requests[i-1]);
    head=cylinders-1;

    printf("->%d",head);
    for (i = index-1; i >=0; i--){
        printf("->%d",requests[i]);
        totalSeekTime += abs(requests[i] - head);
        head=requests[i];
    }
    printf("\nTotal seek time: %d\n", totalSeekTime);

    return 0;
}

