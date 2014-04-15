#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

double Pk(int x) {
	double a = 2, b = 2;
	fr(i,1,x) a *= (2.0/3.0), b /= 3.0;
	return 1-a+b;
}

int mark[111];
double dp[111];
double Pg(int x) {
	if (mark[x]) return dp[x];
	mark[x] = 1;
	
	double ret = 0;
	fr(i,1,x) {
		ret += comb(x,i);
	}
	return dp[x] = (Pk(x)+ret)/(1-Pk(x));
}

int main() {
	memset(mark, 0, sizeof mark);
	int N;
	scanf("%d", &N);
	printf("%.6lf\n", (Pk(N)+0.33333333333)/(1-Pk(N)));
}