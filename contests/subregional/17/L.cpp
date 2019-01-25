#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int M = 105;
int v[N][M];

char p[M];
char s[N];

int n, m, k;

int main() {
	int n, m, k;
	scanf("%d %d %d", &m, &n, &k);
	scanf("%s", p);
	scanf("%s", s);
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=m;j++) {
			v[i][j] = 1000000007;
			if (j == 0) v[i][j] = 0;
		}
	}
	int mn = 1000000007;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (s[i-1] == p[j-1]) {
				v[i][j] = v[i-1][j-1];
			}
			else {
				v[i][j] = min(v[i-1][j], min(v[i][j-1], v[i-1][j-1])) + 1;
			}
			if (j==m) mn = min(mn, v[i][j]);
			//printf("%d ", v[i][j]);
		}
		//printf("\n");
	}
	if (mn <= k) printf("S\n");
	else printf("N\n");
	return 0;
}