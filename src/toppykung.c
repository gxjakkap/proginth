#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkDupes(char **stra, int l, char *w){
    if (l < 1) return 0;
    for (int i = 0; i < l; i++){
        if (strcmp(stra[i], w)==0){
            return 1;
        }
    }
    return 0;
}

void insertionSort(char **arr, int n){
    for (int j = 1; j < n; j++){
        char *temp = arr[j];
        int i = j - 1;
        while (i >= 0 && strcmp(arr[i], temp) > 0){
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = temp;
    }
}

int main(){
    int l = 0, u = 0;
    char in[31];
    scanf("%d", &l);

    char **stra = malloc(l * sizeof(char*));

    for (int i = 0; i < l; i++){
        scanf("%s", in);
        if (checkDupes(stra, u, in) == 1) continue;
        stra[u] = malloc((strlen(in) + 1) + sizeof(char));
        strcpy(stra[u], in);
        u++;   
    }

    insertionSort(stra, u);

    for (int i = 0; i < u; i++){
        printf("%s", stra[i]);
        if (i != u - 1) printf("\n");
        free(stra[i]);
    }

    free(stra);

    return 0;
}