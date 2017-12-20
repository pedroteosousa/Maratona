#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 200;
const int inf = 1791791791;
const int mod = 1e9+7;

int c[N][N];

int main() {
	int n;
	scanf("%d", &n);
    c[0][0] = c[1][1] = 1;
	c[1][0] = 0;
	for (int i=2;i<=n;i++) {
		for (int j=0;j<=i;j++) {
			if (j != 0) c[i][j] += c[i-1][j-1];
			c[i][j] += c[i-2][j];
			c[i][j] %= 2;
		}
	}
	for (int i=n;i>=n-1;i--) {
		printf("%d\n", i);
		for (int j=0;j<=i;j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}

