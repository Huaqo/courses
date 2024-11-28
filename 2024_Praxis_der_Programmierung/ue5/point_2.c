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

void move_point(struct point * ptr, float delta_a, float delta_b){
    if (ptr != NULL){
        ptr->x += delta_a;
        ptr->y += delta_b;
    }
}

int main() {
    struct point p1 = {3.0f,4.0f};
    struct point * ptr = &p1;
    struct point p2 = {0.0f,0.0f};

    printf("\nx-Koordinate von p1: %f", ptr->x);
    printf("\ny-Koordinate von p1: %f", ptr->y);

    p2 = p1;

    printf("\nx-Koordinate von p2: %f", p2.x);
    printf("\ny-Koordinate von p2: %f", p2.y);

    printf("\nAdresse von p1: %p", (void*)&p1);
    printf("\nAdresse von p2: %p", (void*)&p2);


    printf("\n\n");

    move_point(ptr, 4.0f , 5.0f);

    printf("\nx-Koordinate von p1: %f", ptr->x);
    printf("\ny-Koordinate von p1: %f", ptr->y);

    printf("\n\n");

    return 0;
}
