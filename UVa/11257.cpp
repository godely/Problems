#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f
#define maxn 100

double eps = 1e-10;
double pi = acos(-1.0);

int cmp(double a, double b = 0) { 
	if (fabs(a-b) < eps) return 0; 
	else if (a < b) return -1; 
	return 1; 
}

struct PT { 
	double x, y;

	PT () {}
	PT(double x, double y) : x(x), y(y) {}
	
	PT operator+(const PT &q) const { return PT(x+q.x, y+q.y); }
	PT operator-(const PT &q) const { return PT(x-q.x, y-q.y); }
	PT operator*(double t) const { return PT(x*t, y*t); }
	PT operator/(double t) const { return PT(x/t, y/t); }
	PT operator-() const { return PT(-x, -y); }
	PT operator[](double t) const { return PT(x*cos(t) - y*sin(t), x*sin(t) + y*cos(t)); }
	double operator*(const PT &q) const { return x*q.x + y*q.y; }
	double operator%(const PT &q) const { return x*q.y - y*q.x; }
	double operator!() const { return sqrt(x*x + y*y); }
	double operator^(const PT &q) const { return atan2(*this%q,*this*q); }
	double operator>(const PT &q) const { return ((*this*q)/(q*q)); }
	bool operator<(const PT &q) const {
		if (cmp(x,q.x) != 0) return cmp(x,q.x) < 0;
		if (cmp(y,q.y) != 0) return cmp(y,q.y) < 0;
		return 0;
	}
} p[maxn], vec, perp;

int n;

PT proj(PT x, PT a, PT b) {
	x = x-a; b = b-a;
	double t = x>b;
	if (cmp(t,0) < 0) return a;
	else if (cmp(t,1) > 0) return a+b;
	return a+b*t;
}

double test(PT a, PT v) {
	double ini = 0, fim = 4000.0, m = 0;
	PT c;
	rp(_,30) {
		m = (ini+fim)/2.0;
		c = a + (v*m);
		
		rp(j,n) {
			if (cmp(!(c-proj(c,p[j],p[(j+1)%n])), m) < 0) {
				fim = m;
				goto tend;
			}
		}
		ini = m;
		tend:;
	}
	return m;
}

int main() {
	while (sf(n) == 1 && n > 0) {
		rp(i,n) scanf("%lf%lf", &p[i].x, &p[i].y);
		double res = 0;
		rp(i,n) {
			int a = i;
			int b = (i+1)%n;
			vec = p[b] - p[a];
			perp = vec[pi/2.0] / !vec;
			double ini = 0, fim = 1, g, h;
			rp(_,25) {
				g = (2*ini + fim)/3;
				h = (ini + 2*fim)/3;
				if (test(p[a] + (vec*g), perp) < test(p[a] + (vec*h), perp)) ini = g;
				else fim = h;
			}
			res = max(res, test(p[a] + (vec*ini), perp));
		}
		printf("%.3lf\n", res);
	}
	return 0;
}