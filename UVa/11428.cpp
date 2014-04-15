#include <iostream>

using namespace std;

int N;

bool read() {
	cin >> N;
	if (N == 0) return false;
	return true;
}

void process() {
	int x, y;
	int xCub;
	for (int i = 1; i <= 10000; i++) {
		if (i*i*i >= N) {
			x = i;
			break;
		}
	}
	bool noSolution = true;
	for (int i = x; i <= 10000; i++) {
		int xCub = i*i*i;
		for (int j = 1; j <= 10000; j++) {
			int yCub = j*j*j;
			if (xCub - yCub == N) {
				x = i;
				y = j;
				i = 10001;
				noSolution = false;
				break;
			} else if (xCub - yCub < N) {
				break;
			}
		}
	}

	if (noSolution)
		cout << "No solution";
	else
		cout << x << " " << y;
	cout << endl;
}

int main() {
	while (read()) {
		process();
	}
}
