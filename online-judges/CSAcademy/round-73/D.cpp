#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

ll f[N];

ll expr(ll v, ll e, ll m) {
	if (e == 0) return 1ll;
	ll t = expr(v, e/2, m);
	if (e % 2 == 0) return (t*t)%m;
	else return (((t*t)%m)*v)%m;
}

ll choose(int k, int n) {
	return (((f[k]*expr(f[n], mod-2, mod))%mod)*expr(f[k-n], mod-2, mod))%mod;
}

int main() {
	int n; scanf("%d", &n);
	f[0] = 1ll;
	for (int i=1;i<=n;i++) {
		f[i] = (f[i-1]*(ll)i)%mod;
	}
	map<int, int> c;
	int mx = 0;
	for (int i=0;i<n;i++) {
		int a; scanf("%d", &a);
		c[a]++;
		mx = max(mx, c[a]);
	}
	ll resp = 1ll;
	for (auto a : c) {
		resp *= choose(mx, a.second);
		resp %= mod;
		resp *= f[a.second];
		resp %= mod;
	}
	resp *= expr(f[mx], mod-2, mod);
	resp %= mod;
	printf("%lld\n", resp);
    return 0;
}

