#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>


typedef struct
{
    char* codename;
    float open;
    float close;
    float sub;
    int days;
}info;

int cmpfunccharcodename(const void *a, const void *b)
{
    char* p1 = (*(info*)a).codename;
    char* p2 = (*(info*)b).codename;
    return strcmp(p1,p2);
}

//cgetline
#define CGEN_DEFAULT_IO_BUFF_SIZE
#define CGEN_IO_BUF_SIZE 1024
static char *cgetline(char **lineptr, long n, FILE *inp) 
{
    char buff[CGEN_IO_BUF_SIZE];
    long idx = 0, len, tmp;
    while (fgets(buff, CGEN_IO_BUF_SIZE, inp)) 
    {
        len = strlen(buff);
        tmp = idx + len + 1;
        if (tmp > n) 
        {
            *lineptr = realloc(*lineptr, tmp);
            if (*lineptr == NULL) 
            {
                return NULL;  // Lỗi cấp phát bộ nhớ
            }
            n = tmp;
        }
        if (idx == 0) {
            *lineptr[0] = 0;
        }
        strcat(*lineptr, buff);
        idx += len;
        if (buff[len - 1] == '\n') {
            break;
        }
    }
    return idx > 0? *lineptr: NULL;
}
static char *remove_tail_lf(char *s) {
  if (!s) {
    return s;
  }
  char *p = s + strlen(s) - 1;
  if (*p == '\n') {
    *p = '\0';
  }
  return s;
}

int menu()
{
    
    printf("1. View average difference\n");
    printf("2: Search by name \n");
    printf("3. Search by trend \n");
    printf("4: The most increase \n");
    printf("5: Exit \n");
    printf("Lua chon cua ban: ");

    
}

void View(info* a, int idx)
{
    info* list = a;
for (int i = 0; i < idx; i++)
    {
       printf("%s \t %.2f \t %.2f \n", list[i].codename,list[i].open, list[i].close);
    } 
     printf("\n");

}

int main(int argc, char *argv[])
{
    clock_t start = clock();
    if (argc != 2) //argc = the total of input running file and reading file
    {
        printf("Usage: ./prog data.txt\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "r+");
    info* list = NULL;
    char *line = NULL;
    int idx = 0;
    //printf("%d",idx);
    while (cgetline(&line, 0, f))
    {
        remove_tail_lf(line);
        idx++;
    }
    fseek(f, 0, SEEK_SET); //Set the pointer of 'f' to the begining of the file

    int n = 0;//number of line not include the first one
    fscanf(f, "%d \n", &n);
    printf("%d\n",n);
    list = realloc(list, (idx+1)*sizeof(info));
    int count = 0;
    
     for (int i = 0; i < idx-1; i++)
    {
        fscanf(f,"%s\t%f\t%f\n",list[i].codename,&list[i].open,&list[i].close);
        count++;
        list[i].days = i/7 + 1;
    }
    

/*
    while (cgetline(&line, 0, f))
    {
        count++;
        remove_tail_lf(line);
        //printf("%d ",count);
        list[idx].codename = strdup(strtok(line,"\t"));
        list[idx].open = atof(strtok(NULL,"\t"));
        list[idx].close = atof(strtok(NULL,"\n"));
        list[idx].days = (count/n) + 1;
        printf("%d \n",count);
    }
*/
    //fclose(f);
    //View(list,idx);
    int choice = -1;
    while (choice < 0 || choice > 3) //3 is the amount in the menu, can change later on
    {
        menu();
        fflush(stdin);
        scanf("%d ", &choice);
        switch (choice)
        {
        case 1:
            printf(" \n");
            //qsort(list, n, sizeof(info), cmpfunccharcodename);
            View(list,idx);
            choice = -1;
            break;

        case 2:
            printf(" \n");

            choice = -1;
            break;
        
        case 3:
            printf(" \n");

            choice = -1;
            break;

        case 4:
            printf(" \n");

            choice = -1;
            break;
        
        case 5:
            printf("Code by Trinh Phu Quang - 20205219 \n");
            return 0;
        }
    }

    clock_t end = clock();
    double time_process = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Thoi gian xu ly: %lfs\n",time_process);
    return 0;
}