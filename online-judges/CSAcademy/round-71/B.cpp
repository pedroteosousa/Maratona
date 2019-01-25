#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;

int v[505][505];
int c[505][505];
map<int, pair<int, int> > vm;

void f(int x, int y, int n, int m) {
	int mn = inf;
	for (int i=-1;i<=1;i++) {
		for (int j=-1;j<=1;j++) {
			if (x+i < n && x+i >= 0 && y+j < m && y+j >= 0 && (x+i != x || y+j != y)) {
				mn = min(mn, v[x+i][y+j]);
			}
		}
	}
	for (int i=-1;i<=1;i++) {
		for (int j=-1;j<=1;j++) {
			if (x+i < n && x+i >= 0 && y+j < m && y+j >= 0 && (x+i != x || y+j != y)) {
				if (v[x+i][y+j] == mn && mn < v[x][y]) {
					c[x+i][y+j] += c[x][y];
					c[x][y] = 0;
					return;
				}
			}
		}
	}

}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d", &v[i][j]);
			c[i][j] = 1;
			vm[-v[i][j]] = make_pair(i, j);
		}
	}
	for (auto a : vm) {
		f(a.second.first, a.second.second, n, m);
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			printf("%d ", c[i][j]);
		} printf("\n");
	}
    return 0;
}

