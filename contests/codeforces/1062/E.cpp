#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 2e5 + 5;
const int L = 20;
const ll inf = 1791791791;
const ll mod = 1e9+7;

vector<int> adj[N];
int prof[N], p[N][L+5], t[N<<1], pa[N];
pair<int, int> t2[N<<1], t3[N<<1];
int tmet[N], tme = 0;

void init(int n) {
	for (int i = 1; i <= L; i++)
		for (int j = 1; j <= n; j++)
			p[j][i] = p[p[j][i-1]][i-1];
}

int lca(int u, int v) {
	if (min(u, v) == 0) return max(u, v);
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

void dfs(int v, int h = 1) {
	prof[v] = h;
	tmet[v] = tme++;
	if (h == 1) p[v][0] = v;
	for (auto u : adj[v])
		if (prof[u] == 0) {
			p[u][0] = v;
			dfs(u, h+1);
		}
}

void build3(int n) {
	for(int i = n-1; i > 0; i--) t3[i] = max(t3[i<<1], t3[i<<1|1]);
}

pair<int, int> query3(int l, int r, int n) { // [l, r)
	l--;
	pair<int, int> resp = make_pair(-mod, -mod);
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) resp = max(resp, t3[l++]);
		if (r&1) resp = max(resp, t3[--r]);
	}
	return resp;
}

void build2(int n) {
	for(int i = n-1; i > 0; i--) t2[i] = min(t2[i<<1], t2[i<<1|1]);
}

pair<int, int> query2(int l, int r, int n) { // [l, r)
	l--;
	pair<int, int> resp = make_pair(mod, mod);
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) resp = min(resp, t2[l++]);
		if (r&1) resp = min(resp, t2[--r]);
	}
	return resp;
}

void build(int n) {
	for(int i = n-1; i > 0; i--) t[i] = lca(t[i<<1], t[i<<1|1]);
}

int query(int l, int r, int n) { // [l, r)
	l--;
	int resp = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) resp = lca(resp, t[l++]);
		if (r&1) resp = lca(resp, t[--r]);
	}
	return resp;
}

int get(int l, int r, int out, int n) {
	if (l == r) return l;
	if (out == l) return query(l+1, r, n);
	if (out == r) return query(l, r-1, n);
	int p1 = query(l, out-1, n);
	int p2 = query(out+1, r, n);
	return lca(p1, p2);
}

int main() {
	int n, q; scanf("%d %d", &n, &q);
	for (int i=2;i<=n;i++) {
		scanf("%d", &pa[i]);
		adj[pa[i]].pb(i);
	}
	dfs(1);
	init(n);
	for (int i=0;i<n;i++) {
		t[i+n] = i+1;
		t2[i+n] = t3[i+n] = make_pair(tmet[i+1], i+1);
	}
	build(n); build2(n); build3(n);
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		pair<int, int> ll = query2(l, r, n), rr = query3(l, r, n);
		//printf("{%d, %d}, {%d, %d}\n", ll.first, ll.second, rr.first, rr.second);
		int p1 = get(l, r, ll.second, n);
		int p2 = get(l, r, rr.second, n);
		//printf("p1, p2 = %d, %d\n", p1, p2);
		if (prof[p1] > prof[p2]) {
			printf("%d %d\n", ll.second, prof[p1]-1);
		} else printf("%d %d\n", rr.second, prof[p2]-1);
	}
	return 0;
}

