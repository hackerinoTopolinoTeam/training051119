/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 200000

// input data
int T, N, K;
double prob[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int c = 0; c < T; c++) {
        int N, K;
        cin >> N >> K;
        double tmp;
        for(int i = 0; i < N; i++) {
            cin >> prob[i];
        }
        double somma = 0;
        for(int i = 0; i < K; i++) {
            double massimo = -1;
            int pos = -1;
            for(int j = 0; j < N; j++) {
                if(massimo < prob[j]){
                    massimo = prob[j];
                    pos = j;
                }
            }
            somma += massimo;
            //cout << "massimo " << massimo << "\n";
            prob[pos] = prob[pos] * (1 - prob[pos]);
        }
        double result = floor(somma * 1000000) / 1000000;
        printf("%.6f\n", result);

        //cout << result << "\n";
    }

    return 0;
}
