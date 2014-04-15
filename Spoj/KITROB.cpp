#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std; 
#define fr(a,b,c) for (int a = b; a < c; a++) 
#define rp(a,b) fr(a,0,b) 
#define CL(a,b) memset((a),(b),sizeof (a))
#define MP make_pair
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;

double dist(double xa, double ya, double xb, double yb) { return sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb)); }

double dp[1<<19][20];
double minDist[20][20];
int mark[1<<19][20], passo;
int w, l, n;
int x[20], y[20];
int FULLMSK;
double go(int mask, int j) {
	double &pd = dp[mask][j];
	if (mark[mask][j] == passo) return pd;
	mark[mask][j] = passo;
	
	if (mask == FULLMSK) return pd = min(x[j],min(y[j],min(w-x[j],l-y[j])));

	double ans = 1e9;
	rp(i,n) if (!((mask>>i)&1)) ans = min(ans, minDist[j][i] + go(mask|(1<<i), i));
	return pd = ans;
}

int main() {
	passo = 0; CL(mark,0);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &w, &l);
		scanf("%d", &n);
		rp(i,n) scanf("%d%d", &x[i], &y[i]);
		scanf("%d%d", &x[n], &y[n]);
		fr(i,0,n) fr(j,i+1,n) minDist[i][j] = minDist[j][i] = min(dist(x[j],y[j],-x[i],y[i]), min(dist(x[j],y[j],x[i],-y[i]), min(dist(x[j],y[j],2*w - x[i],y[i]), dist(x[j],y[j],x[i], 2*l - y[i]))));
		passo++;
		FULLMSK = (1<<n)-1;
		double ans = 1e9;
		rp(i,n) ans = min(ans, dist(x[n],y[n],x[i],y[i]) + go(1<<i,i));
		printf("%.14lf\n", ans);
	}
	return 0;
}