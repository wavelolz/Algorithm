#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b);
int** cutrod(int arr[], int n);

int main(){
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int** ans = cutrod(arr, n);

    int* cutresult = malloc(n * sizeof(int));
    int count = 0;
    int cur_length = n;
    while(cur_length > 1){
        cutresult[count] = ans[1][cur_length];
        count ++;
        cur_length -= ans[1][cur_length];
    }

    printf("Maximum obtainable value of length [%d] is [%d]\n", n, ans[0][n]);
    printf("It is cut by: ");
    for (int i = 0; i < count; i ++){
        printf("%d ", cutresult[i]);
    }


}

int max(int a, int b){return (a > b) ? a : b;}
int** cutrod(int arr[], int n){
    int** ans = (int**) malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i ++){
        ans[i] = (int*) malloc((n+1) * sizeof(int));
    }
    ans[0][0] = 0;
    ans[0][1] = arr[0];
    ans[1][0] = 0;
    ans[1][1] = 1;
    for (int i = 1; i < n; i ++){
        int maxprofit = INT_MIN;
        int temp;
        for (int j = 0; j <= i; j ++){
            temp = maxprofit;
            maxprofit = max(maxprofit, arr[j] + ans[0][i-j]);
            if (temp != INT_MIN && temp != maxprofit){
                ans[1][i+1] = j+1;
            } else if (maxprofit == arr[0] + ans[0][i]){
                ans[1][i+1] = 1;
            }
        }
        ans[0][i+1] = maxprofit;
    }



    return ans;


}
