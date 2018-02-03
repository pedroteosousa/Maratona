#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 1e5 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

typedef long long ll;
ll p, x0, a, b, x;
ll pt[N];
map<ll, ll> m;

ll expr(ll e, ll n, ll m) {
	if (n == 0) return 1ll;
	ll t = expr(e, n/2, m);
	t = (t*t)%m;
	if (n&1) {
		return (t*e)%m;
	} else return t;
}

int main() {
	scanf("%lld %lld %lld %lld %lld", &p, &x0, &a, &b, &x);
	pt[0] = 1;
	ll bn = 1;
	int i;
	for (i=1;i*i<=p;i++) {
		pt[i] = (pt[i-1]*a)%p;
		if ((i+1ll)*(i+1ll) < p) {
			bn += pt[i];
			bn %= p;
		}
	} bn *= b;
	bn %= p;
	i--;
	ll t = 0;
	ll cur = x0;
	int k = 0;
	for (int j=0;j<N;j++) {
		m[cur] = t;
		//printf("k = %d, %lld %lld %d\n", k, cur, t, i);
		t += i;
		cur = (pt[i]*cur + bn)%p;
		//printf("%lld\n", cur);
	}
	m[cur] = t;
	t = 0;
	cur = x;
	for (int j = 0; j<N; j++) {
		if (m.find(cur) != m.end()) {
			printf("%lld\n", m[cur] + t);
			return 0;
		}
		t++;
		cur = (((cur-b+p)%p)*expr(a, p-2, p))%p;
	}
	printf("NIE\n");
	return 0;
}





