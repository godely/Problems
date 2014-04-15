#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int lol[4];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &lol[0], &lol[1], &lol[2], &lol[3]);
		sort(lol, lol+4);
		if (lol[0] == lol[3]) printf("square\n");
		else if (lol[0] == lol[1] && lol[2] == lol[3]) printf("rectangle\n");
		else if (lol[3] > lol[0]+lol[1]+lol[2]) printf("banana\n");
		else printf("quadrangle\n");
	}
	return 0;
}