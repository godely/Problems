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
	PT operator * (double c) const { return PT(x*c, y*x); }
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

double getRad(double x) {
	return x*PI/180.0;
}

vector<PT> pts;
int main() {
	int T, N;
	double x, y, w, h, ang, areaTemp;
	scanf("%d", &T);
	PT center;
	while (T--) {
		scanf("%d", &N);
		areaTemp = 0;
		pts.clear();
		while (N--) {
			scanf("%lf%lf%lf%lf%lf", &x, &y, &w, &h, &ang);
			areaTemp += w*h;
			center = PT(x,y);
			pts.push_back(RotateCCW(PT(-w/2, -h/2), -getRad(ang))+center);
			pts.push_back(RotateCCW(PT(w/2, -h/2), -getRad(ang))+center);
			pts.push_back(RotateCCW(PT(-w/2, h/2), -getRad(ang))+center);
			pts.push_back(RotateCCW(PT(w/2, h/2), -getRad(ang))+center);
		}
		ConvexHull(pts);
		double area = 0;
		for (int i = 0; i < pts.size(); i++) {
			int j = (i+1)%pts.size();
			area += pts[i].x*pts[j].y - pts[j].x*pts[i].y;
		}
		area /= 2.0;
		printf("%.1lf %%\n", (areaTemp*100.0)/area);
	}
}
