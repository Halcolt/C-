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
struct Profile* prev;
}Profile;
Profile *first, *last;
//-----------------------------------------------------------
Profile* makeProfile(char* name, char* email)
{
    Profile* node = (Profile*)malloc(sizeof(Profile));
    strcpy(node->name, name);
    strcpy(node->email,email);
    node->next=NULL;
    node->prev=NULL;
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
        profile->prev = last;
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
        tmp->prev = f->prev;
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
void processFindLTR()
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