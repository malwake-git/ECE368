#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

static void read(const char * filename){
  

  FILE * fptr = fopen(filename, "rb");
  if (fptr == NULL)
    {
      return;
    }

  int ind=0;
  unsigned char c=0;


  while(fread(&ind,sizeof(int),1,fptr)){
    fread(&c,sizeof(c),1,fptr);
    printf("%d %u\n",ind,c);
  }

  return;
}



int main(int argc, char *argv[]){

  // argv[1]: ops (input)                                                 
  // argv[2]: preorder (output)
  if (argc < 2)
    {
      return EXIT_FAILURE;
    }

  //TreeNode* tr = NULL;
   //bool rtv;
   
   //tr = malloc(sizeof(TreeNode));
   read(argv[1]);
   return 0;
   
}
