// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long

inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)

using namespace std;

bool isVisited [1000000 + 10];

int main ()
{
	int n, m;
	int LIMIT = 1000000;

	while ( scanf ("%d %d", &n, &m) != EOF ) {

		if ( m == 0 && n == 0 ) break;

		Set(isVisited, false);
		bool conflict = false;

		for ( int i = 0; i < n; i++ ) {
			int a, b; scanf ("%d %d", &a, &b);

			if ( !conflict ) 
				for ( int j = a + 1; j <= b; j++ ) {
					if ( isVisited [j] ) { conflict = true; break; }
					else isVisited [j] = true;
				}
		}

		for ( int i = 0; i < m; i++ ) {
			int a, b, c; scanf ("%d %d %d", &a, &b, &c);
			int newStart = a;
			int newEnd = b;

			if (!conflict)
				while (newStart <= LIMIT) {
					for ( int j = newStart + 1; j <= min (newEnd, LIMIT); j++ ) {
						if ( isVisited [j] ) { conflict = true; break; }
						else isVisited [j] = true;
					}

					newStart += c;
					newEnd += c;
				}
		}

		if ( conflict ) printf ("CONFLICT\n");
		else printf ("NO CONFLICT\n");
	}
	return 0;
}

// @END_OF_SOURCE_CODE
