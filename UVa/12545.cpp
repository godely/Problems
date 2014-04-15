#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

char P[1000], T[1000];
int main() {
	int t; scanf("%d", &t);
	int cas = 1;
	while (t--) {
		scanf("%s%s", P, T);
		int size = strlen(P);
		int i = 0, j = size-1;
		int cnt = 0;
		while (i < j) {
			while (P[i] == '?' || P[i] == '1' || P[i] == T[i]) i++;
			while (P[j] == '?' || P[j] == '0' || P[j] == T[j]) j--;
			if (i < j) swap(P[i],P[j]), cnt++;
		}
		i = 0, j = size-1;
		while (i < j) {
			while (P[i] == '?' || P[i] == '0' || P[i] == T[i]) i++;
			while (P[j] == '?' || P[j] == '1' || P[j] == T[j]) j--;
			if (i < j) swap(P[i],P[j]), cnt++;
		}
		int cnt0 = 0, cnt1 = 0, cnt_ = 0;
		for (i = 0; i < size; i++) {
			if (P[i] == '?' && T[i] == '0') cnt++;
			else if (P[i] != T[i]) {
				if (P[i] == '0') cnt0++;
				else if (P[i] == '1') cnt1++;
				else cnt_++;
			}
		}
		
		if (cnt0 > 0) {
			cnt += cnt_ + cnt0;
		} else {
			if (cnt_ < cnt1) {
				cnt = -1;
			} else {
				cnt += cnt_ + cnt1;
			}
		}
		printf("Case %d: %d\n", cas++, cnt);
	}
	return 0;
}