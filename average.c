/* Horton - Beginning C - 5th Ed - Ex 7-1/319
 * floating-point dinamic average calculator 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 64
#define MAX_DIGITS 32

int main() {

  char* fgets_ret;
  char buffer[MAX_DIGITS];

  short input_count = 0;
  float* pInput[MAX_ITEMS];
  float acc=0, ave=0;

  // allocate memory for first item in pInput
  if (!(pInput[0] = malloc(sizeof(int)))) exit(1);

  do {
    printf("Enter float %d (only 'Enter' to terminate): ", input_count+1);
    if (!(fgets_ret = fgets(buffer, MAX_DIGITS, stdin))) exit(1);
    
    if (buffer[0] == '\n') pInput[input_count] = NULL;
    else {
      // substitute '\n' with null-terminator
      buffer[strcspn(buffer, "\n")] = 0;

      if ((*pInput[input_count] = strtof(buffer, NULL)) == 0) exit(1);
    
      // if valid value, allocate memory for next item
      if (!(pInput[++input_count] = malloc(sizeof(int)))) exit(1);
    }
  } while (pInput[input_count]);
  
  // print input
  for (short i=0; i<input_count; i++)
    printf("%.2f\t", *pInput[i]);
  putchar('\n');

 
  if (input_count) {
    // calc average of all input
    for (short i=0; i<input_count; acc += *pInput[i++]);
    ave = acc/input_count;
    printf("Average of the %d number(s): %.2f\n", input_count, ave);
  } else printf("No numbers were entered...\n");
  
  for (int i=0; i<input_count; free(pInput[i++]));   // free allocated memory

  return 0;
}
