#include "pandemic.h"
#include <string.h>

country_t parseLine(char * line) {
  //WRITE ME
  country_t ans;
  for(int i = 0;i<strlen(line);i++){
    if(line[i] != ','){
      ans.name[i] = line[i];
    } else {
      ans.name[i] = '\0';
      if(i >= strlen(len -1)){
        perror("something wrong");
	return EXIT_FAILURE;
      }
      for(int j = i+1; j < strlen(line);j++){
        
      }
    }
  }
  
  
  //ans.name[0] = '\0';
  //ans.population = 0;
  return ans;
}

void calcRunningAvg(unsigned * data, size_t n_days, double * avg) {
  //WRITE ME
}

void calcCumulative(unsigned * data, size_t n_days, uint64_t pop, double * cum) {
  //WRITE ME
}

void printCountryWithMax(country_t * countries,
                         size_t n_countries,
                         unsigned ** data,
                         size_t n_days) {
  //WRITE ME
}
