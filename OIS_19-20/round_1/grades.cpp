
#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000000

// input data
int N, i;
int G[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &G[i]));

    // insert your code here

    int ii = -1 , is = -1;
    for(int j = 0; j < N; j++){
            if(G[j] < 6){
                ii = j;
                break;
            }
    }
    for(int j = N - 1; j >= 0; j--){
        if(G[j] >= 6){
            is = j;
            break;
        }
    }

    if( ii == -1 || is == -1 || N ==1 || ii >= is){
        printf("-1\n");
    }  else {
        int res = (is - ii) + 1;
        printf("%d\n", res); // print the result
    }
    return 0;
}
