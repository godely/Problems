#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <bitset>
#include <vector>
#include <utility>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define F first
#define S second
typedef pair<int,int> pii;

int T, N, A, D;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &A, &D);
		printf("%d\n", ((2*A + (N-1)*D)*N)>>1);
	}
	return 0;
}