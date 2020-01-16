/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 1000000

using namespace std;

// input data
int N, i;
int C[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));

    // insert your code here
    int mind = C[0];
    for(i = 0; i < N; i++) {
        mind = max(mind, C[i] - C[i - 1]);
    }

    printf("%d\n", mind); // print the result
    return 0;
}
