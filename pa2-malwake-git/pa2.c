#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "pa2.h"

//#ifdef TEST_BUILDPA2

int main(int argc, char ** argv){

  //int main(int argc, char *argv[]){

  // argv[1]: option '-b' or '-e'
  // argv[2]: ops (input)                                                 
  // argv[3]: preorder (output)
  //printf("%s\n",argv[1]);
  if(argc < 3 || argc > 4)
    {
      return EXIT_FAILURE;
    }

  if (strcmp(argv[1], "-b") == 0) {

    if (argc != 4)
    {
      return(EXIT_FAILURE);
    }

   TreeNode* tr = NULL;

   FILE * fptr = fopen(argv[2], "rb");
  if (fptr == NULL)
    {
      printf("%d\n",-1);
      return EXIT_FAILURE;
    }

   tr = readArray( fptr, tr);

   if(tr == NULL){
      printf("%d\n",0);
      fclose(fptr);
      return EXIT_FAILURE;
    }
     printf("%d\n",1);

   fclose(fptr);

   
   //tr = readFile(argv[2]);
   
  if (tr == NULL)
    {

      return EXIT_FAILURE;
    }

  //FILE * fptr1 = fopen(argv[2], "wb");
  //if(fptr1 != NULL){
    bool rtw = printPreOrder(tr,argv[3]);
    if(rtw == false){
      deleteTreeNode(tr);
      return EXIT_FAILURE;
    }


  /*
  FILE * fptr1 = fopen(argv[3], "wb");
  if(fptr1 != NULL){
      fclose(fptr1);
  }
  */

  deleteTreeNode(tr);
  return EXIT_SUCCESS;
  }

  else if(strcmp(argv[1], "-e") == 0){

    if (argc != 3)
    {
      return EXIT_FAILURE;
    }

      TreeNode *tr = NULL;
      tr = readFileE2(argv[2]);
      //print2DUtil(tr, 0);
      
    if (tr == NULL)
    {
      return EXIT_FAILURE;
    }
    
  bool checktr = checkBST(tr);
  
  bool checkht = checkBalance(tr);
  printf("%d %d %d\n",1,(int)checktr,(int)checkht);
 
  
    deleteTreeNode(tr);
    //free(tr);

    return EXIT_SUCCESS;


  }
  else{
    return(EXIT_FAILURE);
  }
}



//#endif
