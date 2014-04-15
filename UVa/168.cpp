#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define MAXN 1000010
#define pb push_back
#define inf 0x3f3f3f3f

using namespace std;
char str1[1111], str2[1111], str3[1111];
int k, size;
char *pt;
vector<int> adj[1111];
bool mark[1111];

void dfs(int a, int from, int n) {
	if (n==k) mark[a]=1;
	for (int i = 0; i < adj[a].size(); i++) {
		if (!mark[adj[a][i]] && adj[a][i] != from) {
			if (n==k) printf("%c ", a+'A');
			dfs(adj[a][i], a, (n+1)%(k+1));
			return;
		}
	}
	printf("/%c\n", a+'A');
}

int main() {
	while (scanf("%s", str1)==1 && str1[0]!='#') {
		rp(i,30) adj[i].clear();
		memset(mark,0,sizeof mark);
		scanf("%s%s%d", str2, str3, &k);
		k--;
		pt = strtok(str1, ";");
		do {
			size = strlen(pt);
			fr(i,2,size) {
				if(pt[i]=='.')continue;
				adj[pt[0]-'A'].pb(pt[i]-'A');
			}
		} while ((pt=strtok(NULL, ";")));
		dfs(str2[0]-'A', str3[0]-'A', 0);
	}
	return 0;
}