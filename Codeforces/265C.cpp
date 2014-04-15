#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

char str[1000100];
int n;

void rec(int id) {
	if (id == n) return;
	if (str[id] == 'l') rec(id+1);
	printf("%d\n", id+1);
	if (str[id] == 'r') rec(id+1);
}

int main() {
	scanf("%s", str); n = strlen(str);
	rec(0);
	return 0;
}