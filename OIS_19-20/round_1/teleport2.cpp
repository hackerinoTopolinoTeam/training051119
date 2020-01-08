/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// input data
int T, i;
double Xa, Ya, Xb, Yb, Xc, Yc, R;

double dist(double X1, double Y1, double X2, double  Y2) {
    return sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        //assert(7 == scanf("%d %d %d %d %d %d %d",
             //       &Xa, &Ya, &Xb, &Yb, &Xc, &Yc, &R));
        cin >> Xa >> Ya >> Xb >> Yb >> Xc >> Yc >> R;

        // insert your code here

        double result;
        bool d1 = dist(Xa,Ya,Xc,Yc) <= R, d2 = dist(Xb,Yb,Xc,Yc) <= R;
        //cout << d1 << " " << d2 << "\n";
        if(d1 && d2)
            result = 0;
        else if(d1)
            result = dist(Xb,Yb,Xc,Yc) - R;
        else if(d2)
            result = dist(Xa,Ya,Xc,Yc) - R;
        else result = min(dist(Xa,Ya,Xb,Yb),dist(Xa,Ya,Xc,Yc)+dist(Xb,Yb,Xc,Yc)-2*R);


        // print result (round down and print six decimals)
        // DO NOT EDIT!
        result = floor(result * 1000000) / 1000000;
        printf("%.6f\n", result);
    }
    return 0;
}
