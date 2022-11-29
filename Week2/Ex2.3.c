//excercise 2.3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE *fptr1,*fptr2;
    char c[100];
    fptr1 = fopen("lab1.txt", "rb");
    fptr2 = fopen("lab1w.txt", "wb");

    while(feof(fptr1) == 0) {
        fread(c, 1, 100, fptr1);
        fwrite(c, 1, strlen(c), fptr2);
    }
    
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}