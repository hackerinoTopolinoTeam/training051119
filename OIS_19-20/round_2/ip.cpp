#include <stdio.h>
#include <assert.h>

long long A[4], B[4];

int main() {
    assert(4 == scanf("%lld.%lld.%lld.%lld", &A[0], &A[1], &A[2], &A[3]));
    assert(4 == scanf("%lld.%lld.%lld.%lld", &B[0], &B[1], &B[2], &B[3]));

    // at this point, the arrays A and B contain four elements each with the individual IP octects
    // for example: 192.168.1.1 creates an array [192, 168, 1, 1] with 192 at index 0

    long long A1 = A[0] * 256 * 256 * 256 + A[1] * 256 * 256 + A[2] * 256 + A[3];
    long long B1 = B[0] * 256 * 256 * 256 + B[1] * 256 * 256 + B[2] * 256 + B[3];
    long long result = B1 - A1 + 1;
    printf("%lld\n", result);  // print the result
    return 0;
}
