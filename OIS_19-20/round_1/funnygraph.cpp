/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// input data
const int MAXN = 100010;
int N, M, i;
int a, b, z;
long long P[MAXN];
bool exist[MAXN];

int main() {
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &M));
    memset(exist, false, sizeof exist);
    bool avanti = true;

    for (i = 0; i < M && avanti; i++) {
        assert(3 == scanf("%d %d %d", &a, &b, &z));

        // use a, b and z here
        if(a == b && z != 0) {
            avanti = false;
        }
        else if(a == b) continue;
        else if(!exist[a] && !exist[b]) {
            exist[a] = true;
            exist[b] = true;
            P[a] = 0;
            P[b] = P[a] - z;
        } else if(exist[a] && !exist[b]) {
            exist[b] = true;
            P[b] = P[a] - z;
        } else if(exist[b] && !exist[a]) {
            exist[a] = true;
            P[a] = P[b] + z;
        } else {
            //cout << "entro2\n";
            if(P[a] - P[b] != z) {
                //cout << "breakko\n";
                avanti = false;
            }4 5
0 1 1
1 3 -1
3 0 0
3 2 4
2 0 3
        }
    }

    // insert your code here

    printf("%d\n", (avanti ? i : i-1));  // print the result
    return 0;
}
