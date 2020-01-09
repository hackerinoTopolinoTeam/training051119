#include <bits/stdc++.h>

using namespace std;

long long R, C, K;

int main() {

  assert(3 == scanf("%lld %lld %lld", &R, &C, &K));

  long long risC = (C %K == 0)?C/K:C/K +1;

  long long risR = (R %K == 0)?R/K:R/K +1;
  long long result = risC * risR;
  
  printf("%lld\n", result);  // print the result
  return 0;
}
