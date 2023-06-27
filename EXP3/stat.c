#include <stdio.h>
#include <sys/stat.h>
int main(){
    struct stat s;
    stat("dir.c",&s);
    printf("Size of the file : %i\n",s.st_size);
}
