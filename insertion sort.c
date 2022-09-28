#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *insertionsort(arr, n);

int main() {
    int arr [] = {4, 6, 2, 9, 1, 8, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int st = 0;
    int ed = n - 1;
    printf("Original Array : ");
    for (int i = 0; i <= ed; i ++){
        printf("%d ", arr[i]);
    }

    int *ans = insertionsort(arr, n);

    printf("\n--------------\n");
    printf("Sorted Array : ");

    for (int i = 0; i <= ed; i ++){
        printf("%d ", ans[i]);
    }

    printf("\n--------------\n");
}

int *insertionsort(int arr[], int n){
    int *ans, temp;
    ans = malloc(sizeof(int) * n);
    ans[0] = arr[0];
    for (int i = 1; i < n; i ++){
        ans[i] = arr[i];
        int j = i;
        while ((j > 0) & ( ans[j - 1] > ans[j])){
            temp = ans[j];
            ans[j] = ans[j - 1];
            ans[j - 1] = temp;
            j -= 1;
        }
    }
    return ans;
}




