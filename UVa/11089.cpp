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

ll fib[100];
void go(int N, int i) {
	if (i == 1) {
		printf("0");
		return;
	} else if (i == 0) {
		return;
	}
	
	if (N<fib[i-1]) {
		printf("0");
		go(N,i-1);
	} else {
		printf("01");
		go(N-fib[i-1],i-2);
	}
}

int main() {
	fib[0] = fib[1] = 1;
	fr(i,2,50) fib[i] = (fib[i-1]+fib[i-2]);
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N); N--;
		int i = 0;
		while (N-fib[i] >= 0) N-=fib[i++];
		printf("1");
		go(N,i);
		puts("");
	}
}