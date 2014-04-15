#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mod 1000000007
using namespace std;

int V[10100], NEXT[10100], PREV[10100];
stack<int> st;
int main() {
	int N, aux;
	long long sum;
	while (scanf("%d", &N) == 1) {
		fr(i,1,N+1) scanf("%1d", &V[i]);
		V[0] = V[N+1] = 0;
		
		while (!st.empty()) st.pop();
		fr(i,1,N+2) {
			while (!st.empty() && V[i] < V[st.top()]) {
				aux = st.top();
				NEXT[aux] = i-aux;
				st.pop();
			}
			st.push(i);
		}
		
		while (!st.empty()) st.pop();
		sum = 0;
		for (int i = N; i >= 0; i--) {
			while (!st.empty() && V[i] <= V[st.top()]) {
				aux = st.top();
				PREV[aux] = aux-i;
				st.pop();
			}
			st.push(i);
		}

		fr(i,1,N+1) {
			sum = (sum+((((NEXT[i]+PREV[i]+(NEXT[i]-1)*(PREV[i]-1)-1+mod)%mod)*V[i])%mod))%mod;
		}
		printf("%lld\n", sum);
	}
	return 0;
}