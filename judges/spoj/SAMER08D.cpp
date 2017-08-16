#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int inf = 1791791791;

#define pb push_back

int dp[N][N];
int resp[N][N];

int main() {
	while(true) {
		int k;
		scanf("%d", &k);
		if (k == 0) break;
		string s1, s2;
		cin >> s1 >> s2;
		int n1 = s1.size(), n2 = s2.size();
		memset(dp, 0, sizeof(dp));
		memset(resp, 0, sizeof(resp));
		for (int j=1;j<=n2;j++) {
			for (int i=1;i<=n1;i++) {
				if (s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1]+1;
				}
			}
		}	
		/*for (int i=1;i<=n1;i++) {
			for (int j=1;j<=n2;j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}*/
		for (int i=1;i<=n1;i++) {
			for (int j=1;j<=n2;j++) {
				if (dp[i][j] >= k) {
					//printf("dp[%d][%d] = %d -> %d\n", i, j, dp[i][j], resp[i-dp[i][j]][j-dp[i][j]]);
					for (int p = k;p<=min(2*k, dp[i][j]); p++) {
						resp[i][j] = max(resp[i][j], resp[i-p][j-p]+p);
					}
				}
				resp[i][j] = max(resp[i][j], max(resp[i][j-1], resp[i-1][j]));
			}
		}
		printf("%d\n", resp[n1][n2]);
		/*for (int i=0;i<=n1;i++) {
			for (int j=0;j<=n2;j++) {
				printf("%d ", resp[i][j]);
			}
			printf("\n");
		}*/
	}
	return 0;
}

