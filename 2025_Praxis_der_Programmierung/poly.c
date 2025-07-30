#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float x;
	float y;
}Point;

typedef struct Listelement Listelement;

struct Listelement {
	Point pnt;
	Listelement *next;
};

typedef struct {
	char* name;
	Listelement *first;
} Polygon;

void append(Polygon * pz, Point pnt) {
  Listelement * new = malloc(sizeof(Listelement));

  if (!new) {
	perror("Malloc failed.");
	exit(1);
  }

  new->pnt = pnt;
  new->next = NULL;

  if (pz->first == NULL){
    pz->first = new;
  } else {
    Listelement * tmp = pz->first;

    while (tmp->next != NULL) {
      tmp = tmp->next;
    }

    tmp->next = new;
  }
}

void polyPrint(Polygon *pz){
	if (pz == NULL || pz->first == NULL){
		printf("Kein Polygon.");
		return;
	}
	
	printf("%s\n",pz->name);

	Listelement *le = pz->first;
	while(le != NULL){
		printf("(%f, %f)\n", le->pnt.x, le->pnt.y);
		le = le->next;
	}	
}

void shorten(Polygon *pz){
	if (pz == NULL || pz->first == NULL){
		printf("Kein Polygon.");
	}	

	Listelement *le = pz->first;
	while(le->next->next != NULL){
		le = le->next;
	}
	free(le->next);
	le->next = NULL;
}

Polygon mirror(Polygon *pz){

	Polygon newPZ;
	newPZ.first = NULL;

	if (pz == NULL || pz->first == NULL){
		newPZ.name = NULL;
		printf("Kein Polygon.");
		return newPZ;
	}	
	
	const char *prefix = "Copy of ";
    size_t newNameLen = strlen(prefix) + strlen(pz->name) + 1;
    char *newName = malloc(newNameLen);
    if (!newName) {
        perror("Malloc failed");
        exit(1);
    }
    strcpy(newName, prefix);
    strcat(newName, pz->name);
    newPZ.name = newName;	

    Listelement *le = pz->first;
    while (le != NULL) {
        Listelement *newElem = malloc(sizeof(Listelement));
        if (!newElem) {
            perror("Malloc failed");
            exit(1);
        }
        newElem->pnt = le->pnt;

        newElem->next = newPZ.first;
        newPZ.first = newElem;

        le = le->next;
    }	

	return newPZ;
}

int main() {
	Point pnt = (Point){.x = 10, .y = 20};
	Point pnt2 = (Point){.x = 20, .y = 30};
	Listelement first = {.pnt = pnt, .next = NULL};
	Polygon pz;
	pz.name = "Mein Polygon";
	pz.first = &first;
	append(&pz, pnt2);
	polyPrint(&pz);
	shorten(&pz);
	polyPrint(&pz);
	append(&pz, (Point){.x = 30, .y = 40});
	append(&pz, (Point){.x = 50, .y = 40});
	append(&pz, (Point){.x = 60, .y = 40});
	append(&pz, (Point){.x = 70, .y = 40});

	polyPrint(&pz);
	Polygon pzMirror = mirror(&pz);
	polyPrint(&pzMirror);


	return 0;
}
