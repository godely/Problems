#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

const double pi = acos(-1);
const double eps = 1e-6;

int cmp(double a, double b = 0) {
	if (fabs(a-b) < eps) return 0;
	else if (a < b) return -1;
	return 1;
}

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	
	PT operator+(const PT &q) { return PT(x+q.x, y+q.y); }
	PT operator-(const PT &q) { return PT(x-q.x, y-q.y); }
	PT operator*(double t) { return PT(x*t, y*t); }
	PT operator/(double t) { return PT(x/t, y/t); }
	double operator*(const PT &q) { return x*q.x + y*q.y; }
	double operator%(const PT &q) { return x*q.y - y*q.x; }
	double operator!() { return sqrt(x*x + y*y); }
	PT operator-() { return PT(-x,-y); }
} seg[10];

double projK(PT p, PT q) {
	return (p*q)/(q*q);
}

double ang(PT p, PT q) {
	return fabs(atan2(p%q,p*q));
}

PT rot(PT p, double t) { return PT(p.x*cos(t) - p.y*sin(t), p.x*sin(t) + p.y*cos(t)); }

PT inters(PT a, PT b, PT c, PT d) {
	b = b - a, d = c - d, c = c - a;
	return a + b * ((c % d) / (b % d));
}

bool pertenceSeg(PT p1, PT p2, PT p){
	int pvet;
	pvet = (p - p1)%(p2 - p1);
	if(pvet == 0){
		return p.x >= min(p1.x,p2.x) && p.x <= max(p1.x, p2.x) 
			&& p.y >= min(p1.y, p2.y) && p.y <= max(p1.y, p2.y);
	}else{
		return false;
	}
}

bool intersectaSegmento(PT p1, PT p2, PT p3, PT p4){
	int d1,d2,d3,d4;
	
	d1 = (p1 - p3)%(p4 - p3);
	d2 = (p2 - p3)%(p4 - p3);
	d3 = (p3 - p1)%(p2-p1);
	d4 = (p4 - p1)%(p2-p1);
	
	if(((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) &&
		((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0))){
		return true;
	}
	return pertenceSeg(p3,p4, p1) || pertenceSeg(p3,p4,p2) || pertenceSeg(p1,p2,p3)
		|| pertenceSeg(p1,p2,p4);
}

PT ref(PT a, PT b, PT c) {
	PT u = b-a;
	PT v = PT((c-a).y, -(c-a).x);
	//printf("> %lf %lf, %lf %lf, %lf %lf\n", a.x, a.y, b.x, b.y, c.x, c.y);
	PT p = v*projK(u,v);
	return p*2 - u;
}

int main() {
	int T; scanf("%d", &T);
	double s, X1, Y1, X2, Y2, r;
	int t;
	int cas = 1;
	while (T--) {
		scanf("%lf%lf%lf%lf%lf%lf%d", &s, &X1, &Y1, &X2, &Y2, &r, &t);
		seg[0] = PT(-s,0);
		fr(i,1,6) seg[i] = rot(seg[i-1],-pi/3.0);
		/*seg[1] = PT(-s*sin(pi/3.0),s*cos(pi/3.0));
		seg[2] = PT(s*sin(pi/3.0),s*cos(pi/3.0));
		seg[3] = PT(s,0);
		seg[4] = PT(s*sin(pi/3.0),-s*cos(pi/3.0));
		seg[5] = PT(-s*sin(pi/3.0),-s*cos(pi/3.0));*/
		
		/*rp(i,6) {
			printf("%lf %lf, %lf %lf %lf\n", seg[i].x, seg[i].y, ang(seg[i],seg[(i+1)%6])*180/pi, !(seg[(i+1)%6]-seg[i]), !seg[i]);
		}*/
		
		PT P = PT(X1,Y1);
		PT V = PT(X2,Y2)-P;
		while (t > 0) {
			V = V/(!V);
			//printf("%lf %lf, %lf %lf\n", P.x, P.y, V.x, V.y);
			double k = projK(-P, V);
			if (cmp(!P,r) <= 0 || (cmp(k) >= 0 && cmp(!(P + V*k),r) <= 0)) break;
			
			rp(i,6) {
				if ((cmp(seg[i].x,P.x) != 0 || cmp(seg[i].y,P.y) != 0) && cmp(ang(seg[i]-P,V)) == 0) {
					//printf("Bateu corner: %d\n", i);
					t -= 2;
					P = seg[i];
					V = -V;
					goto atl;
				}
			}
			
			rp(i,6) {
				if (!pertenceSeg(seg[i],seg[(i+1)%6],P) && intersectaSegmento(P,P+(V*1000000.0),seg[i],seg[(i+1)%6])) {
					//printf("Bateu reta: %d (%lf %lf , %lf %lf)\n", i, seg[i].x, seg[i].y, seg[(i+1)%6].x, seg[(i+1)%6].y);
					t--;
					PT novo = inters(P, P+V, seg[i], seg[(i+1)%6]);
					V = ref(novo,P,seg[i]);
					P = novo;
					break;
				}
			}
			
			atl:;
			//puts("");
		}
		if (t <= 0) printf("Case %d: Stops\n", cas++);
		else printf("Case %d: %d\n", cas++, t);
	}
	return 0;
}