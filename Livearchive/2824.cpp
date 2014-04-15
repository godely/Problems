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

char ch[22], gb[220], gb2[220];

int main() {
	while (scanf("%s", ch) == 1) {
		int s = strlen(ch);
		if (s == 6 && strcmp(ch,"THEEND") == 0) break;
		scanf("%s", gb);
		int lst = 0;
		cl(gb2,0);
		int t = strlen(gb)/s;
		for (char c = 'A'; c <= 'Z'; c++) {
			rp(j,s) {
				if (ch[j] == c) {
					int kk = 0;
					fr(k,lst,lst+t) gb2[j+kk*s] = gb[k], kk++;
					lst+=t;
				}
			}
		}
		printf("%s\n", gb2);
	}
	return 0;
}