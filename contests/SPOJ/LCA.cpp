#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 1e6 + 5;
const int L = 20;
const ll inf = 1791791791;
const ll mod = 1e9+7;

vector<int> adj[N];
int prof[N], p[N][L+5];

void dfs(int v, int h = 1) {
	prof[v] = h;
	if (h == 1) p[v][0] = v;
	for (auto u : adj[v])
		if (prof[u] == 0) {
			p[u][0] = v;
			dfs(u, h+1);
		}
}

void init(int n) {
	for (int i = 1; i <= L; i++)
		for (int j = 1; j < n; j++)
			p[j][i] = p[p[j][i-1]][i-1];
}

int lca(int u, int v) {
	if (prof[u] < prof[v]) swap(u, v);
	for (int i = L; i >= 0; i--)
		if (prof[p[u][i]] >= prof[v])
			u = p[u][i];
	for (int i = L; i >= 0; i--)
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	while (u != v) {
		u = p[u][0];
		v = p[v][0];
	}
	return u;
}

int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n; scanf("%d", &n);
		for (int i=0;i<n;i++) {
			adj[i].clear();
			int m; scanf("%d", &m);
			for (int j=0; j<m;j++) {
				int a; scanf("%d", &a); a--;
				adj[i].pb(a);
				prof[a] = -1;
			}
		}
		int root = 0;
		for (int i=0;i<n;i++) {
			if (prof[i] == -1) prof[i] = 0;
			else root = i;
		}
		dfs(root);
		init(n);
		int q; scanf("%d", &q);
		printf("Case %d:\n", tt);
		for (int i=0;i<q;i++) {
			int a, b; scanf("%d %d", &a, &b);
			printf("%d\n", lca(a-1, b-1) + 1);
		}
	}
    return 0;
}

