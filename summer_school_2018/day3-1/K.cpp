#include <bits/stdc++.h>

using namespace std;

const int N = 8e2 + 5;
const int inf = 1791791791;

int v[N];
int dp[N][N];

int f(int i, int j, int k, int l) {
	if (v[i] == v[k] || v[i] == v[l] || v[j] == v[k] || v[j] == v[l])
		return 0;
	return 1;
}

int solve(int i, int j) {
	if (i == j) return dp[i][j] = 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = inf;
	for (int k=i; k<j; k++) {
		dp[i][j] = min(dp[i][j], solve(i, k) + solve(k+1, j) + f(i, k, k+1, j));
	}
	return dp[i][j];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, n-1));
    return 0;
}

