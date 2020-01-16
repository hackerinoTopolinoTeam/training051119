/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 1000000

using namespace std;
// input data
int N, K, i;
int V[MAXN + 1];

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(2 == scanf("%d %d", &N, &K));
  for (i = 1; i <= N; i++) assert(1 == scanf("%d", &V[i]));

  // insert your code here

  bool vis[N + 1];
  memset(vis, false, sizeof vis);

    int curr = 1;

    int t = 0;
  while(1) {
        //cout << curr << endl;
    if(curr == K) {
        break;
    }else if(vis[curr] == true){
        t = -1;
        break;
    }
    vis[curr] = true;
    curr = V[curr];
    t++;
  }

  printf("%d\n", t);  // print the result
  return 0;
}
