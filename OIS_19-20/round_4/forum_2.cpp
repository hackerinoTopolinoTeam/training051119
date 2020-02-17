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
int A[MAXD+MAXP];
//int T[MAXE], ID[MAXE];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d%d%d", &D, &P, &E));
    for(i=0; i<D+P; i++)
        assert(1 == scanf("%d", &A[i]));

    vector<int> adj[D];
    bool notif[P];
    memset(notif, false, sizeof notif);

    for(i=D; i<D+P; i++) {
        int f = A[i];
        while(f != -1) {
            adj[f].emplace_back(i);
            f = A[f];
        }
    }

    for(int i=0; i<E; i++) {
        int T, ID;
        assert(2 == scanf("%d%d", &T, &ID));
        if(T == 0 || T == 1) {
            if(ID < D) {
                for(int & x : adj[ID])
                    notif[x-D] = T;
            } else {
                notif[ID-D] = T;
            }
        }
        else if(T == 2)
            cout << notif[ID-D] << "\n";
    }
    return 0;
}
