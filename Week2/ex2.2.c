#include <stdio.h>
#include <math.h>

typedef struct point 
{
	double x;
	double y;
} point_t;

typedef struct circle 
{
	point_t center;
	double radius;
}circle_t;

int check(point_t p  ,circle_t c1 ) {
	float distance;
	distance = sqrt( pow( (p.x - c1.center.x), 2) + pow( (p.y - c1.center.y), 2) );
		if (distance <= c1.radius) {
            return 1;
		}
        else return 0;
}
int main() {
	point_t p;
	circle_t c1;
	printf("Enter the center point (center.x, center.y):\n");
	scanf("%lf%lf",&c1.center.x,&c1.center.y);
	printf("Enter the radius of the circle c:\n");
	scanf("%lf",&c1.radius);
	printf("Enter the point p(x, y):\n");
	scanf("%lf%lf",&p.x,&p.y);

	if(check(p,c1)==1) {
        printf("Yes");
    }
    else {printf("No");}

    return 0;
}