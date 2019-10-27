#include <cstdio>

int step_function(int x);

int main(){

  int x = 0;
  if (x > 0) printf("Positive.\n");
  else if (x <0) printf("Negative.\n");
  else printf("Zero.\n");
/////////////////////////////////////
  printf("Ten %d, Twenty %d, Thirtey %d\n", 10, 20, 30);

  int num1 = 42;
  int result1 = step_function(num1);
  int num2 = 0;
  int result2 = step_function(num2);
  int num3 = -32767;
  int result3 = step_function(num3);

  printf("Num1: %d, Step: %d\n", num1, result1);
  printf("Num2: %d, Step: %d\n", num2, result2);
  printf("Num3: %d, Step: %d\n", num3, result3);

}

/**
 * Mathematical step_function.
 *
 * @param[in] (x) any positive or negative number 
 * @return 
 */

int step_function(int x){
  int result = 0;
  if (x <0){
    result = -1;
  } else if (x > 0){
    result = 1;
  }
  return result;
}