#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int qnt[50], sum;
char str[1000000];
int main() {
	int T, cas = 1;
	scanf("%d\n", &T);
	while (T--) {
		memset(qnt,0,sizeof qnt);
		gets(str);
		for (int i = 0; str[i]; i++) {
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) qnt[(str[i]|0x20)-'a']++;
		}
		sort(qnt,qnt+26);
		sum = 0;
		for (int i = 25; i >= 0 && qnt[i] > 0; i--) sum += (i+1)*qnt[i];
		printf("Case #%d: %d\n", cas++, sum);
	}
}