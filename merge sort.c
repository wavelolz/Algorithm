# include <stdio.h>
# include <stdlib.h>
# include <math.h>


void merge(int arr [], int st, int m, int ed);
void mergesort(int arr[], int st, int ed);

int main(){
    int arr [] = {4, 6, 2, 9, 1, 8, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int st = 0;
    int ed = n - 1;

    printf("Original Array : ");
    for (int i = 0; i <= ed; i ++){
        printf("%d ", arr[i]);
    }

    mergesort(arr, st, ed);

    printf("\n--------------\n");
    printf("Sorted Array : ");

    for (int i = 0; i <= ed; i ++){
        printf("%d ", arr[i]);
    }

    printf("\n--------------\n");
}

void mergesort(int arr[], int st, int ed){
    if (st < ed){
        int m = st + (ed - st) / 2;
        mergesort(arr, st, m);
        mergesort(arr, m + 1, ed);
        merge(arr, st, m, ed);
    }
}

void merge(int arr [], int st, int m, int ed){
    const int left_len = m - st + 1;
    const int right_len = ed - m;
    int left_arr [left_len];
    int right_arr [right_len];

    for (int i = 0; i < left_len; i ++){
        left_arr[i] = arr[st + i];
    }
    for (int j = 0; j < right_len; j ++){
        right_arr[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, inx = st;
    while ((i < left_len) & (j < right_len)){
        if (left_arr[i] < right_arr[j]){
            arr[inx] = left_arr[i];
            inx ++;
            i ++;
        } else {
            arr[inx] = right_arr[j];
            inx ++;
            j ++;
        }
    }

    while (i < left_len){
        arr[inx] = left_arr[i];
        inx ++;
        i ++;
    }

    while (j < right_len){
        arr[inx] = right_arr[j];
        inx ++;
        j ++;
    }
}
