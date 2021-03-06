#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "stack.h"

#ifdef TEST_BUILDSTACK
Stack* createStack(unsigned capacity)
{
    Stack* stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (double*)malloc(stack->capacity * sizeof(double));
    //stack->ind = (int)(sizeof(int));
    return stack;
}

int isFull(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

void push(Stack* stack, double item)
{
  if (isFull(stack)){
        return;
  }
    stack->array[++stack->top] = item;
    //stack->ind = ind;
    //printf("%le pushed to stack\n", item);
}

//void push_tree(Stack* stack, TreeNode* tr)
//{
//if (isFull(stack)){
//      return;
//}
//stack->tr[++stack->top] = tr;
    //printf("%d pushed to stack\n", (tr->ind));
//}

double pop(Stack* stack)
{
  if (isEmpty(stack)){
      return INT_MIN;
  }
    return stack->array[stack->top--];
}

//TreeNode pop_tree(Stack* stack)
//{
  //if (isEmpty(stack)){
  //    return INT_MIN;
  //}
  //  return stack->tr[stack->top--];
//}

void free_stack(Stack* stack)
{
  //if (isEmpty(stack)){
  //  return INT_MIN;
  //}
  //stack->array = NULL;
  //free(stack->array);
   

    // Finally free the stack
  //stack = NULL;
  //free(stack);
   
    while(!isEmpty(stack)){
    free(stack->array);
    stack->array = NULL;
    free(stack);
    stack = NULL;
    }

    //return;
}

double peek(Stack* stack)
{
  if (isEmpty(stack)){
        return INT_MIN;
  }
    return stack->array[stack->top];
}

#endif
