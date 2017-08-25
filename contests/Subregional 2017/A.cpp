#include <bits/stdc++.h>

using namespace std;

vector<int> conn[100000];
int seen[100000];

void dfs(int node, int prof, int k) {
	seen[node] = prof;
	for (int i=0;i<conn[node].size();i++) {
		if (seen[conn[node][i]] == 0) dfs(conn[node][i], (prof)%k+1, k);
	}
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	if (k == 1 && m != 0) {
		printf("-1\n");
		return 0;
	}
	for (int i=0;i<m;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}
	for (int i=1;i<=n;i++) {
		if (seen[i] == 0) {
			dfs(i, 1, k);
		}
	}
	for (int i=0;i<n;i++) {
		printf("%d\n", seen[i+1]);
	}
	return 0;
}