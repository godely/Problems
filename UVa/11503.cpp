#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std;
#define MP make_pair
typedef pair<int,int> pii;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second

#define maxn 300000

char A[50], B[50];
map<string,int> m;
int rep[maxn], sz[maxn];
int findset(int x) {
	if (x == rep[x]) return x;
	return rep[x] = findset(rep[x]);
}

int main() {
	int T, N; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		m.clear();
		int k = 0;
		rp(i,N) {
			scanf("%s%s", A, B);
			if (m.count(A) == 0) {
				rep[k] = k;
				sz[k] = 1;
				m[A] = k++;
			}
			if (m.count(B) == 0) {
				rep[k] = k;
				sz[k] = 1;
				m[B] = k++;
			}
			int a = m[A];
			int b = m[B];
			if (findset(a) != findset(b)) {
				sz[findset(b)] += sz[findset(a)];
				rep[findset(a)] = findset(b);
			}
			printf("%d\n", sz[findset(b)]);
		}
	}
	return 0;
}