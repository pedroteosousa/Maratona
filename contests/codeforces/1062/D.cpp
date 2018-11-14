#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

ll resp[N];

int main() {
	int n; scanf("%d", &n);
	ll ans = 0ll;
	for (int i=2;i<=n;i++) {
		for (int j = 2 * i; j <= n; j += i) {
			resp[j] += 4ll * (long long)j / (long long)i;
		}
	}
	for (int i=0;i<=n;i++) {
		ans += resp[i];
	}
	printf("%lld\n", ans);
    return 0;
}

