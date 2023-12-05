/* Horton - Beginning C - 5th Ed - Ex 13-1/588
 * define a macro for comparing two values & test it
 */

#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x, y) (x) == (y) ? 0 : (x) < (y) ? -1 : 1
#define LOOPS 100
#define POSRANGE 10

int main() {
  
  int n1, n2;

  for (int i=0; i<LOOPS; i++) {
    n1 = rand() % POSRANGE - 5;
    n2 = rand() % POSRANGE - 5;
    if (COMPARE(n1, n2) == -1)
      printf("%d is less than %d\n", n1, n2);
    else if (COMPARE(n1, n2) == 1)
      printf("%d is more than %d\n", n1, n2);
    else
      printf("%d is equal to %d\n", n1, n2);
  }

  return 0;
}

