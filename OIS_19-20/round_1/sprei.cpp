/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 10000
#define MAXM 100

using namespace std;

// input data
int N, M, B, i, j;
int C[MAXN][MAXM];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d %d %d", &N, &M, &B));
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            assert(1 == scanf("%d", &C[i][j]));

    // insert your code here

    long long linea[N];
    for(int k = 0; k < N; k++) {
        linea[k] = C[k][0];
    }

    sort(linea, linea + N);


    bool rimossi[N];
    fill(rimossi, rimossi + N, false);
    long long n_rimosso = 0;
    for(int k = 1; k < N; k++) {
        cout << linea[k] << "\n";
        if(linea[k] - 1 == linea[k - 1] && rimossi[k] == false){
            rimossi[k] = true;
            n_rimosso += 1;
        }
    }
    cout << "\n";


    printf("%lld\n", n_rimosso); // print the result
    return 0;
}
