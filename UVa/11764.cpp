#include <iostream>

using namespace std;
int caseT;

void process() {
	int N;
	cin >> N;

	int pas, cur;

	int H = 0, L = 0;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		if (i > 0) {
			if (cur > pas)
				H++;
			else if (cur < pas)
				L++;
		}
		pas = cur;
	}

	cout << "Case " << caseT++ << ": " << H << " " << L << endl;
}

int main() {
	int T;
	caseT = 1;
	cin >> T;
	while (T--) {
		process();
	}
}
