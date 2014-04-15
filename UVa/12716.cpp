#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
typedef pair<int,int> pii;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define oo 0x3f3f3f3f
#define PB push_back
#define MP make_pair
typedef long long ll;
#define maxn 30000001

int gcd(int a, int b) { return !b ? a : gcd(b,a%b); }

char str[100];
char* bin(int n) {
	int k = 0;
	while (n > 0) str[k++] = (n&1)+'0', n>>=1;
	reverse(str,str+k);
	str[k] = 0;
	return str;
}

int pd[maxn+10];
int main() {
	int cas = 1;
	pd[0] = pd[1] = pd[2] = 0;
	fr(i,3,maxn) pd[i] = (i&1);
	for (int i = 2; i < maxn; i++) {
		int m = 0;
		for (int j = i; (j|i) < maxn; j+=i) {
			if ((j&i) == 0) pd[i|j]++;
		}
	}
	fr(i,2,maxn) pd[i]+=pd[i-1];
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("Case %d: %d\n", cas++, pd[N]);
	}
	return 0;
}