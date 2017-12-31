#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 2e5 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int outd[N], c[N];
vector<int> conn[N];
set<pair<int, int> > g[3];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++) {
		scanf("%d", &c[i]);
	}
	for (int i=0;i<m;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[b].push_back(a);
		outd[a]++;
	}
	for (int i=0;i<n;i++) {
		g[c[i]].insert(mp(outd[i], i));
	}
	int count = 0;
	for (int i=0;i<2*n;i++) {
		if (g[1].size() == 0) break;
		if (i%2 == 1) count++;
		while (g[i%2].size() && g[i%2].begin()->first == 0) {
			pair<int, int> k = *g[i%2].begin();
			for (auto a : conn[k.second]) {
				g[c[a]].erase(mp(outd[a], a));
				outd[a]--;
				g[c[a]].insert(mp(outd[a], a));
			}
			g[i%2].erase(k);
		};
	}
	printf("%d\n", count);
    return 0;
}

