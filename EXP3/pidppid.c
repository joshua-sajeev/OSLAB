#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    pid_t a;
    a = fork();
    if (a==0){
        printf("Child Process \n");
        exit(0);
        printf("Child Process Id : %d\n",getpid());
        printf("Child's Parent Id : %d\n",getppid());
    }
    else if(a>0){
        wait(NULL);
        printf("Parent Process\n");
        printf("Parent Process id %d\n",getpid());
        printf("Parent's Parent Process id %d\n",getppid());
    }
    else {
        printf("Child Process creation failed ");
    }
}
