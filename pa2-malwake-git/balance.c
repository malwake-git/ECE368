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
#define PA2_H


//#ifdef TEST_BUILDBALANCE

TreeNode *readFile(const char * filename){

  // if( access( filename, F_OK ) == 0 ) {
  //printf("%d\n",-1);
  //return false;
  TreeNode *tr = NULL;

  //}

  FILE * fptr = fopen(filename, "rb");
  if (fptr == NULL)
    {
      printf("%d\n",-1);
      return NULL;
    }
  tr = readArray(fptr,tr);
    if(tr == NULL){
      fclose(fptr);
      printf("%d\n",0);
      return NULL;
    }
  fclose(fptr);
  printf("%d\n",1);
  return tr;

}

TreeNode *readFileE(const char * filename){

  FILE * fptr = fopen(filename, "rb");
  if (fptr == NULL)
    {
      printf("%d %d %d\n",-1,0,0);
      return NULL;
    }
  //printf("here\n");
  TreeNode *tr = NULL;
   tr = readArraycheck(fptr);
    if(tr == NULL){
      fclose(fptr);
      printf("%d %d %d\n",-1,0,0);
      return NULL;
    }
    //printf("here1\n");

  fclose(fptr);

  return tr;
}


TreeNode *readArraycheck(FILE * fptr){

  int ind = 0;
  unsigned char c = 0;
  TreeNode *tr = NULL;
  
  while(fread(&ind,sizeof(int),1,fptr)){
    fread(&c,sizeof(c),1,fptr);
    tr = insertE(tr, ind,(int)c);

      }
    fseek (fptr, 0, SEEK_SET);
  return tr;
  

}

TreeNode *insertE(TreeNode* tr, int key, int nodes)
{
  if (tr == NULL){
    //printf("Here4\n");
    return(createE(key,nodes));
	  }
  //printf("nodes= %d\n",nodes);

  if (key <= tr->key){
    tr->left  = insertE(tr->left, key, nodes);
  }
  else if (key > tr->key){
    tr->right = insertE(tr->right, key,nodes);
  }
  
    tr->height = 1 + maximum(height(tr->left),height(tr->right));
   
  
    //tr->balance = findBalance(tr);
    return tr;
}

TreeNode *insertE1(TreeNode* tr, int key)
{
  if (tr == NULL){
    //printf("Here4\n");
    return(create(key));
	  }
  //printf("nodes= %d\n",nodes);

  if (key <= tr->key){
    tr->left  = insertE1(tr->left, key);
  }
  else if (key > tr->key){
    tr->right = insertE1(tr->right, key);
  }
  
    tr->height = 1 + maximum(height(tr->left),height(tr->right));
   
  
    tr->balance = findBalance(tr);
    return tr;
}

TreeNode *readArray(FILE * fptr,TreeNode * tr)
{
  //FILE * fptr = fopen(filename, "rb");
  //if (fptr == NULL)
  // {
  //    return NULL;
  // }

  int ind=0;
  //TreeNode *tr = NULL;
  char c;


  while(fread(&ind,sizeof(int),1,fptr)){
    fread(&c,sizeof(c),1,fptr);
    if(c == 'i'){

      tr = insert(tr, ind);
      tr = balance(tr);
      //print2DUtil(tr, 0);

      }
    else if(c == 'd'){
      //printf("---------------------------------------------------\n");
      //printf("d = %d\n",ind);
    
      //print2DUtil(tr, 0);
      //tr = balance(tr);
      deleteNodeE(tr,ind);
      //print2DUtil(tr, 0);

      //tr = balance(tr);
    }
    else{
      return NULL;
    }
  }

    
  fseek (fptr, 0, SEEK_SET);
 
  //fclose (fptr);
  return tr;
}

