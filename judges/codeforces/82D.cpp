#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int inf = 1791791791;

#define pb push_back

int v[N][N];
int val[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &val[i]);
	}
	memset(v, inf, sizeof(v));
	v[0][0] = max(val[1], val[2]);
	v[1][0] = max(val[0], val[2]);
	v[2][0] = max(val[1], val[0]);
	for (int i=1;i<=(n-3)/2;i++) {
		int mn = inf;
		int id = -1;
		for (int j=0;j<n;j++) {
			int t = i*2;
			printf("t = %d | j = %d | i = %d\n", t, j, i);
			if (j <= t) {
				v[j][i] = v[j][i-1] + max(val[t+1], val[t+2]);
				if (v[j][i-1] < mn) {
					mn = v[j][i-1];
					id = j;
				}
			}
			else {
				v[t+1][i] = max(v[t+2][i], val[id]) + mn;
				v[t+2][i] = max(v[t+1][i], val[id]) + mn;
				break;
			}
		}
	}
	int mn = inf;
	if (n % 2 == 0) {
		for (int i=0;i<n;i++) {
			printf("mn1 = %d\n", mn);
			mn = min(mn, v[i][(n-3)/2] + max(val[i], val[n-1]));
			printf("mn2 = %d\n", mn);
		}
	}
	else {
		for (int i=0;i<n;i++) {
			mn = min(mn, v[i][(n-1)/2] + val[i]);
		}
	}
	printf("%d\n", mn);
    return 0;
}

