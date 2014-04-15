#include <bits/stdc++.h>
using namespace std;

long long N, K;
map<long long,int> s;
set<long long> p;
long long a, b, c, r, m[200011], v[200011];
long long find(int a) {
	if (a >= 0) {
		s[m[a]]--;
		if (s[m[a]] == 0) p.insert(m[a]);
	}
	long long ret = *p.begin();
	s[ret]++;
	p.erase(p.begin());
	return ret;
}

int main() {
	int T, cas = 1, tam;
	scanf("%d", &T);
	while (T--) {
		s.clear(); p.clear();
		scanf("%lld%lld", &N, &K);
		scanf("%lld%lld%lld%lld", &a, &b, &c, &r);
		m[0] = a;
		s[a]++;
		for(int i = 1; i < K; i++) m[i] = (b*m[i-1]+c)%r, s[m[i]]++;
		for(int i = 0, j = 0; j <= K; i++) if (!s.count(i)) p.insert(i), j++;
		tam = 0;
		long long st = -1;
		for (int i = K;; i++) {
			m[i] = find(i-K-1);
			if (i == K) st = m[i];
			if (i != K && m[i] == st) break;
			v[tam++] = m[i];
		}
		printf("Case #%d: %lld\n", cas++, v[(N-tam)%tam]);
	}
}