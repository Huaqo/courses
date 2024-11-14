#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define SIZE 512

int main() {

  int fd = open("./test.txt", O_RDWR); 
  if (fd == -1){
    perror("could not open file");
    return EXIT_FAILURE;
  }

  char * buffer = (char *) calloc(SIZE, sizeof(char)); 

  if (buffer == NULL) {
    perror("could not allocate buffer");
    close(fd);
    return EXIT_FAILURE;
  }

  ssize_t r = read(fd, buffer, SIZE-1); 
  if (r == -1) {
    perror("could not read file");
    free(buffer);
    close(fd);
    return EXIT_FAILURE;
  }
  return 0;

  printf("%.*s", SIZE-1, buffer);
  free(buffer);
  close(fd);
  return EXIT_SUCCESS;
}
