#include <stdio.h>
#include <unistd.h>

int main(){
    char*a[]={"l",".",NULL};
    execv("/bin/ls",a);
   // execlp("ls","l",".",NULL)
    //exec("/bin/ls","l",".",NULL)
    
}
