/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

// constraints
#define MAXD 500000
#define MAXP 500000
#define MAXE 500000

// input data
int D, P, E, i;
pair<int, pair<bool,int> > A[MAXD+MAXP];
//int T[MAXE], ID[MAXE];

bool dfs(int s) {
    bool res = false;
    int max_i = -1;
    while(s != -1) {
        if(A[s].S.S > max_i) {
            max_i = A[s].S.S;
            res = A[s].S.F;
        }
        s = A[s].F;
    }
    return res;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d%d%d", &D, &P, &E));
    for(i=0; i<D+P; i++) {
        int a;
        assert(1 == scanf("%d", &a));
        A[i] = {a, {false,-1}};
    }

    for(i=0; i<E; i++) {
        int T, ID;
        assert(2 == scanf("%d%d", &T, &ID));
        if(T == 0 || T == 1)
            A[ID].S = {T,i};
        else {
            cout << (dfs(ID) ? 1 : 0) << "\n";
        }
    }
    return 0;
}
