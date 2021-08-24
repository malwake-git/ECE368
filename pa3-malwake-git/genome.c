#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "genome.h"

bool compareStrings(char* x, char* y)
{
    int flag = 0;
  
  
    while (*x != '\0' || *y != '\0') {
        if (*x == *y) {
            x++;
            y++;
        }
        else if ((*x == '\0' && *y != '\0')
                 || (*x != '\0' && *y == '\0')
                 || *x != *y) {
            flag = 1;
            //printf("Uequal Strings\n");
            return false;
        }
    }
  
    // If two strings are exactly same
    if (flag == 0) {
      return true;
    }
    return true;
}

int pow1(int x, int y){

  if(y == 0)
    return 1;

  int base= x;
  int i = 1;
  while(i < y){
    x *=base;
    i++;
  }
  return x;
  

}

void quickSort(char ** items, int left, int right, char * h, char * temp)
{
  int i, j;
  char *x;
  //char * temp = (char*) malloc(sizeof(h));

  i = left;
  j = right;
  x = items[(left+right)/2];

  do {
    while((strcmp(items[i],x) < 0) && (i < right)) {
       i++;
    }
    while((strcmp(items[j],x) > 0) && (j > left)) {
        j--;
    }
    if(i <= j) {
      strcpy(temp, items[i]);
      strcpy(items[i], items[j]);
      strcpy(items[j], temp);
      i++;
      j--;
   }
  } while(i <= j);

  if(left < j) {
    quickSort(items, left, j,h,temp);
  }
  if(i < right) {
    quickSort(items, i, right,h,temp);
  }
}

void FreeHashGraph(GNode** hashGraph, int GRAPH_SIZE, int k){
  ///loop through your hashGraph and free all existing nodes
  ///Then free the hashGraph

  //int s;

  if(hashGraph == NULL)
    return;
  
  int l = 0;
  k--;
  while(l < GRAPH_SIZE){

   
    /*
     printf("Key = %s\n",hashGraph[k]->key);
    for(s = 0; s < 4; s++){
  printf("Hash->inedge[%d]->key = %s\n",s,hashGraph[k]->inEdges[s]->key);
  printf("Hash->outedge[%d]->key = %s\n",s,hashGraph[k]->outEdges[s]->key);
    }
    */
    
   //free(hashGraph[l]->inEdges[s]);
   //printf("Hash->inedge[1]->key = %s\n",hashGraph[k]->inEdges[1]->key);
   //free(hashGraph[l]->outEdges[s]);
   //printf("Hash->outedge[1]->key = %s\n",hashGraph[k]->outEdges[1]->key);
    //printf("Hash->outedge[%d]->key = %s\n",k,hashGraph[k]->key);
    if(hashGraph[l] != NULL){
      free(hashGraph[l]);
    }
    l++;
}


  free(hashGraph);
}
/*
bool checkHash(int nodeHash, GNode * node, GNode * prev){
  //printf("Here1\n");
  if(node == NULL){
    
    return false;
  }
  //printf("node->key = %s, pre= %s\n",node->key,prev->key);

  if(nodeHash == node->Hash){
    return true;
  }
  
  //int k = getval(node->key[node->key_len-1]);
  int s;
  for(s = 0; s < 4; s++){
       if(node->inEdges[s] != NULL){
	 printf("1s= %d\n",s);
	    break;
       }
	}
  //printf("k = %d, s = %d\t",k,s);
  //printf("prev->inEdge->key= %s\n",prev->inEdges[s]->key);
  printf("node->inEdge->key= %s\n",node->inEdges[s]->key);

  while(node->inEdges[s]){
  //while(s != 4){
    printf("Hash of prev = %s\n",node->inEdges[s]->key);
    if(nodeHash == node->inEdges[s]->Hash){
      return true;
    }
    node = node->inEdges[s];

     for(s = 0; s < 4; s++){
       if(node->inEdges[s] != NULL){
	 printf("s= %d\n",s);
	    break;
       }
	}
  }
  
    return false;
}
*/
int inDegreeSize(GNode * node){

  int sum = 0;
  
  for(int i = 0; i < 4; i++){
    if(node->inEdges[i] != NULL)
      sum++;
  }
  return sum;
}

