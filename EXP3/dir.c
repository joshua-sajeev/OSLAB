#include <stdio.h>
#include <dirent.h>
int main(){
    struct dirent *dr;
    DIR *d;
    d=opendir(".");
    if (d==NULL) {
    printf("Couldn't open the directory");
    }
    else {
        while (dr=readdir(d)) {
            printf("%s\n",dr->d_name);
        }
        closedir(d);
    }
}
