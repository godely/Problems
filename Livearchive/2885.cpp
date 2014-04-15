#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
using namespace std;
typedef pair<int,int> pii;

#define maxn 500
#define maxm 50000

const double eps = 1e-8;
const double pi = acos(-1.0);

int cmp(double a, double b = 0) { 
	if (fabs(a-b) < eps) return 0; 
	else if (a < b) return -1; 
	return 1; 
}

struct PT { 
	double x, y;
	int t;

	PT () {}
	PT(double x, double y) : x(x), y(y), t(-1) {}
	
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
} p[10000];

bool isIntersect(PT a, PT b, PT c, PT d) {
	//printf("%lf %lf\n%lf %lf\n%lf %lf\n%lf %lf\n%d\n\n", a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y, (((c-a)%(b-a))*((d-a)%(b-a)) <= 0 && (((a-c)%(d-c))*((b-c)%(d-c))) <= 0));
	return (((c-a)%(b-a))*((d-a)%(b-a)) < 0 && (((a-c)%(d-c))*((b-c)%(d-c))) < 0);
}

bool isIntersect2(PT a, PT b, PT c, PT d) {
	//printf("%lf %lf\n%lf %lf\n%lf %lf\n%lf %lf\n%d\n\n", a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y, (((c-a)%(b-a))*((d-a)%(b-a)) <= 0 && (((a-c)%(d-c))*((b-c)%(d-c))) <= 0));
	return (((c-a)%(b-a))*((d-a)%(b-a)) <= 0 && (((a-c)%(d-c))*((b-c)%(d-c))) <= 0);
}

int N, M, L, k;

bool can(int i, int j) {
	if (i == (j^1) && p[i].t == 1) return 1;
	for (int l = 0; l < k && p[l].t == 1; l+=2) {
		if (isIntersect(p[i],p[j],p[l],p[l+1])) return 0;
	}
	return 1;
}

bool can2(int i, int j) {
	for (int l = 0; l < k && p[l].t == 1; l+=2) {
		if (isIntersect2(p[i],p[j],p[l],p[l+1])) return 0;
	}
	return 1;
}

int to[maxm], tel[maxm], ant[maxm], adj[maxn], z;
double cost[maxm], C[maxn][100];
#define add(a,b,c,d) to[z] = b, cost[z] = c, tel[z] = d, ant[z] = adj[a], adj[a] = z++

struct stt {
	double cs;
	int t, v;
	
	stt() {}
	stt(double cs, int t, int v) : cs(cs), t(t), v(v) {}
	
	bool operator<(const stt &lhs) const {
		if (cmp(cs,lhs.cs) != 0) return cmp(cs,lhs.cs) > 0;
		return t > lhs.t;
	}
} aux;

priority_queue<stt> pq;

double dij(int source, int sink) {
	while (!pq.empty()) pq.pop();
	pq.push(stt(0,0,source));
	rp(i,k+1) rp(j,N+1) C[i][j] = 1000000.0;
	C[source][0] = 0;
	while (!pq.empty()) {
		aux = pq.top(); pq.pop();
		int v = aux.v, t = aux.t;
		double cs = aux.cs;
		if (cmp(cs,C[v][t]) > 0) continue;
		//printf("%d %d %lf\n", v, t, cs);
		if (v == sink) return cs;
		
		for (int i = adj[v]; i != -1; i = ant[i]) {
			if (t + tel[i] <= N && C[to[i]][t + tel[i]] > cs + cost[i]) {
				C[to[i]][t + tel[i]] = cs + cost[i];
				pq.push(stt(cs + cost[i], t+tel[i], to[i]));
			}
		}
	}
	return -1;
}

int main() {
	while (scanf("%d%d%d", &N, &M, &L) == 3 && (N+M+L) > 0) {
		k = 0;
		rp(i,M) {
			scanf("%lf%lf%lf%lf", &p[k].x, &p[k].y, &p[k+1].x, &p[k+1].y);
			p[k].t = p[k+1].t = 1;
			k+=2;
		}
		rp(i,L) {
			scanf("%lf%lf", &p[k].x, &p[k].y);
			p[k].t = 2;
			k++;
		}
		scanf("%lf%lf", &p[k].x, &p[k].y);
		p[k++].t = 0;
		scanf("%lf%lf", &p[k].x, &p[k].y);
		p[k++].t = 3;
		
		cl(adj,-1); z = 0;
		rp(i,k) {
			rp(j,k) {
				if (i == j) continue;
				if (can(i,j)) {
					//printf("> %d %d\n", i, j);
					add(i,j,!(p[i]-p[j]),0);
				}
				if (p[i].t == p[j].t && p[i].t == 2 && can2(i,j)) add(i,j,0,1);
			}
		}
		
		printf("%d\n", int(dij(k-2,k-1)+0.5+eps));
	}
	return 0;
}