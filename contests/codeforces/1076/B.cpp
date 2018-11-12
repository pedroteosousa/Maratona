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
	ll n; scanf("%lld", &n);
    ll resp = 0;
	if (n % 2) {
		ll p = n;
		for (ll i = 3; i * i <= n; i += 2) {
			if (n % i == 0) {
				p = i;
				break;
			}
		}
		n = n - p;
		resp++;
	}
	resp += (n / 2ll);
	printf("%lld\n", resp);
	return 0;
}

