#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define PI acos(-1)
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	//PT (const PT &p) : x(x), y(y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (double c) const { return PT(x*c, y*c); }
	PT operator / (double c) const { return PT(x/c, y/c); }
	bool operator <(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y, rhs.x); }
	bool operator== (const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y, rhs.x); }
} A, B, C;

const double EPS = 1e-7;
double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double norm(PT p) { return sqrt(dot(p,p)); }
double dist2(PT p, PT q) { return dot(p-q, p-q); }
double cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }
double area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }
PT RotateCCW(PT p, double t) {
	return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

bool between(const PT &a, const PT &b, const PT &c) {
	return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}

double getRad(double x) {
	return x*PI/180.0;
}

PT CLI(PT a, PT b, PT c, PT d) {
	b = b-a; d = c-d; c = c-a;
	return a + b*cross(c,d)/cross(b,d);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf", &A.x, &A.y); scanf("%lf%lf", &B.x, &B.y); scanf("%lf%lf", &C.x, &C.y);
		double angA = acos(dot(C-A,B-A)/(norm(C-A)*norm(B-A)))/3.0;
		double angB = acos(dot(C-B,A-B)/(norm(C-B)*norm(A-B)))/3.0;
		double angC = acos(dot(A-C,B-C)/(norm(A-C)*norm(B-C)))/3.0;
		PT t1 = A + RotateCCW(B-A, angA);
		PT t2 = A + RotateCCW(t1-A, angA);

		PT t3 = B + RotateCCW(C-B, angB);
		PT t4 = B + RotateCCW(t3-B, angB);
		
		PT t5 = C + RotateCCW(A-C, angC);
		PT t6 = C + RotateCCW(t5-C, angC);
		
		PT a1 = CLI(A,t1,B,t4);
		PT a2 = CLI(A,t2,C,t5);
		PT a3 = CLI(B,t3,C,t6);
		printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", a3.x, a3.y, a2.x, a2.y, a1.x, a1.y);
	}
	return 0;
}