#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "pa1.h"

#define ARRAYSIZE 3
#define MAXNODES 500
#define INFOSIZE 2
#ifdef TEST_BUILDMAIN
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
  Stack* stack = NULL; stack = createStack(MAXNODES);
  Stack* stack_ind = NULL; stack_ind = createStack(MAXNODES);
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
  //TreeNode* tr_temp = tr;
  FILE * fptr = fopen(argv[2], "w");
  preOrderNode(tr, fptr);
  fclose(fptr);

  //printf("%le\n",Left_child(tr)->value); 
  //Left_child(tr)->value2 = 2;
  //printf("%le\n",Left_child(tr)->value2);
  
  calcTotalC(tr, param[2]); 

  //printf("%le, %le, %le \n",param[0],param[1],param[2]);

  double cc = calcC_(tr, param[0], param[1], 0);

  //printf("%le\n", cc);

  FILE * fptr1 = fopen(argv[3], "wb");
  if(fptr1 != NULL){
  
    Calcdelay(fptr1, tr, 0,cc);
    fclose(fptr1);

  }
  //delayPrint(tr,fptr1);
  
  deleteTreeNode(tr_right);
  deleteTreeNode(tr_left);
  //deleteTreeNode(tr_temp);
  deleteTreeNode(tr);
  free(param);
  free_stack(stack_ind);
  free_stack(stack);
  free(stack_ind->array);
  free(stack->array);
  free(stack);
  free(stack_ind);
  return 0;
}
#endif
