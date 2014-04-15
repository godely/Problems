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
#define fr(a,b,c) for (int a = b; a < c; a++) 
#define rp(a,b) fr(a,0,b) 
#define CL(a,b) memset((a),(b),sizeof (a))
#define MP make_pair
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;
#define MOD 10000000000007LL

int N, K;
char gb[21000];
int vs;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);
		scanf("%s", gb);
		vs = 0;
		bool poss = 0;
		int res = 0;
		for (int i = 0; i < N; i++) {
			int j = i;
			for (; j < N && gb[j] == gb[i]; j++);
			vs = j-i;
			i = j-1;
			if (vs >= K) poss = 1, res+=(vs+K-1)/K;
			else res++;
		}
		if (poss) printf("%d\n", res);
		else printf("-1\n");
	}
	return 0;
}