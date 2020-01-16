#include <bits/stdc++.h>
using namespace std;
// constraints
#define MAXN 120
#define MOD 1000000007

// input data
int N, X, i, j;
int M[MAXN][MAXN];
int memo[MAXN][MAXN][MAXN][MAXN];

int f(const int & u, const int & l, const int & r, const int & d) {
    if(memo[u][l][r][d] != -1) return memo[u][l][r][d];
    int res = 1;

    if(d < u || r < l) return 1;

    /// top row
    int v = 0;
    for(int i=l; i<=r; i++)
        v += M[u][i];
    if(v >= X) res += f(u+1,l,r,d);

    /// bottom row
    v = 0;
    for(int i=l; i<=r; i++)
        v += M[d][i];
    if(v >= X) res += f(u,l,r,d-1);

    /// left column
    v = 0;
    for(int i=u; i<=d; i++)
        v += M[i][l];
    if(v >= X) res += f(u,l+1,r,d);

    /// right column
    v = 0;
    for(int i=u; i<=d; i++)
        v += M[i][r];
    if(v >= X) res += f(u,l,r-1,d);

    return memo[u][l][r][d] = res;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &X));
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            assert(1 == scanf("%d", &M[i][j]));
        }
    }

    // insert your code here
    memset(memo, -1, sizeof memo);
    printf("%d\n", f(0,0,N-1,N-1)); // print the result
    return 0;
}
