#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof(a))
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1
#define MAXN 40100

vector<ll> thing(int N, ll mask) {
	vector<ll> num = vector<ll>();
	rp(i,N) {
		int qnt;
		num.PB(0LL);
		rp(j,i) {
			qnt = 0;
			rp(k,60) if ((num[j]>>k)&1LL) {
				qnt++;
				if (qnt == i) num[i]|=(1LL<<k);
			}
		}
		qnt = N-i-1;
		rp(j,60) if (!((mask>>j)&1LL)) {
			if (qnt > 0) {
				qnt--;
				mask|=(1LL<<j);
				num[i]|=(1LL<<j);
			}
		}
	}
	return num;
}

bool foi[100];
vector<ll> go(int N, vector<ll> vec) {
	int M = (int)vec.size();
	fr(i,0,M) fr(j,i+1,M) fr(k,j+1,M) {
		if (((vec[i]&vec[j])&vec[k]) != 0) return vector<ll>();
	}
	N-=M;
	ll mask = 0;
	rp(i,M) mask|=vec[i];
	vector<ll> r = thing(N,mask);
	mask = 0;
	fr(i,0,M) {
		fr(j,i+1,M) {
			if ((vec[i]&vec[j]) == 0) return vector<ll>();
			mask |= (vec[i]&vec[j]);
		}
	}
	rp(i,N) {
		M = (int)vec.size();
		vec.PB(r[i]);
		CL(foi,0);
		rp(k,60) {
			if (!((mask>>k)&1LL)) {
				rp(j,M) if (!foi[j] && ((vec[j]>>k)&1LL)) {
					foi[j] = 1;
					mask |= (1LL<<k);
					vec[M] |= (1LL<<k);
					break;
				}
			}
		}
	}
	sort(vec.begin(),vec.end());
	M = (int)vec.size();
	fr(i,0,M) fr(j,i+1,M) fr(k,j+1,M) if (((vec[i]&vec[j])&vec[k]) != 0) return vector<ll>();
	fr(i,0,M) fr(j,i+1,M) if ((vec[i]&vec[j]) == 0) return vector<ll>();
	return vec;
}

int main() {
	int N, M;
	ll x;
	vector<ll> vec;
	scanf("%d%d", &N, &M);
	rp(i,M) scanf("%lld", &x), vec.PB(x);
	vec = go(N,vec);
	for (int i = 0; i < (int)vec.size(); i++) printf("%lld ", vec[i]);
	puts("");
}