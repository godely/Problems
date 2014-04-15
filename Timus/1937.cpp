#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for(int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define maxn 100100
#define BASE 29
#define mp make_pair
#define g(c) (c-'a'+1)
typedef unsigned long long ull;

ull B[maxn];
ull hashL[maxn], hashR[maxn], hashT[maxn], tmpHash;
map<ull,int> hashP;

char T[maxn], P[maxn];
int n, m;

int main() {
	scanf("%s%s", T, P);
	n = strlen(T); m = strlen(P);

	B[0] = 1;
	Fr(i,1,n+1) B[i] = B[i-1]*BASE;
	
	//Calcular os hashes de T de tamanho n-m
	int s = n-m;
	hashL[0] = 0, hashR[n-1] = 0;
	Rp(i,s) hashL[0] = hashL[0]*BASE + g(T[i]), hashR[n-1] = hashR[n-1]*BASE + g(T[n-1-i]);
	Fr(i,1,n) {
		hashL[i] = (hashL[i-1] - g(T[i-1])*B[s-1])*BASE + g(T[(i+s-1)%n]);
		hashR[n-1-i] = (hashR[n-i] - g(T[n-i])*B[s-1])*BASE + g(T[(n-i-s+n)%n]);
	}
	
	/*Rp(i,n) printf("%llu ", hashL[i]);
	printf("\n");
	Rp(i,n) printf("%llu ", hashR[i]);
	printf("\n");*/
	
	//Calcular os hashes de T de tamanho m
	hashT[0] = 0;
	Rp(i,m) hashT[0] = hashT[0]*BASE + g(T[i]);
	Fr(i,1,n) hashT[i] = (hashT[i-1] - g(T[i-1])*B[m-1])*BASE + g(T[(i+m-1)%n]);

	/*Rp(i,n) printf("%llu ", hashT[i]);
	printf("\n");*/

	//Guardar num set os hashes de P de tamanho m
	hashP.clear();
	tmpHash = 0;
	Rp(i,m) tmpHash = tmpHash*BASE + g(P[m-1-i]);
	hashP.insert(mp(tmpHash,1));
	//printf("(%llu %d) ", tmpHash, 1);
	Fr(i,1,m) tmpHash = (tmpHash - g(P[m-i])*B[m-1])*BASE + g(P[m-i]), hashP.insert(mp(tmpHash,m-i+1));//, printf("(%llu %d) ", tmpHash, m-i+1);
	
	//Verificar respostas
	Rp(i,n) if (hashL[i] == hashR[(i+s-1)%n] && hashP.count(hashT[(i+s)%n]) > 0) {
		printf("Yes\n%d %d\n", i+s+1, hashP[hashT[(i+s)%n]]);
		goto ok;
	}
	printf("No\n");
	ok:;
}