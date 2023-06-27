#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    int f;
    char m[30] = "Hey There";
    char new[30];
    f=open("Sample.txt",O_RDWR);
    printf("File Descriptor: %d\n",f);

    if(f!=-1){
        printf("File opened \n");
        write(f,m,sizeof(m));
        lseek(f,0, SEEK_SET);
        read(f, new, sizeof(m));
        printf("%s was returned to the file\n",m);
        close(f);
    }
}
