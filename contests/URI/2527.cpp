#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 7e3 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

long double p[N][N];

int main() {
	for (int i=1;i<=6;i++)
		p[1][i] = 1.0/6.0;
	for (int i=2;i<=1000;i++) {
		for (int j=0;j<=6000;j++) {
			for (int k=1;k<=6;k++) {
				p[i][j+k] += p[i-1][j]*(1.0/6.0);
			}
		}
	}
	int n, v;
	while (scanf("%d %d", &n, &v) != EOF) {
		long double resp = 0;
		for (int i=v;i<=6*n;i++) {
			resp += p[n][i];
		}
		printf("%.4Lf\n", resp);
	}
	return 0;
}

