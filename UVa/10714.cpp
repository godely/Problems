#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

void process() {
	int length, ants;
	scanf("%d%d",&length,&ants);
	int positions[ants];
	for (int i = 0; i < ants; i++) {
		scanf("%d",&positions[i]);
	}
	sort(positions, positions + ants);
	int mini = 0;
	for (int i = 0; i < ants; i++) {
		if (min(positions[i], length - positions[i]) > mini)
			mini = min(positions[i], length - positions[i]);
	}

	int maxa = max(length - positions[0], positions[ants-1]);

	printf("%d %d\n", mini, maxa);
}

int main() {
	int T;
	cin >> T;
	while (T--)
		process();
	return 0;
}
