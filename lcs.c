# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int* lcs(char arr1[], char arr2[]);
int* max(int n1, int n2);

int main(){
    char arr1[] = "BDCABA";
    char arr2[] = "ABCBDAB";
    int* ans;
    ans = lcs(arr1, arr2);

    printf("The length of LCS is: %d\n", ans[0]);
    printf("One of the LCS is: ");
    for (int i = 0; i < ans[0]; i ++){
        printf("%c", arr1[ans[ans[0]-i]-1]);
    }



    return 0;



}

int* max(int n1, int n2){
    int* ans;
    ans = (int*) malloc(2*sizeof(int));
    if (n1 >= n2){
        ans[0] = 0;
        ans[1] = n1;
        return ans;
    } else {
        ans[0] = 1;
        ans[1] = n2;
        return ans;
    }
    return 0;

}
int* lcs(char arr1[], char arr2[]){
    int n1, n2;
    n1 = strlen(arr1) + 1;
    n2 = strlen(arr2) + 1;
    int **m, **anc;
    m = (int**) calloc(n1, sizeof(int*));
    for (int i = 0; i < n1; i ++){
        m[i] = (int*) calloc(n2, sizeof(int));
    }

    anc = (int**) calloc(n1, sizeof(int*));
    for (int i = 0; i < n1; i ++){
        anc[i] = (int*) calloc(n2, sizeof(int));
    }


    for (int i = 1; i < n1; i ++){
        for (int j = 1; j < n2; j ++){
            if (arr1[i-1] == arr2[j-1]){
                m[i][j] = m[i-1][j-1] + 1;
                anc[i][j] = 3;
            } else {
                int *k;
                k = max(m[i-1][j], m[i][j-1]);

                m[i][j] = k[1];
                if (k[0] == 0){
                    anc[i][j] = 1;
                } else {
                    anc[i][j] = 2;
                }

            }

        }
    }


    int* inx;
    inx = (int*) malloc(sizeof(int) * 50);
    int count = 0;
    int posi = n1 - 1, posj = n2 - 1;
    while (anc[posi][posj] != 0){
        if (anc[posi][posj] == 1){
            posi -= 1;
        } else if (anc[posi][posj] == 2){
            posj -= 1;
        } else {
            inx[count + 1] = posi;
            count ++;
            posi -= 1;
            posj -= 1;

        }
    }
    inx[0] = count;

    return inx;




}
