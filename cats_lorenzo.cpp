/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
#define MAXN 1000

// input data
int Nm, Nf, i;
int M[MAXN], F[MAXN];
int memo[MAXN][MAXN];

int calcola(int m, int f) {
    if(m == Nm || f == Nf) return 0;

    if(memo[m][f] != -1) return memo[m][f];

    int a = abs(M[m] - F[f]) + calcola(m+1, f+1),
        b = calcola(m+1, f),
        c = calcola(m, f+1);

    return memo[m][f] = max(a, max(b, c));
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    memset(memo, -1, sizeof memo);

    assert(2 == scanf("%d %d", &Nm, &Nf));
    for(i=0; i<Nm; i++)
        assert(1 == scanf("%d", &M[i]));
    for(i=0; i<Nf; i++)
        assert(1 == scanf("%d", &F[i]));

    // insert your code here
    
    printf("%d\n", calcola(0,0)); // change 42 with actual answer
    return 0;
}
