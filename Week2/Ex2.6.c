#include<stdio.h>
#include<string.h>
int main()
{
    FILE *p,*p1;
    char c[90],b[100];

    p = fopen("class1EF.txt","r");
    p1 = fopen("class1EF_1.txt","w+");
    while (fgets(c,100,p) != NULL)
    {
        sprintf(b,"%s \n",c);
        fputs(b,p1); 
    }
    fclose(p);
    fclose(p1);
}