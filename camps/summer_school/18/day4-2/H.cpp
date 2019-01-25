#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const ll N = 2e6 + 5, M = 25;
const ll lim = 1e12+5;
vector<ll> pascal[N];

bool find(ll n, ll k) {
	//printf("%lld %lld\n", n, k); getchar();
	ll cur = 1;
	if (n == 1) return true;
	for (int i = 1; i < pascal[k].size(); i++) {
		if (n % pascal[k][i] == 0ll && find(n/pascal[k][i], k-i)) return true;
	}
	return false;
}

int main() {
	pascal[0].pb(1);
	for (int i=1;i<N;i++) {
		for (int j=0;j<min(M, (ll)i+1);j++) {
			ll l = 0, r = 0;
			if (pascal[i-1].size() >= j && j > 0) l = pascal[i-1][j-1];
			if (pascal[i-1].size() > j) r = pascal[i-1][j];
			if (l+r <= lim)
				pascal[i].pb(l+r);
			else {
				pascal[i].pb(lim);
				break;
			}
			//printf("%lld ", pascal[i][j]);
		}
		//printf("\n"); getchar(); 
	}
	ll n; scanf("%lld", &n);
	if (n <= 1) {
		printf("%lld\n", n);
		return 0;
	}
	for (ll i = 2; i*i <= 4ll*n; i++) {
		if (find(n, i)) {
			printf("%lld\n", i);
			return 0;
		}
	}
	printf("%lld\n", n);
    return 0;
}

