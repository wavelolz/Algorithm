#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void binary_search(int arr [], int st, int ed, int target);

int main(){
    int arr[] = {7, 9, 10, 23, 45, 76, 90, 102};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 90;
    printf("Array is : ");
    for (int i = 0; i < n; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n--------------\n");
    printf("Target is : %d", target);
    printf("\n--------------\n");
    binary_search(arr, 0, n - 1, target);
}

void binary_search(int arr [], int st, int ed, int target){
    if (ed >= st){
        int m = st + (ed - st) / 2;
        if (arr[m] == target){
            printf("Value found at index : %d", m);
        } else if (arr[m] < target){
            binary_search(arr, m + 1, ed, target);
        } else {
            binary_search(arr, st, m - 1, target);
        }
    }



}
