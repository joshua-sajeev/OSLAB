#include<stdio.h> 
void swap(int *a,int *b){ 
	int temp; 
	temp=*a; 
	*a=*b; 
	*b=temp; 
} 
int  main(){ 
	int i,j,n,pid[50],at[50],bt[50],ct[50]={0},tat[50],wt[50],sum=0; float ttat=0,twt=0,atat,awt; 
	printf("Enter number of processes: "); 
	scanf("%d",&n); 
	for(i=0;i<n;i++){ 
		printf("Enter arrival time of P%d: ",i+1); 
		scanf("%d",&at[i]); 
		printf("Enter burst time of P%d: ",i+1); 
		pid[i]=i+1; 
		scanf("%d",&bt[i]); 
	} 
	printf(" Entered Data \n"); 
	printf("+-------------------------+\n"); 
	printf("| PID\t| AT \t| BT \t|\n"); 
	printf("+-------------------------+\n"); 
	for(i=0;i<n;i++) 
		printf("| P%d\t| %d\t| %d\t|\n",pid[i],at[i],bt[i]); 
	printf("+-------------------------+\n"); 
	for(i=1;i<n;i++){ 
		for(j=0;j<n-i;j++){ 
			if(at[j]>at[j+1]){ 
				swap(&pid[j],&pid[j+1]); 
				swap(&at[j],&at[j+1]); 
				swap(&bt[j],&bt[j+1]); 
			} 
		} 
	} 
	for(i=1;i<n-1;i++){ 
		for(j=1;j<n-i;j++){ 
			if(bt[j]>bt[j+1]){ 
				swap(&pid[j],&pid[j+1]); 
				swap(&at[j],&at[j+1]); 
				swap(&bt[j],&bt[j+1]); 
			} 
		} 
	} 
	for (i=0;i<n;i++){ 
		sum+=bt[i]; 
		ct[i]+=sum; 
		tat[i]=ct[i]-at[i]; 
		ttat+=tat[i];
		wt[i]=tat[i]-bt[i]; 
		twt+=wt[i]; 
	} 
	atat=ttat/n; 
	awt=twt/n; 
	printf(" Final Data \n"); 
	printf("+---------------------------------------------------+\n"); printf("| PID\t| AT \t| BT \t| CT\t| TAT \t| WT \t|\n"); printf("+---------------------------------------------------+\n"); 
	for(i=0;i<n;i++) 
		printf("| P%d\t| %d\t| %d\t| %d\t| %d\t|%d\t|\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]); 
			printf("+---------------------------------------------------+\n"); printf("Average Turn Around Time = %0.2f\n",atat); printf("Average Waiting Time = %0.2f\n",awt); 
} 

