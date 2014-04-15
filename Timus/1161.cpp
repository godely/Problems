#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std; 
#define fr(a,b,c) for (int a = b; a < c; a++) 
#define rp(a,b) fr(a,0,b) 
#define CL(a,b) memset((a),(b),sizeof (a))
#define MP make_pair
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;

using namespace std;

int n;
double p[200];
double sum;

int main() {
	scanf("%d", &n);
	sum = 0;
	rp(i,n) scanf("%lf", &p[i]), sum += p[i];
	sort(p,p+n);
	double ans = sum;
	for (int i = n-1; i >= 1; i--) {
		sum -= p[i];
		sum -= p[i-1];
		p[i-1] = 2.0*sqrt(p[i]*p[i-1]);
		sum += p[i-1];
		ans = min(ans,sum);
	}
	printf("%.2lf\n", ans);
}