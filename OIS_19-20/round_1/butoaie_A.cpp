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
    assert(2 == scanf("%d%d", &P, &Q));
    int rim = 0;
    for(i=0; i<N; i++) {
        assert(1 == scanf("%d", &V[i]));
        if(V[i] > 0) rim++;
    }

    // insert your code here
    int p = max(P,Q), s = min(P,Q), np = (P==p ? K : N-K), ns = (s==Q ? N-K : K), res = 0;

    while(rim) {
        sort(V, V+N, greater<int>());

        int t_rim = rim;
        for(int i=0; i<rim; i++) {
            assert(V[i] >= 0);
            if(i < np)
                V[i] -= p;
            else
                V[i] -= s;

            if(V[i] <= 0) t_rim--;
        }

        rim = t_rim;
        res++;
    }

    printf("%d\n", res); // print the result
    return 0;
}
