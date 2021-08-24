#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selection_sort(int *arr, int n){
    for (int i = n-1; i >= 1; i--){
        int max_ind = 0;
        for (int j = 1; j <= i; j++){
            if (arr[j] >= arr[max_ind])
                max_ind = j;
        }
        int tmp = arr[max_ind];
        arr[max_ind] = arr[i];
        arr[i] = tmp; 
    }
}

int main(int argc, char *argv[]){
    int arr[] = {3, 1, 6, 3, 2, 5, 4, 5};
    printf("Before Sorting\n");
    print_array(arr, 8);
    selection_sort(arr, 8);
    printf("After Sorting\n");
    print_array(arr, 8);
    return 0;
}