int outDegreeSize(GNode * node){

  // if(node->outEdges == NULL)
  //return 0;
  
  int sum = 0;
  
  for(int i = 0; i < 4; i++){
    if(node->outEdges[i] != NULL)
      sum++;
  }
  return sum;
}



int checkHash1(GNode ** hashGraph, int k, char *h, GNode *curr, int k_len)
{
  if(curr == NULL)
    return -1;

  int i = 0;
  char * k1 = NULL;
  k1 = (char*)malloc(sizeof(char)*(k_len));
  char * k2 = NULL;
  k2 = (char*)malloc(sizeof(char)*(k_len));
  strncpy(k2,h,k_len-1);
  k2[k_len] = '\0';
 
  //printf("hash[k]->key = %s\n",hashGraph[k]->key);
  while(i < k){

    strncpy(k1,hashGraph[i]->key+1,k_len);
      k1[k_len] = '\0';
      //printf("k2 = %s, k1 = %s\n",k2,k1);
      if(strcmp(k1,k2) == 0){
	printf("i = %d\n",i);
      printf("k1 = %s\n",k1);
      if(curr == hashGraph[i]){
      //if(h != curr->key){
	free(k1);
	free(k2);
      return -1;
      }
      strncpy(k1,curr->key+1,k_len);
      k1[k_len] = '\0';
      //printf("hashGraph[i+1]->key = %s, h= %s\n",hashGraph[i+1]->key,h);
      if(strcmp(k1,k2) == 0 && strcmp(hashGraph[i+1]->key,h) != 0){
      //printf("k-1= %d\n",k-1);
	free(k1);
	free(k2);
      return -1;
      }
      free(k1);
      free(k2);
	return i;
      }
      i++;

  }
  free(k1);
  free(k2);
  return -1;
}

/*
int BuildGraph(char* inputFilename, char* nodeFilename, int k_len, GNode** hashGraph, int GRAPH_SIZE){
  int lineLen = getLineLength(inputFilename);
  
  FILE* ifptr = fopen(inputFilename, "r");
  if(!ifptr){
    printf("Could not open input file!!\n");
    FreeHashGraph(hashGraph, GRAPH_SIZE,-1);
  }
  char* buffer = NULL;
  buffer = (char*)malloc(sizeof(char)*lineLen + 2);
  char *h = NULL;
  h = (char*)malloc(sizeof(char)*k_len);

  GNode* prev=NULL, *curr=NULL;
  int l;
  int k = 0;
  int t;
  char d;
  int nodeHash;
  GNode* newNode = NULL;
  char * k1 = NULL;
  k1 = (char*)malloc(sizeof(char)*(k_len));
  char * k2 = NULL;
  k2 = (char*)malloc(sizeof(char)*(k_len));
 
  while(fgets(buffer,lineLen+1,ifptr)){
    getc(ifptr);
    //prev = NULL;
    //curr = NULL;
    l = 0;
    //printf("\n%s\n",buffer);

    for(int o = 0; o < lineLen; o++){
      d = buffer[o];
      if(getval(d) < 0 || getval(d) > 3){
	FreeHashGraph(hashGraph, GRAPH_SIZE,k);
	return 0;
      }
    }
    
     while(l <= (lineLen-k_len)){
      
      strncpy(h,buffer+l,k_len);
      h[k_len] = '\0';
      //printf("--------------------------\n");
      //printf("h = %s\t",h);
      nodeHash = hash(h, k_len, GRAPH_SIZE);
      //printf("nodeHash = %d\n",nodeHash);
      //s = nodeHash;


      

      strncpy(k2,h,k_len-1);
      k2[k_len] = '\0';


      if(k > 0){
	//printf("Here\n");
      strncpy(k1,prev->key+1,k_len-1);
      k1[k_len] = '\0';
      //printf("k1 = %s,k2 = %s\n",k1,k2);
      }
      else{

	  newNode = (GNode*)malloc(sizeof(GNode));
	  InitGNode(newNode, h, k_len,nodeHash);
	  curr = newNode;
	  hashGraph[k] = newNode;
	  k++;
	  if(prev){
	    AddEdges(prev, curr);///Definition in genome.h
	  }
	
      }
     


      if(strcmp(k1,k2) == 0){
	if( (t = checkHash1(hashGraph, k, h, curr, k_len)) > -1){
	  //hashGraph[];
	  //k++;
	  
	  if(prev){
	    //printf("prev->key = %s\n",prev->key);
	    AddEdges(prev, hashGraph[t+1]);///Definition in genome.h
	    //curr = hashGraph[t];
	  }
	  
	}
	else{
	  newNode = (GNode*)malloc(sizeof(GNode));
	  InitGNode(newNode, h, k_len,nodeHash);
	  curr = newNode;
	  hashGraph[k] = newNode;
	  k++;
	  if(prev){
	    AddEdges(prev, curr);///Definition in genome.h
	  }
	}
      }

      prev=curr;
       l++;
     }
     
  }
  for(int m = 0; m < k; m++){
    //printf("HashGraph->key= %s\t inEd= %ld\t outEd= %ld\n",hashGraph[m]->key,sizeof(hashGraph[m]->inEdges), sizeof(hashGraph[m]->outEdges));
    hashGraph[m]->inDegree = inDegreeSize(hashGraph[m]);
     hashGraph[m]->outDegree = outDegreeSize(hashGraph[m]);
    
     //printf("HashGraph->key = %s\t in = %d, out = %d\n",hashGraph[m]->key,hashGraph[m]->inDegree,hashGraph[m]->outDegree);
  }
  //FreeHashGraph(hashGraph, GRAPH_SIZE);
  fseek(ifptr, 0, SEEK_SET);
  free(buffer);
  free(h);
  free(k1);
  free(k2);
  fclose(ifptr);
  
  // for each line in the input file:
  //   prev=NULL;
  //   curr=NULL;
  //   for each k_len substring in the line:
  //     int nodeHash = hash(str, k_len, GRAPH_SIZE);///hash defined in genome.h
  //     check if node exists already(handle collisions). 
  //     If it doesnt exist, malloc and use InitGNode
  //     Code may be something like:
  //       GNode* newNode = (GNode*)malloc(sizeof(GNode));
  //       InitGNode(newNode, str, k_len);
  //     If there is an error at any point, make sure we free what we have malloc
  //       maybe use FreeHashGraph(hashGraph, GRAPH_SIZE); for ease
  //     set curr equal to the node, either the one we malloc or the one existing
  //     if(prev)
  //       AddEdges(prev, curr);///Definition in genome.h
  //     prev=curr;
  return k;
}
*/