bool checkBST(TreeNode *tr){

  if (tr == NULL)
    return true;
     
  if (tr->left != NULL && tr->left->key > tr->key)
    return false;
     
  if (tr->right != NULL && tr->right->key < tr->key)
    return false;
   
  if (!checkBST(tr->left) || !checkBST(tr->right))
    return false;
     
  return true;

  /*
  if (tr == NULL){
    return true;
  }

  //printf("tr->key = %d\n",tr->key);
  if(tr->left == NULL && tr->right == NULL){
    return true;
  }
     
  if ((tr->left == NULL || tr->left->key > tr->key) ){
    return false;
  }
     
  if (tr->right == NULL || tr->right->key <= tr->key){
    return false;
  }
  */
  /*
  int nodes = tr->nodes;
  //printf("key = %d, nodes= %d\n",tr->key, tr->nodes);

  switch(nodes)
    {
    case 1:
      if(tr->right == NULL && tr->left != NULL){
	return false;
      }
      else{
	return checkBST(tr->right);
      }
    case 2:
      if(tr->left == NULL && tr->right != NULL){
	return false;
      }
      else{
	return checkBST(tr->left);
      }
    case 3:
      if(tr->right == NULL || tr->left == NULL){
	return false;
      }
      else{
	return (checkBST(tr->left) && checkBST(tr->right));
      }
    case 0:
      if(tr->right != NULL || tr->left != NULL){
	return false;
      }
      else{
	return true;
      }
      
    }
  */
  //return true;
  //return true;
  /*
  if(nodes == 1 && tr->right == NULL){
    return false;
  }
  else if (){
    return checkBST(tr->right);
  }

  if(nodes == 2 && (tr->left == NULL)){
    return false;
  }
  else{
    return checkBST(tr->left);
  }
  
  if(nodes == 3 && (tr->right == NULL || tr->left == NULL)){
    return false;
  }
  else{
    return (checkBST(tr->left) && checkBST(tr->right));
  }
  
  

  if (nodes == 0 && (tr->left != NULL || tr->right != NULL)){
    return false;
  }
  */
     
}

bool checkBalance(TreeNode *tr){

  int left=1; 
  int right=1; 
 
  if (tr == NULL){
        return true;
  }
  if(tr->left != NULL){
    left = tr->left->height;
  }
  if(tr->right != NULL){
    right = tr->right->height;
  }
 if (abs(left - right) <= 1 && checkBalance(tr->left) && checkBalance(tr->right)){
        return true;
    }
    else{
    return false;
    }

}



TreeNode *balance(TreeNode *tr){

    tr->height = maximum(height(tr->left),height(tr->right))+1;

    int balance = findBalance(tr);
    int balance1 = 0;

     if (balance > 1 ){
       if(tr->left != NULL){
	 balance1 = findBalance(tr->left);
       }
    
      //if(tr->key > tr->left->key && balance1 > 0){
       if(balance1 > 0 && (tr->left->left != NULL)){
        return rightRotate(tr);
      }
      //else if (tr->key < tr->left->key || (tr->key > tr->left->key && balance1 < 0)){

       else if(balance1 < 0 && (tr->left->right != NULL)){
	  tr->left =  leftRotate(tr->left);
	  return rightRotate(tr);
      }
     }

    

   else if (balance < -1 ){
     //printf("tr->key %d, ,tr->right = %d,key = %d, balance = %d\n",tr->key,tr->right->key, key, balance);
     if(tr->right != NULL ){
      balance1 = findBalance(tr->right);
     }
   
      //if(tr->key < tr->right->key && balance1 < 0){
      if(balance1 < 0 && (tr->right->right != NULL)){
      return leftRotate(tr);
       }
//else if (tr->key > tr->right->key || (tr->key < tr->right->key && balance1 > 0)){
    else if(balance1 > 0 && (tr->right->left != NULL)){
	  tr->right =  rightRotate(tr->right);
	  return leftRotate(tr);
      }

   }
    
    return tr;

}




void numChild(TreeNode *tr){

  if((tr->left != NULL) && (tr->right != NULL))
    {
      tr->child = 3;
    }
  else if((tr->left != NULL) && (tr->right == NULL))
    {
      tr->child = 2;
    }
  else if((tr->left == NULL) && (tr->right != NULL))
    {
      tr->child = 1;
    }
  else
    {
      tr->child = 0;
    }


  return;
}
TreeNode *deleteNodeE(TreeNode * tr, int key){

  if ( key <= tr->key )
        tr->left = deleteNode(tr->left, key);
 
  else if( key > tr->key )
        tr->right = deleteNode(tr->right, key);

  else
    {
      if( (tr->left == NULL) || (tr->right == NULL) )
        {
            TreeNode *temp = tr->left ? tr->left : tr->right;
 
            if (temp == NULL)
            {
                temp = tr;
                tr = NULL;
            }
            else {
             *tr = *temp;
	    }
            free(temp);
        }
        else
        {
          
            TreeNode* temp = preNode(tr->left);
 
            tr->key = temp->key;
 
            tr->left = deleteNode(tr->left, temp->key);
        }
    }
 
  if (tr == NULL){
      return tr;
  }
    tr->height = 1 + maximum(height(tr->left),height(tr->right));
 
  
    tr->balance = findBalance(tr);

    // tr = balance(tr);
    tr = balance(tr);

    return tr;

}


