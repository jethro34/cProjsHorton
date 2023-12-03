/* Horton - Beginning C - 5th Ed - Ex 7-2/319
 * sort strings by length
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 64
#define MAX_CHARS 128

int compstr(const void* pStr1, const void* pStr2);

int main() {
  char* fgets_ret;
  char buffer[MAX_CHARS];

  short input_count = 0;
  char* pInput[MAX_ITEMS];

  // allocate memory for first item in pInput
  if (!(pInput[0] = malloc(sizeof(int)))) exit(1);

  do {
    printf("Enter proverb %d (only 'Enter' to terminate): ", input_count+1);
    if (!(fgets_ret = fgets(buffer, MAX_CHARS, stdin))) exit(1);
    
    if (buffer[0] != '\n') {
      // substitute '\n' with null-terminator
      buffer[strcspn(buffer, "\n")] = '\0';

      if (!(strcpy(pInput[input_count++], buffer))) exit(1);
    
      // if valid value, allocate memory for next item
      if (!(pInput[input_count] = malloc(sizeof(int)))) exit(1);
    }
  } while (buffer[0] != '\n');
  putchar('\n');

  if (!input_count) printf("No strings were entered\n");
  else
    qsort(pInput, input_count, sizeof(pInput[0]), compstr);

  // print input after sorting
  printf("Proverbs entered, sorted by length:\n");
  for (short i=0; i<input_count; i++)
    printf("%s\n", pInput[i]);

  // free allocated memory
  for (int i=0; i<input_count; free(pInput[i++]));

  return 0;
}

// helper funct for qsort; '<' sorts string lengths
int compstr(const void* pStr1, const void* pStr2) {
  return strlen(*(char**)pStr1) - strlen(*(char**)pStr2);
}

