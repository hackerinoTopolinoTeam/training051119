/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 100000

using namespace std;

// input data
int T, N, K, i, j;
int A[MAXN], B[MAXN];

long long fib[MAXN];

int dp(int n, int r) {
    if(n < 0)
        return 0;
    else {
        int massimo = INT_MIN;
        int somma = 0;
        while(r > 0) {
            massimo = max( massimo, dp( n - 1, r) + somma);
            r -= fib[A[n]];
            somma += B[n];
        }
        return massimo;
    }
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < MAXN; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(2 == scanf("%d %d", &N, &K));
        for (j=0; j<N; j++)
            assert(2 == scanf("%d %d", &A[j], &B[j]));

        // insert your code here
        long long massimo = 0;
        if(K == 1) {
            for(int k = 0; k < N; k++) {
                if(fib[A[k]] == 1) {
                    if(B[k] > massimo) {
                        massimo = B[k];
                    }
                }
            }
        }
        printf("%lld\n", massimo); // print the result
    }

    return 0;
}
