#ifndef HEAP_H_
#define HEAP_H_
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1023
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct _Heap{
    int count;
    int array[SIZE];
}Heap;

void init(Heap *h){

    h->count = 0;
}

void upward_heapify(Heap *h, int i){

    int tmp = h->array[i];
    int child = i;
    int parent = (child - 1) / 2;

    while (child > 0 && h->array[parent] < tmp){
        h->array[child] = h->array[parent];
        child = parent;
        parent = (child - 1) / 2;
    }
    h->array[child] = tmp;
}

void downward_heapify(Heap *h, int ii, int n){

    int tmp = h->array[ii];
    int i = ii;
    int j; 
    while ((j  = 2 * i + 1) <= n){
        if (j < n && h->array[j] < h->array[j+1]) 
            j = j + 1;
        if (tmp >= h->array[j]){
            break;
        } else {
            h->array[i] = h->array[j];
            i = j;
        }
    }
    h->array[i] = tmp;
}

void insert(Heap *h, int e){

    h->array[h->count] = e;
    h->count++;
    upward_heapify(h, h->count-1);
}

int del(Heap *h){

    int ret = h->array[0];
    h->array[0] = h->array[h->count-1];
    h->count--;
    downward_heapify(h, 0, h->count-1);
    return ret;
}

void print(Heap *h){

    int l = 0;
    printf("*******************************\n");
    for (int i = 0; i < h->count; i = 2 * i + 1){
        printf("level %d\n", l);
        int j = i;
        while(j < min(2*i+1, h->count)){
            printf("%d ", h->array[j]);
            j++;
        }
        printf("\n");
        l++;
    }
    printf("*******************************\n");
}

void hsort(Heap *h){
    
    for (int i = 1; i < h->count; i++){
        upward_heapify(h, i);
    }
    for (int i = h->count-1; i >= 1; i--){
        //swap
        int tmp = h->array[0];
        h->array[0] = h->array[i];
        h->array[i] = tmp;
        downward_heapify(h, 0, i-1);
    }
}

void efficient_hsort(Heap *h){
    for(int i = h->count/2 - 1; i >= 0; i--){
        downward_heapify(h, i, h->count-1);
    }
    for (int i = h->count-1; i >= 1; i--){
        //swap
        int tmp = h->array[0];
        h->array[0] = h->array[i];
        h->array[i] = tmp;
        downward_heapify(h, 0, i-1);
    }
}
#endif