#include <stdio.h>

int main() {
    int start = 65; // ASCII value of 'A'
    int end = 90;   // ASCII value of 'Z'

    printf("Alphabets from A to Z:\n");
    
    for (int i = 65; i <= end; i++) {
        char alphabet = (char)i;
        printf("%c ", alphabet);
    }
    
    printf("\n");

    return 0;
}