void newTraverseHelper(GNode* node, FILE* outfile, int i, GNode ** hashGraph){
  fprintf(outfile, "%c", node->key[0]);
  int c = 0;
  if((node->inDegree == 1 && node->outDegree == 1) || hashGraph[i] == node)
    {
      for(int j = 0; j < 4; ++j){
	if (node->outEdges[j] && (node->outEdges[j] != node)){
	  if(c>0){
	    fprintf(outfile, "%c", node->key[0]);
	  }
	  newTraverseHelper(node->outEdges[j], outfile, i, hashGraph);
	  c++;
	}
      }
    }
  else if(node->outDegree == 0){
    int s = 1;
    while(node->key[s]){
      fprintf(outfile, "%c", node->key[s]);
      //fprintf("", node->key[s]);
      s++;
    }
    fprintf(outfile,"\n");
  }
  else{

    int s = 1;
    while(node->key[s]){
      fprintf(outfile, "%c", node->key[s]);
      //fprintf("", node->key[s]);
      s++;
    }
    fprintf(outfile,"\n");
  }


}



void TraverseHelper(GNode* node, FILE* outfile){
  fprintf(outfile, "%c", node->key[0]);
  
  if( (node->inDegree == 1 || node->inDegree == 0) && node->outDegree == 1)
    {
      printf("node= %s1\n",node->key);
    for(int j = 0; j < 4; ++j){
      if (node->outEdges[j]){
        TraverseHelper(node->outEdges[j], outfile);
      }
    }
  }
  else if(node->outDegree == 0){
    int s = 1;
    while(node->key[s]){
      fprintf(outfile, "%c", node->key[s]);
      //fprintf("", node->key[s]);
      s++;
    }
    fprintf(outfile,"\n");
  }
  else if(node->inDegree > 1 && node->outDegree == 1){
    printf("stop= %s, in= %d, out= %d\n",node->key,node->inDegree,node->outDegree);
    
    int s = 1;
    while(node->key[s]){
      fprintf(outfile, "%c", node->key[s]);
      //fprintf("", node->key[s]);
      s++;
    }
    fprintf(outfile,"\n"); 
  }
  /*
  else if( node->inDegree > 0 && node->outDegree > 1 ){

    for(int j = 0; j < 4; ++j){
      if (node->outEdges[j]){
        TraverseHelper(node->outEdges[j], outfile);
      }
    }
  
  }
  */
  
}


