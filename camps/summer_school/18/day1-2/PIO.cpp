#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e5 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

typedef long long ll;

struct point {
	ll x, y;
	point(ll a, ll b) {
		x = a; y = b;
	}
	point() {

	}
	point operator- (const point &p) {
		return point(x-p.x, y-p.y);
	}
	point operator+ (const point &p) {
		return point(x+p.x, y+p.y);
	}
	bool operator< (const point &p) const {
		return atan2(y, x) < atan2(p.y, p.x);
	}
	ll operator^ (const point &p) {
		return x*p.y - y*p.x;
	}
	ll len() {
		return x*x+y*y;
	}
};

point v[N];

int main() {
	int n; scanf("%d", &n);
	for (int i=0;i<n;i++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		v[i] = point(a, b);
	}
	sort(v, v+n);
	ll resp = 0;
	int l = 0, r = 0;
	point f(0ll, 0ll);
	for (;l < n; l++) {
		if ((v[l%n] ^ v[r%n]) > 0) {
			do {
				f = f + v[r%n];
				r++;
			} while ((v[l%n] ^ v[r%n]) > 0);
		}
		resp = max(resp, f.len());
		f = f - v[l%n];
	}
	printf("%lld\n", resp);
	return 0;
}
