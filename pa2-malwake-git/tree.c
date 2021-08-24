#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>
#include "pa2.h"
#define COUNT 10
#define ARRAYSIZE 10000000
//#define ARRAYSIZE 100000
//#define ARRAYSIZE 10000000000
#define PA2_H


TreeNode *readFileE2(const char * filename){

  FILE * fptr = fopen(filename, "rb");
  
  if (fptr == NULL)
    {
      printf("%d %d %d\n",-1,0,0);
      //fclose(fptr);
      return NULL;
    }
  TreeNode *tr = NULL;
  int *array1 = (int*)calloc(ARRAYSIZE, sizeof(int));
  int *array2 = (int*)calloc(ARRAYSIZE, sizeof(int));
  Stack *stack1 = NULL;
  Stack *stack2 = NULL;
  stack1 = createStack(ARRAYSIZE);
  stack2 = createStack(ARRAYSIZE);
  tr = readArraycheck2(fptr,array1,array2, stack1, stack2);
    if(tr == NULL){
      fclose(fptr);
      free(array1);
      free(array2);
      free(stack1->array);
      free(stack1);
      free(stack2->array);
      free(stack2);
      return NULL;
    }

  fclose(fptr);
  free(array1);
  free(array2);
  free(stack1->array);
  free(stack1);
  free(stack2->array);
  free(stack2);

  return tr;
}

TreeNode *readArraycheck2(FILE * fptr,int * array1, int * array2, Stack * stack1, Stack * stack2){

  int ind = 0;
  unsigned char c = 0;
  int k =0;
  TreeNode *tr = NULL;
  
  while(fread(&ind,sizeof(int),1,fptr)){
    fread(&c,sizeof(c),1,fptr);

    if(c > 3 || c < 0){
      printf("%d %d %d\n",0,0,0);
      return NULL;
    }
    
     (array1)[k] = ind;
     (array2)[k] = (int)c;
    
     k++;

      }
  for(int i = k-1; i >= 0; i--){
    push(stack1,array1[i]);
    push(stack2,array2[i]);
  }

  tr = insertE3(tr, stack1,stack2);

  //print2DUtil(tr, 0);


    fseek (fptr, 0, SEEK_SET);

    if(tr == NULL){
      printf("%d %d %d\n",-1,0,0);
      return NULL;
    }
    
  return tr;
  

}

TreeNode *insertE3(TreeNode* tr,Stack* stack1, Stack* stack2)
{
  int nodes = pop(stack2);
  int key = pop(stack1);
  if (nodes == 0){

    return(createE(key,nodes));
	  }


  else if(nodes == 2){
    tr = createE(key,nodes);
    tr->left  = insertE3(tr->left, stack1, stack2);
    
  }
  else if (nodes == 1){
    tr = createE(key,nodes);
    tr->right = insertE3(tr->right, stack1, stack2);
  }
  else
    {
      tr = createE(key,nodes);
      tr->left = insertE3(tr->left, stack1, stack2);
      tr->right = insertE3(tr->right, stack1, stack2);
    }
  
    tr->height = 1 + maximum(height(tr->left),height(tr->right));
   
  
    tr->balance = findBalance(tr);
  
    return tr;
}

TreeNode* constructTree(int pre[], int size, int array2[])
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, 0, size - 1,
                             size, array2);
}


TreeNode* constructTreeUtil(int pre[], int* preIndex,int low, int high, int size,int array2[])
{
  
  if (*preIndex >= size || low > high){
        return NULL;
  }
 
  
  TreeNode* root = createE(pre[*preIndex],array2[*preIndex]);
    *preIndex = *preIndex + 1;

    if (low == high){
      
        return root;
    }
   
    int i;
    for (i = low; i <= high; ++i){
        if (pre[i] > root->key)
	  {     break;
	  }
    }

    
    
    root->left = constructTreeUtil(pre, preIndex, *preIndex,i -1, size, array2);
    
    root->right = constructTreeUtil(pre, preIndex, i, high, size, array2);

    root->height = 1 + maximum(height(root->left),height(root->right));
   
  
    root->balance = findBalance(root);
 
    return root;
}
