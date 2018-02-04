#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
const int N = 2e4, M = 55;
const ll inf = 1e12;

struct dinitz {
	struct edge {
		int from, to;
		ll c, f;
	};
	vector<edge> edges;
	vector<int> adj[N];

	void addEdge(int i, int j, ll c) {
		edges.pb({i, j, c, 0ll});
		adj[i].pb(edges.size() - 1);
		edges.pb({j, i, 0ll, 0ll});
		adj[j].pb(edges.size() - 1);
	}

	int tbfs, seen[N], dist[N];
	bool bfs (int s, int t) {
		tbfs++;
		queue<int> q; q.push(t);
		dist[t] = 0; 
		while (q.size()) {
			int u = q.front(); q.pop();
			seen[u] = tbfs;
			for (auto a : adj[u]) {
				int v = edges[a].to;
				if (seen[v] == tbfs || edges[a^1].c == edges[a^1].f)
					continue;
				seen[v] = tbfs;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		return seen[s] == tbfs;
	}

	ll dfs(int u, ll f, int s, int t) {
		if (u == t || f == 0)
			return f;
		for (auto a : adj[u]) {
			int v = edges[a].to;
			if (seen[v] != tbfs || dist[v] + 1 != dist[u] || edges[a].c == edges[a].f)
				continue;
			ll nf = dfs(v, min(f, edges[a].c - edges[a].f), s, t);
			if (nf) {
				edges[a].f += nf;
				edges[a^1].f -= nf;
				return nf;
			}
		}
		return 0ll;
	}

	ll max_flow(int s, int t) {
		ll resp = 0ll;
		while (bfs(s, t)) {
			ll val = 0;
			do {
				resp += val;
				val = dfs(s, inf, s, t);
			} while (val);
		}
		return resp;
	}
};

int k[M][M];
int id[M][M][4];

int main() {
	dinitz d;
	int n, m; scanf("%d %d", &n, &m);
	getchar();
	int t = 1;
	for (int i=0;i<=n+1;i++) {
		for (int j=0;j<=m+1;j++) {
			if (i >= 1 && i <= n && j >= 1 && j <= m) {
			}
			id[i][j][0] = t++;
			id[i][j][1] = t++;
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			d.addEdge(id[i][j][0], id[i-1][j][1], 1);
			d.addEdge(id[i][j][0], id[i+1][j][1], 1);
			d.addEdge(id[i][j][0], id[i][j-1][1], 1);
			d.addEdge(id[i][j][0], id[i][j+1][1], 1);
		}
	}
	ll sum = 0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			char mander = getchar();
			if (mander == 'H') {
				d.addEdge(0, id[i][j][0], 1);
				d.addEdge(id[i][j][1], t, 1);
				sum += 1;
			}
			if (mander == 'O') {
				d.addEdge(0, id[i][j][0], 2);
				d.addEdge(id[i][j][1], t, 2);
				sum += 2;
			}
			if (mander == 'N') {
				d.addEdge(0, id[i][j][0], 3);
				d.addEdge(id[i][j][1], t, 3);
				sum += 3;
			}
			if (mander == 'C') {
				d.addEdge(0, id[i][j][0], 4);
				d.addEdge(id[i][j][1], t, 4);
				sum += 4;
			}
			if (mander == '.') mander = 0;
			k[i][j] = mander;
		} getchar();
	}
	ll flow = d.max_flow(0, t);
	sum -= flow;
	if (sum == 0 && flow > 0) printf("Valid\n");
	else printf("Invalid\n");
	return 0;
}
