//by stor
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long

using namespace std;

const double PI = acos(-1.0);
const double _120g = 2.0*PI/3.0;
const double _60g = PI/3;

const double EPS = 1e-8;
int cmp(double a, double b){
		if(fabs(a-b) < EPS) return 0;
		else if(a < b) return -1;
		else return 1;
}

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	
	PT operator+(const PT &p) { return PT(x+p.x, y+p.y); }
	PT operator-(const PT &p) { return PT(x-p.x, y-p.y); }
	PT operator*(double t) { return PT(x*t, y*t); }
	PT operator/(double t) { return PT(x/t, y/t); }
	double operator *(PT q) { return x*q.x + y*q.y; }
	double operator %(PT q) { return x*q.y - y*q.x; }
} a, b, c;

double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double norm(PT p) { return sqrt(p.x*p.x + p.y*p.y); }
double ang(PT p, PT q) { return acos(dot(p,q)/(norm(p)*norm(q))); }
PT ccw(PT p, double t) { return PT(p.x*cos(t) - p.y*sin(t), p.x*sin(t) + p.y*cos(t)); }
PT intersect(PT p, PT q, PT r, PT s){
       PT i = q-p, j = s-r, k = PT(p%q, r%s);
       return PT(PT(i.x, j.x)%k, PT(i.y, j.y)%k)/(i%j);
}

int main() {
	scanf("%lf%lf %lf%lf %lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
	if (cmp(ang(b-a,c-a), _120g) >= 0) printf("%.8lf %.8lf\n", a.x, a.y);
	else if (cmp(ang(a-b, c-b),_120g) >= 0) printf("%.8lf %.8lf\n", b.x, b.y);
	else if (cmp(ang(a-c, b-c),_120g) >= 0) printf("%.8lf %.8lf\n", c.x, c.y);
	else {
		if (cmp((b-a)%(c-a),0) > 0) swap(b,c);
		PT q1 = ccw(b-a, _60g)+a;
		PT q2 = ccw(c-a, -_60g)+a;
		PT V = intersect(c, q1, b, q2);
		printf("%.8lf %.8lf\n", V.x, V.y);
		//Quero a intersecção entre (c->q1) e (b->q2)
	}
	return 0;
}