#include <stdio.h>
#include <stdlib.h>

struct point {
  float x;
  float y;
};


void move(struct point * punkt, float dx, float dy) {
  punkt->x += dx;
  punkt->y += dy;
}


int main() {
  struct point * ptr;

  ptr = malloc(sizeof(struct point));  // impl. Typcast des Pointers
   
  if (ptr != NULL) {
    ptr->x = 10;
    ptr->y = 20;

    printf("\nx-Koordinate von p: %f", ptr->x);
    printf("\ny-Koordinate von p: %f", ptr->y);

    free(ptr);

    printf("\n");
    printf("\nnach free():");
    
    // Dangling Pointer!
    printf("\nx-Koordinate von p: %f", ptr->x);
    printf("\ny-Koordinate von p: %f", ptr->y);

    printf("\n\n");
  }
  return 0;
}

