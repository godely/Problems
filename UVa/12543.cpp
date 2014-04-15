#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

char str[100000], aux[100000];
int size, count, temp;

int main() {
	temp = 0;
	while (gets(str)) {
		size = strlen(str);
		count = 0;
		for (int i = 0; i <= size; i++) {
			if (i+4 < size && str[i] == 'E' && str[i+1] == '-' && str[i+2] == 'N' && str[i+3] == '-' && str[i+4] == 'D') goto lol;
			if (str[i] != '-' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
				if (count > temp) {
					for (int j = i-count, k = 0; j < i; j++, k++) aux[k] = (str[j] == '-') ? str[j] : str[j] | 0x20;
					aux[count] = '\0'; 
					temp = count;
				}
				count = 0;
			} else count++;
		}
	}
	lol:;
	printf("%s\n", aux);
	return 0;
}