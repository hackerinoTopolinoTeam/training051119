/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 1000

using namespace std;

// input data
int Nm, Nf, i;
vector<int> M(MAXN), F(MAXN);

vector<vector<int>> memo( MAXN, vector<int>(MAXN, -1));

int result(int mi, int fi) {
    if(mi >= Nm || fi >= Nf)
        return 0;
    if(memo[mi][fi] != -1)
        return memo[mi][fi];
    int 
        tmp1 = abs(M[mi] - F[fi]) + result(mi + 1, fi + 1),
        tmp2 = result(mi + 1, fi),
        tmp3 = result(mi, fi + 1);

    int memo_tmp = max(max(tmp1, tmp2), tmp3);
    memo[mi][fi] = memo_tmp; 
    return memo_tmp;
}


int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Nm, &Nf));
    for(i=0; i<Nm; i++)
        assert(1 == scanf("%d", &M[i]));
    for(i=0; i<Nf; i++)
        assert(1 == scanf("%d", &F[i]));

    // insert your code here

    int solution = result(0, 0);

    printf("%d\n", solution); // change 42 with actual answer
    return 0;
}
