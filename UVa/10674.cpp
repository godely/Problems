#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define pi acos(-1)

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
} c1, c2;

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

struct ABC {
    PT pt1, pt2;

    ABC() {}
    ABC(PT pt1, PT pt2) : pt1(pt1), pt2(pt2) {}

    bool operator<(const ABC &lhs) const {
        if (!equal(pt1.x,lhs.pt1.x)) return pt1.x < lhs.pt1.x;
        return pt1.y < lhs.pt1.y;
    }
} res[10];

int main() {
    double x1, y1, r1, x2, y2, r2;
    while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2) > 0 && r1 > 0) {
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            printf("-1\n");
        } else {
            bool inv = 0;
            if (r1 <= r2) {
                c1 = PT(x1,y1);
                c2 = PT(x2,y2);
            } else {
                inv = 1;
                c1 = PT(x2,y2);
                c2 = PT(x1,y1);
                swap(r1,r2);
            }
            int k = 0;
            if (equal(dist(c1,c2)+r1,r2)) {
                PT x = c2+((c1-c2)/norm(c1-c2))*r2;
                res[k++] = ABC(x,x);
            } else if (dist(c1,c2)+r1 > r2) {
                double ang2 = acos((r2-r1)/dist(c1,c2));
                double ang = pi-ang2;
                PT a = c1+(RotateCCW(c2-c1,ang)/norm(c2-c1))*r1;
                PT b = c2+(RotateCCW(c1-c2,-ang2)/norm(c1-c2))*r2;
                if (inv) res[k++] = ABC(b,a);
                else res[k++] = ABC(a,b);

                a = c1+(RotateCCW(c2-c1,-ang)/norm(c2-c1))*r1;
                b = c2+(RotateCCW(c1-c2,ang2)/norm(c1-c2))*r2;
                if (inv) res[k++] = ABC(b,a);
                else res[k++] = ABC(a,b);
                if (equal(dist(c1,c2), r1+r2)) {
                    a = c2+((c1-c2)/norm(c1-c2))*r2;
                    res[k++] = ABC(a,a);
                } else if (dist(c1,c2) > r1+r2) {
                    ang = asin((r1+r2)/dist(c1,c2));
                    ang2 = pi/2-ang;

                    a = c1+(RotateCCW(c2-c1,pi/2-ang)/norm(c2-c1))*r1;
                    b = c2+(RotateCCW(c1-c2,ang2)/norm(c1-c2))*r2;
                    if (inv) res[k++] = ABC(b,a);
                    else res[k++] = ABC(a,b);

                    a = c1+(RotateCCW(c2-c1,-pi/2+ang)/norm(c2-c1))*r1;
                    b = c2+(RotateCCW(c1-c2,-ang2)/norm(c1-c2))*r2;
                    if (inv) res[k++] = ABC(b,a);
                    else res[k++] = ABC(a,b);
                }
            }
            printf("%d\n", k);
            sort(res,res+k);
            for (int i = 0; i < k; i++) printf("%.5lf %.5lf %.5lf %.5lf %.5lf\n", res[i].pt1.x, res[i].pt1.y, res[i].pt2.x, res[i].pt2.y, dist(res[i].pt1, res[i].pt2));
        }
    }
    return 0;
}
