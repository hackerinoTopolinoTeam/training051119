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

int solve(int A, int Atot){
    /// La macchina è stata usata per A anni
    if(Atot-1 == Y)
        return (A == 0) ? 0 : -P[A-1];

    if(A == D)
        return -P[A-1] + solve(0, Atot+1);

    int op1 = (A == 0) ? C : 0, op2 = (A == 0) ? C : 0;

    op1 += M[A] + solve(A+1, Atot+1);
    op2 += M[A] - P[A] + solve(0, Atot+1);

    int res = min(op1, op2);
    if(A == 0 && Atot == 0)
        cout << op1 << " " << op2 << "\n";

    if(A == 0 && Atot == 1)
        cout << op1 << " " << op2 << "\n";
    return res;
}

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(3 == scanf("%d %d %d", &C, &D, &Y));

  // warning! M and P are 1-based
  for (i = 0; i < D; i++) assert(1 == scanf("%d", &M[i]));
  for (i = 0; i < D; i++) assert(1 == scanf("%d", &P[i]));

  cout << solve(0,0) << "\n"; // print the result
  return 0;
}
