#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	int T, N, a, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int temp = 0, ai = 0, af = 0, bf = 0, max = 0, lc = -1;
		for (int i = 0; i < N-1; i++) {
			scanf("%d", &a);
			temp += a;
			if (temp > max) {
				af = ai;
				bf = i+1;
				max = temp;
			} else if (temp == max && (i+1-ai) > (bf-af)) {
				af = ai;
				bf = i+1;
			} else if (temp < 0) {
				temp = 0;
				ai = i+1;
			}
		}
		if (max > 0)
			printf("The nicest part of route %d is between stops %d and %d\n", cas++, af+1, bf+1);
		else
			printf("Route %d has no nice parts\n", cas++);
	}
}
