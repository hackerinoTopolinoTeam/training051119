/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;
// constraints
#define MAXN 100000

// input data
int N, P, i;
int H[MAXN];

vector<int> des;
vector<int> temp;
bool isDes(int pos){
    if(pos < 0 || pos >= N)
        return false;
    int hd = (pos < N -1 )? H[pos + 1] : 0;
    int hs = (pos > 0) ? H[pos-1] : 0;
    return ((H[pos] > hd )&& (H[pos] > hs));
}

void destroy(int pos) {
    H[pos] = 0;
    if(isDes(pos-1))
        temp.push_back(pos-1);
    if(isDes(pos+1))
        temp.push_back(pos+1);
}
int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &P));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &H[i]));
    int res = 0;
    for(int i = 0; i < N ; i++){
        //cout<<isDes(i)<<"\n";
        if(isDes(i))
            des.push_back(i);
    }

    /*for(auto x: des)
        cout<<x<<"   ";*/
    for(int i = 0; i < P; i++){
        if(des.empty()) break;
        res += des.size();
        for(auto x: des)
            destroy(x);
        des = temp;
        temp.clear();
    }

    // insert your code here

    printf("%d\n", res); // print the result
    return 0;
}
