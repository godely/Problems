#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <bitset>
#include <vector>
#include <utility>
#include <set>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second
typedef pair<int,int> pii;

const double eps = 1e-6;
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
	bool operator<(const PT &q) const {
		if (cmp(x,q.x) != 0) return cmp(x,q.x) < 0;
		if (cmp(y,q.y) != 0) return cmp(y,q.y) < 0;
		return 0;
	}
} pts[1010];

PT proj(PT a, PT b) { return b*(a>b); }

PT reflex(PT a, PT b, PT v) {
	a = a - b;
	return b + proj(a,v)*2.0 - a;
}

int ccw(PT a, PT b, PT c) { return cmp((b-a)%(c-a)); }

PT pivo;
bool cmp_radial(PT p, PT q) {
	int aux = ccw(pivo,p,q);
	return aux < 0 || (aux == 0 && cmp(!(p-pivo),!(q-pivo)) < 0);
}

void convexHull(vector<PT> &p) { 
	pivo = p[0]; 
	fr(i,1,p.size()) if (p[i] < pivo) pivo = p[i]; 
	sort(p.begin(), p.end(), cmp_radial); 

	vector<PT> g; 
	for (int i = 0, j = 0; i < p.size(); i++) { 
		while (j >= 2 && ccw(g[j-2], g[j-1], p[i]) >= 0) g.pop_back(), j--; 
		g.push_back(p[i]), j++; 
	}
	p = g;
} 

set<PT> s;
int N;
PT c, v;
vector<PT> ch;

bool test(PT c, PT v) {
	rp(j,N) if (!s.count(reflex(pts[j],c,v))) return 0;
	return 1;
}

int main() {
	while (scanf("%d", &N) == 1 && N > 0) {
		s.clear(); ch.clear();
		rp(i,N) scanf("%lf%lf", &pts[i].x, &pts[i].y), s.insert(pts[i]), ch.push_back(pts[i]);
		convexHull(ch);
		int M = ch.size();
		rp(i,M) {
			c = ch[i];
			v = (ch[(i+1)%M]-ch[i])[((ch[(i+1)%M]-ch[i])^(ch[(i-1+M)%M]-ch[i]))/2.0];
			if (test(c,v)) {
				puts("Y");
				goto fim;
			}
			c = (ch[i]+ch[(i+1)%M])/2.0;
			v = (ch[(i+1)%M]-ch[i])[pi/2.0];
			if (test(c,v)) {
				puts("Y");
				goto fim;
			}
		}
		puts("N");
		fim:;
	}
	return 0;
}