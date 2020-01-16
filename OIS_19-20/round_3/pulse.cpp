/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

// constraints
#define MAXP 150000
#define MAXN 600

using namespace std;


// input data
int N, P, i;
int X[MAXP], Y[MAXP], R[MAXP];

int memo[MAXN][MAXN];

bool isValid(int x, int y) {

    return x > 0 && x <= N && y > 0 && y <= N && memo[x][y] == -3;

}

int bfs() {

    queue<pair<int,int>> q;
    q.push({1,1});

    memo[1][1] = 0;
    while(!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();
        //cout<<curr.first<<" "<<curr.second<<endl;
        if(curr.first == N && curr.second == N) {
            return memo[N][N];
        }

        if(isValid(curr.first + 1, curr.second)) {
            memo[curr.first + 1][curr.second] = memo[curr.first][curr.second] + 1;
            q.push({curr.first + 1, curr.second});
        }
        if(isValid(curr.first - 1, curr.second)) {
            memo[curr.first - 1][curr.second] = memo[curr.first][curr.second] + 1;
            q.push({curr.first - 1, curr.second});
        }
        if(isValid(curr.first, curr.second + 1)) {
            memo[curr.first][curr.second + 1] = memo[curr.first][curr.second] + 1;
            q.push({curr.first, curr.second + 1});
        }
        if(isValid(curr.first, curr.second - 1)) {
            memo[curr.first][curr.second - 1] = memo[curr.first][curr.second] + 1;
            q.push({curr.first, curr.second - 1});
        }
    }
    return -111;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &P));
    for(i=0; i<P; i++)
        assert(3 == scanf("%d %d %d", &X[i], &Y[i], &R[i]));

    // insert your code here
    for(i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            memo[i][j] = -3;
    }

    for(i = 0; i < P; i++)
        memo[X[i]][Y[i]] = -1;

    printf("%d\n", bfs()); // print the result
    return 0;
}
