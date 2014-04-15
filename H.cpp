#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1
#define MAXN 40100
  
const double eps = 1e-8; 
const double pi = acos(-1.0); 
  
int cmp(double a, double b = 0) { 
    if (fabs(a-b) < eps) return 0; 
    else if (a < b) return -1; 
    return 1; 
} 
  
struct PT {
    double x, y;
    int id;
  
    PT () {} 
    PT(double x, double y) : x(x), y(y) {} 
      
    //Chamemos (*this) de p 
    PT operator+(const PT &q) const { return PT(x+q.x, y+q.y); } 
    PT operator-(const PT &q) const { return PT(x-q.x, y-q.y); } 
    PT operator*(double t) const { return PT(x*t, y*t); } 
    PT operator/(double t) const { return PT(x/t, y/t); } 
    PT operator-() const { return PT(-x, -y); } 
    PT operator[](double t) const { return PT(x*cos(t) - y*sin(t), x*sin(t) + y*cos(t)); } //rotaciona p em t radianos anti-horario 
    double operator*(const PT &q) const { return x*q.x + y*q.y; } //produto escalar entre p e q 
    double operator%(const PT &q) const { return x*q.y - y*q.x; } //produto cruzado entre p e q 
    double operator!() const { return sqrt(x*x + y*y); } //norma de p 
    double operator^(const PT &q) const { return atan2(*this%q,*this*q); } //pega o angulo entre p e q 
    double operator>(const PT &q) const { return ((*this*q)/(q*q)); } //pega o k da projeção de p em q 
} s[21], k[MAXN], w[MAXN], m[MAXN];
typedef PT VEC;

int ccw(PT a, PT b, PT c) { return cmp((b-a)%(c-a)); }

PT pivo = PT(0,1);
bool cmp_radial(PT p, PT q) {
    return atan2(p.y,p.x) < atan2(q.y,q.x);
}

int main() {
    int S, K, W, WW, N;
    while (scanf("%d%d%d", &S, &K, &W) == 3) {
        K-=S;
        WW = W<<1;
        rp(i,S) scanf("%lf%lf", &s[i].x, &s[i].y);
        rp(i,K) scanf("%lf%lf", &k[i].x, &k[i].y);
        rp(i,WW) scanf("%lf%lf", &w[i].x, &w[i].y);
        rp(i,S) {
            N = 0;
            rp(j,S) if (i != j) m[N] = (s[j]-s[i]), m[N++].id = -1;
            rp(j,K) m[N] = (k[j]-s[i]), m[N++].id = -1;
            rp(j,WW) m[N] = (w[j]-s[i]), m[N++].id = j>>1;
            sort(m,m+N,cmp_radial);
            rp(j,N) printf("%lf %lf, %d\n", (m[j]+s[i]).x, (m[j]+s[i]).y, m[j].id);
            if ()
        }
    }
}