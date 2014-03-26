#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof(a))
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1
#define MAXN 40100

const double eps = 1e-8;
int cmp(double a, double b) {
	if (fabs(a-b) < eps) return 0;
	else if (a < b) return -1;
	return 1;
}

struct C {
	bool operator()(const double &a, const double &b) {
		return a < b;
	}
};

map<double,int,C> mp;

int passo;
int K;
double ps, pr, pw, pl;
int pu, pd;
double dp[102][102][1002];
int mark[102][102][1002];
double go(int won, int lost, int pint) {
	if (mark[won][lost][pint] == passo) return dp[won][lost][pint];
	mark[won][lost][pint] = passo;
	if (lost == K) return dp[won][lost][pint] = 0.0;
	if (won == K) return dp[won][lost][pint] = 1.0;

	double pi = pint/1000.0;
	dp[won][lost][pint] = go(won+1,lost,pint)*(1-pw)*(pi*(ps-pr) + pr) + go(won+1,lost,min(1000,pint+pu))*pw*(pi*(ps - pr) + pr) + go(won,lost+1,max(0,pint-pd))*pl*(pi*(pr-ps) - pr + 1) + go(won,lost+1,pint)*(1-pl)*(pi*(pr-ps) - pr + 1);
	return dp[won][lost][pint];
}

int main() {
	int T;
	memset(mark,0,sizeof mark);
	passo = 0;
	int pi, pi2, pu2, pd2, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &K);
		scanf("%lf %lf %d.%d %d.%d %lf %d.%d %lf", &ps, &pr, &pi, &pi2, &pu, &pu2, &pw, &pd, &pd2, &pl);
		pi = pi*1000 + pi2;
		pu = pu*1000 + pu2;
		pd = pd*1000 + pd2;
		passo++;
		printf("Case #%d: %lf\n", cas++, go(0,0,pi));
	}
	return 0;
}