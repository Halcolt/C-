#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX_L 256



//-----------------------------------------------------------
typedef struct Profile
{
char name[MAX_L]; // ten sinh vien
char email[MAX_L];// email cua sinh vien
struct Profile* next;
}Profile;
Profile* first, *last;
//-----------------------------------------------------------
Profile* makeProfile(char* name, char* email)
{
    Profile* node = (Profile*)malloc(sizeof(Profile));
    strcpy(node->name, name);
    strcpy(node->email,email);
    node->next=NULL;
    return node;
}
//-----------------------------------------------------------
int listEmpty()
{
    return first == NULL && last == NULL;
}
//-----------------------------------------------------------
void insertLast(char* name, char* email){
    Profile* profile = makeProfile(name,email);//khoi tao node moi
    if(listEmpty()){
        first = profile; last = profile;//TH danh sach rong
    }else{
        last->next = profile;
        last = profile;
    }
}

//-----------------------------------------------------------

void load(char* filename){
    FILE* f = fopen(filename,"r");
    if(f == NULL) printf("Load data -> file not found\n");
    while(!feof(f)){
        char name[256], email[256];
        fscanf(f,"%s%s",name, email);
        insertLast(name,email);
    }
    fclose(f);
}

//-----------------------------------------------------------
void initList()
{
    first = NULL; last = NULL;
}
//-----------------------------------------------------------
int ListEmpty()
{
    return first == NULL && last == NULL;
}
//-----------------------------------------------------------
Profile* removeProfile(Profile* f, char* name)
{
    if(ListEmpty) {return NULL;}
    if(strcmp(f->name,name) == 0)
    {
        Profile* tmp = f->next;
        free(f);
        if(tmp == NULL) {last == NULL;}
        return tmp;
    } else 
        {
            f->next = removeProfile(f,name); /// from removeProfile(f->name,name)
            return f;
        }
}
//-----------------------------------------------------------
void processFind()
{
    char name[256];
    scanf("%s",name);
    Profile* profile = NULL;
    for(Profile* p = first; p != NULL; p = p->next)
    {
        if (strcmp(p->name,name) == 0)
        {
            profile = p;break;
        }
    }
    if(profile == NULL)
    {
        printf("NOT FOUND PROFILE %s\n",name);
    }else
        {
            printf("FOUND PROFILE %s, %s", profile->name, profile->email);
        }
}

//-----------------------------------------------------------
void processLoad()
{
    char filename[256];
    scanf("%s",filename);
    load(filename);
}
//-----------------------------------------------------------
void processStore() // luu du lieu DS vao file van ban
{
    char filename[256];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    for(Profile* p = first; p != NULL; p = p->next){
        fprintf(f,"%s %s",p->name,p->email);
        if(p->next != NULL) fprintf(f,"\n");
    }
    fclose(f);
}
//-----------------------------------------------------------
void processInsert()
{
    char name[256], email[256];
    scanf("%s%s",name,email);
    insertLast(name,email);
}
//-----------------------------------------------------------
void processRemove()
{
    char name[256];
    scanf("%s",name);
    first = removeProfile(first,name);
}
//-----------------------------------------------------------


void printList()
{
    for(Profile* p = first; p != NULL; p = p->next)
        printf("%s, %s\n",p->name, p->email);
}

int main()// chay chuong trinh trong che do interactive
{
    initList();
    while(1)
    {
    printf("Enter command: ");
    char cmd[256];
    scanf("%s",cmd);
    if(strcmp(cmd,"Quit")==0) break;
    else if(strcmp(cmd,"Load")==0) processLoad();
    else if(strcmp(cmd,"Print")==0) printList();
    else if(strcmp(cmd,"Find")==0) processFind();
    else if(strcmp(cmd,"Insert")==0) processInsert();
    else if(strcmp(cmd,"Remove")==0) processRemove();
    else if(strcmp(cmd,"Store")==0) processStore();
    }
    return 0;
}