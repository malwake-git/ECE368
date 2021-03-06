#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include "delay.h"
#define DELAY_H

#define ARRAYSIZE 3
#define MAXNODES 100000
#define INFOSIZE 2

#ifdef TEST_BUILDDELAY
bool readArray(const char * filename, double * * param, Stack * stack, Stack * stack_ind)
{
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
    {
      return false;
    }
  double value;
  double value2;
  int ind=0;
  int count = 0;
  char c;
  char c2;
  
  *param = malloc(ARRAYSIZE * sizeof(double));
  
  //printf("%ld \n",ftell(fptr));
  //|| (fscanf(fptr, "%c%lf %lf%c", &c, & value, &value2, &c2) != EOF)
  //while (fscanf(fptr, "%lf", &value) != EOF){
  int i=0;
  for (c = getc(fptr); c != EOF; c = getc(fptr)){
    if (c == '\n'){ // Increment count if this character is newline
            i += 1;
    }
  }
  //printf("i= %d \n",i);
  fseek (fptr, 0, SEEK_SET);
  while (count < 3 && fscanf(fptr, "%le", & value) == 1)
    {
      (*param)[count] = value;
      
      count++;
    }
  
  int k = 0;
  while(k < i-1){
    
    if(fscanf(fptr,"%d",&ind) == 1){
    fscanf(fptr,"%c",&c);
    fscanf(fptr,"%le",&value);
    fscanf(fptr,"%c",&c2);

    push(stack_ind, (double)ind);
    push(stack, value);
 
    
    }
      //ind = 0;
    //else if ((fscanf(fptr, "%d%c%lf%c",&ind , &c ,& value, &c2) == 1)){
    else{
      //printf("Here5 \n");
	fscanf(fptr,"%c",&c);
	fscanf(fptr,"%le",&value);
	fscanf(fptr,"%le",&value2);
	fscanf(fptr,"%c",&c2);
	//printf("%c%le %le%c\n", c, value, value2, c2);
	//double arr[] = {0,value2,value};
	push(stack_ind,0);
	push(stack, value);
	push(stack,value2);
	
    }
	
    k++;
  }

  
  fseek (fptr, 0, SEEK_SET);
 
  fclose (fptr);
  return true;
}

TreeNode* buildtree(Stack * stack, Stack * stack_ind, TreeNode* tr_right, TreeNode* tr_left){

  TreeNode* tr = NULL;
  int ind = 0;
    double value2 =0;
    double value =0;


  if(((int)peek(stack_ind)) == 0){
    //TreeNode* tr;
  

    ind = (int)pop(stack_ind);
    value2 = pop(stack);
    value = pop(stack);
    //printf("%d\n",stack->top);
    //printf("%d\n",stack_ind->top);
    

    
    tr_right = buildtree(stack,stack_ind,tr_right,tr_left);
    tr_left = buildtree(stack,stack_ind,tr_right,tr_left);
    tr = create(tr_left,tr_right,ind,value,value2);

    
    return tr;
    }
  else
    {
      ind = (int)pop(stack_ind);
      value = pop(stack);
      /*
      if(stack->top == -1 && stack_ind ->top == -1){
      free(stack->array);
      free(stack_ind->array);
      free(stack);
      free(stack_ind);
      */
      //Stack* stack = NULL;
      //Stack* stack_ind = NULL;

      tr = create(NULL,NULL,ind,value,0);

      return tr;
    }
  
}

void printTre(TreeNode* tr)
{
  if(tr == NULL)
    {
      return;
    }
  if(tr->ind == 0){
    printf("(%le %le)\n", tr->value,tr->value2);
    printTre(tr-> right);
    printTre(tr-> left);
  }
  else
    {
      printf("%d(%le)\n", tr->ind,tr->value);
      printTre(tr-> left);
      printTre(tr -> right);
    }
  return;
}


