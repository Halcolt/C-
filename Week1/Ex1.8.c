
#include<stdio.h>
void main() {
    FILE  *p, *p1;
    char c;

    p = fopen("lab1.txt","r");
    p1 = fopen("lab2.txt","w");

    c = fgetc (p);

    while (c!= EOF) {
        if (c >= 65 && c <= 90) {
            c = c + 32;     
        }
        else if (c >= 97 && c <= 122) {
            c = c - 32;
        }
        fputc(c,p1);
        c= fgetc(p);
    }

    fclose(p);
    fclose(p1);
}
    