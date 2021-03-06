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
//#define ARRAYSIZE 1000
//#define ARRAYSIZE 100000
#define ARRAYSIZE 10000000
//#define ARRAYSIZE 1000000
//#define ARRAYSIZE 100000000
//#define ARRAYSIZE 10000000000
#define PA2_H

Stack* createStack(unsigned capacity)
{
  Stack* stack = (Stack*)calloc(1,sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)calloc(stack->capacity, sizeof(int));

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

void push(Stack* stack, int item)
{
  if (isFull(stack)){
        return;
  }
    stack->array[++stack->top] = item;  
}

int pop(Stack* stack)
{
  if (isEmpty(stack)){
      return INT_MIN;
  }
    return stack->array[stack->top--];
}


int peek(Stack* stack)
{
  if (isEmpty(stack)){
        return INT_MIN;
  }
    return stack->array[stack->top];
}
