#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define PI acos(-1)

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
};

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

void ConvexHull(vector<PT> &pts) {
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	vector<PT> up, dn;
	for (int i = 0; i < pts.size(); i++) {
		while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
		while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
	}
	pts = dn;
	for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

	if (pts.size() <= 2) return;
	dn.clear();
	dn.push_back(pts[0]);
	dn.push_back(pts[1]);
	for (int i = 2; i < pts.size(); i++) {
		if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
		dn.push_back(pts[i]);
	}
	if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
		dn[0] = dn.back();
		dn.pop_back();
	}
	pts = dn;
}

PT pps(PT a, PT b, PT c) {
    double r = dot(b-a, b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a,b-a)/r;
    //printf("a(%.3lf %.3lf) b(%.3lf %.3lf) b-a(%.3lf %.3lf) c-a(%.3lf %.3lf) vet(%.3lf %.3lf) r:%.3lf\n", a.x, a.y, b.x, b.y, (b-a).x, (b-a).y, (c-a).x, (c-a).y, (a+(b-a)*r).x, (a+(b-a)*r).y, r);
    return a+(b-a)*r;
}

double distancePT(PT a, PT b, PT c) {
    //printf("%lf\n", sqrt(dist2(c, ProjectPointSegment(a, b, c))) );
    return sqrt(dist2(c, pps(a, b, c)));
}

vector<PT> pts;
int main() {
    int T, a, b, N, cas=1;
    double sumX, sumY;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        sumX=0;
        sumY=0;
        pts.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &a, &b);
            pts.push_back(PT(a, b));
            sumX+=a;
            sumY+=b;
        }
        printf("Case #%d: ", cas++);
        if (N <= 2) {
            printf("0.000\n");
            continue;
        }
        sumX/=N;
        sumY/=N;
        PT center = PT(sumX, sumY);
        ConvexHull(pts);
        double minD=10000000;
        for (int i = 0; i < pts.size(); i++) {
            minD = min(minD, distancePT(pts[i], pts[(i+1)%pts.size()], center));
        }
        printf("%.3lf\n", minD);
    }
}
