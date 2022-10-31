#include<stdio.h>
void main() {
    FILE  *p, *p1;
    char c[100];

    p = fopen("lab1.txt","r");
    p1 = fopen("labw1.txt","w");

    while (fgets(c,100,p)!= NULL) {
        fputs(c,p1);
    }

    fclose(p);
    fclose(p1);
}
    
