#include <stdio.h>
#include <stdbool.h>

typedef struct tnode
{
  int ind;
  double value;
  double value2;
  double total_c;
  double r;
  double c;
  double t;

  struct tnode *left;
  struct tnode *right;
  struct tnode *next;
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
void Calcdelay(FILE * ptr, TreeNode * head, double cap_sum);
double calcC_(TreeNode * head, double R_prev, double resistPerLength, double dist);
bool readArray(const char * filename, double * * param, Stack * * stack, Stack * * stack_ind);
TreeNode* buildtree(Stack * * stack, Stack * * stack_ind, TreeNode* tr_right, TreeNode* tr_left);
void printTre(TreeNode* tr);
void calcTotalC(TreeNode * head, double capPerLength);
