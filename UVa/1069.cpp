#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

long long coef[1000], expo[1000];
int r;

long long mulMod(long long a, long long b, long long mod) {
	return ((a%mod)*(b%mod))%mod;
}

long long fastExp(long long n, long long e, long long mod) {
	long long ans = 1;
	for (; e > 0; e>>=1, n=mulMod(n,n,mod)) if (e&1) ans=mulMod(ans,n,mod);
	return ans;
}

char str[10000];
int sign, exping;
long long num;
int main() {
	int cas = 1;
	while (scanf("%s", str) == 1 && str[0] != '.') {
		memset(coef, 0, sizeof coef);
		memset(expo, 0, sizeof expo);
		r = 0;
		sign = 1;
		exping = 0;
		num = 0;
		int i;
		for (i = 1; str[i] != '/'; i++) {
			if (str[i] >= '0' && str[i] <= '9') num=(num*10)+(str[i]-'0');
			else {
				if (exping) {
					expo[r++] = num;
					exping = 0;
					num = 0;
				}
				if (str[i] == 'n') {
					coef[r] = sign*(num + !num);
					if (str[i+1] == '^') exping = 1, i++;
					else expo[r++] = 1;
				} else {
					if (num > 0) coef[r++] = sign*num;
					if (str[i] == '-') sign = -1;
					else if (str[i] == '+') sign = 1;
				}
				num = 0;
			}
		}
		num = 0;
		for (i = i+1; str[i]; i++) num=(num*10)+(str[i]-'0');
		long long ans;
		fr(i,1,r+2) {
			ans = 0;
			rp(j,r) {
				ans = (ans+mulMod(coef[j],fastExp(i,expo[j],num),num))%num;
			}
			if (ans != 0) {
				printf("Case %d: Not always an integer\n", cas++);
				goto fim;
			}
		}
		printf("Case %d: Always an integer\n", cas++);
		fim:;
	}
	return 0;
}