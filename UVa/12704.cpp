#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) :x(x), y(y) {}
    
    PT operator+(const PT &q) const { return PT(x+q.x, y+q.y); }
    PT operator-(const PT &q) const { return PT(x-q.x, y-q.y); }
    double operator!() const { return sqrt(x*x + y*y); }
} p;

int main() {
    int T;
    int a, b, c;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        if (c == 0) printf("0.00 0.00\n");
        else {
            p.x = a;
            p.y = b;
            double d = !p;
            printf("%.2lf %.2lf\n", double(c) - d, d + double(c));
        }
    }
    return 0;
}