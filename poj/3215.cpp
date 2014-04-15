//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 1061109567
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define maxn 110000
#define dbg if(0)

const double eps = 1e-7;

ll gcd(ll a, ll b) {
	return (!b) ? a : gcd(b, a%b);
}

int cmp(double a, double b = 0) {
	if (fabs(a-b) < eps) return 0;
	else if (a < b) return -1;
	return 1;
}

struct frac {
	ll num, den;
	frac () {}
	frac (ll num_, ll den_) {
		ll a_ = num_, b_ = den_;
		if (a_ < 0) a_ = -a_;
		if (b_ < 0) b_ = -b_;
		ll k = gcd(a_, b_);
		num=num_/k;
		den=den_/k;
		if (den < 0) den*=-1, num*=-1;
	}
	
	double toVal() {
		return (double)num/den;
	}
	bool operator==(const frac &lhs) {
		return num == lhs.num && den == lhs.den;
	}
};

struct ev {
	frac f;
	ll toDown, toUp;
	ev() {
		toDown = 0, toUp = 0;
	}
	ev(frac a, int b, int c) : f(a), toDown(b), toUp(c) {}
	
	bool operator<(const ev &lhs) const {
		return (double)f.num/f.den < (double)lhs.f.num/lhs.f.den;
	}
	bool operator==(ev &lhs) {
		return (f == lhs.f);
	}
	ev operator+(const ev &lhs) {
		return ev(f, toDown+lhs.toDown, toUp+lhs.toUp);
	}
} events[maxn], realEv[maxn];

char lmv[100];
double showdouble(double a) {
	sprintf(lmv, "%.2lf", a + eps);
	bool zero = true;
	int len = strlen(lmv);
	Fr(i,0,len) if(!(lmv[i] != '-' && lmv[i] != '0' && lmv[i] != '.')) zero = false;
	if(zero) return 0.00;
	return a + eps;
}

ll a[maxn], b[maxn];
double interval[5];	
int main() {
	int n;
	ll up, down, zero;
	while (scanf("%d", &n) == 1) {
		if (!n) break;
		up = down = zero = 0;
		int k = 0;
		Fr(i,0,n) {
			scanf("%lld%lld", &a[i], &b[i]);
			if (b[i] == 0) {
				if (a[i] < 0) down++;
				else if (a[i] > 0) up++;
				else zero++;
			} else {
				if (b[i] < 0) up++, events[k++] = ev(frac(-a[i],b[i]), 1, 0);
				else down++, events[k++] = ev(frac(-a[i],b[i]), 0, 1);
			}
		}
		int r = 0;
		if (k > 0) {
			sort(events, events+k);
			realEv[0] = ev();
			realEv[0].f = events[0].f;
			Fr(i,0,k) {
dbg				printf("%d %lld %lld %lld %lld\n", r, events[i].f.num, events[i].f.den, events[i+1].f.num, events[i+1].f.den);
				realEv[r] = realEv[r]+events[i];
				if (i < k-1 && (events[i].f.num != events[i+1].f.num || events[i].f.den != events[i+1].f.den)) {
					r++;
					realEv[r] = ev();
					realEv[r].f = events[i+1].f;
				}
			}
			r++;
dbg			puts("");
		}
		int done = 0;
		if (min(up,down)+zero > max(up,down)) {
			interval[done++] = -INF;
		}
dbg		printf("> up:%lld down:%lld zero:%lld\n", up, down, zero);
		Fr(i,0,r) {
dbg			printf("up:%lld down:%lld zero:%lld, i:%d, done:%d\n", up, down, zero, i, done);
			zero += realEv[i].toUp + realEv[i].toDown;
			down -= realEv[i].toUp;
			up -= realEv[i].toDown;
			if (min(up,down)+zero > max(up,down)) {
				interval[done++] = realEv[i].f.toVal();
			}
dbg			printf("up:%lld down:%lld zero:%lld, i:%d, done:%d\n", up, down, zero, i, done);
			zero -= realEv[i].toUp + realEv[i].toDown;
			up += realEv[i].toUp;
			down += realEv[i].toDown;
		}
		if (min(up,down)+zero > max(up,down)) {
			interval[done++] = INF;
		}
		/*Fr(i,0,done) {
			printf("%lf ", interval[i]);
		}
		printf("\n");*/
		if (done == 0) {
			if (min(up,down)+zero > max(up,down)) {
				printf("(-inf,+inf)\n");
			} else printf("-1\n");
		} else if (done == 1) {
			printf("[%.2lf,%.2lf]\n", showdouble(interval[0]), showdouble(interval[0]));
		} else {
			if (cmp(interval[0],-INF) == 0) printf("(-inf,");
			else printf("[%.2lf,", showdouble(interval[0]));
			
			if (cmp(interval[done-1],INF) == 0) printf("+inf)\n");
			else printf("%.2lf]\n", showdouble(interval[done-1]));
		}
	}
	return 0;
}