#include<stdio.h>

void printtable(int b,int bs[],int p,int ps[],int allocation[]){

    printf("Block No\tSize\tProcess No\tSize\n");
    for (int i = 0; i < b; i++) {
        printf("%d\t\t%d\t",i+1,bs[i]);
        if(allocation[i]!=-1){
            printf("%d\t\t%d\n",allocation[i]+1,ps[allocation[i]]);
        }
        else{
            printf("Not allocated\n");
        }
    }
}
void firstfit(int b,int bs[],int p,int ps[]){

    int allocation[10];
    for (int i = 0; i < b; i++) {
        allocation[i]=-1;
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < b; j++) {
            if(allocation[j]==-1 && bs[j]>=ps[i]){
                allocation[j]=i;
                break;
            }
        }
    }
    printtable(b,bs,p,ps,allocation);
}

void bestfit(int b,int bs[],int p,int ps[]){

    int allocation[10];
    for (int i = 0; i < b; i++) {
        allocation[i]=-1;
    }
    
    int bi;
    for (int i = 0; i < p; i++) {
        bi=-1;
        for (int j = 0; j < b; j++) {
            if(allocation[j]==-1 && bs[j]>=ps[i]){
                if(bi==-1){
                    bi=j;
                }
                else if(bs[bi]>bs[j]){
                    bi=j;
                }
            }
        }
        if(bi!=-1)
            allocation[bi]=i;
    }
    printtable(b,bs,p,ps,allocation);
}

void worstfit(int b,int bs[],int p,int ps[]){

    int allocation[10];
    for (int i = 0; i < b; i++) {
        allocation[i]=-1;
    }
    
    int wi;
    for (int i = 0; i < p; i++) {
        wi=-1;
        for (int j = 0; j < b; j++) {
            if(allocation[j]==-1 && bs[j]>=ps[i]){
                if(wi==-1){
                    wi=j;
                }
                else if(bs[wi]<bs[j]){
                    wi=j;
                }
            }
        }
        if(wi!=-1)
            allocation[wi]=i;
    }
    printtable(b,bs,p,ps,allocation);
}

int main(){

    int blockSize=6,processSize=4;
    int blocks[6]={200,400,600,500,300,250},process[4]={357, 210, 468, 491};

    
    firstfit(blockSize,blocks,processSize,process);
    // bestfit(blockSize,blocks,processSize,process);
    // worstfit(blockSize,blocks,processSize,process);


}
