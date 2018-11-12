#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 6e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

struct edge {
	int from, to;
	ll cost;
	int id;
	bool operator< (const edge &e) const {
		return id < e.id;
	}
};

vector<edge> adj[N], g[N];
set<edge> tree;
ll dist[N];
bool seen[N];
edge ee[N];
priority_queue< pair<int, int> > pq;

void dfs(int u, int h = 0) {
	if (h) pq.push(make_pair(h, u));
	for (edge e: g[u]) {
		ee[e.to] = e;
		dfs(e.to, h + 1);
	}
}

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);	
	for (int i=0;i<m;i++) {
		int a, b; ll c;
		scanf("%d %d %lld", &a, &b, &c);
		a--; b--;
		adj[a].push_back({a, b, c, i});
		adj[b].push_back({b, a, c, i});
	}
	priority_queue< pair<ll, pair<int, edge> > > q;
	q.push(make_pair(0, make_pair(0, (edge){-1, -1, -1})));
	while (q.size()) {
		pair<ll, pair<int, edge> > info = q.top();
		q.pop();
		int u = info.second.first;
		ll d = info.first;
		if (seen[u]) continue;
		edge eee = info.second.second;
		if (eee.to != -1) {
			tree.insert(eee);
			g[eee.from].push_back(eee);
		}
		seen[u] = true;
		dist[u] = -d;
		for (edge e: adj[u]) {
			if (!seen[e.to]) {
				q.push(make_pair(d - e.cost, make_pair(e.to, e)));
			}
		}
	}
	dfs(0);
    while ((int)tree.size() > k) {
		pair<int, int> p = pq.top();
		pq.pop();
		tree.erase(ee[p.second]);
	}
	printf("%d\n", (int)tree.size());
	for (auto e: tree) {
		printf("%d ", e.id + 1);
	} printf("\n");
	return 0;
}

