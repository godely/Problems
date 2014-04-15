#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 200100
#define BASE 29ULL
typedef unsigned long long ull;

ull B[maxn], hashL[maxn], hashR[maxn];
char P[maxn];
int n;

//abcdcbacdc
int main() {
	B[0] = 1;
	rp(i,maxn-10) B[i+1] = B[i]*BASE;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", P);
		n = strlen(P);
		hashL[0] = P[0]-96;
		hashR[n-1] = P[n-1]-96;
		//printf("%llu %llu\n", hashL[0], hashR[n-1]);
		fr(i,1,n) {
			hashL[i] = hashL[i-1]*BASE + P[i]-96;
			hashR[n-i-1] = hashR[n-i]*BASE + P[n-i-1]-96;
			//printf("%llu %llu\n", hashL[i], hashR[n-i-1]);
		}
		rp(i,n-1) {
			//printf("> (%d) %llu %llu\n", i, hashL[i]*B[n-i-1], hashR[0]-hashR[i+1]*B[i+1]);
			if (hashL[i] == hashR[0]-hashR[i+1]*B[i+1] && hashR[i+1] == hashL[n-1]-hashL[i]*B[n-i-1]) {
				printf("alindrome\n");
				goto fim;
			}
		}
		if (hashL[n-1] == hashR[0]) printf("palindrome\n");
		else printf("simple\n");
		fim:;
	}
	return 0;
}