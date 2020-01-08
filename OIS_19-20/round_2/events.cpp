/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 50000

using namespace std;

// input data
int N, V, i;
int prices[MAXN], vouchers[MAXN];

bool my(int a, int b) {

return a > b;

}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &V));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &prices[i]));
    for(i=0; i<V; i++)
        assert(1 == scanf("%d", &vouchers[i]));

    // insert your code here



    sort(prices, prices + N, my);
    sort(vouchers, vouchers + V, my);

    int cont = 0;

    for(int j = 0, k = 0; j < N && k < V;) {

        if(prices[j] <= vouchers[k]) {
            cont += 1;
            k++;
            j++;
        }else {
            j++;
        }
    }

    printf("%d\n", cont); // print the result
    return 0;
}
