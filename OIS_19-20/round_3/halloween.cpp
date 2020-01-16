/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N;
int C[MAXN];
long long M;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %lld", &N, &M));
    long long sum = 0;
    for(int i=0; i<N; i++) {
        assert(1 == scanf("%d", &C[i]));
        sum += C[i];
    }
    long long R = M % sum;
    int res = N-1;
    if(R != 0) {
        for(int i=0; i<N; i++) {
           R -= C[i];
           if(R <= 0) {
            res = i;
            break;
           }
        }
    }

    // insert your code here

    printf("%d\n", res); // print the result
    return 0;
}
