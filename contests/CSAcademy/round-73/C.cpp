#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

vector<pair<int, int> > l[5];
vector<int> conn[N][5];
int root[5];

int dfs(int n, int p, int k) {
	l[k].push_back(make_pair(conn[n][k].size(), p));
	for (int i=0;i<conn[n][k].size();i++) {
		dfs(conn[n][k][i], p+1, k);
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i=0;i<2;i++) {
			for (int j=1;j<=n;j++) {
				int a; scanf("%d", &a);
				if (a == 0) {
					root[i] = j;
					continue;
				}
				conn[a][i].push_back(j);
			}
			dfs(root[i], 1, i);
			sort(l[i].begin(), l[i].end());
		}
		bool ok = true;
		for (int i=0;i<n;i++) {
			if (l[0][i] != l[1][i]) ok = false;
		}
		printf("%d\n", ok);
		for (int i=0;i<2;i++) {
			l[i].clear();
			for (int j=1;j<=n;j++) {
				conn[j][i].clear();
			}
		}
	}
    return 0;
}

