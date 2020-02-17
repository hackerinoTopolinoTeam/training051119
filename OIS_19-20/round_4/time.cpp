/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints

// input data
int H0, M0, H1, M1;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(4 == scanf("%d%d%d%d", &H0, &M0, &H1, &M1));
    int res = 0;
    // insert your code here
   if((H0 * 60 + M0) < (H1 * 60 + M1)){
        res = (H1 * 60 + M1) - (H0 * 60 + M0);
   } else {
        res = H1* 60 + M1 + (24 * 60 - (H0 * 60 + M0));
   }

    printf("%d %d\n", (res/60), (res%60) ); // print the result
    return 0;
}
