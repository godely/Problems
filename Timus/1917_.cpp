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

#define fr(a,b,c) for( int a = b ; a < c ; ++a )
typedef long long ll;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

int arr[1010];

int main() {
	int n,p;
	cin >> n >> p;
	set<int> s;
	fr(i,0,n) cin>>arr[i],s.insert(arr[i]);
	sort(arr,arr+n);
	int aux = 0;
	int ans = 0;
	int qtd = 0;
	for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		int x = *it;
		int ct = 0;
		fr(i,aux,n) {
			if(arr[i]<=x)++ct;
			else if(arr[i]>x) break;
		}
		int lol = ct*x;
		//cout << "nao deu " << lol << endl;
		if(lol>p) {
			//cout << "nao deu " << lol << endl;
			if(it==s.begin()) continue;
			set<int>::iterator lucas = it;
			int y = *(--lucas);
			//cout << "Y " << y << endl;
			ct = 0;
			int pos = 0;
			bool ok = 1;
			fr(i,aux,n) {
				if(arr[i]<=y)++ct;
				else if(arr[i]>y) {pos=i;ok=0;break;}
			}
			if(ok)pos=n;
			lol=ct*y;
			if(lol<=p) {
				//cout << "deu " << lol << endl;
				qtd+=(pos-aux);
				aux = pos;
				++ans;
			}
		}
	}
	int ct = 0;
	int pos = 0;
	bool ok = 1;
	int x = *s.rbegin();
	//cout << "X " << x << endl;
	//cout << aux << endl;
	fr(i,aux,n) {
		if(arr[i]<=x)++ct;
		else if(arr[i]>x) {pos=i;ok=0;break;}
	}
	if(ok)pos=n;
	int lol=ct*x;
	//cout << "LOL "<<lol << endl;
	if(lol<=p) {
		//cout << "deu " << lol << endl;
		qtd+=(pos-aux);
		aux = pos;
		++ans;
	}
	cout << qtd << " " << ans << endl;
	return 0;
}
