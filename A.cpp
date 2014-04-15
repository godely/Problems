#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
#define MAXN 3010
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define F first
#define S second

int n, a, b;
int ma, mb;
int mark[MAXN][MAXN], passo = 0;
double dp[MAXN][MAXN];

double go(int x, int y) {
	if (y < 0) return 0.0;
	if (x < 0) return 0.0;
	double &pd = dp[x][y];
	if (mark[x][y] == passo) return pd;
	mark[x][y] = passo;
	int g = ma - x + mb - y;
	if (g >= n) return pd = 0.0;
	int x_ = a - n + x;
	int y_ = b - n + y;


	double prob = 2.0/(2.0*x_ + y_);
	double prob1 = 2.0*x_/(2.0*x_ + y_) - prob;
	double prob2 = double(y_)/(2.0*x_ + y_) - prob;
	printf("%d %d = %.9lf\n", x_, y_, prob);
	pd = prob;
	if (x > 0) pd += prob1*go(x-1,y);
	if (y > 0) pd += prob2*go(x,y-1);
	return pd;
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	if (a+b+1 <= n) printf("%.9lf\n%.9lf\n",1.0,1.0);
	a++;
	ma = min(n,a), mb = min(n,b);
	passo++;
	printf("%.9lf\n", go(ma, mb));
	a--;
}