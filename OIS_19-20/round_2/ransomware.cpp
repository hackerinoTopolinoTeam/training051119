/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * This template uses "new style" C++ strings, using the String class.
 * If you are more comfortable using the "old style" C string, please
 * look at the template specific for C.
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
const int MAXN = 100;

// input data
int N;
string contacts[MAXN];
map<string, int> m;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> contacts[i];
    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        m[s] = i;
    }

    for (int i = 0; i < N; i++) {
        string cont = contacts[i], tmp = "", ris = "";
        for(char & c : cont) {
            tmp += c;
            if(m.count(tmp) == 1) {
                ris += ('0' + m[tmp]);
                tmp = "";
            }
        }
        cout << ris << "\n";
    }


    return 0;
}
