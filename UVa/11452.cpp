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
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

char str[10000];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		int s = strlen(str), ini = 0;
		for (int i = s/2; i >= 0; i--) {
			if (strncmp(str,str+i,i) == 0) {
				ini = i;
				break;
			}
		}
		int ind = s - ini;
		rp(i,8) {
			printf("%c", str[i%ini+ind]);
		}
		puts("...");
		//printf("%d\n", ind);
	}
	return 0;
}