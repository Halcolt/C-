#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char c[50],c1[50];
    char *p;
    printf("Nhap chuoi 1:");
    scanf("%s",c);
    printf("Nhap chuoi 2:");
    scanf("%s",c1);

    p = malloc ((strlen(c) + strlen(c1))*sizeof(char));
    strcpy(p,c);
    strcat(p,c1);

    printf("%s",p);
    free(p);
    return 0;
}