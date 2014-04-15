#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for (int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define maxn 510

int N, M, D;
int cut[maxn], d[maxn], mark[maxn];

int main() {
	int a;
	while (scanf("%d%d%d", &N, &M, &D) == 3 && N > 0) {
		Rp(i,M) mark[i] = 1;
		Rp(i,M) scanf("%d", &cut[i]);
		Rp(i,D) scanf("%d", &d[i]);
		if (!D) printf("0\n");
		else {
			sort(cut,cut+M);
			sort(d,d+D);
			
			int a = 0;
			if (d[0] < cut[0]) {
				a = cut[0]-d[0]+mark[0];
				mark[0] = 0;
			}
			
			int b = 0;
			if (d[D-1] >= cut[M-1]) {
				b = d[D-1]-cut[M-1]+mark[M-1];
				mark[M-1] = 0;
			}
			int res = a+b;
			for (int i = 0; i < M-1; i++) {
				a = lower_bound(d,d+D,cut[i]) - d;
				if (a < cut[i+1]) {
					b = lower_bound(d,d+D,cut[i+1]) - d - 1;
					int temp = min(cut[i+1]-d[a]+mark[i+1], d[b]-cut[i]+mark[i]);
					bool foi = 0;
					//printf("%d %d, %d %d, %d %d\n", a, b, d[a], d[b], cut[i+1]-d[a]+1, d[b]-cut[i]+1);
					for (int j = a; j < b; j++) {
						temp = min(temp, (d[j]-cut[i]+mark[i]) + (cut[i+1]-d[j+1]+mark[i+1]));
						foi = 1;
					}
					res += temp;
					if (foi) mark[i] = mark[i+1] = 0;
					else {
						if (cut[i+1]-d[a]+1 <= d[b]-cut[i]+1) mark[i] = 0;
						else mark[i+1] = 0;
					}
				}
			}
			printf("%d\n", res);
		}
	}
	return 0;
}