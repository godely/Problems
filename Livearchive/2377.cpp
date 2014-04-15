#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
typedef pair<int,int> pii;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define oo 0x3f3f3f3f
#define PB push_back
#define MP make_pair
typedef long long ll;

const double eps = 1e-8;
const double pi = acos(-1.0);

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
} P[100];

double bb(int n, double i, double j) {
	PT vec;
	double m;
	rp(_,100) {
		m = (i+j)/2.0;
		vec = P[n+1][m]-P[n][m];
		if (cmp(vec%PT(0,1)) >= 0) i = m;
		else j = m;
	}
	return fabs(i);
}

double bb2(int n, double i, double j) {
	PT vec;
	double m;
	rp(_,100) {
		m = (i+j)/2.0;
		vec = P[n+1][m]-P[n][m];
		if (cmp(vec%PT(0,1)) < 0) i = m;
		else j = m;
	}
	return fabs(i);
}

bool check;
double minleft, maxleft, minright, maxright;
void test(int i) {
	PT vec = P[i+1] - P[i];
	double rotleft, rotright;
	if (cmp(vec%PT(0,1)) >= 0) {
		rotleft = bb(i,0,pi);
		rotright = bb(i,0,-pi);
		maxleft = min(maxleft,rotleft);
		maxright = min(maxright,rotright);
	} else {
		check = 1;
		rotleft = bb2(i,0,pi);
		rotright = bb2(i,0,-pi);
		minleft = max(minleft,rotleft);
		maxleft = min(maxleft,minleft+pi);
		minright = max(minright,rotright);
		maxright = min(maxright,minright+pi);
	}
}

int main() {
	int cas = 1;
	int N, O;
	while(scanf("%d%d", &N, &O) == 2 && N > 0) {
		P[0] = PT(0,0);
		fr(i,1,N+1) scanf("%lf%lf", &P[i].x, &P[i].y);
		//printf("%lf\n", bb2(0,0,-pi)*180.0/pi);
		minleft = minright = 0;
		maxleft = maxright = 1e10;
		check = 0;
		rp(i,N) {
			test(i);
			//printf("%d (%lf %lf): left [%lf,%lf] // right [%lf,%lf]\n", i, P[i].x, P[i].y, minleft*180.0/pi, maxleft*180.0/pi, minright*180.0/pi, maxright*180.0/pi);
		}
		printf("Case %d: ", cas++);
		if (!check) printf("Acceptable as proposed\n");
		else {
			minleft*=180.0/pi;
			minright*=180.0/pi;
			maxleft*=180.0/pi;
			maxright*=180.0/pi;
			if (cmp(minleft,maxleft) > 0 && cmp(minright,maxright) > 0) printf("Unacceptable\n");
			else if (cmp(minleft,maxleft) > 0) printf("Acceptable after clockwise rotation of %.2lf degrees\n", minright);
			else if (cmp(minright,maxright) > 0) printf("Acceptable after counterclockwise rotation of %.2lf degrees\n", minleft);
			else {
				if (cmp(minright,minleft) <= 0) printf("Acceptable after clockwise rotation of %.2lf degrees\n", minright);
				else printf("Acceptable after counterclockwise rotation of %.2lf degrees\n", minleft);
			}
		}
		puts("");
	}
	return 0;
}