/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
#define MAXN 100000

// input data
int T, N, K, i, j;
int A[MAXN], B[MAXN];
int fib[MAXN];

void prec() {
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2; i<12c; i++)
        fib[i] = fib[i-1] + fib[i-2];
}
typedef pair<int, int> pii;
#define F first
#define S second
int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    prec();
    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(2 == scanf("%d %d", &N, &K));
        for (j=0; j<N; j++)
            assert(2 == scanf("%d %d", &A[j], &B[j]));

        // insert your code here
        vector<pii> V;
        for(int j=0; j<N; j++) {
            if(A[j] < 6) {
                int volte = K/fib[A[j]];
                while(volte--)
                V.push_back({fib[A[j]], B[j]});
            }
        }

        long long result = 0;
        for(int j=0; j<(1<<(int)V.size()); j++) {
            int Kt = K;
            long long tmp = 0;
            for(int k=0; k<(int)V.size(); k++) {
                bool prendo = (j & (1<<k)) > 0;
                if(prendo && Kt < V[k].F) break;
                if(prendo) {
                    tmp += V[k].S;
                    Kt -= V[k].F;
                }
            }
            result = max(tmp, result);
        }
        printf("%lld\n", result); // print the result
    }
    return 0;
}
