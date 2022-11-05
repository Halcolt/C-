#include<stdio.h>
#include<string.h>
int main()
{
    FILE *p, *p1;
    char c[100];
    int a;                          //number of character in a line
    char b[10];                     //from int to string
    p = fopen("lab1.txt","r");
    p1 = fopen("labw1.txt","w+");
    while (fgets(c,100,p) != NULL)
    {
        a = strlen(c);
        sprintf(b,"%d ",a);
        fputs(b,p1); 
        fputs(c,p1);  
    }
    fclose(p);
    fclose(p1);

}