#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define maxl 256
typedef struct Profile{
    char name[256];
    char email[256];
    struct Profile *next;
}Profile;

Profile* first, *last;

Profile* makeProfile(char* name, char* email){
    Profile* node = (Profile*)malloc(sizeof(Profile));
    strcpy(node->name,name);
    strcpy(node->email,email);
    node->next = NULL;
    return node;
}

void initList(){
    first = NULL; last = NULL;
}
int listEmpty(){
    return first == NULL && last == NULL;
}

void insertLast(char* name, char* email){
    Profile* profile = makeProfile(name,email);//khoi tao node moi
    if(listEmpty()){
        first = profile; last = profile;//TH danh sach rong
    }else{
        last->next = profile;
        last = profile;
    }
}
void printList(){
    for(Profile* p = first; p != NULL; p = p->next)
        printf("%s, %s\n",p->name, p->email);
}

Profile* removeProfile(Profile* f, char* name){// f la con tro can xoa
    if(listEmpty()) return NULL;
    if(strcmp(f->name,name) == 0){
        Profile* tmp = f->next;
        free(f);//giai phong vung nho cua f
        if(tmp == NULL) last = NULL;
        return tmp;//tra ve node ke tiep
    }else{
        f->next = removeProfile(f->next,name);
        return f;
    }
}

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

void pFind(){
    char name[256];
    scanf("%s",name);
    Profile* profile = NULL;
    for(Profile* p = first; p != NULL; p = p->next){
        if(strcmp(p->name,name)==0){
            profile = p;
            break;
        }
    }
    if(profile == NULL){
        printf("NOT FOUND profile %s\n",name);
    } else {
        printf("FOUND profile %s, %s\n",profile->name,profile->email);
    }
}

void pLoad(){// load du lieu tu file vao bo nho
    char filename[256];
    scanf("%s",filename);
    load(filename);
}

void pStore(){// luu du lieu DS vao file van ban
    char filename[256];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    for(Profile* p = first; p != NULL; p = p->next){
        fprintf(f,"%s %s",p->name,p->email);
        if(p->next != NULL) fprintf(f,"\n");
    }
    fclose(f);
}

void pInsert(){
    char name[256], email[256];
    scanf("%s%s",name,email);
    insertLast(name,email);
}

void pRemove(){
    char name[256];
    scanf("%s",name);
    first = removeProfile(first,name);
}

int main(){// chay chuong trinh trong che do interactive
    initList();
    while(1){
    printf("Enter command: ");
    char cmd[256];
    scanf("%s",cmd);
    if(strcmp(cmd,"Quit")==0) break;
    else if(strcmp(cmd,"Load")==0) pLoad();
    else if(strcmp(cmd,"Print")==0) printList();
    else if(strcmp(cmd,"Find")==0) pFind();
    else if(strcmp(cmd,"Insert")==0) pInsert();
    else if(strcmp(cmd,"Remove")==0) pRemove();
    else if(strcmp(cmd,"Store")==0) pStore();
    }
}
