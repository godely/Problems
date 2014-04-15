#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct abc {
	char s[20];
	int day, month, year;

	abc() {}
	abc(int day, int month, int year) : day(day), month(month), year(year) {}

	bool operator<(const abc &lhs) const {
		if (year != lhs.year) return year < lhs.year;
		if (month != lhs.month) return month < lhs.month;
		return day < lhs.day;
	}
} A[111];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s%d%d%d", A[i].s, &A[i].day, &A[i].month, &A[i].year);
	}
	sort(A, A+N);
	printf("%s\n%s\n", A[N-1].s, A[0].s);
}