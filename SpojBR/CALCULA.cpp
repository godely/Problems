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

#define maxn 110
#define maxm 20100
#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++
int to[maxn], ant[maxn], adj[maxm], z;

char line[11000];
int main() {
	int n, cas = 1;
	while (scanf("%d", &n) == 1 && n > 0) {
		printf("Teste %d\n", cas++);
		gets(line);
		gets(line);
		int res = 0, lastOp = 1, temp = 0;
		for (int i = 0; line[i]; i++) {
			if (line[i] == '+' || line[i] == '-') {
				res = res + lastOp*temp;
				temp = 0;
				lastOp = (line[i] == '+') ? 1 : -1;
			} else {
				temp = temp*10 + line[i] - '0';
			}
		}
		res = res + lastOp*temp;
		printf("%d\n", res);
		puts("");
	}
	return 0;
}