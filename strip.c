/* Horton - Beginning C - 5th Ed - Ex 7-3/319
 * read a string & display it stripped of non-letters
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 128

int main() {
  char *pStr, *pTkn;
  char *pDlm = ";., !?\"\n"; // init delimiter str

  // allocate memory for ptrs
  if (!(pStr = calloc(MAX_CHARS, sizeof(int)))) exit(1);
  if (!(pTkn = malloc(sizeof(int)))) exit(1);

  printf("Enter string: ");
  if (!fgets(pStr, MAX_CHARS, stdin)) exit(1);
    
  if (pStr[0] == '\n') return 0;
  
  printf("Stripped string:\n");
  pTkn = strtok(pStr, pDlm); 
  
  while (pTkn) {
    printf("%s", pTkn);
    pTkn = strtok(NULL, pDlm); 
  }
  putchar('\n');

  // free allocated memory
  free(pStr);
  free(pTkn);

  return 0;
}

