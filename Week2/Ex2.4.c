// exercise 2.4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE *fptr1,*fptr2;
    char c[100];
    fptr1 = fopen(argv[1], "r");
    fptr2 = fopen(argv[2], "w");

    while(feof(fptr1) == 0) {
        fread(c, 1, 100, fptr1);
        fwrite(c, 1, strlen(c), fptr2);
    }

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}