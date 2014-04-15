#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void process () {
	char cartao[20];

	for (int i = 0; i < 4; i++) {
		string tempC;
		cin >> tempC;
		for (int j = 0; j < 4; j++) {
			cartao[4*i+j] = tempC[j];
		}
	}

	int sum1 = 0;
	for (int i = 0; i < 16; i+=2) {
		int a = cartao[i] - '0';
		a *= 2;
		sum1 += a%10 + a/10;
	}

	int sum2 = 0;
	for (int i = 1; i < 16; i+=2) {
		sum2 += cartao[i] - '0';
	}

	int sum = sum1 + sum2;

	if (sum % 10 == 0)
		cout << "Valid";
	else
		cout << "Invalid";
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		process();
	}
	return 0;
}
