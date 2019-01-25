#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

vector<int> conn[N];
int seen[N];

int resp = 0;

int dfs(int v) {
	seen[v] = 1;
	int sz = 1;
	int par[2] = {0, 0};
	for (auto a : conn[v]) {
		if (seen[a] == 0) {
			int k = dfs(a);
			sz += k;
			par[k%2]++;
		}
	}
	resp += par[0];
	return sz;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=1;i<n;i++) {
		int a, b; scanf("%d %d", &a, &b);
		conn[a].pb(b);
		conn[b].pb(a);
	}
	if (n % 2) {
		printf("-1\n");
		return 0;
	}	
	dfs(1);
	printf("%d\n", resp);
    return 0;
}

