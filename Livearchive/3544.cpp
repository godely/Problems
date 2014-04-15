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

int p, w;
char line[200000];
int g[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int group[] = {0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7};

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &p, &w);
		gets(line);
		gets(line);
		int s = strlen(line);
		int tmp = 0;
		int last = -1;
		rp(i,s) {
			if (line[i] != ' ' && group[line[i]-'A'] == last) tmp+=w;
			if (line[i] == ' ') {
				tmp += p;
				last = -1;
			} else {
				tmp += p*g[line[i]-'A'];
				last = group[line[i]-'A'];
			}
		}
		printf("%d\n", tmp);
	}
	return 0;
}