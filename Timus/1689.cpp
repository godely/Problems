#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int ini[100001], fim[100001];

int main() {
	int g, w, b, p, n, pos = 0, temp = 0;
	scanf("%d%d%d%d%d", &g, &w, &b, &p, &n);
	rp(i,n) scanf("%d", &ini[i]), fim[i] = ini[i] + w - 1;
	sort(ini,ini+n); sort(fim,fim+n);
	for (int i = 0; i < g - b; i++) {
		int v1 = lower_bound(fim, fim+n, i) - fim;
		int v2 = lower_bound(ini, ini+n, i+b) - ini);
		
		int t1 = lower_bound(fim, fim+n, i+b-p) - fim;
		int t2 = lower_bound(fim, fim+n, i+p) - fim;
		//printf("> %d\n", v1 + v2 + (t1-t2));
		if (v1 + v2 + (t1-t2) > temp) {
			temp = v1 + v2 + (t1-t2);
			pos = i;
		}
	}
	printf("%d\n", pos);
	return 0;
}