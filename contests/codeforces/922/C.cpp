#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

typedef long long ll;

int main() {
	ll n, k; scanf("%lld %lld", &n, &k);
	set<ll> s;
	ll j;
	for (j=1;j<=k;j++) {
		if (s.find(n%j) != s.end()) {
			break;
		} else s.insert(n%j);
	}
	if (j > k) printf("Yes\n");
	else printf("No\n");
    return 0;
}

