/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
#define MAXN 1000
typedef pair<int,int> pii;
#define F first
#define S second
// input data
int R, C, i, j;
int M[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<pii> dir = {{0,-1},{-1,0},{1,0},{0,1}};

bool inside(pii x) {
    return (x.F >= 0 && x.S >= 0 && x.F < R && x.S < C);
}

int bfs(pii s) {
    bool isola = true;
    queue<pii> q;
    q.push(s);
    while(!q.empty()) {
        pii act = q.front(); q.pop();
        if(vis[act.F][act.S])
            continue;

        vis[act.F][act.S] = true;
        if(act.F == 0 || act.S == 0 || act.F == R-1 || act.S == C-1) {
            isola = false;
        }
        for(pii & x : dir) {
            pii next = {act.F+x.F, act.S+x.S};
            if(!vis[next.F][next.S] && inside(next) && M[next.F][next.S] == 1)
                q.push(next);
        }
    }
    return isola;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &R, &C));
    for(i=0; i<R; i++)
        for (j=0; j<C; j++)
            assert(1 == scanf("%d", &M[i][j]));

    // insert your code here
    memset(vis, false, sizeof vis);
    int res = 0;
    for(i=0; i<R; i++)
        for (j=0; j<C; j++) {
            if(M[i][j] == 1 && !vis[i][j])
                res += bfs({i,j});
        }
    printf("%d\n", res); // print the result
    return 0;
}
