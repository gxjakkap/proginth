#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int a;
    unsigned int k;
} Action;

int main(){
    unsigned int n, m, q, qi;

    scanf("%u %u %u", &n, &m, &q);

    unsigned int *am = calloc(n, sizeof(unsigned int));
    Action *act = malloc (m * sizeof(Action));
    
    for (int i = 0; i < (int)m; i++){
        scanf("%u %u", &act[i].a, &act[i].k);
    }

    for (int i = 0; i < (int)m; i++){
        for (int j = 0; j < act[i].k; ++j){
            am[(act[i].a - 1) + j] ^= 1;
        }
    }


    for (int i = 0; i < (int)q; i++){
        scanf("%u", &qi);
        int p = qi - 1, j = p, s = am[j], c = 0;

        // count up
        int cur = am[j];
        while (cur == s && j < n){
            j++; 
            c++;
            cur = am[j];
        }

        //count down
        j = p - 1;
        cur = am[j];
        while (cur == s && j >= 0){
            --j; 
            c++;
            cur = am[j];
        }

        printf("%d", c);
        if (i != ((int)q - 1)) printf("\n");
    }

    free(am);
    free(act);
    return 0;
}