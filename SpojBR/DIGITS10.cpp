#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define max(a,b) a<b?b:a

using namespace std;

int a,b,d,count[11],N,M;
void C(int x, int f) {
	int k = 1;
	int l=x;
	while(x) {
		a=x/10;
		b=x%10;
		d=l%k;

		for (int i=0; i<b;i++) count[i]+=f*k*(a+(i?1:0));
		count[b]+=f*(k*(a-(b?0:1))+d+1);
		for (int i=b+1; i<10; i++) count[i]+=f*k*a;

		k*=10;
		x/=10;
	}
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N) {
		memset(count,0,sizeof count);
		C(M,1);
		C(N-1,-1);
		printf("%d", count[0]);
		for(int i = 1; i < 10; i++) printf(" %d", count[i]);
		printf("\n");
	}
}