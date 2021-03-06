#include <stdlib.h>
#include <stdio.h>
#include <math.h>
unsigned power (unsigned x, unsigned y);
void run_check(unsigned x, unsigned y, unsigned expected_ans){
  if(power(x,y) != expected_ans){
    printf("you are wrong!");
    exit(EXIT_FAILURE);
  }
}


int main(void){
  run_check(-1,2,1);
  run_check(-2,-1,-0.5);
  run_check(-2,0,1);
  run_check(1000,2,1000000);
  run_check(2,0.5,sqrt(2));
  run_check(0,0,1);
  run_check(-1,-1,-1);
  run_check(0.4,1,0.4);
  return EXIT_SUCCESS;
}

