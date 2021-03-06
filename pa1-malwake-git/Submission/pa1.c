#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "delay.h"

#define ARRAYSIZE 3
#define MAXNODES 100000
#define INFOSIZE 2
#ifdef TEST_BUILDPA1
int main(int argc, char *argv[]){

  // argv[1]: prerder (input)                                                
  // argv[2]: postorder (output) 
  // argv[3]: postorder (output)
  if (argc < 4)
    {
      return EXIT_FAILURE;
    }

  //double * preArray = NULL;
  double * param;
  Stack* stack =NULL;
  stack = (Stack*)malloc(sizeof(Stack));
  //stack = (*Stack)calloc(1,sizeof(Stack));
  createStack(MAXNODES,stack);
 
  Stack* stack_ind = NULL;
  stack_ind = (Stack*)malloc(sizeof(Stack));
  //stack_ind = (*Stack)calloc(1,sizeof(Stack));
  createStack(MAXNODES,stack_ind);
  TreeNode* tr = NULL;
  TreeNode* tr_right = NULL;
  TreeNode* tr_left = NULL;
  bool rtv;
  
  rtv = readArray(argv[1], &param, stack, stack_ind);
 
  if (rtv == false)
    {
      return EXIT_FAILURE;
    }
  
  tr = buildtree(stack,stack_ind,tr_right,tr_left);
  //free(stack->array);
  //free(stack);
  //free(stack_ind->array);
  //free(stack_ind);
  //TreeNode* tr_temp = tr;
  FILE * fptr = fopen(argv[2], "wb");
  preOrderNode(tr, fptr);
  fclose(fptr);

  
  calcTotalC(tr, param[2]); 


  double cc = calcC_(tr, param[0], param[1], 0);

  //printf("%le\n", cc);

  FILE * fptr1 = fopen(argv[3], "wb");
  if(fptr1 != NULL){
  
    Calcdelay(fptr1, tr, 0,cc);
    fclose(fptr1);

  }
  //delayPrint(tr,fptr1);
  //push(stack,3.0);
  //push(stack_ind,4.0);
  free(stack_ind->array);
  free(stack->array);
  free(stack);
  free(stack_ind);
  
  deleteTreeNode(tr_right);
  deleteTreeNode(tr_left);
  deleteTreeNode(tr);

  free(param);

  return 0;
}
#endif
