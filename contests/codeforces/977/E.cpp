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
int p[N], w[N], ed[N];

int find(int x) {
	return p[x] = ((p[x] == x) ? x : find(p[x])); 
}

void join(int a, int b) {
	if ((a = find(a)) == (b = find(b))) return;
	if (w[a] < w[b]) swap(a, b);
	p[b] = a;
	w[a] += w[b];
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i=1;i<=n;i++) {
		w[p[i] = i] = 1;
	}
	while(m--) {
		int a, b; scanf("%d %d", &a, &b);
		conn[a].pb(b);
		conn[b].pb(a);
		join(a, b);
	}
	for (int i=1;i<=n;i++) {
		if (conn[i].size() != 2) ed[find(i)] = -inf;
		ed[find(i)] += conn[i].size();
	}
	int resp = 0;
	for (int i=1;i<=n;i++) {
		if (find(i) == i) {
			if (ed[i] == 2*w[i]) {
				resp++;
			}
		}
	}
	printf("%d\n", resp);
    return 0;
}

