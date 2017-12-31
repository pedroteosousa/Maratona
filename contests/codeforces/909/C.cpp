#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e3 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

char s[N];
long long dp[N][N];

int main() {
	int n;
	scanf("%d", &n); getchar();
	for (int i=0;i<n;i++) {
		s[i] = getchar(); getchar();
		dp[i][0] = 1;
	}
	for (int i=0;i<n;i++) {
		for (int j=i;j>=0;j--) {
			if (s[i] == 'f') {
				dp[i+1][0] = 0;
				dp[i+1][j+1] = dp[i][j];
			} else {
				dp[i+1][j] = dp[i+1][j+1] + dp[i][j];
				dp[i+1][j] %= mod;
			}
		}
	}
	long long resp = 0;
	for (int i=0;i<n;i++) {
		resp += dp[n-1][i];
		resp %= mod;
	}
	printf("%lld\n", resp);
    return 0;
}

