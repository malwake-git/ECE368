#include <stdio.h>
#include <stdlib.h>

typedef struct _GapSeq{
    int * ks;
    int kn;
    int n;
}GapSeq;

void print_array(int *arr, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void shell_sort(int *arr, int n, GapSeq *gq)
{
    int * garr = gq->ks;
    int kn = gq->kn;
    for (int kk = kn-1; kk >= 0; kk--){
        int k = garr[kk];
        for (int j = k; j < n; j++){
            int temp = arr[j];
            int i = j;
            while (i >= k && arr[i-k] > temp){
                arr[i] = arr[i-k];
                i -= k;
            }
            arr[i] = temp;
        }
    }

}

GapSeq* gap_sequence(int n){
    GapSeq *gq = (GapSeq *)malloc(sizeof(GapSeq));
    gq->ks = (int *)malloc(sizeof(int)*n);

    int i = 0;
    int h = 1;
    while(h <= n){
        (gq->ks)[i] = h;
        h = 3 * h + 1;
        i++;
    }
    gq->kn = i;
    gq->n = n;
    
    return gq;
}

int main(int argc, char *argv[]){
    int arr[] = {3, 1, 6, 3, 2, 5, 4, 5};
    printf("Before Sorting\n");
    print_array(arr, 8);
    
    GapSeq* gq = gap_sequence(8);
    shell_sort(arr, 8, gq);
    printf("After Sorting\n");
    print_array(arr, 8);
    
    free(gq->ks);
    free(gq);
    return 0;
}