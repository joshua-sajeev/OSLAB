#include <stdio.h>
#include <time.h>

int queue[100];
int front = -1; 
int rear = -1; 

void insert(int m){
    if(front== -1){
        front =0;
    }
    rear=rear+1;
    queue[rear]= m;
}

int delete(){
    int n;
    n=queue[front];
    front+=1;
    return n;
}

int main(){	
    int n,i,j,pid[50],at[50],bt[50],ct[50]={0},wt[50],tat[50],tq,l,times=0,temp[10],exist[10]={0};
    float ttat=0,twt=0,awt,atat;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    for ( i = 0; i < n; i++) {
        pid[i]=i+1;
        printf("Enter AT of P%d: ",i+1);
        scanf("%d",&at[i]);
        printf("Enter BT of P%d: ",i+1);
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
    }
    
    printf("\n");
    printf("Entered Data\n");
    printf("PID\tAT\tBT\t\n");
    
    for ( i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\n",pid[i],at[i],bt[i]);
    }
    
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    insert(0);
    exist[0]=1;
    while(front<=rear) {
        l=delete();
        if(bt[l]>=tq){
            bt[l]=bt[l]-tq;
            times+=tq;
        }
        else{
            times+=bt[l];
            bt[l]=0;
        }
        for ( i = 0; i < n; i++) {
            if(exist[i]==0 && at[i]<=times){
                insert(i);
                exist[i]=1;
            }
        }
        if(bt[l]==0){
            ct[l]=times;
            tat[l]=ct[l]-at[l];
            wt[l]=tat[l]-temp[l];
            ttat+=tat[l];
            twt+=wt[l];
        }
        else{
            insert(l);
        }
    }
    atat=ttat/n;
    awt=twt/n;
    printf("Final Data\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\t\n");
    
    for ( i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    
    printf("Avg TAT = %0.2f\n",atat);
    printf("Avg WT = %0.2f",awt);
}
