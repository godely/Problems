#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define let(i) (str[i]-'a')

char str[3000];

bool isLetter(char s) {
	return s >= 'a' && s <= 'z';
}

char getBack(int pos) {
	int type = 0;
	for (int i = pos-1; i > 0; i--) {
		if (str[i] == ' ') continue;
		else if (isLetter(str[i])) return '.';
		else {
			if (str[i] == '-') {
				if (type == 1) return '-';
				else if (type == 0) type = 1;
				else return '.';
			}
			else if (str[i] == '+') {
				if (type == 2) return '+';
				else if (type == 0) type = 2;
				else return '.';
			}
		}
	}
	return '.';
}

char getFront(int pos) {
	int type = 0;
	for (int i = pos+1; str[i]; i++) {
		if (str[i] == ' ') continue;
		else if (isLetter(str[i])) return '.';
		else {
			if (str[i] == '-') {
				if (type == 1) return '-';
				else if (type == 0) type = 1;
				else return '.';
			}
			else if (str[i] == '+') {
				if (type == 2) return '+';
				else if (type == 0) type = 2;
				else return '.';
			}
		}
	}
	return '.';
}

char getSign(int pos) {
	for (int i = pos-1; i > 0; i--) {
		if (str[i] == '+' && str[i+1] != '+' && (str[i-1] == ' ' || str[i-1] == '-' || isLetter(str[i-1]))) return '+';
		else if (str[i] == '-' && str[i+1] != '-' && (str[i-1] == ' ' || str[i-1] == '+' || isLetter(str[i-1]))) return '-';
	}
	return '.';
}

int val[30], posVal[30], use[30];
int main() {
	while (gets(str+3)) {
		str[0] = ' '; str[1] = '+'; str[2] = ' ';
		rp(i,26) val[i] = posVal[i] = i+1, use[i] = 0;
		int sum = 0;
		for (int i = 0; str[i]; i++) {
			if (isLetter(str[i])) {
				use[let(i)] = 1;
				if (getBack(i) == '-') {
					val[let(i)]--;
					posVal[let(i)]--;
				} else if (getBack(i) == '+') {
					val[let(i)]++;
					posVal[let(i)]++;
				} else {
					if (getFront(i) == '-') {
						posVal[let(i)]--;
					} else if (getFront(i) == '+') {
						posVal[let(i)]++;
					}
				}
				
				if (getSign(i) == '+') {
					sum += val[let(i)];
				} else {
					sum -= val[let(i)];
				}
			}
		}
		printf("Expression: %s\n", str+3);
		printf("    value = %d\n", sum);
		rp(i,26) if (use[i]) printf("    %c = %d\n", i+'a', posVal[i]);
	}
	return 0;
}