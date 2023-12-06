/* Horton - Beginning C - 5th Ed - Ex 13-3/588
 * define & test a macro, PRINT_VALUE(expr)
 * (where expr is a math expression),
 * that ouputs on a new line 'expr = result'
 * (where result is the resulting value
 * from evaluating expr).
 */

#include <stdio.h>

#define PRINT_VALUE(expr) printf(#expr " = %d", expr)

int main() {
  
  PRINT_VALUE((7 + 6) * 3 + 30);

  return 0;
}

