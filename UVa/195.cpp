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

char str[1111], test[1111], size;

char fix(int i) {
	char ret;
	if (str[i] <= 'Z') ret = ((str[i]-'A')<<1) + 'A';
	else ret = (str[i]-'a')*2 + 'A' + 1;
	return ret;
}

void print() {
	rp(i,size) {
		if (str[i]&1) printf("%c", ((str[i]-'A')>>1)+'A');
		else printf("%c", ((str[i]-'A')>>1) + 'a');
	}
	printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        test[0] = '\0';
        scanf("%s", str);
        size = strlen(str);
		rp(i,size) {
			str[i] = fix(i);
		}
        sort(str,str+size);
        do {
            if (strcmp(str,test)==0) continue;
            print();
            strcpy(test,str);
        } while (next_permutation(str, str+size));
    }
    return 0;
}
