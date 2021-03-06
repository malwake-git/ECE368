#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa1.h"

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  // BT-Delete
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free(tr);
}
// Whole tree (not needed)
void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  if((tn->ind == 0)){
    fprintf(fptr, "(%le %le)\n", tn -> value,tn->value2);
  }
  else{
     fprintf(fptr, "%d(%le)\n", tn -> ind,tn->value);
  }
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

static void postOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
  fprintf(fptr, "%d\n", tn -> ind);
}

// Whole tree (not needed)
void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// Whole tree (not needed)
void postOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  postOrderNode(tr -> root, fptr);
  fclose (fptr);
}

// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/


TreeNode* newNode(int data) 
{ 
    TreeNode * node = malloc(sizeof(TreeNode)); 
    node->ind = data; 
    node->left = node->right = NULL; 
    return (node); 
}
// (not needed)
int search(int * arr, int strt, int end, int info) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == info) 
            break; 
    } 
    return i; 
}
// (not needed)
TreeNode* buildUtil(int * in, int * post, int inStrt, int inEnd, int * pIndex) 
{ 
    // Base case 
    if (inStrt > inEnd) 
        return NULL; 
  
    /* Pick current node from Postorder traversal using 
       postIndex and decrement postIndex */
    TreeNode* node = NULL;
    node = newNode(post[*pIndex]);
    
    (*pIndex)--; 
  
    /* If this node has no children then return */
    if (inStrt == inEnd) 
        return node; 
  
    /* Else find the index of this node in Inorder 
       traversal */
    int iIndex = search(in, inStrt, inEnd, node->ind); 
  
    /* Using index in Inorder traversal, construct left and 
       right subtress */
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex); 
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
    return node; 
}
// (Not needed)
/*
Tree * buildTree(int * inArray, int * postArray, int size)
{
//Tree * buildTree(int * inArr, int * post, int size)

  Tree * tree = malloc(sizeof(Tree));
  int pIndex = size - 1;
  tree->root = buildUtil(inArray, postArray, 0, size - 1, &pIndex);
  return tree;
 
}
*/
int empty(TreeNode *tr){
  return(tr == NULL);
}

TreeNode *create (TreeNode *left, TreeNode *right, int ind, double value, double value2){

  //info = malloc(size * sizeof(float))
  TreeNode *new_node = NULL;
  new_node = malloc(sizeof(TreeNode));
  new_node->ind = ind;
  new_node->value = value;
  new_node->value2 = value2;
  //new_node->info = info;
  new_node->left = left;
  new_node->right = right;
  return new_node;

}

int Info(TreeNode *Node)
{
  return(Node->ind);
}

TreeNode *Left_child (TreeNode *tr)
{
  return(tr->left);

}

TreeNode *Right_child (TreeNode *tr)
{
  return(tr->right);

}

#endif
