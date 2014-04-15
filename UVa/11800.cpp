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
#define iter(a) typeof((a).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1; a>=b ; --a )
#define Rp(a,b) Fr(a,0,b)
#define fr Fr
#define rp Rp
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,pair<int,int> > pdi;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define dbg if(0)

const double eps = 1e-7;
const double pi = acos(-1.0);

int cmp(double a, double b = 0) {
	if (fabs(a-b) < eps) return 0;
	if (a < b) return -1;
	return 1;
}

struct P {
	double x,y;
	
	P() {}
	P(double x, double y) : x(x) , y(y) {}

	P operator +(const P &p) const { return P(x+p.x, y+p.y);}
	P operator -(const P &p) const { return P(x-p.x, y-p.y);}
	double operator % (const P &p) const { return x*p.y - y*p.x;}
	double operator * (const P &p) const { return x*p.x + y*p.y;}
	double operator!() const { return x*x + y*y; }
	double operator^(const P &q) const { return atan2(*this%q, *this*q); }
} p[10], q[10];

bool intersect(P a, P b, P c, P d) {
	return (((c-a)%(b-a))*((d-a)%(b-a)) < 0 && (((a-c)%(d-c))*((b-c)%(d-c))) < 0);
}

int test() {
	fr(i,0,4) {
		fr(j,i,4) {
			if (intersect(q[i],q[(i+1)%4],q[j],q[(j+1)%4])) {
				return 0;
			}
		}
	}
	
	double ang = (q[3]-q[0])^(q[0]-q[1]);
	double lad = !(q[3]-q[0]);
	//printf ("%lf %lf\n", ang, lad);
	bool angsEqual = 1, sidesEqual = 1;
	rp(i,3) {
		double ang_ = (q[i]-q[(i+1)&3])^(q[(i+1)&3]-q[(i+2)&3]);
		double lad_ = !(q[i]-q[(i+1)&3]);
		if (cmp(ang_,ang) != 0) angsEqual = 0;
		if (cmp(lad,lad_) != 0) sidesEqual = 0;
	}
	if (angsEqual && sidesEqual) {
		printf("Square\n");
		return 1;
	}
	bool oppositeEqual = 0;
	if (cmp(!(q[0]-q[1]),!(q[2]-q[3])) == 0 && cmp(!(q[1]-q[2]),!(q[3]-q[0])) == 0) oppositeEqual = 1;
	if (angsEqual && cmp(fabs(ang),pi/2.0) == 0 && oppositeEqual) {
		printf("Rectangle\n");
		return 1;
	}
	bool has90 = 0;
	rp(i,4) {
		double ang_ = (q[i]-q[(i+1)&3])^(q[(i+1)&3]-q[(i+2)&3]);
		if (cmp(ang_,pi/2.0) == 0) {
			has90 = 1;
			break;
		}
	}
	if (!has90 && sidesEqual) {
		printf("Rhombus\n");
		return 1;
	}
	if (oppositeEqual && !has90) {
		printf("Parallelogram\n");
		return 1;
	}
	if ((cmp((q[0]-q[1])%(q[2]-q[3])) == 0 && cmp((q[1]-q[2])%(q[3]-q[0])) != 0) || (cmp((q[0]-q[1])%(q[2]-q[3])) != 0 && cmp((q[1]-q[2])%(q[3]-q[0])) == 0)) {
		printf("Trapezium\n");
		return 1;
	}
	printf("Ordinary Quadrilateral\n");
	return 1;
}

int r[10];
int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		rp(i,4) scanf("%lf%lf", &p[i].x, &p[i].y);
		rp(i,4) r[i] = i;
		printf("Case %d: ", cas++);
		do {
			rp(i,4) q[i] = p[r[i]];
			if (test()) break;
		} while (next_permutation(r+1,r+4));
	}
	return 0;
}