/*đoạn code chưa có khả năng tìm đường ngắn nhất, 
mới thành công trong việc tìm thấy đường đi
Đoạn code có 1 vài chỗ comment thừa và 1 số chỗ khó hiểu
=> để tạm đó để fix vào 1 ngày nào đó ko sao
hàm print map, maze có đường đi là 0, 1 là tường, 2 là lối đã chọn để đi, 
3 ban đâu được thiết kế là để cho đường có thể đi dc push vào stack(CHƯA DÙNG)
4 là những đường đi vào nhưng bị vào ngõ cụt và phải quay lại

Idea: có 1 điểm, tìm những đường có thể đi-> push vào stack-> pop()sau khi push xong
và đưa ra địa chỉ của phần tử vừa pop và nhét vào trong mảng track, 
đây là đường đi mới_tiếp tục tìm đường và push 
vào stack cho đến khi ra dc mê cung mảng final dc copy từ track có count thấp nhất,
mảng track chứ đường đi từ đầu .
(*) Idea còn lại chưa thành công trong fix bug:khi thoát khỏi mê cung, pop mảng đầu 
của stack, biến count dc gán là biến step của phần tử trong stack(roll back) và tìm 
đường mới, nếu đường mới bắt đầu tìm dc tốt hơn đường cũ(count cuối<max), gán final = track mới 
=> roll back tiếp cho tới khi stack trống và chạy hết mê cung, đường đi tốt nhất được
lưu ở final
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int row,col;
	struct Node* next; 
    int step;
}Node;

int n,m,x,y, count = 0,max,trip = 0;  
Node* top,track[100],final[100];

Node* makeNode(int a, int b)            //a is row, b iss col
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->row = a; p->col = b; p->step=count;p->next = NULL;
    return p;
}
void printstack()
{
    Node* tmp = top;
    while (tmp != NULL)
    { 
        printf("%d %d\n",tmp->col,tmp->row);
        tmp = tmp->next;
    }  
}
void printMap(int** A)
{
    for( int i = 0; i < n+1; i++)            //i|n is row, j|m is col
    {
		for(int j = 0; j < m+1; j++)
        {
			
            printf("%d\t",A[i][j]);
		}
        printf(" \n",i);
	}
}

void initStack()
{
    top = NULL;
}
    
int stackEmpty() 
{
    return top == NULL;
}


int push(int** A,int a, int b)
{
    Node* tmp = top;
    while (tmp != NULL)
    {
        //printf("d");
        if(tmp->row==a && tmp->col==b)
        {
            return 0;
        }
        tmp = tmp->next;
    }
    Node* p = makeNode(a,b);
    p->next = top; top = p;  
}

void pop()
{
    Node* tmp = top; top = top->next; free(tmp); 
}

int exercuted(int** A)
{
    if(stackEmpty()) return ' ';
    //printMap(A);
    int a = top->row, b = top->col;
    pop();
    findpath(A,a,b);
    return 0;
}

int check(int** A,int c,int d)
{
    int a = c ,b = d;
    if (A[a][b] == 0)
    {return 0;} else {return 1;}
}

int findpath(int** A,int c,int d)
{
    int a = c ,b = d;
    track[count].col = b; track[count].row=a;
    track[count].step = count; 
    
    A[a][b] = 2;          
    int key = 0;    //check stuck(case there is nothing in stack yet)          
    if( a == n || b == m || a == 0 || b == 0) 
    {
        A[a][b] = 2;
        if (trip == 0)
        {
            max = count ;
            for (int i = 0; i <= count; i++)
            {
                final[i] = track[i];
            } 
            trip++;
        }
        track[count].row = a;track[count].col=b; 
        if (max < count)
        {
            max = count;
            for (int i = 0; i <= count; i++)
            {
                final[i] = track[i];
            } 
        }
        return 0;
    }                                                                    
    if (check(A,a,b-1) == 0 && A[a][b-1]!=(2) && A[a][b-1]!=(3)) {push(A,a,b-1);printf("\nL ");key = 1;}      //check l
    if (check(A,a,b+1) == 0 && A[a][b+1]!=(2) && A[a][b+1]!=(3)) {push(A,a,b+1);printf("R ");key = 1;}        //check r
    if (check(A,a-1,b) == 0 && A[a-1][b]!=(2) && A[a-1][b]!=(3)) {push(A,a-1,b);printf("U ");key = 1;}        //check up
    if (check(A,a+1,b) == 0 && A[a+1][b]!=(2) && A[a+1][b]!=(3)) {push(A,a+1,b);printf("D \n");key = 1;}      //check down
    //printf("\n-----------\n");
    //printMap(A);
    //printstack();   
    if (key == 0)
    {
        A[a][b] = 4;
        count--;
        findpath(A,track[count].row,track[count].col);
        return 0;
    }  
    count++;
    //printf("-%d-\n",key);
    exercuted(A);
}
                     
int main() 
{
    initStack();
	printf("Maze \n");
	FILE* f = fopen("maze.txt","r");
	fscanf(f,"%d %d %d %d",&n,&m,&x,&y);    //x,y is the start point, x for row, y for col
    //printf("%d %d\n\n",track[0].col,track[0].row);
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        A[i] = (int *)malloc(m * sizeof(int));
    }
	for( int i = 0; i < n; i++)            //i|n is row, j|m is col
    {
		for(int j = 0; j < m; j++)
        {
			fscanf(f,"%d",&A[i][j]);
            printf("%d ",A[i][j]);
		}
        printf("\n");
	}
    fclose(f);
    m = m-1;
    n = n-1;
    if(A[y][x] == 1) {printf("Error init start point\n "); return 1;}
    findpath(A,y,x);
    printMap(A);
    for (int i = 0; i <= max; i++)
    {
        printf("(%d,%d) ", final[i].col, final[i].row );
    }
    printf("step: %d\n",max+1);

    
    printf(" \n");
    free(A);
}
































