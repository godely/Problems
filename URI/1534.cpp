#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f
#define MOD 10007

int M[80][80];

int main() {
	int N;
	while (scanf("%d", &N) == 1) {
		rp(i,N) rp(j,N) M[i][j] = 3;
		rp(i,N) M[i][i] = 1;
		rp(i,N) M[i][N-1-i] = 2;
		rp(i,N) {
			rp(j,N) printf("%d", M[i][j]);
			puts("");
		}
	}
}