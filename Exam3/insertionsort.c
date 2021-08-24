#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertion_sort(int * arr, int n){
    for (int j = 1; j < n; j++){
        for (int i = j; i >= 1; i--){
            if (arr[i-1] > arr[i]){
                //swap
                int tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
                printf("j=%d; i=%d\n", j , i);
                print_array(arr, n);
            } else {
                break;
            }
        }
    }
} 

void insertion_sort_move(int *arr, int n){
    for (int j = 1; j < n; j++){
        int temp = arr[j];
        int i = j;
        while (i > 0 && arr[i-1] > temp){
            arr[i] = arr[i-1];
            i--;
        }
        arr[i]  = temp;
    }
}

void insertion_sort_sentinel(int *arr, int n){
    for (int j = n-1; j >= 1; j--){
        if (arr[j-1] > arr[j]){
            // swap arr[j-1] and arr[j]
            int t = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = t;
        }
    }
    
    for (int j = 2; j < n; j++){
        int temp = arr[j];
        int i = j;
        while (arr[i-1] > temp){ // gurantee that arr[0] <= temp 
            arr[i] = arr[i-1];
            i--;
        }
        arr[i]  = temp;
    }
}

int main(int argc, char *argv[]){
    int arr[] = {3, 1, 6, 3, 2, 5, 4, 5};
    printf("Before Sorting\n");
    print_array(arr, 8);
    insertion_sort_sentinel(arr, 8);
    printf("After Sorting\n");
    print_array(arr, 8);
    return 0;
}
