/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXT 10000

// input data
int T, i;
int N[MAXT];

int memo[100000000];

int somma_binario(int x){
    int somma = 0;
    while(x > 0){
        somma += x % 2;
        x = x / 2;
    }
    return somma;
}

int somma_triario(int x){
    int somma = 0;
    while(x > 0){
        somma += x % 3;
        x = x / 3;
    }
    return somma;
}


int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    memo[0] = 0;
    for(int j = 1; j <= 100000000; j++) {
        if(somma_binario(j) == somma_triario(j)){
            memo[j] = memo[j - 1] + 1;
        }else
            memo[j] = memo[j-1];
    }

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(1 == scanf("%d", &N[i]));

        // insert your code here

        printf("%d ", memo[N[i]]); // print the result
    }
    printf("\n");
    return 0;
}
