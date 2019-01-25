#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int main() {
	int n; scanf("%d", &n);
	ll num = 1ll;
	vector<ll> pot;
	pot.pb(1ll);
	for (int i=1;i<25;i++) {
		pot.pb(2ll * pot.back());
	}
	int mxk = 0, mn = 1000;
	for (int i=2;i<=n;i++) {
		if (n % i == 0) {
			num *= i;
			int count = 0;
			while (n % i == 0) {
				n /= i;
				count++;
			}
			mn = min(mn, count);
			int k = lower_bound(pot.begin(), pot.end(), count) - pot.begin();
			mxk = max(k, mxk);
			//printf("k = %d for count = %d and div = %d\n", k, count, i);
		}
	}
	if (num != 1 && mn != pot[mxk]) mxk++;
	printf("%lld %d\n", num, mxk);
    return 0;
}

