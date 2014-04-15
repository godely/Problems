//by stor
#include <bits/stdc++.h>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define MAXN 100100

int size;
char T[MAXN], P[MAXN];
int back[MAXN];

//ab
//ba

void pre_kmp() {
	int i = 0, j = -1;
	back[0] = -1;
	while (i < size) {
		while (j >= 0 && P[i] != P[j]) j = back[j];
		i++, j++;
		back[i] = j;
	}
}

//amanaplanacanal
//lanacanalpanama

void kmp() {
	int i = 0, j = 0;
	while (i < size) {
		while (j >= 0 && T[i] != P[j]) j = back[j];
		i++, j++;
		//printf("%d %d\n", i, j);
		if (i == size) {
			printf("%s%s\n", T, P+j);
		}
	}
}

int main() {
	while (scanf("%s", T) == 1) {
		size = strlen(T);
		rp(i,size) P[i] = T[size-1-i];
		P[size] = '\0';
		pre_kmp();
		kmp();
	}
	return 0;
}