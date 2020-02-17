/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;
// constraints
#define MAXN 100005

// input data
int N, i;
int P[MAXN], T[MAXN];

vector<int> adj[MAXN];
int dfs(int node) {
    //cout<<node<<endl;
    if(adj[node].empty())
        return 0;
    int maxx = INT_MIN;
    int maxi = -1;
    int sum = 0;
    for(int i = 0; i < adj[node].size(); i++) {
        sum += dfs(adj[node][i]);
        sum += T[adj[node][i]-1];
        if(T[adj[node][i]-1] > maxx) {
            maxx = T[adj[node][i]-1];
            maxi = i;
        }
        //cout<< "SUM"<<sum <<endl;
    }
    return sum - maxx;
}
int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(int i = 0; i <= N; i++)
        adj[i] = vector<int>();
    for(i=0; i<N; i++) {
        assert(1 == scanf("%d", &P[i]));
        adj[P[i]].push_back(i+1);
    }
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &T[i]));

    // insert your code here

    printf("%d\n", dfs(0)); // print the result
    return 0;
}
