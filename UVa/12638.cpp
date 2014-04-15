#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 2011
typedef long long ll;
using namespace std;

char str[11111];
int sz, res;

bool go(int i, int cnt, int ans) {
	if (i >= sz) {
		if (!cnt) res = ans;
		return 1;
	}
	
	if (str[i] == '0') {
		if (cnt < 2) return go(i+1, 0, ans+1);
		else return go(i+1, cnt-1, ans);
	} else if (str[i] == '1') {
		if (!cnt) return go(i+1, 2, ans);
		else return go(i+1, cnt+1, ans);
	} else {
		str[i] = '0';
		if (go(i,cnt,ans)) return 1;
		str[i] = '1';
		if (go(i,cnt,ans)) return 1;
		str[i] = '?';
	}
	return 0;
}

int main() {
	while (scanf("%s", str) == 1) {
		sz = strlen(str);
		res = 0;
		go(0,0,0);
		printf("%d\n", res);
	}
	return 0;
}