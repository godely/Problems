//by stor
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <time.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define pb push_back

using namespace std;

const double PI = acos(-1.0);
const double _90g = PI/2.0;
const double EPS = 1e-9;

int N;
double R;

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
	double operator ~() { return atan2(y,x); }
	bool operator==(const PT &lhs) const { return x==lhs.x && y==lhs.y; }
} C, p[310];

double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double norm(PT p) { return sqrt(p.x*p.x + p.y*p.y); }
double dist(PT p, PT q) { return norm(p-q); }
PT middle(PT p, PT q) { return (p+q)/2.0; }
double ang(PT p, PT q) { return acos(dot(p,q)/(norm(p)*norm(q))); }
PT rotateCcw(PT p, double t) { return PT(p.x*cos(t) - p.y*sin(t), p.y*cos(t) + p.x*sin(t)); }
double cat(double hyp, double side) { return sqrt(hyp*hyp - side*side); }

struct segment {
	double ini, fim;
	segment(){}
	segment(double ini, double fim):ini(ini), fim(fim) {}
	
	bool operator<(const segment &lhs) const {
		if (ini != lhs.ini) return ini < lhs.ini;
		return fim < lhs.fim;
	}
} interval[320];

int maximo = 0;
bool test(double raio) {
	double ang1, ang2, dist, _g, init, last;
	int size;
	rp(i,N) {
		init = 0, last = 2*PI;
		if (norm(p[i]-C)+R <= raio) return 1;
		size = 0;
		rp(j,N) {
			dist = norm(p[i]-p[j]);
			if (i == j || dist >= 2*raio || (p[i].x == p[j].x && p[i].y == p[j].y)) continue;
			_g = acos((dist/2.0)/raio);
			ang1 = ~((rotateCcw(p[j]-p[i], -_g)/dist)*raio);
			ang2 = ~((rotateCcw(p[j]-p[i], _g)/dist)*raio);
			if (ang1 < 0) ang1 = ang1 + 2*PI;
			if (ang2 < 0) ang2 = ang2 + 2*PI;
			if (ang1 > ang2) init = max(init,ang2), last = min(last,ang1);
			else interval[size++] = segment(ang1,ang2);
		}
		dist = norm(p[i]-C);
		if (dist+raio > R) {
			_g = acos((R*R + dist*dist - raio*raio)/(2*R*dist));
			ang1 = ~((rotateCcw(p[i]-C, -_g)/dist)*R - p[i]);
			ang2 = ~((rotateCcw(p[i]-C, _g)/dist)*R - p[i]);
			if (ang1 < 0) ang1 = ang1 + 2*PI;
			if (ang2 < 0) ang2 = ang2 + 2*PI;
			if (ang1 > ang2) init = max(init,ang2), last = min(last,ang1);
			else interval[size++] = segment(ang1,ang2);
		}
		sort(interval, interval + size);
		rp(j,size) {
			if (init < interval[j].ini) return 0;
			init = max(init,interval[j].fim);
			if (init >= last) break;
		}
		if (init < last) return 0;
	}
	return 1;
}

int main() {
	srand(time(NULL));
	scanf("%d %lf", &N, &R);
	rp(i,N) scanf("%lf %lf", &p[i].x, &p[i].y);
	C = PT(0,0);
	N = unique(p, p+N) - p;

	double ini = 0.0, fim = 2*R, raio;
	while (fabs(fim-ini) > EPS) {
		raio = (ini+fim)/2.0;
		if (test(raio)) fim = raio;
		else ini = raio;
	}
	printf("%.8lf\n", raio);
	return 0;
}