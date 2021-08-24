#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

static bool readArray(const char * filename, int * * array, int * size)
{
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
    {
      return false;
    }
  int numint = 0;
  int value;
  while (fscanf(fptr, "%[^\n]", &value) != EOF)
    {
      numint ++;
      printf("%l\n");
    }
  if (numint == 0)
    {
      // no integer to read
      return false;
    }
  * size = numint;
  int * arr = malloc(sizeof(int) * numint);
  fseek (fptr, 0, SEEK_SET);
  //int ind = 0;
  while (ind < numint)
    {
      if (fscanf(fptr, "%d", & arr[ind]) != 1)
	{
	  fprintf(stderr, "SOMETHING WRONG\n");
	  free (arr);
	  * size = 0;
	  return false;
	}
      ind ++;
    }
  fclose (fptr);
  * array = arr;
  return true;
}


int main(int argc, char *argv[]){

  // argv[1]: prerder (input)                                                
  // argv[2]: postorder (output) 
  // argv[3]: postorder (output)
  if (argc < 4)
    {
      return EXIT_FAILURE;
    }

  int * inArray = NULL;
  int * postArray = NULL;
  int insize;
  int postsize;
  bool rtv;
  rtv = readArray(argv[1], & inArray, & insize);
  if (rtv == false)
    {
      return EXIT_FAILURE;
    }



  return 0;
}
