#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  size_t len = strlen(inputName)+8;
  char * res = malloc(len*sizeof(*res));
  strcpy(res,inputName);
  const char * s = ".counts";
  strcat(res,s);
  return res;
  
}
