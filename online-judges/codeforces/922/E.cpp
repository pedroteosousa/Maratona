#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 1e4 + 5, M = 1e3+5;
const int inf = 1791791791;
const int mod = 1e9+7;

typedef long long ll;

ll dp[N][M], cost[N], c[N];

int main() {
	int n; ll w, b, x; scanf("%d %lld %lld %lld", &n, &w, &b, &x);
    for (int i=1;i<=n;i++) {
		scanf("%lld", &c[i]);
	}
    for (int i=1;i<=n;i++) {
		scanf("%lld", &cost[i]);
	}
	memset(dp, -1, sizeof dp);
	dp[0][0] = w;
	for (int i=1;i<=n;i++) {
		set< pair<ll, ll> > s;
		int j = N-1;
		for (;dp[j][i-1] == -1;j--);
		ll k = 0;
		//printf("k = %lld, i = %d\n", k, i);
		for (;j>=0;j--) {
			//printf("inserting %lld %lld\n", dp[j][i-1] - k*cost[i], j);
			s.insert(make_pair(-(dp[j][i-1]-k*cost[i]), j));
			k++;
		}
		for (j=0;j<N;j++) {
			dp[j][i] = dp[j][i-1];
		}
		for (j=0;j<N;j++) {
			if (s.size() == 0) break;
			pair<ll, ll> f = *s.begin();
			ll missing = max(0ll, j - f.second);
			//printf("calculating dp[%d][%d], f = (%lld, %lld), missing = %lld, c[%d] = %lld\n", j, i, f.first, f.second, missing, i, c[i]);
			if (c[i] >= missing && dp[f.second][i-1] - cost[i]*missing >= 0) {
				//printf("oin\n");
				dp[j][i] = max(dp[j][i], dp[f.second][i-1] - cost[i]*missing);
			} else if (dp[f.second][i-1] - cost[i]*missing < 0) {
				break;	
			} else {
				s.erase(f);
				j--;
				continue;
			}
			dp[j][i] = min(dp[j][i]+x, w+(ll)j*b);
		}
	}
	ll k = 0;
	while (dp[k][n] >= 0) k++;
	printf("%lld\n", k-1);
	return 0;
}