void TraverseHelper1(GNode* node, FILE* outfile, GNode ** hashGraph, int i)

{
  fprintf(outfile, "%c", node->key[0]);
 
  //printf("%c", node->key[0]);
  if((node->inDegree == 1 && node->outDegree == 1) || hashGraph[i] == node)
    {
    //fprintf(outfile, "%c", node->key[node->key_len-1]);
    //printf("Hash->key= %s\n",node->key);
      int c = 0;
    for(int j = 0; j < 4; ++j){
      if (node->outEdges[j] != NULL && (node->outEdges[j] != node) ){
	if(c > 0){
	  //printf("Here2\n");
	  fprintf(outfile, "%c", hashGraph[i]->key[0]);
	}

        TraverseHelper1(node->outEdges[j], outfile,hashGraph, i);
	c++;
	//printf("--------------------\n");
        //break;
      }
      else if(node->outEdges[j] == node){
	if(c > 0){
	  fprintf(outfile, "%c", hashGraph[i]->key[0]);
	}
	int s = 0;
    while(node->key[s]){
      //printf("Here1\n");
      fprintf(outfile, "%c", node->key[s]);
      s++;
      
    }
    c++;
    fprintf(outfile,"\n");
      }
    }
  }
  else if (hashGraph[i] != node){
    int s = 1;
    while(node->key[s]){
      fprintf(outfile, "%c", node->key[s]);
      //fprintf("", node->key[s]);
      //printf("node->key = \n");
	    
      s++;
    }
    fprintf(outfile,"\n");
  }
}

void TraverseGraph(GNode** hashGraph, int k_len, int GRAPH_SIZE, char* outputFilename,int k){
  FILE* outfile = fopen(outputFilename, "w");
 
  if(!outfile){
    printf("Could not open this output file!!\n");
    return;
  }

  
  for(int i = 0; i < GRAPH_SIZE; i++){
    if(hashGraph[i] != NULL && (hashGraph[i]->inDegree != 1 || hashGraph[i]->outDegree > 1) ){
      //printf("Key= %s, in = %d, out= %d\n",hashGraph[i]->key, hashGraph[i]->inDegree, hashGraph[i]->outDegree);
      //TraverseHelper1(hashGraph[i], outfile, hashGraph, i);
      TraverseHelper1(hashGraph[i], outfile, hashGraph,i);
    }
  
  }
 
  /*
  for(int i = 0; i < GRAPH_SIZE; i++){
    if(hashGraph[i] != NULL && (hashGraph[i]->outDegree > 1 || hashGraph[i]->inDegree != 1)){
      printf("hashGraph[%d] = %s, in= %d, out= %d\n",i,hashGraph[i]->key,hashGraph[i]->inDegree,hashGraph[i]->outDegree);
      TraverseHelper( hashGraph[i], outfile);

    }
  */
  
  
  fclose(outfile);
}


