#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

const double pi = acos(-1);
const double tempo = pi/45600;
const double c = 20220;
const double EPS = 1e-7;

int N, w, h, m[110], d[110], q;

int a, b, tempoEsq, tempoDir;
double angEsq, angDir, cur;
int main() {
	int cas = 1;
	while (scanf("%d", &N) == 1 && N > 0) {
		scanf("%d%d", &w, &h);
		rp(i,N-1) scanf("%d%d", &m[i], &d[i]);
		scanf("%d", &m[N-1]);
		printf("Apartment Complex: %d\n\n", cas++);
		while(scanf("%d", &q) && q > 0) {
			printf("Apartment %d: ", q);
			a = (q%100)-1;
			b = q/100-1;
			if (a < 0 || a >= N || b < 0 || b >= m[a]) printf("Does not exist\n\n");
			else {
				angEsq = cur = 0.0;
				for (int i = a-1; i >= 0; i--) {
					cur+=d[i];
					if (m[i] > b) {
						angEsq = max(angEsq, atan2(h*(m[i]-b),cur));
					}
					cur+=w;
				}
				angEsq += EPS;
				tempoEsq = (int)((angEsq/tempo)+c);
				angDir = cur = 0.0;
				for (int i = a+1; i < N; i++) {
					cur+=d[i-1];
					if (m[i] > b) {
						angDir = max(angDir, atan2(h*(m[i]-b),cur));
					}
					cur+=w;
				}
				angDir = (pi-angDir)+EPS;
				tempoDir = (int)((angDir/tempo)+c);
				
				printf("%.2d:%.2d:%.2d - %.2d:%.2d:%.2d\n\n", tempoEsq/3600, (tempoEsq%3600)/60, tempoEsq%60, tempoDir/3600, (tempoDir%3600)/60, tempoDir%60);
			}
		}
	}
	return 0;
}