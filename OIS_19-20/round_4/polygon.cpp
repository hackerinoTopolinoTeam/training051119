/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
#define MAXF 1000
#define MAXN 100
#define seg segmento

// input data
int F, i;
int X[MAXF];
int Y[MAXF];
struct punto{
    double x,y;
    bool operator==(punto p){
        return p.x == this->x && p.y == this->y;
    }
};
struct segmento {
    punto a,b;

    string toString(){
        stringstream ss;
        ss<<"{(" <<a.x<< ";" <<a.y<< "),("<< b.x<<";"<<b.y<<")}";
        return ss.str();
    }
};

bool sortSeg(seg a, seg b){
    return a.a.x < b.a.x;
}

vector<segmento> segmenti;
void swapp(double &a, double &b) {
    int c = b;
    b = a;
    a = c;
}
bool checkTriangolo(segmento first, segmento second) {
    //cout<< first.toString()<<"  "<<second.toString()<<endl;
    //cout<<(first.a == second.a)<<endl;
    return (first.a == second.a) || (first.b == second.a) || (first.a == second.b) || (first.b == second.b);
}
void segmenta(double x1, double y1, double x2, double y2) {
    //cout<< "Segmenta con "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<endl;
    if(y1 == y2)
        return;
    if(y1 < y2) {
        swapp(x1,x2);
        swapp(y1,y2);
    }
    if(x1 == x2) {
        double yprec = y1;
        for(double currY = y1 - 1; currY >= y2; currY--) {
            segmenti.push_back({{x1, yprec}, {x1, currY}});
            yprec = currY;
        }
        return;
    }
    //trova eq retta
    double  a = -1 / (x2 - x1),
            b = 1 / (y2 - y1),
            c = (x1 / (x2 - x1)) - (y1 / (y2 - y1));

    //trova segmentini
    double yprec = y1, xprec = x1;
    for(double currY = y1 - 1; currY >= y2; currY--) {
        double newx = (( -b * currY) - c ) / a;
        segmenti.push_back({{xprec, yprec}, {newx, currY}});
        yprec = currY;
        xprec = newx;
    }
}
int myFloor(double x) {
    int a = x *10;
    return (int)a/10;
}
int calcolaRow(int yRow) {
    vector<segmento> avseg;
    for(auto s: segmenti) {
        if(s.a.y == yRow) {
            //cout<<"Ho preso "<<s.toString()<<endl;
            avseg.push_back(s);
        }
    }
    sort(avseg.begin(), avseg.end(), sortSeg);
    //cout<<"Numero segmenti "<<avseg.size()<<endl;
    int tot = 0;
    for(int i = 0; i < avseg.size(); i+=2) {
        segmento first = avseg[i];
        segmento second = avseg[i+1];
        //cout<<checkTriangolo(first, second)<<endl;
        if(!checkTriangolo(first, second)) {
            double xsx = max(first.a.x, first.b.x);
            double xdx = min(second.a.x, second.b.x);
            xsx = myFloor(xsx+ 0.5);
            xdx = myFloor(xdx);
            tot += abs(xdx - xsx);
        }
    }
    return tot;
}
int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &F));
    int minx = INT_MAX, maxx = INT_MIN, miny= INT_MAX, maxy = INT_MIN;
    for(i=0; i<F; i++) {
        assert(2 == scanf("%d%d", &X[i], &Y[i]));
    }

    for(int i = 0; i < F - 1; i++) {
        segmenta(X[i], Y[i], X[i+1], Y[i+1]);
    }
    segmenta(X[0], Y[0], X[F-1], Y[F-1]);
    /*for(auto &x : segmenti){
        cout << x.toString() << "\n";
    }*/
    int res = 0;
    for(int curry = 0; curry < 100; curry++) {
        res += calcolaRow(curry);
    }
    // insert your code here
    printf("%d\n", res); // print the result
    return 0;
}
