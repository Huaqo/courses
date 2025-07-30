/*
 * Name: Joaquin Gottlebe
 * Matrikelnummer: 829101
 */

// Import dependencies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines Constants
#define N 5

// Defines structs
struct le {
  int value[N];
  struct le *next;
};

// Defines type definitions
typedef struct le listelement;
typedef listelement *list;

// Defines functions
void insert(int ar[], list *l);
void delete_all(list *l);
void print_list(list l);
int compare(int ar[], list l, int pos);
int insertBehind(int new[], list *l, int ar[]);
list reverse(list l);

// Implement functions

// Takes an array and a list
// Inserts array as a new element in the list
// Returns void
void insert(int ar[], list *l) {
  listelement *new;
  new = malloc(sizeof(listelement));
  memcpy(new->value, ar, sizeof(int) * N);
  new->next = *l;
  *l = new;
}

// Takes a list
// Frees the memory for the list
// Returns void
void delete_all(list *l) {
  if (l == NULL) {
    printf("List empty.\n");
    return;
  } else {

    list next;
    while (*l != NULL) {
      next = (*l)->next;
      free(*l);
      *l = next;
    }
  }
}

// Takes a list
// Prints it properly formatted
// Returns void
void print_list(list l) {
  if (l == NULL) {
    printf("List empty\n");
    return;
  } else {
    while (l != NULL) {
      printf("[");
      for (int i = 0; i < N; i++) {
        printf("%d", l->value[i]);
        if (i < N - 1) {
          printf(",");
        }
      }
      printf("]");
      if (l->next != NULL)
        printf(",");
      l = l->next;
    }
  }
  printf("\n\n");
}

// Takes an array and a list and a position in the list
// Compares array with the array in the list at the given position
// If the arrays doesnt equal it returns the index where it first differs -1 if
// they are equal, returns -2 if pos is longer then the list or list is empty
int compare(int ar[], list l, int pos) {
  if (l == NULL) {
    printf("List empty.\n");
    return -2;
  } else {

    int index = 0;
    while (l != NULL) {
      if (index == pos) {
        for (int i = 0; i < N; i++) {
          if (l->value[i] != ar[i]) // If arrays arent equal
            return i;
        }
        return -1; // Success
      }
      l = l->next;
      index++;
    }
  }
  return -2; // pos is bigger then list or list is empty
}

// Takes a new array and an array of a list and the list itself
// Inserts behind the lists array
// Returns 0 if successfull otherwise returns -1
int insertBehind(int new[], list *l, int ar[]) {
  if (l == NULL) {
    printf("List empty.\n");
    return -1;
  } else {

    int pos = 0;
    for (list curr = *l; curr; curr = curr->next, pos++) {
      if (compare(ar, *l, pos) == -1) {
        listelement *new_elem = malloc(sizeof(*new_elem));
        if (!new_elem) {
          perror("malloc");
          exit(1);
        }
        memcpy(new_elem->value, new, sizeof(int) * N);
        new_elem->next = curr->next;
        curr->next = new_elem;
        return 0; // success
      }
    }
    return -1; // array not in list
  }
}

// Takes a list
// Reverses the order of the elements and also the order of the order inside the
// elements. Returns a reversed list
list reverse(list l) {

  list new_list = NULL;
  if (l == NULL) {
    printf("List empty.\n");
  } else {

    while (l != NULL) {
      int reversed[N];
      for (int i = 0; i < N; i++) {
        reversed[i] = l->value[N - 1 - i];
      }
      insert(reversed, &new_list);
      l = l->next;
    }
  }
  return new_list;
}

// Takes int array
// Prints it
// Returns void
void print_array(int ar[]) {
  printf("[");
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      printf("%d", ar[i]);
    } else {
      printf("%d, ", ar[i]);
    }
  }
  printf("]");
}

// Takes void
// Main function
// Returns 0 if successfull
int main(void) {

  // Initialising lists
  list testList = NULL;
  list emptyList = NULL;

  // Initialising arrays
  int arr1[N] = {1, 2, 3, 4, 5};
  int arr2[N] = {6, 7, 8, 9, 10};
  int arr3[N] = {11, 12, 13, 14, 15};
  int arrCompare[N] = {6, 7, 8, 9, 10};
  int arrNew[N] = {100, 101, 102, 103, 104};
  int arrNotInList[N] = {90, 91, 92, 93, 94};

  // Insert arrays into lists
  insert(arr1, &testList);
  insert(arr2, &testList);
  insert(arr3, &testList);

  // Print after insert
  printf("\nInserted three arrays into testList: ");
  print_list(testList);

  // Compare testList at position 1 with arrCompare and print result
  int pos = 1;
  int compareResult = compare(arrCompare, testList, pos);
  printf("Compare array ");
  print_array(arrCompare);
  printf(" at position %d of testList: %d\n\n", pos, compareResult);

  // Insert new array into list  behind arr2 and print new list
  int insertResult1 = insertBehind(arrNew, &testList, arr2);
  if (insertResult1 == 0) {
    printf("Inserted ");
    print_array(arrNew);
    printf(" behind ");
    print_array(arr2);
    printf(" of testList.\n");
    printf("testList after insertBehind: ");
    print_list(testList);
  } else {
    print_array(arrNew);
    printf(" not found in testList\n\n");
  }

  // Insert arrNotInList into testList behind
  int insertResult2 = insertBehind(arrNew, &testList, arrNotInList);
  if (insertResult2 == 0) {
    printf("Inserted ");
    print_array(arrNotInList);
    printf(" behind ");
    print_array(arr2);
    printf(" of testList.\n");
    printf("testList after insertBehind: ");
    print_list(testList);
  } else {
    print_array(arrNotInList);
    printf(" not found in testList\n\n");
  }

  // Print reversed testList
  list reversedList = reverse(testList);
  printf("reversedList of testList:");
  print_list(reversedList);

  // Test functions with empty list
  print_list(emptyList);
  compare(arrCompare, emptyList, 1);
  insertBehind(arrNew, &emptyList, arr2);
  reverse(emptyList);

  // Free  memory
  delete_all(&testList);
  delete_all(&reversedList);
  delete_all(&emptyList);

  return 0;
}
