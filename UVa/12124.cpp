#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>
#include <vector>

#define INF 1100000

using namespace std;

int size[1010];
int price[1010][1010];
int quality[1010][1010];

int main() {
	int T, n, b, pric, qualit, k, tp, init, end, mid, temp, waste;
	bool could;
	char type[50], name[50];
	scanf("%d", &T);
	map<string, int> mapa;
	while (T--) {
		scanf("%d%d", &n, &b);
		k = 1;
		mapa.clear();
		memset(size, 0, sizeof(size));
		for (int i = 0; i < n; i++) {
			scanf("%s%s%d%d", type, name, &pric, &qualit);
			tp = mapa[type];
			if (tp == 0)
				tp = k++;
			mapa[type] = tp;
			price[tp][size[tp]] = pric;
			quality[tp][size[tp]++] = qualit;
		}
		init = 0, end = 1000000000;
		while (init < end) {
			mid = (init + end + 1)/2;
			could = true;
			waste = 0;
			for (int i = 1; i < k; i++) {
				temp = INF;
				for (int j = 0; j < size[i]; j++) {
					if (quality[i][j] >= mid && price[i][j] < temp) temp = price[i][j];
				}
				if (temp == INF) {
					could = false;
					break;
				}
				waste += temp;
			}
			if (could && waste <= b) {
				init = mid;
			} else {
				end = mid-1;
			}
		}
		printf("%d\n", init);
	}
}