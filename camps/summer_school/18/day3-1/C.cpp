#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)

const int N = 5e6 + 5;
const long long inf = 1791791791791791791;

int p[N];
long long dp[300][300];

long long solve(int t, int n, int m, int i, int j) {
	//debug("calling dp to state (%d, %d, %d, %d, %d)\n", t, n, m, i, j);
	if (t < -1) {
		printf("-1\n");
		exit(0);
	}
	if (dp[i][j] != 0) return dp[i][j];
	if (t == -1)
		return 0;
	long long v1 = inf, v2 = inf;
	if (i < n) {
		v1 = 2*p[t];
		dp[i+1][j] = solve(t-j, n, m, i+1, j);
		v1 += dp[i+1][j];
	}
	if (t != n*m-2) if (j < m) {
		v2 = 2*p[t];
		dp[i][j+1] = solve(t-i, n, m, i, j+1);
		v2 += dp[i][j+1];
	}
	//debug("%lld %lld\n", v1, v2);
	return dp[i][j] = min(v1, v2);
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0;i<n*m;i++) {
		scanf("%d", &p[i]);
	}
	sort(p, p+n*m);
	long long resp = 4*p[n*m-1];
	resp += solve((n*m)-2, n, m, 1, 1);
	printf("%lld\n", resp);	
	return 0;
}
