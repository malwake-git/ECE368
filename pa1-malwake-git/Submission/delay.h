#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#ifndef DELAY_H
#define DELAY_H
typedef struct tstack
{
  int top;
  unsigned capacity;
  double* array;
  //int ind;
} Stack;


typedef struct tnode
{
  int ind;
  double value;
  double value2;
  double total_c;
  double r;
  double c;
  double t;

  //double t;

  struct tnode *left;
  struct tnode *right;
  //struct tnode *next;
} TreeNode;

typedef struct trnode
{
  TreeNode * root;
} Tree;

int empty(TreeNode *tr);
//TreeNode *create ( TreeNode *left, TreeNode *right);
TreeNode *create (TreeNode *left, TreeNode *right, int ind, double value, double value2);
int Info (TreeNode *Node);
TreeNode *Left_child (TreeNode *tr);
TreeNode *Right_child (TreeNode *tr);
void freeTree(Tree * tr);
void preOrder(Tree * tr, char * filename);
//Tree * buildTree(int * inArray, int * postArray, int size);
void deleteTreeNode(TreeNode * tr);
void preOrderNode(TreeNode * tn, FILE * fptr);
//void postOrderNode(TreeNode * tn, FILE * fptr);
void postOrder(Tree * tr, char * filename);
TreeNode* newNode(int data) ;
int search(int * arr, int strt, int end, int info);
TreeNode* buildUtil(int * in, int * post, int inStrt, int inEnd, int * pIndex);

bool readArray(const char * filename, double * * param, Stack * stack, Stack * stack_ind);
TreeNode* buildtree(Stack * stack, Stack * stack_ind, TreeNode* tr_right, TreeNode* tr_left);
void printTre(TreeNode* tr);
void delayPrint(TreeNode * tn, FILE * fptr);
void calcTotalC(TreeNode * tr, double capPerLength);
double calcC_(TreeNode * tr, double R_prev, double resistPerLength, double dist);
void Calcdelay(FILE * ptr, TreeNode * tr, double sum, double c);
void createStack(unsigned capacity, Stack *stack);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack,double item);
//void push_tree(Stack* stack,TreeNode tr);
double pop(Stack* stack);
void free_stack(Stack* stack);
//TreeNode pop_tree(Stack* stack);
double peek(Stack* stack);
#endif
