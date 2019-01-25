#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 2e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

struct info {
	ll n0, n1, p0, p1;
	info operator+(const info &f) {
		return {n0 + f.n0, n1 + f.n1, p0 + f.p0, p1 + f.p1};
	}
};

vector<int> adj[N];
int seen[N];
ll resp = 0;

info dfs(int u, int p = 0) {
	seen[u] = 1;
	info m = {0ll, 0ll, 0ll, 0ll};
	if (p == 0) m.n0++;
	else m.n1++;
	for (auto v : adj[u]) {
		if (seen[v] == 0) {
			info f = dfs(v, (p + 1) % 2);
			info filho = {f.n0, f.n1, f.p0, f.p1};
			if (p == 0) {
				filho.p1 = f.n1 + f.p1;
			} else {
				filho.p0 = f.n0 + f.p0;
			}
			resp += (filho.p0 + filho.p1);
			// combinar sub-arvores
			if (p == 0) {
				resp += filho.p0 * (m.n0 - 1) + m.p0 * filho.n0;
				resp += filho.p1 * m.n1 + m.p1 * filho.n1 - m.n1 * filho.n1;
				resp += filho.p0 * m.n1 + m.p1 * filho.n0;	
				resp += filho.p1 * (m.n0 - 1) + m.p0 * filho.n1;
			} else {
				resp += filho.p1 * (m.n1 - 1) + m.p1 * filho.n1;
				resp += filho.p0 * m.n0 + m.p0 * filho.n0 - m.n0 * filho.n0;
				resp += filho.p1 * m.n0 + m.p0 * filho.n1;	
				resp += filho.p0 * (m.n1 - 1) + m.p1 * filho.n0;
			}
			m = m + filho;
		}
	}
	return m;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, 0);
	printf("%lld\n", resp);
}

