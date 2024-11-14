#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *mywdfunc(unsigned int bufsize) {
  if (bufsize < 100) {
    return NULL;
  }

  char *buf = (char *)calloc(bufsize,sizeof(char));
  
  if (buf == NULL){
      return NULL;
  }

  if (getcwd(buf,bufsize-1) == NULL) {
    free(buf);
    return NULL;
  }

  return buf; 
}

int main() {

  char *ret = mywdfunc(512);

  printf("%s", ret);
  free(ret);
  return EXIT_SUCCESS;
}
