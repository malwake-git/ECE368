#ifndef STACK_H
#define STACK_H

typedef struct tstack
{
  int top;
  unsigned capacity;
  double* array;
  //int ind;
} Stack;

Stack* createStack(unsigned capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack,double item);
//void push_tree(Stack* stack,TreeNode tr);
double pop(Stack* stack);
void free_stack(Stack* stack);
//TreeNode pop_tree(Stack* stack);
double peek(Stack* stack);
bool readArray(const char * filename, double * * param, Stack * * stack, Stack * * stack_ind);
TreeNode* buildtree(Stack * * stack, Stack * * stack_ind, TreeNode* tr_right, TreeNode* tr_left);
#endif
