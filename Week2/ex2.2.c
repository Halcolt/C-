#include<stdio.h>
typedef struct point 
{
    double x;
    double y;
} point_t;

typedef struct circle
{
    point_t center;
    double radius;
} circle_t;

int checkradius(point_t p, circle_t c) 
{
    int a, b;
    a = (p.x-c.center.x)*(p.x-c.center.x) + (p.y-c.center.y)*(p.y-c.center.y); 
    b = (c.radius)*(c.radius);
    printf("%ld %ld \n",p.x,p.y);
    if (a < b)
    {
        
        return 1;
    }
    else return 0;
}

int main() {
    point_t p;
    circle_t c;
    printf("Nhap toa do diem:");
    scanf("%lf %lf",&p.x,&p.y);

    printf("Nhap tam va ban kinh duong tron:");
    scanf("%lf %lf %lf",&c.center.x,&c.center.y,&c.radius);
    printf("%ld %ld \n",p.x,p.y);
    if (checkradius(p,c) == 1){
        printf("yes");
    } 
    else {printf("no");}
    return 0;
    
}
    
