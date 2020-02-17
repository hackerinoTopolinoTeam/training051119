/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
#define MAXN 100
typedef long long ll;

// input data
int N, i;
set<ll> C;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(i=0; i<N; i++) {
        ll c;
        cin >> c;
        C.insert(c);
    }

    //sort(C,C+N);
    ll gcd = -1;
    for(ll x : C)
        if(gcd == -1) gcd = x;
        else gcd = __gcd(gcd, x);

    // insert your code here

    // change the following two lines to print the result
    set<ll> res;
    for (ll i=1; i*i<=gcd; i++) {
        if(gcd % i == 0) {
            res.insert(i);
            if(gcd / i != i) res.insert(gcd / i);
        }
    }
    //sort(res.begin(), res.end());
    for(ll x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}
