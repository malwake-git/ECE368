#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "pa1.h"
#define PA1_H

#define ARRAYSIZE 3
#define MAXNODES 500
#define INFOSIZE 2

#ifdef TEST_BUILDPA1
bool readArray(const char * filename, double * * param, Stack * stack, Stack * stack_ind)
{
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
    {
      return false;
    }
  //int numint = 0;
  double value;
  double value2;
  int ind=0;
  int count = 0;
  char c;
  char c2;
  //int indicator = 0;
  //Stack* tr_stack = createStack(MAXNODES);
  //TreeNode* tr_temp;
  //int a;
  //push(*stack,10);
  //printf("%d popped from stack\n", pop(*stack));
  
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
      
      //printf("%lf \n",(*param)[count]);
      count++;
    }
  
  int k = 0;
  while(k < i-1){
    //if(fscanf(fptr, "%c%lf %lf%c", &c, & value, &value2, &c2) == 1){
    
    if(fscanf(fptr,"%d",&ind) == 1){
      //printf("Here4 \n");
    fscanf(fptr,"%c",&c);
    fscanf(fptr,"%le",&value);
    fscanf(fptr,"%c",&c2);
    //printf("%d%c%le%c\n",ind , c , value,c2);
    //int d[] = {ind,value}; //ind(value)
    //push(*stack,* d);
    //double arr[] = {ind,value};
    push(stack_ind, (double)ind);
    push(stack, value);
    //push(*stack, {ind,value,0});
    //push(*stack,ind);
    //printf("Top: %le , %d\n",pop((*stack)),(int)pop((*stack)));
    //printf("Top: %d \n",pop(*stack));
    
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
  //tr = malloc(sizeof(TreeNode));
  //printf("%d\n",(int)peek(*stack_ind));
  //printf("%le\n",peek(*stack));
  if(((int)peek(stack_ind)) == 0){
    //TreeNode* tr;
    int ind = (int)pop(stack_ind);
    double value2 = pop(stack);
    double value = pop(stack);
    //printf("ind: %d\n",ind);
    //printf("value: %le\n",value);
    //printf("value2: %le\n",value2);
    tr_right = buildtree(stack,stack_ind,tr_right,tr_left);
    tr_left = buildtree(stack,stack_ind,tr_right,tr_left);
    tr = create(tr_left,tr_right,ind,value,value2);
    //printf("ind: %d\n",tr->ind);
    //printf("value: %le\n",tr->value);
    //printf("value2: %le\n",tr->value2);
    
    return tr;
    }
  else
    {
      //TreeNode* tr;
      int ind = (int)pop(stack_ind);
      double value = pop(stack);
      tr = create(NULL,NULL,ind,value,0);
      //printf("indf: %d\n",tr->ind);
      //printf("valuef: %le\n",tr->value);
      return tr;
    }

}

void printTre(TreeNode* tr)
{
  if(tr == NULL)
    {
      printf("Here 656\n");
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
		
	  //tr->t = sum / (tr -> r);
	tr->t = sum / (tr -> r);
	//printf("ind = %d,t= %le\n",tr->ind,tr->t);
	//fprintf(fptr, "%d(%le)\n", tr -> ind,tr->t);
	//fprintf(fptr, "%d(%le)\n", tn -> ind,tn->value);
	//int ind = tr->ind;
	//double t = tr->t;
	fwrite(&tr->ind, sizeof(int), 1, fptr);
	
	fwrite(&tr->t, sizeof(double), 1, fptr);
	
	return;
	
	}
	
	double c_left = sum - (tr-> left -> c) * (tr->r) * (tr->r);
	
	double c_right = sum - (tr->right -> c) * (tr -> r) * (tr -> r);
	
	Calcdelay(fptr, tr-> left, c_left,c);
	
	Calcdelay(fptr, tr-> right, c_right,c);
	
	return;
	
}
#endif

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
