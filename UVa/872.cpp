#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define clvec(vec,n) for(int i = 0; i <= n; i++) vec[i].clear()
#define pb push_back

using namespace std;

int N;
char str1[10000], str2[10000];
int no[100], grau[100];
vector<int> adj[100];

int btN;
int res[100];
bool ok;
void bt() {
	if (btN==N) {
		ok=1;
		printf("%c", res[0]+'A');
		for (int i = 1; i < btN; i++) {
			printf(" %c", res[i]+'A');
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (grau[no[i]]==0) {
			for (int j = 0; j < adj[no[i]].size(); j++) grau[adj[no[i]][j]]--;
			res[btN++]=no[i];
			grau[no[i]]--;
			bt();
			grau[no[i]]++;
			btN--;
			for (int j = 0; j < adj[no[i]].size(); j++) grau[adj[no[i]][j]]++;
		}
	}
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) {
		gets(str1);
		int size1 = strlen(str1);
		N = 0;
		for (int i = 0; i < 30; i++) adj[no[i]].clear();
		for (int i = 0; i < size1; i+=2) {
			no[N++] = str1[i]-'A';
		}
		sort(no,no+N);
		memset(grau,0,sizeof grau);
		gets(str2);
		int size2 = strlen(str2);
		for (int i = 0; i < size2; i+=4) {
			adj[str2[i]-'A'].pb(str2[i+2]-'A');
			grau[str2[i+2]-'A']++;
		}
		btN=0;
		ok=0;
		bt();
		if (!ok) printf("NO\n");
		if (T) printf("\n");
		getchar();
	}
}