void delayPrint(TreeNode * tn, FILE * fptr)
{
   if (tn == NULL)
    {
      return;
    }
  if((tn->ind == 0)){
    //return;
  }
  else{
     fprintf(fptr, "%d(%le)\n", tn -> ind,tn->value);
  }
  delayPrint(tn -> left, fptr);
  delayPrint(tn -> right, fptr);
  //return;
}
/*
double computeC(TreeNode * tr, double * param, double link_c){
  
  //if(tr == NULL)
  //{
  //  return 0;
  //}
  double c =0;
  if(tr->ind == 0){
    c = (tr->value*param[2] + tr->value2*param[2] + link_c)/2;
  }
  else{
    c = tr->value + link_c/2;
  }
  return c;
}

double computeSum(TreeNode * tr,double * param, double link_c, double link_r,double * * stack)
{
  double sum = 0;
  double total = 0;
  
  if (tr == NULL)
    {
      return 0;
    }
  Stack* stack_temp = stack;
  if(!isEmpty(*stack)){
    sum += pop(stack_temp);
  }
  TreeNode* tr_temp = tr;
  //while(!empty(tr_temp)){
  c= computeC(tr, param,link_c);
  sum = c* pow((param[0]+link_r),2);
  total = sum;
  link_c += param[2]*(*tr->value);
  //link_r += param[1]*(*tr->value2);
    total += computeSum(tr->left, param, link_c, link_r,stack_temp);
  link_c += param[2]*(*tr->value2);
  total += computeSum(tr->right, param, link_c, link_r,stack_temp);

  push(*stack,sum);
    //}
  free(stack_temp);
  return sum;

}

void delayTime(TreeNode * * tr, double * param, double link_r, double link_c){
{
  
  if (tr == NULL)
    {
      return;
    }
  //double t = 0;
  //double link_c = 0;
  double sum = 0;
  double* stack1 = createStack(MAXNODES);
  //double link_left=0;
  //double link_right=0;
  TreeNode* tr_temp = tr;
  
  sum = computeSum(tr,param,link_c,&stack1);
  
  //while(tr != NULL){
    //if((tr->ind == 0)){
      
      //return t;
      //}
    //else{
      //delayPrint(tr->ind,t,fptr);
      // fprintf(fptr, "%d(%le)\n", tr -> ind,tr->value);
      //}
    //t += delayTime(tr -> left, fptr);
    //t += delayTime(tr -> right, fptr);
    //t = (1/(r+param[0]) * ())
  tr->t = 1/(param[0]+link_r)*sum;
  link_r += param[1]*(*tr->value);
  link_c += param[2]*(*tr->value);
  delayTime(*tr->left,param,link_r,link_c);
  if(tr->ind == 0){
    link_r = link_r+ param[1]*(*tr->value2) -param[1]*(*tr->value);
    link_c = link_r+ param[2]*(*tr->value2) -param[2]*(*tr->value);
  }
  delayTime(*tr->right,param,link_r,link_c);
  free(stack1);
    return;
 
 
}
*/

void calcTotalC(TreeNode * tr, double capPerLength) 
{
  //printf("capper: %le",capPerLength);
	if (tr == NULL) {
		return;
	}
	
	if(tr->right == NULL || tr->left == NULL) {
		tr -> total_c += tr-> value;
				
		return;
		
		}
	//printf("Here 3\n");
	tr-> left->total_c = ((tr-> value) / 2.0) * capPerLength;
	//printf("Here 2\n");
	tr ->right -> total_c = ((tr-> value2) / 2.0) * capPerLength;
	//printf("Here 1\n");

	tr -> total_c = tr->total_c + (tr ->left -> total_c) + (tr->right ->total_c);
	//printf("%d\n",(tr->left->ind));
	//tr ->right = Right_child(tr);
	//tr->left = Left_child(tr);
	//printf("%le\n",capPerLength);
	calcTotalC(tr->left, capPerLength);
	calcTotalC(tr -> right, capPerLength);
	return;
	
}

double calcC_(TreeNode * tr, double R_prev, double resistPerLength, double dist) 
{
	
	if(tr == NULL) 
	return 0;
	
	tr-> r = R_prev + (dist * resistPerLength);
		
	if(tr-> left == NULL || tr -> right == NULL) {
	
		tr-> c = tr -> total_c;
		
		return tr -> c;
	}
	
	tr -> c = tr-> total_c;
	
	tr -> c =tr->c+ calcC_(tr-> left, tr -> r, resistPerLength, tr -> value) + calcC_(tr-> right, tr-> r, resistPerLength, tr->value2);
	
	return tr-> c;
	
}

