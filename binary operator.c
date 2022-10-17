# include <stdlib.h>
# include <stdio.h>

void decimaltobinary(int n);


int main(){
    int a = 13;
    decimaltobinary(a);

}

void decimaltobinary(int n){
    int *arr1 = malloc(sizeof(int) * 50);
    int *arr2 = malloc(sizeof(int) * 50);
    int count = 0;
    while (n != 0){
        int res = n % 2;
        arr1[count] = res;
        count ++;
        n /= 2;
    }
    for (int i = 0; i <= count; i ++){
        arr2[i] = arr1[count - 1 - i];
    }

    for (int i = 0; i < count; i ++){
        printf("%d", arr2[i]);
    }



}


