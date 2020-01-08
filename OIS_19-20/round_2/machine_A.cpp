/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXD 1000
// input data
int C, D, Y, i;
int M[MAXD + 1];
int P[MAXD + 1];

int  dp(int y, int a, int cost) {
    //cout << "y " << y << " a " << a << " cost " << cost << endl;
    if(y == Y)
        return cost - P[a];
    int result = dp(y + 1, 1, cost - P[a] + C);
    if(a <= D)
        result = min(result,  dp(y + 1, a + 1, cost + M[a]));
    return result;
}

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(3 == scanf("%d %d %d", &C, &D, &Y));
  M[0] = 0;
  P[0] = 0;
  // warning! M and P are 1-based
  for (i = 1; i <= D; i++) assert(1 == scanf("%d", &M[i]));
  for (i = 1; i <= D; i++) assert(1 == scanf("%d", &P[i]));

  // insert your code here

  printf("%d\n", dp(1,1, C));  // print the result
  return 0;
}