void Calcdelay(FILE * fptr, TreeNode * tr, double sum,double c) 
{
  if(tr == NULL)
    {
      return;

    }

  sum =sum+ (tr -> c) * (tr -> r) * (tr -> r)+c*0;
	
	if(tr ->ind != 0) {
		
	  tr->t = sum / (tr -> r);
	  //double t = sum / (tr -> r);
	//printf("ind = %d,t= %le\n",tr->ind,tr->t);
	//fprintf(fptr, "%d(%le)\n", tr -> ind,tr->t);
	//fprintf(fptr, "%d(%le)\n", tn -> ind,tn->value);
	//int ind = tr->ind;
	//double t = tr->t;
	fwrite(&tr->ind, sizeof(tr->ind), 1, fptr);
	
	fwrite(&tr->t, sizeof(tr->t), 1, fptr);
	
	return;
	
	}
	
	double c_left = sum - (tr-> left -> c) * (tr->r) * (tr->r);
	
	double c_right = sum - (tr->right -> c) * (tr -> r) * (tr -> r);
	
	Calcdelay(fptr, tr-> left, c_left,c);
	
	Calcdelay(fptr, tr-> right, c_right,c);
	
	return;
	
}

/*
int main(int argc, char *argv[]){

  // argv[1]: prerder (input)                                                
  // argv[2]: postorder (output) 
  // argv[3]: postorder (output)
  if (argc < 4)
    {
      return EXIT_FAILURE;
    }

  //double * preArray = NULL;
  double * param;
  Stack* stack = NULL; stack = createStack(MAXNODES);
  Stack* stack_ind = NULL; stack_ind = createStack(MAXNODES);
  TreeNode* tr = NULL;
  TreeNode* tr_right = NULL;
  TreeNode* tr_left = NULL;
  bool rtv;
  
  rtv = readArray(argv[1], &param, &stack, &stack_ind);
 
  if (rtv == false)
    {
      return EXIT_FAILURE;
    }
  
  tr = buildtree(&stack,&stack_ind,tr_right,tr_left);
  //TreeNode* tr_temp = tr;
  FILE * fptr = fopen(argv[2], "w");
  preOrderNode(tr, fptr);
  fclose(fptr);

  //printf("%le\n",Left_child(tr)->value); 
  //Left_child(tr)->value2 = 2;
  //printf("%le\n",Left_child(tr)->value2);
  
  calcTotalC(tr, param[2]); 

  //printf("%le, %le, %le \n",param[0],param[1],param[2]);

  double grand_cap = calcC_(tr, param[0], param[1], 0);

  printf("%le\n", grand_cap);

  FILE * fptr1 = fopen(argv[3], "wb");
  Calcdelay(fptr1, tr, 0);
  //delayPrint(tr,fptr1);
  fclose(fptr1);
  
  deleteTreeNode(tr_right);
  deleteTreeNode(tr_left);
  //deleteTreeNode(tr_temp);
  deleteTreeNode(tr);
  free(param);
  free_stack(stack_ind);
  free_stack(stack);
  free(stack_ind->array);
  free(stack->array);
  free(stack);
  free(stack_ind);
  return 0;
}
#endif
*/


void createStack(unsigned capacity, Stack *stack)
{
  //Stack* stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (double*)malloc(stack->capacity * sizeof(double));
    //stack->array = malloc(stack->capacity * sizeof(double));

    //double array;
    //stack->ind = (int)(sizeof(int));
    return;
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

  /*
    while(!isEmpty(stack)){
      stack->array = NULL;
    free(stack->array);
    stack->array = NULL;
    stack = NULL;
    free(stack);
    stack = NULL;
    }
  */

  //printf("%d\n",isEmpty(stack));

  if (isEmpty(stack)){
      free(stack->array);
      free(stack);
      return;
  }
    //if(stack->array != NULL){
    //free(stack->array);
      //stack->top--;
    //return;
      // }
    //free(stack);
}

double peek(Stack* stack)
{
  if (isEmpty(stack)){
        return INT_MIN;
  }
    return stack->array[stack->top];
}

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
  new_node->total_c = 0;
    new_node->c = 0;
    new_node->r = 0;
    new_node->t = 0;
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
