#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define ULL unsigned long long

char str[1111111], ch[11];

ULL M[130][130];
int H[130], h;
ULL A[130][3];

int F[20][130], f[20];

int main() {
	int T, N, size, a, b, c, Q, x;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		memset(M,0,sizeof M);
		memset(f,0,sizeof f);
		memset(F,0,sizeof F);
		h=0;
		rp(i,N) {
			scanf("%s", str);
			size = strlen(str);
			a = str[0]-33;
			H[h++] = a;
			fr(j,3,size) {
				M[a][str[j]-33]++;
			}
		}
		rp(i,h) {
			rp(j,130) {
				if (M[H[i]][j] > 0) {
					F[i][f[i]++] = j;
				}
			}
		}
		scanf("%d", &Q);
		while (Q--) {
			scanf("%s %s %d", str, ch, &x);
			size = strlen(str);
			memset(A,0,sizeof A);
			rp(i,size) {
				A[str[i]-33][0]++;
			}
			a = 0;
			while (x--) {
				rp(j,95) {
					A[j][a^1] = A[j][a];
				}
				rp(i,h) {
					A[H[i]][a^1] = 0;
				}
				rp(i,h) {
					rp(j,f[i]) {
						A[F[i][j]][a^1] += A[H[i]][a]*M[H[i]][F[i][j]];
					}
				}
				a^=1;
			}
			printf("%llu\n", A[ch[0]-33][a]);
		}
	}
	return 0;
}
