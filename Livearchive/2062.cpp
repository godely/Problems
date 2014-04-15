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
	while (scanf("%s", str) == 1 && strcmp(str,"end") != 0) {
		int size = strlen(str);
		int ok = 2;
		rp(i,size) if (isVowel(str[i])) {
			ok |= 1;
			break;
		}
		rp(i,size-2) {
			if ((isVowel(str[i]) && isVowel(str[i+1]) && isVowel(str[i+2])) || (isCons(str[i]) && isCons(str[i+1]) && isCons(str[i+2]))) {
				ok = 0;
				break;
			}
		}
		rp(i,size-1) {
			if (str[i] != 'e' && str[i] != 'o' && str[i] == str[i+1]) {
				ok = 0;
				break;
			}
		}
		if (ok == 3) printf("<%s> is acceptable.\n", str);
		else printf("<%s> is not acceptable.\n", str);
	}
}