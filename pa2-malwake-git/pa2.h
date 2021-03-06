#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

//#ifndef PA2_H
#define PA2_H

typedef struct tnode
{
  int key;
  int child;
  int balance;
  int height;
  int nodes;
  
  struct tnode *left;
  struct tnode *right;
  //struct tnode *next;
} TreeNode;

typedef struct _tnode
{
  int key;
  char ch;
  
} stnode;

typedef struct tstack
{
  int top;
  unsigned capacity;
  int* array;
} Stack;

void freePreNode(TreeNode *tr);

void print2DUtil(TreeNode *root, int space);
TreeNode *create(int key);
stnode *createNode(int key,char ch);
int height(TreeNode *tr);
int maximum(int first, int second);
TreeNode *insert(TreeNode* tr, int key);
TreeNode *insertE1(TreeNode* tr, int key);

TreeNode *rightRotate(TreeNode *y);
TreeNode *leftRotate(TreeNode *y);
int findBalance(TreeNode *tr);

int key(TreeNode *Node);
TreeNode *Left_child (TreeNode *tr);
TreeNode *Right_child (TreeNode *tr);
TreeNode *rightBalance(TreeNode *tr, int balance);
TreeNode *leftBalance(TreeNode *tr, int balance);


TreeNode *balance(TreeNode *tr);
void postOrderNode(TreeNode * tn, FILE * fptr);
void preOrderNode(TreeNode * tn, FILE * filename);
bool printPreOrder(TreeNode * tn, const char * filename);
void deleteTreeNode(TreeNode * tr);
void preTree(TreeNode* tr);

void numChild(TreeNode *tr);
TreeNode *readFile(const char * filename);
TreeNode *readArray(FILE * fptr, TreeNode * tr);
//TreeNode *readArray(const char * filename);
TreeNode *deleteNode(TreeNode * tr, int key);
TreeNode* preNode(TreeNode* tr);
TreeNode* prepreNode(TreeNode* tr);

TreeNode *readFileE(const char * filename);
bool checkBalance(TreeNode *tr);
bool checkBST(TreeNode *tr);
TreeNode *readArraycheck(FILE * fptr);
TreeNode *insertE(TreeNode* tr, int key, int nodes);
TreeNode *createE(int key,int nodes);

TreeNode *readArraycheck2(FILE * fptr,int * array1, int * array2, Stack * stack1, Stack * stack2);
TreeNode *readFileE2(const char * filename);
TreeNode* constructTreeUtil(int pre[], int* preIndex,int low, int high,int size, int array2[]);
TreeNode* constructTree(int pre[], int size, int array2[]);
TreeNode *insertE3(TreeNode* tr,Stack* stack1, Stack* stack2);

Stack* createStack(unsigned capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack,int item);
int pop(Stack* stack);
int peek(Stack* stack);

TreeNode *deleteNodeE(TreeNode * tr, int key);

//#endif
