#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

ll acc[N], pot[N], accp[N]; 
char s[N];

int main() {
	int n, q; scanf("%d %d %s", &n, &q, s);
	for (int i=1;i<=n;i++) {
		acc[i] = acc[i-1];
		if (s[i-1] == '1') acc[i]++;
	}
	pot[0] = accp[0] = 1ll;
	for (int i=1;i<N;i++) {
		pot[i] = (2ll * pot[i-1]) % mod;
		accp[i] = (accp[i-1] + pot[i]) % mod;
	}
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		int count = acc[r] - acc[l-1];
		ll resp = 0ll;
		if (count) resp = accp[count - 1];
		ll z = (r - l + 1) - count;
		ll start = (pot[count] - 1ll + mod) % mod;
		if (z) resp += (accp[z-1] * start) % mod;
		resp %= mod;
		printf("%lld\n", resp);
	}
    return 0;
}

