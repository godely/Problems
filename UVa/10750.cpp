//by stor
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <set>
#include <vector>
#define foreach(it, a,b) for(typeof(a)it=(a) ; it!=(b) ; it++)
#define all(x) (x).begin(), (x).end()
#define poly vector<point>

using namespace std;

const double EPS = 1E-8;

inline int cmp(double a, double b=0){
	if (fabs(a-b) < EPS) return 0;
	if( a< b) return -1;
	return 1;
}

struct point {
	double x,y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	point operator +(point q){ return point(x + q.x, y + q.y); }
	point operator -(point q){ return point(x - q.x, y - q.y); }
	point operator *(double t){ return point(x * t, y * t); }
	point operator /(double t){ return point(x / t, y / t); }
	double operator *(point q){ return x * q.x + y * q.y; }
	double operator %(point q){ return x * q.y - y * q.x; }

	int cmp(point q) const {
		if( int t = ::cmp(x, q.x)) return t;
		return ::cmp(y , q.y);
	}
	bool operator < (point q) const { return cmp(q) < 0;}
};
double norma(point p){ return sqrt(p.x*p.x + p.y*p.y); }

bool ycmp(point a, point b) {
	if (a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}

double resA=0, resB=0;
double closest_pair (poly &P) {
	int n = P.size();
	double d = norma(P[0]-P[1]);
	resA = (P[0].x+P[1].x)/2.0;
	resB = (P[0].y+P[1].y)/2.0;
	set<point, bool(*)(point,point)> s(&ycmp);
	sort(all(P));
	for(int i=0,j=0 ; i<n ; i++) {
		point lower(0, P[i].y - d) , upper(0, P[i].y + d);
		while(P[i].x - P[j].x > d)
			s.erase(P[j++]);
			foreach(p, s.lower_bound(lower), s.upper_bound(upper)) {
			/* os pontos mais proximos sao tirados de P[i] e *p */
				if (norma(P[i]-*p) < d) {
					d = norma(P[i]-*p);
					resA = (P[i].x+(*p).x)/2.0;
					resB = (P[i].y+(*p).y)/2.0;
				}
			}
			s.insert(P[i]);
		}
	return d;
}

int main() {
	point q;
	poly p;
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        p.clear();
        for (int i = 0; i < N; i++) {
            scanf("%lf%lf", &q.x, &q.y);
            p.push_back(q);
        }
        closest_pair(p);
        printf("%.3lf %.3lf\n", resA, resB);
        if (T) printf("\n");
    }
}