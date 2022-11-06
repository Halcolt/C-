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

int checkradius(point_t p, circle_t c) {
    if ((p.x-c.center.x)*(p.x-c.center.x) - (p.y - c.center.y)*(p.y - c.center.y) < (c.radius)*(c.radius)) {
        return 1;
    }
    return 0;

int main() {
    point_t p;
    circle_t c;
    printf("Nhap toa do diem:");
    scanf("%f%f",&p.x,&p.y);

    printf("Nhap tam va ban kinh duong tron:");
    scanf("%f%f%f",&c.center.x,&c.center.y,&c.radius);

    if (checkradius(p,c) == 1){
        printf("yes");
    } else {printf("no");}
    return 0;
    
}
    
}