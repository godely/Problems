#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <iostream>
#define F first
#define S second
#define pii pair<int,int>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int p[200];
int t[200], s = 0, maior, menor;
int main() {
	int a;
	while (scanf("%d", &a) == 1 && a > 0) {
		s = 0;
		p[s] = a;
		t[s++] = 0;
		menor = a;
		while (scanf("%d", &a) == 1 && a > 0) p[s] = a, t[s++] = 0, menor=min(menor,a);
		maior = menor*2;
		while (1) {
			bool ok = 1;
			if (maior > 18000) {
				printf("Signals fail to synchronise in 5 hours\n");
				break;
			}
			//printf("%d\n", maior);
			for (int i = 0; i < s; i++) {
				if (t[i]+p[i]-5 <= maior) {
					t[i] += 2*p[i];
					if (t[i] > maior) maior = t[i];
					ok = 0;
					break;
				}
			}
			if (ok) {
				printf("%.2d:%.2d:%.2d\n", maior/3600, (maior/60)%60, maior%60);
				break;
			}
		}
	}
}