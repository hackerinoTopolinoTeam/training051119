/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// input data
long long N, K, M, P, Q;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(5 == scanf("%lld%lld%lld%lld%lld", &N, &K, &M, &P, &Q));

    // insert your code here

    long long alice;
    long long bob;

    if(N%2==0) {
        bob = P - (M * (N / 2));
        alice = Q - (M * (N / 2));

    }else {
        alice = P - (M * ((N / 2) + 1));
        bob = Q - (M * (N / 2));

    }

    printf("%lld\n", alice - bob); // print the result
    return 0;
}
