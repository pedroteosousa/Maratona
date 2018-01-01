#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 1791791791;

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

int main() {
	int n, m; scanf("%d %d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);	
		a--; b--;
		conn[a].push_back(b);
	}
	for (int i=0;i<n;i++) {
		if (!seen[i]) scc_dfs(i);
	}
	int not_leaf[N];
	memset(not_leaf, 0, sizeof not_leaf);
	int count = 0;
	for (int i=0;i<n;i++)
		for (auto a : conn[i])
			if (comp[a] != comp[i]) {
				not_leaf[comp[i]] = 1;
				break;
			}
	for (int i=1;i<ncomp;i++)
		if (not_leaf[i] == 0) count++;
	if (count > 1) {
		printf("0\n");
		return 0;
	}
   	count = 0; 
	for (int i=0;i<n;i++)
		if (not_leaf[comp[i]] == 0)
			count++;
	printf("%d\n", count);
	for (int i=0;i<n;i++)
		if (not_leaf[comp[i]] == 0) printf("%d ", i+1);
	printf("\n");
	return 0;
}

