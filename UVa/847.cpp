#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

map<int, bool> pd;
int n;
bool isWinning(int p) {
	if (p >= n) return false;
	if (pd.find(p) == pd.end()) {
		bool wins = false;
		for (int i = 2; i <= 9; i++) {
			if (!isWinning(p*i)) {
				wins = true;
				break;
			}
		}
		pd[p] = wins;
	}
	return pd[p];
}

int main() {
	while (scanf("%d", &n) == 1) {
		pd.clear();
		printf("%s\n", (isWinning(1)) ? "Stan wins." : "Ollie wins.");
	}
}