#include <iostream>
#include <cstdio>

using namespace std;

int N;
int numbers[20];
int counta = 1;

bool read() {
	if (scanf("%d",&N) == EOF) return false;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	return true;
}

void process() {
	long long product;
	long long maxProduct = 0;
	for (int i = 0; i < N; i++) {
		product = 1;
		for (int j = i; j < N; j++) {
			product *= numbers[j];
			if (product > maxProduct)
				maxProduct = product;
		}
	}

	cout << "Case #" << counta++ << ": The maximum product is " << maxProduct << "." << endl << endl;
}

int main() {
	while (read()) {
		process();
	}
	return 0;
}
