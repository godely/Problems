#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	int a, N;
	while (scanf("%d", &N) == 1 && N > 0) {
		int sum = 0;
		while (N--) {
			scanf("%d", &a);
			//printf("%d\n", sum, a);
			sum=sum^a;
		}
		if (!sum) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
