/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 200000

// input data
int N, K, Q, P, i;
int V[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d%d", &N, &K));
    assert(2 == scanf("%d%d", &Q, &P));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &V[i]));

    // insert your code here

    int valm = 0;
    for(int i = 0; i < N; i++) {
        valm = max(valm, V[i]);
    }

    int giorni = (valm % Q) == 0 ? valm / Q : valm / Q + 1;

    printf("%d\n", giorni); // print the result
    return 0;
}
