/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

using namespace std;

// input data
long long R, C, K;

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(3 == scanf("%lld %lld %lld", &R, &C, &K));

  long long risC = (C %K == 0)?C/K:C/K +1;

  long long risR = (R %K == 0)?R/K:R/K +1;
  long long result = risC * risR;
  // insert your code here

  printf("%lld\n", result);  // print the result
  return 0;
}
