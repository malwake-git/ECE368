#include "heap.h"

int main(int argc, char *argv[]){
    Heap *h = (Heap *)malloc(sizeof(Heap));
    init(h);
    
    int elem[] = {18, 16, 17, 8, 15, 14, 9, 4, 3};
    for (int i = 0; i < 9; i++){
        insert(h, elem[i]);
        printf("%d inserted\n", elem[i]);
    }
    printf("#elems in heap: %d\n", h->count);
    print(h);
    
    insert(h, 14);
    print(h);
    
    printf("element removed: %d\n", del(h));
    print(h);

    efficient_hsort(h);
    print(h);
        
    return 0;
}