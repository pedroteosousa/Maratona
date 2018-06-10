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
	ll n, m, a, b;
	scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
	if (n % m == 0) printf("0\n");
	else {
		ll t = (n/m);
		ll t1 = (n-t*m) * b;
		ll t2 = ((t+1ll)*m-n) * a;
		printf("%lld\n", min(t1, t2));
	}
    return 0;
}