/*

void TraverseGraph(GNode** hashGraph, int k_len, int GRAPH_SIZE, char* outputFilename, int size){
  
  FILE* outfile = fopen(outputFilename, "w");
  if(!outfile){
    printf("Could not open this output file!!\n");
    return;
  }
  //GNode** hash = (GNode**)malloc(sizeof(GNode*)*GRAPH_SIZE);
  
  for(int i = 0; i < GRAPH_SIZE; i++){

    if(hashGraph[i] != NULL){

    
    if(k_len == 1){
      
	fprintf(outfile,"%c\n",hashGraph[i]->key[0]);
      if(i == k-1){
	i++;
	fprintf(outfile,"%c\n",hashGraph[i]->key[0]);
      }
    }
    else if(hashGraph[i]->inDegree != 1 || hashGraph[i]->outDegree != 1){
     
      TraverseHelper1(hashGraph[i], outfile,hashGraph,i);
      //TraverseHelper(hashGraph[i], outfile);
    }
    }
  }
  fclose(outfile);

  //
  if(k_len > 1){

    char ** string = (char **) malloc(sizeof(char) * GRAPH_SIZE);
    char * h = (char *) malloc(sizeof(char) * (k_len * size));
    int r = 0;
    
    FILE* readout = fopen(outputFilename,"r");
  if(!readout){
    printf("Was not able to read the written file\n");
    return;
  }

  while(fgets(h,sizeof(h)+1,readout)){                
    strncpy( string[r],h,strlen(r) );
    printf("%s",string[r]);
    r++;
  }

  printf("1%s",string[r-3]);
  char * temp = (char*) malloc(sizeof(h));
  quickSort(string, 0, r-1,h, temp);

  fclose(readout);

  FILE * outfile2 = fopen(outputFilename,"w+");
  if(!outfile2){
    printf("Could not open this output file!!\n");
    return;
  }

  for(int jj = 0; jj < r; jj++){
    //fprintf(outfile2,"%s",string[jj]);
    printf("%s",string[jj]);
  }
  
  fclose(outfile2);
  free(temp);
  free(string);
  free(h);

  }
  //
  //Do some sort of loop that will start a traversal at every hnode
 // use TraverseHelper to traverse after we are at hnode to make this easier
  //
  
  return;
}
*/




void PrintUniqueNodes(char* nodeFilename, GNode** hashGraph, int GRAPH_SIZE, int k){
  FILE* nodeOut = fopen(nodeFilename, "w");
  if(!nodeOut){
    printf("Could not open this output file!!\n");
    return;
    //FreeHashGraph(hashGraph, GRAPH_SIZE);
  }
  //int i = 0;
  for(int i = 0; i < GRAPH_SIZE; i++){
    if(hashGraph[i] != NULL)
      fprintf(nodeOut, "%s\n", hashGraph[i]->key);
  }
  /*do some sort of loop to print all unique nodes here*/
  
  fclose(nodeOut);
}
/*
bool createNode(GNode ** hashGraph, char * h,int k_len,int nodeHash,int k, GNode * curr){

 
  int i = 0;
  while(i < k){
    if(hashGraph[i]->Hash == nodeHash){
      return false;
    }
    i++;
  }

  
  GNode * newNode = (GNode*)malloc(sizeof(GNode));
  InitGNode(newNode, h, k_len,nodeHash);
  curr = newNode;
  hashGraph[k] = newNode;
  return true;

}
*/
/*
int BuildGraph1(char* inputFilename, char* nodeFilename, int k_len, GNode** hashGraph, int GRAPH_SIZE){
  int lineLen = getLineLength(inputFilename);
  FILE* ifptr = fopen(inputFilename, "r");
  if(!ifptr){
    printf("Could not open input file!!\n");
  }
  char* buffer = (char*)malloc(sizeof(char)*lineLen + 2); 
  GNode* prev=NULL, *curr=NULL;
  int num_nodes = pow1(4,k_len);
  //GNode *curr1 = NULL;

  char *h = (char*)malloc(sizeof(char)*k_len+1);

  //int d;
  int l;
  int k = 0;
  
  int nodeHash;

 
  while(fgets(buffer,lineLen+1,ifptr)){
    getc(ifptr);

    l = 0;
    //printf("\n%s\n",buffer);

//
    for(int o = 0; o < lineLen; o++){
      d = buffer[o];
      if(getval(d) < 0 || getval(d) > 3){
	return 0;
      }
    }
 //
     while(l <= (lineLen-k_len)){
      
      strncpy(h,buffer+l,k_len);
      h[k_len] = '\0';
      
      nodeHash = hash(h, k_len, GRAPH_SIZE);
      //printf("nodeHash = %d\n",nodeHash);
      //s = nodeHash;

      //createNode(hashGraph,h,k_len,nodeHash,k,curr);
       
       if( createNode(hashGraph,h,k_len,nodeHash,k,curr) ){
	 curr = hashGraph[k];
	 k++;
	 //printf("prev->key = %s, curr->key = %s\n",prev->key,curr->key);
	 if(prev)
	   AddEdges(prev, curr);///Definition in genome.h
       }
      
      prev = curr;
      l++;
      //if(k == num_nodes)
	//printf("Num = %d\n",num_nodes);
      if(k == num_nodes)
	break;
     }
     if(k == num_nodes)
       break;
  }

  char * k1 = (char*)malloc(sizeof(char)*(k_len));
  char * k2 = (char*)malloc(sizeof(char)*(k_len));
  int b;

  if(k_len > 1){
  for(int v = k-1;v >= 0;v--){
    //printf("\nhash[v]->key = %s\n",hashGraph[v]->key);
    
   strncpy(k2,hashGraph[v]->key+1,k_len-1);
   k2[k_len-1] = '\0';
   b = v-2;
     while(b > -1){
       strncpy(k1,hashGraph[b]->key,k_len-1);
       k1[k_len-1] = '\0';
       //if(strcmp(k1,k2) == 0){

       
       if(compareStrings(k1,k2)){
	 
	  if(v != k-1){
	    //printf("from:hash[v]->key = %s, to:hash[b]->key = %s\n",hashGraph[v]->key, hashGraph[b]->key);
	   AddEdges( hashGraph[v], hashGraph[b]);
	 }
       }
       
       b--;
     }
  }
  }

  
  for(int m = 0; m < k; m++){

    hashGraph[m]->inDegree = inDegreeSize(hashGraph[m]);
    hashGraph[m]->outDegree = outDegreeSize(hashGraph[m]);
    //printf("hash->key = %s,in = %d, out= %d\n",hashGraph[m]->key,hashGraph[m]->inDegree,hashGraph[m]->outDegree);
    }
  
  
  fseek(ifptr, 0, SEEK_SET);
  free(k1);
  free(k2);
  free(buffer);
  free(h);
  fclose(ifptr);
  return k;

}
*/

