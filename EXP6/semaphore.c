#include <linux/limits.h>
#include <stdlib.h>
#include <stdio.h>
int mutex=1,empty=3,full=0,x=0;
int wait(int S){
    S--;
    return S;
}
int signal(int S){
    S++;
    return S;
}
void producer(){
    empty=wait(empty);
    mutex=wait(mutex);
    x++;
    printf("Producer produces an item %d\n",x);
    mutex=signal(mutex);
    full=signal(full);
}
void consumer(){
    full=wait(full);
    mutex=wait(mutex);
    printf("Consumer consumes an item %d\n",x);
    x--;
    empty=signal(empty);
    mutex=signal(mutex);
}
int main(){
    int choice;
    while (1) {
        printf("1.Producer\n2.Consumer\n3.Exit\nEnter your choice");
        scanf("%d",&choice);
        switch (choice) {
        	case 1:
                if (mutex==1 & empty!=0)
                    producer();
                else
                    printf("Buffer is full\n");
                break;
            case 2:
                if (mutex==1 & full!=0)
               	    consumer();
                else
                    printf("Buffer is empty\n");
                break;
            case 3:
                printf("Exiting\n");
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }
}

