/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
#define MAXN 100000

// input data
int N, D;
int L[MAXN], P[MAXN], S[MAXN], T[MAXN];

int fun1(int t, int b) {

    if(t < S[b]) {
        return S[b];
    }else if (t == S[b]) {
        return S[b] + T[b];
    }
    int k = floor((t - S[b]) / (T[b])) + 1;

    int tt = S[b] + k * T[b];

   return tt;
}


struct MyComp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
};

int tempo(int a, int b) {
    if(P[a] <= L[b] - D * (b - a)) {//Può arrivare il segnale
        return -1;
    }



    return fun1(S[a], b);
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &D));
    for(int i=0; i<N; i++)
        assert(4 == scanf("%d %d %d %d", &L[i], &P[i], &S[i], &T[i]));

    // insert your code here

    vector<int> adj[N];

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(P[i] - D * (j - i) >= L[j]) {
                adj[i].push_back(j);
            }
        }
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, MyComp> q;
    int tempi[N];

    fill(tempi, tempi + N, INT_MAX);

    q.push({0, S[0]});
    tempi[0] = S[0];

    while(!q.empty()) {
        //pair<int,int> node
        int curr = q.top().first;
        //cout<<curr<<" "<<tempi[curr]<<endl;

        /*if(curr == N - 1)
            break;
        */
        q.pop();
        for(int i = 0; i < adj[curr].size(); i++) {
            int tmp =  fun1(tempi[curr], adj[curr][i]);
            if(tempi[adj[curr][i]] > tmp) {
                tempi[adj[curr][i]] = tmp;
                q.push({adj[curr][i], tmp});
            }
        }
    }


    if(tempi[N - 1] == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n", tempi[N - 1]);

    return 0;
}
