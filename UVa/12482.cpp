#include <bits/stdc++.h>
using namespace std;

char str[150];

int main() {
	int N, L, C, size;
	int tempLine, lines;
	while (scanf("%d%d%d", &N, &L, &C) == 3) {
		tempLine = 0;
		lines = 1;
		for (int i = 0; i < N; i++) {
			scanf("%s", str);
			size = strlen(str);
			if (tempLine + size > C) {
				tempLine = size + 1;
				lines++;
			} else tempLine += size + 1;
		}
		printf("%d\n", (lines+L-1)/L);
	}
	return 0;
}