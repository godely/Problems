#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

struct pt {
	int x, y;
	pt() {}
	pt(int x, int y) : x(x), y(y) {}
} pt[200100];

int dist2(int i, int j) {
	return (pt[i].x-pt[j].x)*(pt[i].x-pt[j].x) + (pt[i].y-pt[j].y)*(pt[i].y-pt[j].y);
}

int A[200100], B[200100];

int main() {
	int N, Q, R1, R2, c, d, cas = 1;
	while (scanf("%d", &N) == 1 && N > 0) {
		fr(i,2,N+2) scanf("%d%d", &pt[i].x, &pt[i].y);
		scanf("%d%d%d%d", &pt[0].x, &pt[0].y, &pt[1].x, &pt[1].y);
		fr(i,2,N+2) {
			A[i-2] = dist2(0,i);
			B[i-2] = dist2(1,i);
		}
		sort(A, A+N); sort(B, B+N);
		scanf("%d", &Q);
		printf("Case %d:\n", cas++);
		while (Q--) {
			scanf("%d%d", &R1, &R2);
			R1*=R1;
			R2*=R2;
			c = upper_bound(A,A+N,R1) - A;
			d = upper_bound(B,B+N,R2) - B;
			printf("%d\n", max(N-c-d,0));
		}
	}
	return 0;
}