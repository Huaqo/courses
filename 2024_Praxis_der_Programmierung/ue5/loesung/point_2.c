/* point_1.c
 * 
 * Datentyp eines zweidimensionalen Punktes
 * verschiedene Methoden der Komponentenselektion
 */

#include <stdio.h>

  struct point {
    float x;
    float y;
  };

void move(struct point * p, float newx, float newy){
	p->x = newx;
	p->y = newy;
}

int main() {
  struct point p1, p2;
  struct point * ptr;

  ptr = &p1;

  // Pfeil- VS. Punktschreibweise
  p1.x = 3;  // Hier .x da p1 ein struct point ist
  ptr->y = 4; // Hier ->y da ptr ein POINTER auf struct point ist

  printf("\nx-Koordinate von p1: %f", ptr->x);
  printf("\ny-Koordinate von p1: %f", (*ptr).y);

  p2 = p1;

	move(ptr, -5, -3);
	printf("\n Nach dem verschieben von p1:");
	printf("\n x-Koordinate von p1 %f", p1.x);
	printf("\ny-Koordinate von p1: %f", (&p1)->y);
  printf("\nx-Koordinate von p2: %f", p2.x);
  printf("\ny-Koordinate von p2: %f", (&p2)->y);

  printf("\n\n");
  return 0;
}
