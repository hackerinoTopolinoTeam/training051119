/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 100000

// input data
long long N, i;
long long S[MAXN], P[MAXN];

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%lld", &N));
    for(i=0; i<N; i++) {
        assert(1 == scanf("%lld", &S[i]));
        assert(1 == scanf("%lld", &P[i]));
    }

    // insert your code here

    long long sumN = 0, sumD = 0;

    for(int i = 0; i < N; i++) {
        sumN += S[i];
        sumD += P[i];
    }

    long long n = sumN - S[0], d = sumD - P[0];
    int im = 0;

    for(int i = 1; i < N; i++) {
        sumN -= S[i];
        sumD -= P[i];

        if(n * sumD < d * sumN) {
            n = sumN;
            d = sumD;
            im = i;
        }

        sumN += S[i];
        sumD += P[i];
    }

    printf("%d\n", im); // print the result
    return 0;
}
