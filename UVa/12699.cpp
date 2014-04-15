#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define MAXN 2100100

double dp[MAXN];
int mark[MAXN], passo;
int N;
double d, s, a;

double solve(int n) {
	double &pd = dp[n];
	if (mark[n] == passo) return pd;
	mark[n] = passo;
	pd = 1;
	if (n == 0) return pd = 1.0;
	if (n&1) return pd = 0.5*(a+solve(n+1)) + 0.5*(s+solve(n-1));
	else return pd = d + solve(n>>1);
}

int main() {
	int T;
	passo = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lf%lf%lf", &N, &d, &s, &a);
		passo++;
		mark[1] = passo;
		dp[1] = d+s+a;
		printf("%.3lf\n", solve(N));
	}
	return 0;
}