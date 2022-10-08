# include <stdio.h>
# include <stdlib.h>


int partition(int arr[], int st, int ed);
void quicksort(int arr[], int st, int ed);


int main(){
    int arr [] = {4, 6, 2, 9, 1, 8, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int st = 0;
    int ed = n - 1;


    printf("Original Array : ");
    for (int i = 0; i <= ed; i ++){
        printf("%d ", arr[i]);
    }

    quicksort(arr, st, ed);

    printf("\n--------------\n");
    printf("Sorted Array : ");

    for (int i = 0; i <= ed; i ++){
        printf("%d ", arr[i]);
    }

    printf("\n--------------\n");


}


int partition(int arr[], int st, int ed){
    int pivot_inx = (rand() % (ed - st + 1)) + st;
    int temp;
    temp = arr[pivot_inx];
    arr[pivot_inx] = arr[st];
    arr[st] = temp;

    int pivot = arr[st];
    int count = 0;

    for (int i = st + 1; i <= ed; i ++){
        if (pivot >= arr[i]){
            count += 1;
            temp = arr[i];
            arr[i] = arr[st + count];
            arr[st + count] = temp;
        }
    }
    temp = arr[st + count];
    arr[st + count] = arr[st];
    arr[st] = temp;
    return st + count;
}

void quicksort(int arr[], int st, int ed){
    if (ed >= st){
        int pivot_pos;
        pivot_pos = partition(arr, st, ed);
        quicksort(arr, st, pivot_pos - 1);
        quicksort(arr, pivot_pos + 1, ed);
    }

}

