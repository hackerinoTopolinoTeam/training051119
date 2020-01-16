/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 1000000

// input data
int N, i, j;
int M[MAXN], L[MAXN], *F[MAXN];

struct MyComp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

vector<int> amici[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for (i=0; i<N; i++) {
        assert(2 == scanf("%d %d", &M[i], &L[i]));
        F[i] = (int*)malloc(M[i]*sizeof(int));
        for (j=0; j<M[i]; ++j){
            assert(1 == scanf("%d", &F[i][j]));
            amici[F[i][j]].push_back(i);
        }
    }

    /*for(i = 0; i < N; i++) {
            cout << i << " -> ";
        for(auto x : amici[i])
            cout << x << " ";
        cout << endl;
    }*/

    // insert your code here
    queue<int> q;

    for(i = 0; i < N; i++) {
        if(L[i] == 0)
            q.push(i);
    }

    int tot = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        tot++;
        for(int k = 0; k < amici[curr].size(); k++) {
            L[amici[curr][k]]--;
            if(L[amici[curr][k]] == 0)
                q.push(amici[curr][k]);
        }
    }

    printf("%d\n", tot); // print the result
    return 0;
}
