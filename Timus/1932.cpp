#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 70000
typedef long long ll;

int N;
char inp[maxn][7];
ll temp[maxn], igual[5], dif[5];

void solve(int mask) {
	rp(i,N) {
		temp[i] = 0;
		rp(j,4) {
			temp[i] *= 127;
			if (mask&(1<<j)) temp[i] += inp[i][j];
		}
	}
	sort(temp,temp+N);
	ll res = 0, counter = 0;
	rp(i,N) {
		counter++;
		if (i == N-1 || temp[i] != temp[i+1]) res += (counter*(counter-1))>>1, counter = 0;
	}
	igual[__builtin_popcount(mask)] += res;
}

int main() {
	memset(igual,0,sizeof igual);
	scanf("%d", &N);
	rp(i,N) scanf("%s", inp[i]);
	rp(i,16) solve(i);
	dif[0] = igual[4];
	dif[1] = igual[3] - 4*dif[0];
	dif[2] = igual[2] - 6*dif[0] - 3*dif[1];
	dif[3] = igual[1] - 4*dif[0] - 3*dif[1] - 2*dif[2];
	dif[4] = igual[0] - dif[0] - dif[1] - dif[2] - dif[3];
	printf("%I64d %I64d %I64d %I64d\n", dif[1], dif[2], dif[3], dif[4]);
	return 0;
}