#include <iostream>
#include <cstdio>

using namespace std;

int Y, N;

bool read() {
	if (scanf("%d%d",&Y,&N) == EOF) return false;
	return true;
}

void process() {
	int popes[N];

	for (int i = 0; i < N; i++) {
		cin >> popes[i];
	}

	int maxPopes = 0;
	int firstPope;
	int lastPope;
	for (int i = 0; i < N; i++) {
		int lastY = popes[i] + Y - 1;
		int maxTempPopes = 0;
		int j;
		for (j = i; j < N && popes[j] <= lastY; j++) {
			maxTempPopes++;
		}
		if (maxTempPopes > maxPopes) {
			maxPopes = maxTempPopes;
			firstPope = popes[i];
			lastPope = popes[j-1];
		}
	}

	cout << maxPopes << " " << firstPope << " " << lastPope << endl;
}

int main() {
	while (read()) {
		process();
	}

	return 0;
}
