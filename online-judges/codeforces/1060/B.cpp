#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

ll s(ll x) {
	ll resp = 0;
	while (x) {
		resp += (x % 10);
		x /= 10;
	}
	return resp;
}

ll f(ll x) {
	ll resp = 0;
	while (resp * 10ll + 9ll <= x) {
		resp *= 10ll;
		resp += 9ll;
	}
	return resp;
}

int main() {
	ll x; scanf("%lld", &x);
	ll y = f(x);
	printf("%lld\n", s(y) + s(x - y));
    return 0;
}

