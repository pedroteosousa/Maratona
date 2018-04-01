#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 1e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

long long nw[N];
long long v[N];
int n, r;
ll k;

ll getSum(int t) {
	int r2 = min(n, t+r);
	int l2 = max(t-r, 1);
	ll p = v[r2] - v[l2-1];
	p += nw[r2] - nw[l2-1];	
	return p;
}

int mx(int t) {
	return min(t+r, n);
}

bool test(long long p) {
	ll temp = k;
	for (int i=1;i<=n;i++) {
		nw[mx(i)] = max(nw[mx(i)], nw[mx(i)-1]);
		ll ms = p-getSum(i);
		if (ms > 0) {
			nw[mx(i)] += ms;
			temp -= ms;
			if (temp < 0) break;
		}
	}
	for (int i=1;i<=n;i++) {
		nw[i] = 0;
	}
	if (temp >= 0) return true;
	else return false;
}

int main() {
	scanf("%d %d", &n, &r);
	scanf("%lld", &k);
	for (int i=0;i<n;i++) {
		scanf("%lld", &v[i+1]);
		v[i+1] += v[i];
	}
	long long l = 0, r = 2000000000000000000ll;
	while (l < r) {
		long long m = (l+r)/2ll;
		if (test(m)) l = m+1;
		else r = m;
	}
	printf("%lld\n", l-1);
    return 0;
}