int BuildGraph2(char* inputFilename, char* nodeFilename, int k_len, GNode** hashGraph, int GRAPH_SIZE){
  int lineLen = getLineLength(inputFilename);
  FILE* ifptr = fopen(inputFilename, "r");
  if(!ifptr){
    printf("Could not open input file!!\n");
  }
  char* buffer = (char*)malloc(sizeof(char)*lineLen + 2); 
  GNode* prev=NULL, *curr=NULL;
  int num_nodes = pow1(4,k_len);
  //GNode *curr1 = NULL;

  char *h = (char*)malloc(sizeof(char)*k_len+1);
  char * inkey = (char*)malloc(sizeof(char)*(k_len));
  char * outkey = (char*)malloc(sizeof(char)*(k_len));

  //int d;
  int l;
  int k = 0;
  
  int nodeHash;

 
  while(fgets(buffer,lineLen+1,ifptr)){
    getc(ifptr);

    l = 0;
    //printf("\n%s\n",buffer);

   
     while(l <= (lineLen-k_len)){
      
      strncpy(h,buffer+l,k_len);
      h[k_len] = '\0';

      strncpy(outkey,h+1,k_len-1);
      outkey[k_len-1] = '\0';
      

      strncpy(inkey,h,k_len-1);
      inkey[k_len-1] = '\0';

      nodeHash = hash(h, k_len, GRAPH_SIZE);

      //printf("Hash = %d\tkey = %s\n",nodeHash,h);
      

      
      if(hashGraph[nodeHash] == NULL){

	GNode * newNode = (GNode*)malloc(sizeof(GNode));
	InitGNode(newNode, h, k_len,nodeHash,inkey,outkey,k);
	
	hashGraph[nodeHash] = newNode;
	//printf("inkey= %s,outkey=%s\n",hashGraph[nodeHash]->inkey,hashGraph[nodeHash]->outkey);
	curr = hashGraph[nodeHash];
	k++;
	if(prev){
	   AddEdges(prev, curr);///Definition in genome.h
	}
      }
      else if( strcmp(inkey,curr->outkey) == 0 ){
	//if(prev && fgets(buffer,lineLen+1,ifptr)){
	if(prev && (curr->count != (num_nodes-1) && hashGraph[nodeHash]->count != 0) ){
	//if(prev){
	  //printf("Key=%s,count = %d\n",curr->key,curr->count);
	  //printf("%d\n",num_nodes);
	   AddEdges(curr, hashGraph[nodeHash]);///Definition in genome.h
	}
      }
      //fseek(ifptr, 1, SEEK_CUR);
     else if( strcmp(h,hashGraph[nodeHash]->key) != 0){
	printf("\nCollision\n");
     }
      else{
	//printf("Same key\t");
      }
      
      prev = curr;
      l++;
      
     }
  }

  //printf("pow(4,k_len)= %d",pow1(4,k_len)-1);
  for(int ll = 0; ll < GRAPH_SIZE; ll++){
    if(hashGraph[ll] != NULL){
      //printf("hashGraph[%d] = %s\n",hashGraph[ll]->Hash,hashGraph[ll]->key);
      //if(hashGraph[ll])
      /*
      if(hashGraph[ll] == curr)
	for(int jj = 0; jj < 4; jj++){
	  hashGraph[ll]->outEdges[jj] = NULL;
	}

      if(hashGraph[ll]->count == 0){
	for(int jj = 0; jj < 4; jj++){
	  hashGraph[ll]->inEdges[jj] = NULL;
	}
      }
      */
      hashGraph[ll]->inDegree = inDegreeSize(hashGraph[ll]);
      hashGraph[ll]->outDegree = outDegreeSize(hashGraph[ll]);
      //printf("d\n");
      //if(hashGraph[ll]->inDegree == 0 || hashGraph[ll]->outDegree == 0){
      //printf("Key= %s,hash = %d, in = %d, out= %d\n",hashGraph[ll]->key, hashGraph[ll]->Hash,hashGraph[ll]->inDegree, hashGraph[ll]->outDegree);
      //}
      //printf("hashGraph[%d]=%s, in= %d,%s    out= %d,%s\n",ll,hashGraph[ll]->key,hashGraph[ll]->inDegree,hashGraph[ll]->inkey,hashGraph[ll]->outDegree,hashGraph[ll]->outkey);
    }
  }
  
  fseek(ifptr, 0, SEEK_SET);
  free(inkey);
  free(outkey);
  free(buffer);
  free(h);
  fclose(ifptr);
  return k;
}





