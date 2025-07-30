#include <stdio.h>

typedef struct {
	float x;
	float y;
} Point;

void movePoint(Point *p1, Point p2){
	p1->x = p2.x;
	p1->y = p2.y;
}

int main() {
	Point p1, p2;
	Point * ptr;
	ptr = &p1;

	p1.x = 3;
	ptr->y = 4; 

	printf("\nx-Koordinate von p1: %f", ptr->x);
	printf("\ny-Koordinate von p1: %f", (*ptr).y);

	p2 = p1;

	printf("\nx-Koordinate von p2: %f", p2.x);
	printf("\ny-Koordinate von p2: %f", (&p2)->y);

	Point p3;
	p3.x = 10;
	p3.y = 20;

	movePoint(&p1, p3);

	printf("\nx-Koordinate von p1: %f", p1.x);
	printf("\nx-Koordinate von p1: %f", p1.y);

	printf("\n\n");
	return 0;
}
