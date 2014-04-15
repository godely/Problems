#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int number;
bool primo[1000010];

bool read() {
	if (scanf("%d",&number) == EOF) return false;
	return true;
}

void process() {
	if (primo[number] == true) {
		int len;
		for (int i = 1; i <= 1000000; i*=10) {
			if (number % i == number) {
				len = (i/10);
				break;
			}
		}
		int invertedN = 0;
		int tempN = number;
		for (int i = len; i >= 1; i/=10) {
			invertedN += i*(tempN%10);
			tempN /= 10;
		}
		if (number != invertedN && primo[invertedN]) {
			printf("%d is emirp.\n",number);
		} else {
			printf("%d is prime.\n",number);
		}
	} else {
		printf("%d is not prime.\n",number);
	}
}

int main() {
	for (int i = 0; i < 1000010; i++) {
		primo[i] = true;
	}
	primo[0] = false;
	primo[1] = false;
	for (int i = 2; i < 1000010; i++) {
		if (!primo[i]) continue;
		for (int j = i*2; j < 1000010; j+=i) {
			primo[j] = false;
		}
	}

	while (read()) {
		process();
	}

	return 0;
}