int main(int argc, char* argv[]){
  // argv[1] should be an integer of what our k length should be.
  // argv[2] will be the input filename that will contain the different reads. Each line in the
  // input file corresponds to one read.
  // argv[3] will be the filename of where you should output the strings from your traversal
  if(argc != 5){
    printf("Usage: ./pa3 <k_len> <inputFilename> <outputFilename> <nodeoutputFilename>\n");
    exit(1);
  }
  int k_len = atoi(argv[1]);
  if(k_len < 1){
    printf("k_len must be an integer greater than 0\n");
    exit(1);
  }
  char* inputFilename = argv[2];
  char* outputFilename = argv[3];
  char* nodeFilename = argv[4];

  int GRAPH_SIZE = setGraphSize(k_len);///defined in genome.h
  GNode** hashGraph = (GNode**)malloc(sizeof(GNode*)*GRAPH_SIZE);
  for(int i = 0; i < GRAPH_SIZE; ++i){
    hashGraph[i] = NULL;//intialize just in case
  }

  ///Build the graph from the input file
  //int size = BuildGraph(inputFilename, nodeFilename, k_len, hashGraph, GRAPH_SIZE);

  int size = BuildGraph2(inputFilename, nodeFilename, k_len, hashGraph, GRAPH_SIZE);
  //printf("Size= %d\n",size);
  /*
  if(size == 0){
    FreeHashGraph(hashGraph, GRAPH_SIZE, size);
    return EXIT_FAILURE;
  }
  */
  //printf("Here1\n");
  ///Output the unique nodes

  //printf("Hahses-> TTCC = %d, TCCT=%d, CCTT=%d\n",hash("TTCC",k_len,GRAPH_SIZE),hash("TCCT",k_len,GRAPH_SIZE),hash("CCTT",k_len,GRAPH_SIZE));
  
  PrintUniqueNodes(nodeFilename, hashGraph, GRAPH_SIZE, size);

  //printf("Here2\n");
  ///output of the output strings
  TraverseGraph(hashGraph, k_len, GRAPH_SIZE, outputFilename, size);
  //TraverseGraph(hashGraph, k_len, GRAPH_SIZE, outputFilename);

  //printf("Here3\n");
  ///Make sure we free the hashGraph correctly. 
  FreeHashGraph(hashGraph, GRAPH_SIZE, size);
  //printf("Here4\n");
  return 0;
}





