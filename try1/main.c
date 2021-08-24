#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


int main (int argc, char * * argv){

  Stack* stack = createStack(10);
  printf("Top: %le, ind:%d\n",peek(stack),stack->top);
  push(stack, 10);
  
  printf("Top: %le, ind:%d\n",peek(stack),stack->top);

   push(stack, 10);
    push(stack, 10);

      printf("Top: %le, ind:%d\n",peek(stack),stack->top);

    printf("Top: %le, ind:%d\n",peek(stack),stack->top);



}
