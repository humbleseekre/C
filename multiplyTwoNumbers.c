/*
#include <stdio.h>

// // To execute C, please define "int main()"

// // Write a function that takes 2 unsigned 16-bit integers
// // and multiplies them together and returns the answer.
// // Caveat: don't use the multiply operator (no *)
*/

int multiplyTwoNumbers(unsigned int a, unsigned int b){
  unsigned res = 0; // a = 7, b = 3
  int mask = 0;
  while(a){
    if(a&1){ // a = 7
      res += b << mask; 
    }
    ++mask;
    a >>= 1;
  }
  return res;
}

int main() {
  int res = multiplyTwoNumbers(7, 7);
  printf("Mulitplication of these numbers 3 and 7 are %d\n", res); 
  return 0;
}
