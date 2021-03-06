#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname,"r");
  if (f == NULL) {
      perror("Could not open file!");
      exit(EXIT_FAILURE);
  }
  char * line = NULL;
  size_t sz = 0;
  kvarray_t * res;
  res = malloc(sizeof(*res));
  res->sz = 0;
  res->arr = NULL;
  while(getline(&line,&sz,f) >= 0){
    char * e = strchr(line,'=');
    char * n = strchr(line,'\n');
    res->arr = realloc(res->arr,(res->sz+1)*sizeof(*res->arr));
    res->arr[res->sz].key = strndup(line,(size_t)(e-line));
    res->arr[res->sz].value = strndup(e+1,(size_t)(n-e-1));
   
    res->sz++;
  }
  free(line);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    exit(EXIT_FAILURE);
  }
  return res;
}
void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(size_t i = 0; i < pairs->sz; i++){
    free(pairs->arr[i].key);
    free(pairs->arr[i].value);
  }
  free(pairs->arr);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (size_t i = 0; i < pairs->sz; i++) {
    printf("key = '%s' value = '%s'\n", pairs->arr[i].key, pairs->arr[i].value);
  }  
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for(size_t i = 0;i < pairs->sz;i++){
    if(strcmp(key,pairs->arr[i].key) == 0){
      return pairs->arr[i].value;
  }
  }
  return NULL;
  
}
