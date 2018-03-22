#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 2e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

double am[N];
ll a[N];
vector<ll> v;
map<ll, ll> s;

bool isz(double t) {
	if (t < 1e-8) return true;
	else return false;
}

int main() {
	int n; scanf("%d", &n);
	ll T; scanf("%lld", &T);
	double resp = 0.0;
	for (int i=0;i<n;i++) {
		scanf("%lld", &a[i]);
	}
	for (int i=0;i<n;i++) {
		ll b; scanf("%lld", &b);
		if (b == T) resp += (double)a[i];
		else s[b] += a[i];
	}
	int k = 0;
	for (auto b : s) {
		v.pb(b.first);
		am[k++] = (double)b.second;
	}
	int p1=-1, p2=k;
	for (int i=0;i<k;i++) {
		if (v[i] > T) {
			p1 = i-1;
			p2 = i;
			break;
		}
	}
	while (p1 >= 0 && p2 < k) {
		double l = 0, r = am[p1];
		double x1, x2;
		for (int i=0;i<60;i++) {
			x1 = (l+r)/2.0;
			x2 = (x1*(T-v[p1]))/(v[p2]-T);
			if (x2 <= am[p2]) l = x1;
			else r = x1;
		}
		resp += x1 + x2;
		am[p1] -= x1;
		am[p2] -= x2;
		if (isz(am[p2])) {
			p2++;
		}
		if (isz(am[p1])) {
			p1--;
		}
	}
	printf("%.10lf\n", resp);
    return 0;
}