TreeNode *deleteNode(TreeNode * tr, int key)
{
  // BT-Delete
  //printf("tr->key = %d & key = %d\n",tr->key,key);
  if (tr == NULL)
    {
      return NULL;
    }

  // looking for the right node
  if (key < tr->key){
    //tr = balance(tr);
    tr->left = deleteNode(tr->left, key);
  }
 
  else if (key > tr->key){
    //tr = balance(tr);
    tr->right = deleteNode(tr->right, key);
  }

  // the node has one child or no children
    else {
      
      if (tr->left == NULL && tr->right == NULL)
	{
	  free(tr);
	  return NULL;
	}
      else if (tr->left == NULL) {
            TreeNode* temp = tr->right;
            free(tr);
            return(temp);
        }
        else if (tr->right == NULL) {
            TreeNode* temp = tr->left;
            free(tr);
            return(temp);
        }
	else{

  // the node has two children
  TreeNode* temp = preNode(tr->left);
  //printf("temp->key = %d,tr->key = %d\n",temp->key,tr->key);

  TreeNode *temp1 = prepreNode(tr->left);

  if(tr->key == temp->key){

    if(temp1 == NULL){
  
      //temp1->right = NULL;
      //free(temp);
      //return tr;
      //}
      //else{
    tr->right = deleteNode(tr->right, (temp)->key);
  tr = balance(tr);
  return tr;
  }
    

    }
 
  

  tr->key = (temp)->key;
 
  tr->left = deleteNode(tr->left, (temp)->key);
	}
  
    }
  tr = balance(tr);
  return tr;
  
}

void freePreNode(TreeNode *tr){
  while (tr && tr->right != NULL){
    tr = tr->right;
    }
  tr = NULL;
  free(tr);
  return;
    
}


TreeNode* prepreNode(TreeNode* tr)
{
   TreeNode * current = tr;
   TreeNode * curren1 = NULL;

    
    while (current && current->right != NULL){
      curren1 = current;
      current = current->right;
    }
 
    return curren1;
}

TreeNode* preNode(TreeNode* tr)
{
  //if(!tr){
  //return NULL;
  //}
    TreeNode * current = tr;

    
    // while (current && current->right != NULL){
    while(current->right != NULL){
    current = current->right;
    }
 
    return current;
}



/////////////////////////////

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

bool printPreOrder(TreeNode * tn, const char * filename){


  if (tn == NULL)
    {
      return false;
    }
  FILE * fptr = fopen(filename, "wb");
  if(fptr == NULL){
    return false;
  }

  preOrderNode(tn,fptr);
  
  fclose(fptr);
  return true;
}

void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }

  numChild(tn);
  char ch =(char) tn->child;
  
  //printf("%d ", tn -> key);
  //printf("%c\n",ch);
  //fprintf(fptr, "%d %c\n", tn -> key,ch);
  //stnode * node = NULL;
  //node = createNode(tn->key, ch);

  //fwrite(&node, 1, sizeof(stnode), fptr);

  fwrite( &tn->key , 1, sizeof(tn->key), fptr );
 
  fwrite( &ch, 1, sizeof(ch), fptr );

  //free(node);

  //fwrite(&(tn->key),sizeof(tn->key),1,fptr);

  //fwrite(&(ch),sizeof(ch),1,fptr);
  
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
  
  return;
  //fwrite(&(new),sizeof(char),1,fptr);

}

void postOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  
  postOrderNode(tn -> left, fptr);
  postOrderNode(tn -> right, fptr);
  numChild(tn);
  char ch = tn->child + '0';


  fwrite(&(tn->key),sizeof(tn->key),1,fptr);

  fwrite(&(ch),sizeof(ch),1,fptr);
  
  //fprintf(fptr, "%d %d\n", tn -> key,tn->child);

}

void preTree(TreeNode* tr)
{
  if(tr == NULL)
    {
      return;
    }
    numChild(tr);
    printf("%d ", tr->key);
    printf("%d\n", tr->child);
    preTree(tr-> left);
    preTree(tr-> right);
    
    

}

int key(TreeNode *Node)
{
  return(Node->key);
}

TreeNode *Left_child (TreeNode *tr)
{
  return(tr->left);

}

TreeNode *Right_child (TreeNode *tr)
{
  return(tr->right);

}


stnode *createNode(int key,char ch)
{
  stnode* node = NULL;

  node = (stnode*)malloc(sizeof(stnode));
    node->key   = key;
    node->ch = ch;
   
    return(node);
}

TreeNode *createE(int key,int nodes)
{
  TreeNode* node = NULL;

  node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key   = key;

     node->height = 1;
    node->balance = 0;
    node->child = 0;
    node->nodes = nodes;
    
    node->left   = NULL;
    node->right  = NULL;
   
    return(node);
}

