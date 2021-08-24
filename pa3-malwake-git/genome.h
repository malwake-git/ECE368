//#ifndef __GENOME_H_
//#define __GENOME_H_

#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_KMER_LEN 16

int getval(char c){
  switch (c){
    case 'A': case 'a':
      return 0;
    case 'C': case 'c':
      return 1;
    case 'G': case 'g':
      return 2;
    case 'T': case 't':
      return 3;
    default:
      return 0;
  }
  return 0;
}

typedef struct GNode{
    char key[MAX_KMER_LEN];/// Will hold strings only consisting of ACGT
  char inkey[MAX_KMER_LEN-1];
  char outkey[MAX_KMER_LEN-1];
  
    struct GNode* inEdges[4];
    struct GNode* outEdges[4];
    int key_len;/// this is our k length
  int count;
  int Hash;
  int inDegree;
  int outDegree;
}GNode;


/*
typedef struct GNode{
  char key[MAX_KMER_LEN];/// Will hold strings only consisting of ACGT
  int inEdges[4]; ///Edges can be A,C,G,or T. 0 = A, 1 = C, 2 = G, 3 = T
  int outEdges[4]; ///Edges can be A,C,G,or T. 0 = A, 1 = C, 2 = G, 3 = T
  int key_len;/// this is our k length
}GNode;
*/

int getLineLength(char* inputFilename){

  FILE* ifptr = fopen(inputFilename, "r");
  if(!ifptr){
    printf("Could not open input file!!\n");
  }
  int i = 0;
  while(getc(ifptr) != '\n'){
    i++;
  }
  //printf("Line length = %d\n",i);
  fseek (ifptr, 0, SEEK_SET);
  fclose(ifptr);
  return i;

}



GNode * InitGNode(GNode* node, char* k, int kl, int nodeHash, char* ink, char* outk, int count){
  
  int max_chars = kl < MAX_KMER_LEN ? kl : MAX_KMER_LEN;
  if(max_chars != kl){
    printf("Can't save the length of the key correctly. Exiting program.\n");
    exit(1);
  }
  strncpy(node->key, k, kl);
  node->key[kl] = '\0';

  strncpy(node->inkey, ink, kl);
  node->inkey[kl-1] = '\0';
  strncpy(node->outkey, outk, kl);
  node->outkey[kl-1] = '\0';
  
  node->key_len = kl;
  node->Hash = nodeHash;
  node->inDegree = 0;
  node->outDegree = 0;
  node->count = count;
  for(int i = 0; i < 4; i++){
    node->inEdges[i] = NULL;
    node->outEdges[i] = NULL;
  }
  return node;

}


int hash(char * key, int key_len, int GRAPH_SIZE){///this can be used to determine if string exists already
         int toRet = 0;
         int i;
         for(i = 0; i < key_len; ++i){
	   toRet = toRet << 2;
             toRet |= getval(key[i]);
         }
	 //char c = (char)toRet;
	 //printf("toRet = %d\n",toRet);
         toRet = toRet % GRAPH_SIZE;
         return toRet;
     }

/*
long hash(GNode* node, long GRAPH_SIZE){///this can be used to determine if string exists already
  long toRet = 0;
  int i;
  for(i = 0; i < node->key_len; ++i){
    toRet = toRet << 2;
    toRet |= getval(node->key[i]);
  }
  toRet = toRet % GRAPH_SIZE;
  return toRet;
}
*/
void AddEdges(GNode* from, GNode* to){

  /*
  if(from->outEdges[getval(to->key[to->key_len-1])] != to && to->inEdges[getval(from->key[0])] != from;){
    from->outDegree = from->outDegree + 1;
    to->inDegree = to->inDegree + 1;
  }
  */
      from->outEdges[getval(to->key[to->key_len-1])] = to;
      to->inEdges[getval(from->key[0])] = from;

      //from->outDegree++;
      //to->inDegree++;
      /*
      if((from->outDegree < 4) && (to->inDegree < 4))
	{
	  from->outDegree++;
	  to->inDegree++;
	}
      */
      //int v2 = getval(to->key[to->key_len-1]);
      //int v1 = getval(from->key[0]);
      //printf("from = %s, to= %s\n",from->key,to->key);
      //printf("edge(exit%c,enter%c), (%d,%d)\n",from->key[0],to->key[to->key_len-1],v1,v2);
}

int setGraphSize(int k_len){
      int GRAPH_SIZE = 1;
      switch(k_len){
          case 1: GRAPH_SIZE = 4; break;
          case 2: GRAPH_SIZE = 16; break;
          case 3: GRAPH_SIZE = 64; break;
          case 4: GRAPH_SIZE = 256; break;
          case 5: GRAPH_SIZE = 1024; break;
          case 6: GRAPH_SIZE = 4096; break;
          case 7: GRAPH_SIZE = 16384; break;
          case 8: GRAPH_SIZE = 65536; break;
          case 9: GRAPH_SIZE = 262144; break;
          case 10: GRAPH_SIZE = 1048576; break;
          case 11: GRAPH_SIZE = 4194304; break;
          default: GRAPH_SIZE = 16777216; break;
      }
      return GRAPH_SIZE;
}

//#endif //__GENOME_H_
