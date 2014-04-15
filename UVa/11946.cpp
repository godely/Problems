#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char line[100];
char mapi[10] = {'O', 'I', 'Z', 'E', 'A', 'S', 'G', 'T', 'B', 'P'};

int main() {
	int T, tam;
	scanf("%d\n", &T);
	while(T--) {
	//	getchar();
		while (gets(line) && (tam = strlen(line)) > 0) {
			for (int i = 0; i < tam; i++) {
				if (line[i] >= '0' && line[i] <= '9') {
					printf("%c", mapi[line[i]-'0']);
				} else
					printf("%c", line[i]);
			}
			printf("\n");
		}
		if (T)
			printf("\n");
	}
	return 0;
}