TreeNode *create(int key)
{
  TreeNode* node = NULL;

  node = (TreeNode*)calloc(1,sizeof(TreeNode));
    node->key   = key;

     node->height = 1;
    node->balance = 0;
    node->child = 0;
    node->nodes = 0;
    
    node->left   = NULL;
    node->right  = NULL;
   
    return(node);
}
 
int height(TreeNode *tr)
{
  if (tr == NULL){
        return 0;
  }
    return tr->height;
}

int maximum(int first, int second)
{
  if(second > first){
    return second;
  }
  return first;
}


TreeNode *insert(TreeNode* tr, int key)
{
  if (tr == NULL){
    //printf("Here4\n");
    return(create(key));
	  }

 
  if (key <= tr->key){
        tr->left  = insert(tr->left, key);
  }
  else if (key > tr->key){
        tr->right = insert(tr->right, key);
  }
  
    tr->height = 1 + maximum(height(tr->left),height(tr->right));
 
    tr->balance = findBalance(tr);
    //int balance = findBalance(tr);

    /*
    if (balance > 1 ){

      int balance1 = findBalance(tr->left);
      if(balance1 > 0){
        return rightRotate(tr);
      }

      else if(balance1 < 0){
	  tr->left =  leftRotate(tr->left);
	  return rightRotate(tr);
      }
      
      else{

	//int balance1 = findBalance(tr->left);
	//printf("Balance1L = %d\n",balance1);
	   tr = leftBalance(tr,balance);
	   
	   if(balance1 > 0){
	             return rightRotate(tr);
	   }
	   else{
	     tr->left =  leftRotate(tr->left);
	     return rightRotate(tr);
	   }
	  
      }
     
     
    }

     // R-R Case
    else if (balance < -1 ){
  
      int balance1 = findBalance(tr->right);
      
      if(balance1 < 0){
      return leftRotate(tr);
       }

    else if(balance1 > 0){
	  tr->right =  rightRotate(tr->right);
	  return leftRotate(tr);
      }
    
	else{
	  //int balance1 = findBalance(tr->right);
	  //printf("Balance1R = %d\n",balance1);
	    tr = rightBalance(tr,balance);
	    
	   if(balance1 < 0){
	             return leftRotate(tr);
	   }
	   else{
	     tr->right =  rightRotate(tr->right);
	     return leftRotate(tr);
	   }
	} 
}
      */
       
    

    tr = balance(tr);
    return(tr);
}

TreeNode *leftBalance(TreeNode * tr, int balance){

    printf("balance= %d\n",balance);

    //while(balance > 2){
    //pintf("Here1\n");
    //tr->left = leftBalance(tr->left,findBalance(tr->left));
    //balance = findBalance(tr);
    //  printf("new balance= %d\n",balance);
    //}
    //int balance1 = findBalance(tr->left);
    //printf("balance1L= %d\n",balance1);
  if(balance > 0){
    return rightRotate(tr);
  }
  else{
    tr->left =  leftRotate(tr->left);
    return rightRotate(tr);
  }
  
}

TreeNode *rightBalance(TreeNode * tr, int balance){

  //while(balance < -2){
  //tr->right = rightBalance(tr->right,findBalance(tr->right));
  //balance = findBalance(tr);
  //}
  //int balance1 = findBalance(tr->right);
  if(balance < 0){
    return leftRotate(tr);
  }
  else{
    tr->right =  rightRotate(tr->right);
    return leftRotate(tr);
  }
  
}


void print2DUtil(TreeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
 
    // Process left child
    print2DUtil(root->left, space);
}




  
TreeNode *rightRotate(TreeNode *ptr)
{
  
  TreeNode *new = ptr->left;
  TreeNode *temp = new->right;
 
  new->right = ptr;
  ptr->left = temp;
 
    // update the heights
  
    ptr->height = maximum(height(ptr->left), height(ptr->right))+1;
    new->height = maximum(height(new->left), height(new->right))+1;
 
    return(new);

}

TreeNode *leftRotate(TreeNode *ptr)
{
  
  TreeNode *new = ptr->right;
  TreeNode *temp = new->left;
 
  new->left = ptr;
  ptr->right = temp;
 
    // update the heights
    ptr->height = maximum(height(ptr->left), height(ptr->right))+1;
    new->height = maximum(height(new->left), height(new->right))+1;
 
    return(new);

}



int findBalance(TreeNode *tr)
{
  if (tr == NULL){
        return 0;
  }
    return height(tr->left) - height(tr->right);
}


//#endif
