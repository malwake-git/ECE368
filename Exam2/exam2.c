#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


typedef struct TNode{
	int label;
	struct TNode* left;
	struct TNode* right;
}TNode;

typedef struct Queue{
	struct Queue* next;
	TNode *node;
}Queue;

typedef struct QHeader{
	Queue *front;
	Queue *rear;
}QHeader;

void Enqueue(QHeader * header, TNode* node){
	Queue* toInsert = (Queue *)malloc(sizeof(Queue));
	toInsert->node = node;
	toInsert->next = NULL;
	if(header->rear == NULL){
		header->rear = header->front = toInsert;
	}
	else{
		header->rear->next = toInsert;
		header->rear = toInsert;
	}
}
TNode* Dequeue(QHeader *header){
	if(header->front == NULL)
		return NULL;
	Queue *toDeq = header->front;
	header->front = header->front->next;
	if(header->front == NULL)
		header->rear = NULL;
	TNode* toReturn = toDeq ->node;
	free(toDeq);
	return toReturn;
}


QHeader *ReverseList(Queue *header){
    
    //Queue *aux = (QHeader*) malloc(sizeof(QHeader));
    //
    
    QHeader *header1 = (QHeader*) malloc(sizeof(QHeader));
    
	//while((header->front != NULL))
    if(header->next != NULL)
    {
        header1 = ReverseList(header->next);
        
    }
    
    Enqueue(header1, header->node);
    //printf("header1 = %d\n",header1->front->node->label);
    return header1;
}

void Depth_First_Traversal(FILE* outptr, TNode* node){

	if(node == NULL){
       	 return;
    	}
    
    	TNode* q = NULL;
    	QHeader *header = (QHeader*) malloc(sizeof(QHeader));
    	//QHeader *header1 = (QHeader*) malloc(sizeof(QHeader));
    
    Enqueue(header, node);

    while(header->front != NULL){
        q = Dequeue(header);
        
        if(q != NULL){
            fprintf(outptr, "%d\n", q->label);
            //printf("%d\n", q->label);
            Enqueue(header, q->left);
            Enqueue(header, q->right);
            if(q->left != NULL && q->right != NULL){
            	header = ReverseList(header->front);
            }
        }
    }


   
}


void Breadth_First_Traversal(FILE* outptr, TNode* node){


	if(node == NULL){
        	return;
    	}
    	TNode* q = NULL;
    	QHeader *header = (QHeader*) malloc(sizeof(QHeader));
    
    Enqueue(header, node);
    while(header->front != NULL){
        q = Dequeue(header);
        
        if(q != NULL){
    //printf("%d\n", q->label);
    fprintf(outptr, "%d\n", q->label);

    //if(q->left == NULL){
      //Enqueue(header, NULL);
    //}
    //else{
        Enqueue(header, q->right);
    //}
    //if(q->right == NULL){
      //  Enqueue(header, NULL);
    //}
    //else{
        Enqueue(header, q->left);
    //}
        }
        
    }
   
}



TNode* newNode(int data)
{
    TNode* node = (TNode*) malloc(sizeof(TNode));
    node->label = data;
    node->left = NULL;
    node->right = NULL;
  
    return (node);
}
void printPre(TNode *node){
    if(node == NULL){
        return;
    }
    printf("%d\n",node->label);
    printPre(node->left);
    printPre(node->right);
    
}

int main(int argc, char *argv[]){

  if (argc < 2)
    {
      return EXIT_FAILURE;
    }
  
  //QHeader *header = (QHeader*) malloc(sizeof(QHeader));
    TNode *node = newNode(5);
    node->right = newNode(7);
    node->left = newNode(3);
    node->right->left = newNode(6);
    node->right->right = newNode(8);
    node->left->right = newNode(4);
     node->left->left = newNode(2);
     node->left->left->left = newNode(1);
     node->left->left->left->left = newNode(1);
     node->left->left->left->left->left = newNode(1);
     node->left->right->left = newNode(3);
     //node->left->right->right = newNode(4);
     
     printPre(node);
     printf("-----------------------\n");
     FILE * output = fopen(argv[1], "w");
     
     Depth_First_Traversal(output,node);

     fclose(output);

}

/*
{
???some TNode* node defined here???
QHeader qdummy; //local declaration, no malloc
qdummy.front = NULL;
qdummy.rear = NULL;
Enqueue(&qdummy, node);
Tnode* deq = Dequeue(&qdummy);
???
}
*/
