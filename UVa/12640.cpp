#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 3011
#define MAXM 501111

using namespace std;

char str[5100000];
int main() {
	while (gets(str)) {
		bool hasNum = 0;
		int sign = 1;
		int num = 0, acc = 0, res = 0;
		for (int i = 0; str[i]; i++) {
			res = max(res,acc);
			if (str[i] == ' ') {
				if (hasNum) {
					num*=sign;
					if (acc+num < 0) acc = 0;
					else acc+=num;
					hasNum = 0;
					num = 0;
					sign = 1;
				}
			} else {
				hasNum = 1;
				if (str[i] == '-') sign = -1;
				else num = num*10+(str[i]-'0');
			}
		}
		if (hasNum) {
			num*=sign;
			if (acc+num < 0) acc = 0;
			else acc+=num;
		}
		res = max(res,acc);
		printf("%d\n", res);
	}
}