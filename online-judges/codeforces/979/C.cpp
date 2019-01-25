#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int seen[N];
int p[N];
int prof[N];
int sons[N];
vector<int> conn[N];

int dfs(int v, int pr = 0) {
	seen[v] = 1;
	prof[v] = pr;
	sons[v] = 1;
	for (auto a : conn[v]) {
		if (seen[a] == 0) {
			p[a] = v;
			sons[v] += dfs(a, pr+1);
		}
	}
	return sons[v];
}

int main() {
	int n, x, y; scanf("%d %d %d", &n, &x, &y);
	for (int i=0;i<n-1;i++) {
		int a, b; scanf("%d %d", &a, &b);
		conn[a].pb(b);
		conn[b].pb(a);
	}
	dfs(x);
	p[x] = x;
	set<int> s;
	int cur = y;
	while (p[cur] != cur) {
		s.insert(cur);
		cur = p[cur];
	}
	int k = 0;
	for (auto a : conn[x]) {
		if (s.find(a) != s.end()) {
			k = sons[a];
		}
	}
	long long v1 = sons[x] - k;
	long long v2 = sons[y];
	long long resp = ((long long)n)*((long long)(n-1));
	resp -= v1*v2;
	printf("%lld\n", resp);
    return 0;
}

