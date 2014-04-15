//

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
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define CL(a,b) memset(a,b,sizeof(a))
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

const double eps = 1e-12;
const double pi = acos(-1);

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {};
	
	PT operator+(const PT &q) { return PT(x+q.x, y+q.y); }
	PT operator-(const PT &q) { return PT(x-q.x, y-q.y); }
	PT operator*(double t) { return PT(x*t, y*t); }
	PT operator/(double t) { return PT(x/t, y/t); }
	double operator*(const PT &q) { return x*q.x + y*q.y; }
	double operator%(const PT &q) { return x*q.y - y*q.x; }
	double operator!() { return sqrt(x*x + y*y); }
} aux, vetEnt;
typedef PT VET;
PT proj(VET a, VET b) {
	double k = (a*b)/(b*b);
	return b*k;
}

VET rot(VET a, double t) { return VET(a.x*cos(t) - a.y*sin(t), a.x*sin(t) + a.y*cos(t)); }
double dist(PT a, PT b) { return !(a-b); }

double S = 16;
double T, G, best;
int main() {
//	cin.sync_with_stdio(false);
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%lf%lf", &T, &G); T*=100;
		vetEnt = rot(VET(-1,0), G*pi/180.0);
		best = 1e10;
		double i = 0;
		while (true) {
			aux = proj(PT(0,-i)-PT(T,0), vetEnt) + PT(T,0);
			//printf("%lf %lf, %lf %lf -> %lf\n", PT(0,-i).x, PT(0,-i).y, aux.x, aux.y, dist(PT(0,-i),aux));
			if (dist(PT(0,-i),aux) < best) best = dist(PT(0,-i),aux);
			else break;
			i += 85;
		}
		if (best < S+eps) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}