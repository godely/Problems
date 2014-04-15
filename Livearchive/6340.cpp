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
#define maxn 1000100

//#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++
//int to[310000], ant[310000], adj[1100000], z = 0;

int N, M, x, y;
int e[maxn];
set<pii> s;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		s.clear();
		scanf("%d%d", &N, &M);
		int k = 0;
		rp(i,N) {
			e[i] = N-i-1;
			//d[i] = 0;
		}
		rp(i,M) {
			scanf("%d%d", &x, &y); x--, y--;
			if (s.count(MP(x,y))) continue;
			s.insert(MP(x,y));
			e[x]--;
			e[y]++;
			//d[x]++;
			//add(y,x);
		}
		rp(i,N) if (e[i] == 0) {
			printf("2 %d\n", i+1);
			goto fim;
		}
		puts("1");
		fim:;
	}
	return 0;
}