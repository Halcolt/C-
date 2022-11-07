#include<stdio.h>
#include<string.h>
int main()
{
    FILE *p, *p1;
    char c[90];
    int a = 0;                       //number of character in a line
    char b[100];                     //from int to string
    p = fopen("lab1.txt","r");
    p1 = fopen("labw1_1.txt","w+");
    while (fgets(c,100,p) != NULL)
    {
        a++;
        sprintf(b,"%d %s",a,c);
        fputs(b,p1); 
       // fputs(c,p1);  
    }
    fclose(p);
    fclose(p1);
}