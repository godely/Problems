#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b)==2 && a != -1) {
		if (a==1||b==1) printf("%d+%d=%d\n",a,b,a+b);
		else printf("%d+%d!=%d\n",a,b,a+b);
	}
	return 0;
}