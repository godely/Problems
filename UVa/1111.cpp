#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
const double pi = acos(-1);
const double EPS = 1e-8;

int cmp(double a, double b = 0) {
	if (fabs(a-b) <= EPS) return 0;
	else if (a < b) return -1;
	return 1;
}

struct PT {
	double x, y;
	PT(double x = 0, double y = 0) : x(x), y(y) {}
	
	PT operator+(const PT &q) { return PT(x+q.x, y+q.y); }
	PT operator-(const PT &q) { return PT(x-q.x, y-q.y); }
	PT operator*(double t) { return PT(x*t, y*t); }
	PT operator/(double t) { return PT(x/t, y/t); }
	
	double operator*(const PT &q) { return x*q.x + y*q.y; }
	double operator%(const PT &q) { return x*q.y - y*q.x; }
	double operator!() { return sqrt(x*x + y*y); }
	
	bool operator<(const PT &q) { return ((y != q.y) ? y < q.y : x < q.x); }
	bool operator==(const PT &q) { return !cmp(x,q.x) && !cmp(y,q.y); }
};

double angle(PT p, PT q) { return atan2(p%q, p*q); }
int ccw(PT a, PT b, PT c) { return cmp((b-a)%(c-a)); }
PT PPL(PT a, PT b, PT c) { return a + (b-a)*(((c-a)*(b-a))/((b-a)*(b-a))); }
double distPL(PT a, PT b, PT c) { return !(c - PPL(a,b,c)); }

PT pivo;
bool cmp_radial(PT p, PT q) {
	int aux = ccw(pivo,p,q);
	return aux < 0 || (aux == 0 && (cmp(p.y,q.y) < 0 || (cmp(p.y,q.y) == 0 && cmp(p.x,q.x) < 0)));
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

vector<PT> p;
int main() {
	int N, cas = 1;
	double x, y;
	double temp, res;
	while (scanf("%d", &N) == 1 && N > 0) {
		p.clear();
		rp(i,N) scanf("%lf%lf", &x, &y), p.push_back(PT(x,y));
		convexHull(p);
		N = p.size();
		res = 1000000000000.0;
		rp(i,N) {
			temp = 0;
			rp(j,N) {
				if (j == i || j == (i+1)%N) continue;
				temp = max(temp, distPL(p[i], p[(i+1)%N], p[j]));
			}
			res = min(res, temp);
		}
		printf("Case %d: %.2lf\n", cas++, res);
	}
	return 0;
}