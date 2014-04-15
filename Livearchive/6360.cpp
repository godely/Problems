#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isCons(char c) {
	return !isVowel(c);
}

char str[1000000];
int main() {
	int cas = 1, n;
	while (scanf("%d", &n) == 1) {
		int res = 0;
		rp(i,n) {
			scanf("%s", str);
			int temp = 0;
			for (int j = 0; str[j]; j++) temp += str[j];
			res = max(res, temp);
		}
		printf("Case %d: %d\n", cas++, res);
	}
}