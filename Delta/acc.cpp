#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#define mask 0x0000001F

using namespace std;

int primos[6000], np, fat[10];
map< int, long long > resp;
long long  n;
char ehprimo[50001];

void preprocess(){
	memset(ehprimo, 1, sizeof(ehprimo));
	for(int i = 4; i <= 50000; i+=2)ehprimo[i] = 0;
	np = 1;
	primos[0]=  2;
	for(int i = 3; i < 50000; i+= 2){
		if(!ehprimo[i])continue;
		primos[np++] = i;
		if(i >= 224)continue;
		for(int j = i*i; j <= 50000; j+= i)ehprimo[j] = 0;
	}
	resp.clear();
	resp[0] = 1;
	
	fat[0] = 1;
	for(int i =1; i <= 9; i++)fat[i] = i*fat[i-1];
}

int conv(int *q){
	int r = 0;
	for(int i = 0; i < 5; i++){
		r <<= 2;
		r |= q[i];
	}
	for(int i = 5; i < 7; i++){
		r <<= 3;
		r |= q[i];
	}
	r <<= 4;
	r |= q[7];
	r <<= 5;
	r |= q[8];
	return r;
}

int count(int *q, int *w){
	int pos = 0, total = 0, ret = 1;
	
	for(int i = 8; i >= 0; i--){
		while(pos < 9 && w[pos] >= q[i]){
			total++;
			pos++;
		}
		ret *= (total - (8-i));
//		printf("\nret = %d\n", ret);
	}
	//printf("\nret = %d\n", ret);
	pos = 0;
	int c;
	while(pos < 9){
		total = pos+1;
		c = 0;
		while (total < 9 && q[total] == q[pos])total++, c++;
		pos = total;
		ret /= fat[c+1];
	}
	return ret;
}

long long rec(int x){
	long long ret;
	int y = x, t, q[10], w[10];
	if(ret = resp[x])return ret;
	w[0] = y & mask;
//	printf("y = %d e w[0] = %d\n", y, mask);
	y >>= 5;
	w[1] = y & (mask >> 1);
	y >>= 4;
	for(int i = 2; i < 4; i++){
		w[i] = y & (mask  >> 2);
		y >>= 3;
	}
	for(int i = 4; i < 9; i++){
		w[i] = y & (mask >> 3);
		y >>= 2;
	}
//	for(int i = 0; i < 9; i++)printf(" %d", w[i]);
//	printf("\n");
	for(q[8] = 0; q[8] <= w[0]; q[8]++)
	for(q[7] = 0; q[7] <= q[8] && q[7] <= w[1] ; q[7]++)
	for(q[6] = 0; q[6] <= q[7] && q[6] <= w[2]; q[6]++)
	for(q[5] = 0; q[5] <= q[6] && q[5] <= w[3]; q[5]++)
	for(q[4] = 0; q[4] <= q[5] && q[4] <= w[4]; q[4]++)
	for(q[3] = 0; q[3] <= q[4] && q[3] <= w[5]; q[3]++)
	for(q[2] = 0; q[2] <= q[3] && q[2] <= w[6]; q[2]++)
	for(q[1] = 0; q[1] <= q[2] && q[1] <= w[7]; q[1]++) 
	for(q[0] = 0; q[0] <= q[1] && q[0] <= w[8]; q[0]++){
		t = conv(q);
		if(t != x){
	//		printf("%d chamando %d\n", x, t);
			ret +=count(q, w)*rec(t);		
		}
	}

	resp[x] = ret;
	//printf("f(%d) = %d\n", x, ret);
	return ret;
}

long long process(){
	int pos = 0, q[10];
	n++;
	for(int i = 0; i < 9;i++)
		q[i] = 0;
	for(int i = 0; i < np; i++){
		if(n%primos[i] == 0){
			while(n%primos[i] == 0){
				q[pos]++;
				n /= primos[i];
			}
			pos++;
		}
	}
	if(n != 1)q[pos++] = 1;

	sort(q, q + 9);
	return rec(conv(q));
}

int main(){
	int casos, cont = 1;
	scanf("%d", &casos);
	
	preprocess();
	
	while(casos--){
		scanf("%lld", &n);
		printf("Case %d: %lld\n", cont++,process());
	}

	return 0;
}