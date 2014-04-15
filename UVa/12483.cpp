#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define PB push_back
#define MP make_pair
#define F first
#define S second

const double eps = 1e-8;
const double pi = acos(-1);

int cmp(double a, double b = 0) {
	if (fabs(a-b) < eps) return 0;
	else if (a < b) return -1;
	return 1;
}

struct PT {
	double x,y;
	PT (double x=0, double y=0):x(x), y(y){}
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
};

vector< pair<PT,PT> > vec;

PT projSeg(PT x, PT a, PT b) {
	x = x-a; b = b-a;
	double t = x>b;
	if (cmp(t,0) < 0) return a;
	else if (cmp(t,1) > 0) return a+b;
	return a+b*t;
}

double distToSeg(PT x, PT a, PT b) { return !(x-projSeg(x,a,b)); }

int main() {
	int N;
	double L, H;
	double yi, xf, yf;
	while (scanf("%d", &N) == 1) {
		vec.clear();
		scanf("%lf%lf", &L, &H);
		double res = 1e10;
		rp(i,N) {
			scanf("%lf%lf%lf", &yi, &xf, &yf);
			if (i&1) {
				vec.PB(MP(PT(L,yi),PT(xf,yf)));
				res = min(res,xf);
			} else {
				vec.PB(MP(PT(0,yi),PT(xf,yf)));
				res = min(res,L-xf);
			}
		}
		rp(i,N-1) {
			res = min(res,distToSeg(vec[i].S, vec[i+1].F, vec[i+1].S));
		}
		printf("%.2lf\n", res);
	}
	return 0;
}