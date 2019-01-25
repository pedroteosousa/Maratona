#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e3;
const ll inf = 1e12;


struct dinitz {
	struct edge {
		int from, to;
		ll c, f;
	};
	vector<edge> edges;
	vector<int> adj[N];

	void addEdge(int i, int j, ll c) {
		edges.push_back({i, j, c, 0}); adj[i].push_back(edges.size() - 1);
		edges.push_back({j, i, 0, 0}); adj[j].push_back(edges.size() - 1);
	}

	int turn, seen[N], dist[N], st[N];
	bool bfs (int s, int t) {
		turn++;
		queue<int> q; q.push(t);
		dist[t] = 0; 
		while (q.size()) {
			int u = q.front(); q.pop();
			seen[u] = turn;
			st[u] = 0;
			for (auto e : adj[u]) {
				int v = edges[e].to;
				if (seen[v] == turn || edges[e^1].c == edges[e^1].f)
					continue;
				seen[v] = turn;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		return seen[s] == turn;
	}

	ll dfs(int s, int t, ll f) {
		if (s == t || f == 0)
			return f;
		for (int &i = st[s]; i < adj[s].size(); i++) {
			int e = adj[s][i], v = edges[e].to;
			if (seen[v] == turn && dist[v] + 1 == dist[s] && edges[e].c > edges[e].f) {
				if (ll nf = dfs(v, t, min(f, edges[e].c - edges[e].f))) {
					edges[e].f += nf;
					edges[e^1].f -= nf;
					return nf;
				}
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
				val = dfs(s, t, inf);
			} while (val);
		}
		return resp;
	}

	int marked[N];
	vector<int> min_cut(int s, int t) {
		memset(marked, 0, sizeof marked);
		queue<int> q({s});
		marked[s] = 1;
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto e : adj[u]) {
				if (edges[e].c <= edges[e].f) continue;
				int v = edges[e].to;
				if (!marked[v]) {
					q.push(v);
					marked[v] = 1;
				}
			}
		}
		vector<int> cut;
		for (int i = 0; i < edges.size(); i+=4) {
			if (marked[edges[i].from] != marked[edges[i].to])
				cut.push_back(i/4);
		}
		return cut;
	}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);
	dinitz d;
	for (int i=0;i<m;i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		d.addEdge(a, b, c);
		d.addEdge(b, a, c);
	}
	ll mx = d.max_flow(1, n);
	vector<int> cut = d.min_cut(1, n);
	printf("%lld %lld\n", (ll)cut.size(), mx);
	for (auto e : cut) {
		printf("%d ", e+1);
	} printf("\n");
}
