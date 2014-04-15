#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define pi acos(-1)
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

struct PT {
	double x, y;
	int circ;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT(double x, double y, int circ) : x(x), y(y), circ(circ) {}
	//PT (const PT &p) : x(x), y(y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (double c) const { return PT(x*c, y*c); }
	PT operator / (double c) const { return PT(x/c, y/c); }
	bool operator <(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y, rhs.x); }
	bool operator== (const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y, rhs.x); }
} C[50];

const double EPS = 1e-7;
double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double norm(PT p) { return sqrt(dot(p,p)); }
double dist2(PT p, PT q) { return dot(p-q, p-q); }
double cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }
double area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }
bool equal(double a, double b) {
    return (fabs(a-b) < EPS);
}
PT RotateCCW(PT p, double t) {
	return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}
bool between(const PT &a, const PT &b, const PT &c) {
	return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
double dist(PT a, PT b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
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

vector<PT> pts;
void add(PT p, int circ) {
    p.circ = circ;
    pts.push_back(p);
}

double r[50], ang, ang2;
int main() {
    int T, N;
    PT a;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        rp(i,N) {
            scanf("%lf%lf%lf", &C[i].x, &C[i].y, &r[i]);
        }
        if (N == 1) printf("%.10lf\n", 2*pi*r[0]);
        else {
            pts.clear();
            fr(i,0,N) {
                fr(j,i+1,N) {
                    ang2 = acos((r[j]-r[i])/dist(C[i],C[j]));
                    ang = pi-ang2;
                    add(C[i]+(RotateCCW(C[j]-C[i],ang)/norm(C[j]-C[i]))*r[i],i);
                    add(C[j]+(RotateCCW(C[i]-C[j],-ang2)/norm(C[i]-C[j]))*r[j],j);
                    add(C[i]+(RotateCCW(C[j]-C[i],-ang)/norm(C[j]-C[i]))*r[i],i);
                    add(C[j]+(RotateCCW(C[i]-C[j],ang2)/norm(C[i]-C[j]))*r[j],j);
                }
            }
            ConvexHull(pts);
            int size = pts.size();
            double res = 0, d;
            for (int i = 0; i < size; i++) {
                //printf("%lf %lf %d\n", pts[i].x, pts[i].y, pts[i].circ);
                if (pts[i].circ != pts[(i+1)%size].circ) {
                    //printf("1\n");
                    res += dist(pts[i],pts[(i+1)%size]);
                } else {
                    //printf("2\n");
                    a = C[pts[i].circ];
                    d = r[pts[i].circ]*acos(dot(pts[i]-a,pts[(i+1)%size]-a)/(norm(pts[i]-a)*norm(pts[(i+1)%size]-a)));
                    if (cross(pts[i]-a,pts[(i+1)%size]-a) < 0) d = 2*pi*r[pts[i].circ] - d;
                    res += d;
                }
                //printf("%lf\n", res);
            }
            printf("%.10lf\n", res);
        }
    }
    return 0;
}
