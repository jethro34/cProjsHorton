/* Horton - Beginning C - 5th Ed - Ex 8-1/347
 * read a string of arbitrary numbers,
 * store them in an array, and get their average
 * via a function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 128
#define MAX_FLOATS 64

int main() {
  char *pStr, *pTkn;
  char *pDlm = " \n";       // init delimiter str
  float *pFlts[MAX_FLOATS];  // floats array
  short fltcount = 0;
  float accavg=0;

  // allocate memory for ptrs
  if (!(pStr = calloc(MAX_CHARS, sizeof(int)))) exit(1);
  if (!(pTkn = malloc(sizeof(int)))) exit(1);

  printf("Enter floats separated by a space: \n");
  if (!fgets(pStr, MAX_CHARS, stdin)) exit(1);
    
  if (pStr[0] == '\n') return 0;
  
  // get first token, store as string
  pTkn = strtok(pStr, pDlm); 
  
  while (pTkn) {
    // if valid token, allocate memory to store as a float
    if (!(pFlts[fltcount] = malloc(sizeof(int)))) exit(1);
    // convert to float & store 
    *pFlts[fltcount++] = strtof(pTkn, NULL); 
    pTkn = strtok(NULL, pDlm);  // keep asking for tokens
  }
  putchar('\n');
  
  // calculate average
  for (short i=0; i<fltcount; accavg += *pFlts[i++]);
  accavg /= fltcount;

  printf("Average of the floats entered: %.2f\n", accavg);

  // free allocated memory
  free(pStr);
  free(pTkn);
  for (short i=0; i<fltcount; free(pFlts[i++]));

  return 0;
}

