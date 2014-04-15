#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define MP make_pair
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define MAXN 1001

char g[100][100];

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		int R = 0, C = -1;
		bool badCase = 0;
		while (scanf("%s", g[R]) == 1) {
			if (g[R][0] == '*') goto endCase;
			if (C == -1) C = strlen(g[R]);
			else if (C != strlen(g[R])) badCase = 1;
			R++;
		}
		endCase:;
		printf("Case %d: ", cas++);
		if (R != 2*C - 1 || C - 2 < 0) badCase = 1;
		if (badCase) printf("Bad");
		else {
			int D = C - 2;
			rp(j,C) {
				if (j == 0) badCase |= (g[0][j] != '.');
				else if (j < C - 1) badCase |= (g[0][j] != '-');
				else badCase |= (g[0][j] != '.');
			}
			fr(i,1,D+1) {
				rp(j,C) {
					if (j == 0) badCase |= (g[i][j] != '|');
					else if (j < C - 1) badCase |= (g[i][j] != '.');
					else badCase |= (g[i][j] != '|');
				}
			}
			rp(j,C) {
				if (j == 0) badCase |= (g[D+1][j] != '.');
				else if (j < C - 1) badCase |= (g[D+1][j] != '-');
				else badCase |= (g[D+1][j] != '.');
			}
			fr(i,D+2,2*D+2) {
				rp(j,C) {
					if (j == 0) badCase |= (g[i][j] != '|');
					else if (j < C - 1) badCase |= (g[i][j] != '.');
					else badCase |= (g[i][j] != '|');
				}
			}
			rp(j,C) {
				if (j == 0) badCase |= (g[2*D+2][j] != '.');
				else if (j < C - 1) badCase |= (g[2*D+2][j] != '-');
				else badCase |= (g[2*D+2][j] != '.');
			}
			if (badCase) printf("Bad");
			else printf("%d", D);
		}
		puts("");
	}
}