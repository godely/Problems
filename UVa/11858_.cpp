#include <cctype>
#include <cstdio>

const int N = 1048576;
int v[N], L[N], R[N];
long long ans;

/* {{{ FAST integer input */
#define X10(n)	((n << 3) + (n << 1))
#define RI		readint
const int MAXR = 65536;
char buf[MAXR], *lim = buf + MAXR - 1, *now = lim + 1;

void merge(int left, int mid, int right){
	int i, iL, iR, j, k;
	for(i = left, iL = 1; i <= mid; ++i) L[iL++] = v[i];
	for(i = mid+1, iR = 1; i <= right; ++i) R[iR++] = v[i];
	L[iL] = R[iR] = 1 << 30;
	i = j = 1;
	for(k = left; k <= right; ++k){
		if(L[i] > R[j]){
			ans += iL - i;
			v[k] = R[j++];
		} else v[k] = L[i++];
	}
}

void merge_sort(int left, int right){
	if(left < right){
		int mid = (left + right) >> 1;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main(void){
    int n;
    while (scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
		ans = 0;
		merge_sort(0, n - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
