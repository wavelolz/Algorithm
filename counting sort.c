# include <stdio.h>
# include <stdlib.h>

int max(int arr [], int size);
int* countingsort(int arr[], int size, int max);
void main(){
    int arr [] = {9, 8, 1, 1, 4, 9, 3, 2, 1, 1, 10, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int st = 0;
    int ed = n - 1;
    int m = max(arr, n);
    int *ans;
    ans = countingsort(arr, n, m);
    for (int i = 0; i < n; i ++){
        printf("%d ", ans[i]);
    }

}

int max(int arr [], int size){
    int crmax = arr[0];
    for (int i = 1; i < size; i ++){
        if (arr[i] > crmax){
            crmax = arr[i];
        }
    }
    return crmax;
}

int* countingsort(int arr[], int size, int max){
    int *cmpr = calloc(max, sizeof(int) * max);
    int *ans = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i ++){
        cmpr[arr[i] - 1] += 1;
    }

    int cumsum = cmpr[0];
    for (int i = 1; i < max; i ++){
        cumsum += cmpr[i];
        cmpr[i] = cumsum;
    }

    for (int i = size - 1; i >= 0; i --){
        int pos = cmpr[arr[i] - 1] - 1;
        cmpr[arr[i] - 1] -= 1;
        ans[pos] = arr[i];
    }



    return ans;
    free(cmpr);
    free(ans);

}
