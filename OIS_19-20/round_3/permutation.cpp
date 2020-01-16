/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 500000

using namespace std;

// input data
int T, N, i, t;
int V[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(t=0; t<T; t++) {
        assert(1 == scanf("%d", &N));
        for(i=0; i<N; i++)
            assert(1 == scanf("%d", &V[i]));

        // insert your code here

        int errori = 0;
        int diff1 = -1;
        int diff2 = -1;
        for(i = 0; i < N; i++) {
            if(V[i] > V[i + 1] ) {
                errori += 1;
                if(diff1 != -1)
                    diff2 = abs(V[i] -V[i + 1]);
                else
                    diff1 = abs(V[i] -V[i + 1]);
            }
        }

        if(errori <= 1)
            printf("0\n"); // print the result
        else if(errori > 2)
            printf("2\n");
        else
            if(diff1 == 1 || diff2 == 1)
                printf("1\n");
            else printf("2\n");
    }
    return 0;
}
