#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 1791791791;
const int mod = 1000000007;

vector<int> conn[N];

// time complexity: O(V+E)
stack<int> ts;
int tme = 1, ncomp = 1, lowlink[N], seen[N];
int comp[N]; // nodes in the same scc have the same color
int scc_dfs(int n) {
	seen[n] = lowlink[n] = tme++;
	ts.push(n);
	for (auto a : conn[n]) {
		if (seen[a] == 0)
			lowlink[n] = min(lowlink[n], scc_dfs(a));
		else
			lowlink[n] = min(lowlink[n], seen[a]);
	}
	if (lowlink[n] == seen[n]) {
		int node;
		do {
			node = ts.top();
			comp[node] = ncomp;
			ts.pop();
		} while (n != node && ts.size());
		ncomp++;
	}
	int mn = lowlink[n];
	lowlink[n] = inf;
	return mn;
}

int cost[N];

int main() {
	int n, m; scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &cost[i]);
	scanf("%d", &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);	
		a--; b--;
		conn[a].push_back(b);
	}
	map<int, int> ma, count;
	for (int i=0;i<n;i++)
		if (!seen[i]) scc_dfs(i);
	for (int i=0;i<ncomp;i++)
		ma[i] = inf;
	for (int i=0;i<n;i++)
		ma[comp[i]] = min(ma[comp[i]], cost[i]);
	for (int i=0;i<n;i++)
		if (cost[i] == ma[comp[i]])
			count[comp[i]]++;
	long long resp = 1, sum = 0;
	for (auto a : count) {
		sum += ma[a.first];
		resp *= a.second;
		resp %= mod;
	}
	printf("%lld %lld\n", sum, resp);
}

