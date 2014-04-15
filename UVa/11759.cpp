#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

#define EPS (1e-8)
const double pi = acos(-1);

inline int cmp(double a, double b = 0){
	if(fabs(a-b)<=EPS) return 0;
	if(a<b) return -1;
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
		if (int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}
	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) < 0; }
};

typedef vector<point> poly;
typedef point vetor;

vetor normal(vetor v){ return vetor(-v.y,v.x); }
double norma(vetor v){ return hypot(v.x, v.y); }
vetor versor(vetor v){ return v/norma(v); }
double anglex(vetor v){ return atan2(v.y, v.x); }
double angle(vetor v1, vetor v2){ /* angulo orientado ccw */
	return atan2(v1%v2 , v1*v2);
}
int ccw(point a, point b, point c){ /* b-a em relacao a c-a */
	return cmp((b-a)%(c-a)); /* ccw=1 ; cw=-1 ; colinear=0 */
	/* equivalente a cmp(triarea(a,b,c)), mas evita divisao */
}
/* ponto p entre segmento [qr] */
int between3(point p, point q, point r){
	if(cmp((q-p)%(r-p)) == 0) /* colinear */
		if(cmp((q-p)*(r-p)) <= 0) /* < se os extremos nao contam */
			return 1;
	return 0;
}
int intri(point k, point a, point b, point c) {
	int a1,a2,a3;
	a1 = ccw(a,k,b);
	a2 = ccw(b,k,c);
	a3 = ccw(c,k,a);
	if((a1*a2)>0 && (a2*a3)>0) return 1; /*dentro*/
	if(between3(k,a,b) || between3(k,b,c) || between3(k,c,a)) return 2; /*borda*/
	return 0; /*fora*/
}

int inpoly_convex(point k, poly& p){
	/* 'val' indica o sentido do poligono */
	int val = ccw(p[0],p[1],p[2]);
	/* tomar cuidado para o caso em que o poligono comeca com pontos colineares, 'val' recebera 0 */
	int esq,dir,meio, n = p.size();
	esq = 1; dir = n-1;
	while(dir>esq+1) {
		meio = (esq+dir)/2;
		if(ccw(p[0],p[meio],k) == val) esq = meio;
		else dir = meio;
	}
	return intri(k, p[0],p[esq],p[dir]);
}

int P[550];
poly R[550];
double area[550];
bool magic_cmp(int a, int b) { return cmp(area[a],area[b]) >= 0; }

int N, M;
int vis[550], com;
double res[3];
const double con[] = {0.0001, 0.00005};
void dfs(int ind, int id) {
	vis[P[ind]] = id;
	fr(i,ind+1,N) if(vis[P[i]] == -1 && inpoly_convex(R[P[i]][0], R[P[ind]])) dfs(i,1-id);
}

point p_;
int main() {
	int cas = 1;
	double x, y;
	while (scanf("%d", &N) == 1 && N > 0) {
		rp(i,N) {
			R[i].clear();
			P[i] = i;
			area[i] = 0;
			scanf("%d", &M);
			scanf("%lf%lf", &x, &y), R[i].push_back(point(x,y));
			fr(j,1,M) {
				scanf("%lf%lf", &x, &y); p_ = point(x,y);
				area[i] += R[i].back()%p_;
				if (R[i].size() >= 2 && !ccw(R[i][R[i].size()-1], R[i][R[i].size()-2], p_)) R[i].pop_back();
				R[i].push_back(p_);
			}
			area[i] += R[i].back()%R[i][0];
			area[i] = abs(area[i]/2.0);
			if (R[i].size() >= 3 && !ccw(R[i][R[i].size()-1], R[i][R[i].size()-2], R[i][0])) R[i].pop_back();
		}
		sort(P, P+N, magic_cmp);
		memset(vis,-1,sizeof vis);
		com = 0;
		res[0] = res[1] = 0;
		rp(i,N) {
			if (vis[P[i]] == -1) dfs(i,0), com++;
			M = R[P[i]].size();
			rp(j,M) {
				res[vis[P[i]]] += con[vis[P[i]]]*norma(R[P[i]][j]-R[P[i]][(j+1)%M]);
			}
		}
		printf("Case %d:\nTotal Number of Communities %d\nTotal Cost:\nSteel Fence: %.8lf Million Yuan\nWooden Fence: %.8lf Million Yuan\n\n", cas++, max(com,1), res[0], res[1]);
	}
	return 0;
}