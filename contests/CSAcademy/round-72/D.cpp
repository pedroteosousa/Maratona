#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int p[N], c[N], d[N], c2[N];
set<int> m, deg;
vector<pair<int, int> > resp;

int dfs(int n) {
	c[n] = 1;
	if (c[p[n]] == 0) {
		dfs(p[n]);
		printf("%d %d\n", n+1, p[n]+1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &p[i]);
		p[i]--;
		d[p[i]]++;	
	}
	for (int i=0;i<n;i++) {
		m.insert(i);
		if (d[i] == 0) {
			deg.insert(i);
		}
	}
	while (deg.size()) {
		int i = *deg.begin();
		m.erase(i);
		deg.erase(i);
		dfs(i);
	}
	for (int i=0;i<n;i++) {
		if (c[i] == 0) dfs(i);
	}	
	return 0;
}

