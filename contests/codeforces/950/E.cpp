#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 1e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int ho[N], ind[N], outd[N];

vector<int> conn[N];

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

void col(int h1, int h2, int h, int c1, int c2) {
	if ((h1+1)%h == h2) {
		ind[c2]++; outd[c1]++;
		conn[c1].pb(c2);
	}
	if ((h2+1)%h == h1) {
		ind[c1]++; outd[c2]++;
		conn[c2].pb(c1);
	}
}

map<int, vector<int> > comps;

int main() {
	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);
	for (int i=0;i<n;i++) {
		scanf("%d", &ho[i]);
	}
	for (int i=0;i<m;i++) {
		int c1, c2; scanf("%d %d", &c1, &c2);
		col(ho[c1-1], ho[c2-1], h, c1-1, c2-1);
	}
	for (int i=0;i<n;i++) {
		if (!seen[i]) scc_dfs(i);
		comps[comp[i]].pb(i);
	}
	int mn = n+1, id = 0;
	for (auto a : comps) {
		int found = 0;
		for (auto b : a.second) {
			if (outd[b] == 0) {
				found = 1;
				break;
			} else if (ind[b] == 0) {
				found = 2;
				break;
			}
		}
		if (found != 2) {
			if (mn > a.second.size()) {
				mn = a.second.size();
				id = a.first;
			}
		}
	}
	printf("%d\n", mn);
	for (auto a : comps[id]) {
		printf("%d ", a+1);
	} printf("\n");
    return 0;
}

