/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 1000000

using namespace std;
// input data
int N, i;
int E[MAXN], A[MAXN], O[MAXN];

struct MyComp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.first < b.first;
    }
};

void visita() {

    vector<int> ad[N + 1];

    for(int j = 0; j < N; j++) {
        ad[E[j] + 1].push_back(j + 1);
    }
    //cout<<"Fatto lista ad"<<endl;
    priority_queue<pair<int,int>, vector<pair<int,int>>, MyComp> q;
    q.push({A[0],1});

    int c_in = 0;

    while(!q.empty()) {
        pair<int,int> curr = q.top();
        q.pop();
        O[c_in++] = curr.second - 1;
        //cout<<curr.first<<" "<<curr.second<<endl;
        for(int j = 0; j < ad[curr.second].size(); j++) {
            q.push({A[ad[curr.second][j] - 1],ad[curr.second][j]});
        }
    }
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &E[i])); // evacuation directions
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &A[i])); // arrogance


    // insert your code here
    visita();


    // print the result
    for(i=0; i<N; i++) printf("%d ", O[i]);
    printf("\n");
    return 0;
}
