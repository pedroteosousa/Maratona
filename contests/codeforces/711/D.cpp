#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 1791791791;
const int mod = 1000000007;

vector<int> conn[N];

// time complexity: O(V+E)
stack<int> ts;
int tme = 0, ncomp = 0, low[N], seen[N];
int comp[N]; // nodes in the same scc have the same color
int scc_dfs(int n) {
	seen[n] = low[n] = ++tme;
	ts.push(n);
	for (auto a : conn[n]) {
		if (seen[a] == 0)
			scc_dfs(a);
		low[n] = min(low[n], low[a]);
	}
	if (low[n] == seen[n]) {
		int node;
		do {
			node = ts.top(); ts.pop();
			comp[node] = ncomp;
			low[node] = inf;
		} while (n != node && ts.size());
		ncomp++;
	}
	return low[n];
}

long long p2[N];
int main() {
	int n; scanf("%d", &n);
	p2[0] = 1;
	for (int i=0;i<n;i++) {
		p2[i+1] = (p2[i]*2ll)%mod;
		int a; scanf("%d", &a);	
		conn[i].push_back(a-1);
	}
	map<int, vector<int> > comps;
	for (int i=0;i<n;i++) {
		if (!seen[i]) scc_dfs(i);
		comps[comp[i]].push_back(i);
	}
	long long resp = 1ll;
	for (auto a : comps) {
		if (a.second.size() > 1) {
			resp = resp*(p2[a.second.size()] - 2)+mod;
			resp %= mod;
		} else {
			resp *= 2;
			resp %= mod;
		}
	}
	printf("%lld\n", resp);
}



