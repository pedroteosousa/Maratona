#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 2e5 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int ou[N];
vector<int> resp;
vector<int> conn[N];
int seen[N];
int prof[N];
void dfs(int r, int p = 1, int calc = 0) {
	seen[r] = p;
	if (calc) {
		prof[r] = max(prof[r], p);
	}
	for (auto a : conn[r])
		if (seen[a] == 0) dfs(a, p+1, calc);
}

int getmax(int n) {
	int mx = 1;
	int id = 0;
	for (int i=0;i<n;i++) {
		if (seen[i] > mx) {
			mx = seen[i];
			id = i;
		}
	}
	return id;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		conn[a].push_back(b);
		conn[b].push_back(a);
		ou[a]++;
		ou[b]++;
	}
	dfs(0);
	int p1 = getmax(n);
	memset(seen, 0, sizeof seen);
	dfs(p1, 1, 1);
	int p2 = getmax(n);
	memset(seen, 0, sizeof seen);
	dfs(p2);
	debug("p1 = %d && p2 = %d\n", p1, p2);

	set<pair<int, int> > g;
	for (int i=0;i<n;i++) {
		if (i!=p1 && i!=p2) {
			g.insert(mp(ou[i], i));
		}
	}
	long long sum = 0;
	int found = 0;
	vector<int> f;
	do {
		if ((g.size() == 0 && found == 0) || g.begin()->first > 1) {
			g.insert(mp(ou[p2], p2));
			found = 1;
			continue;
		}
		pair<int, int> k = *g.begin();
		debug("%d\n", k.second);
		for (auto a : conn[k.second]) {
			if (ou[a] > 1) {
				g.erase(mp(ou[a], a));
				ou[a]--;
				g.insert(mp(ou[a], a));
			}
		}
		resp.pb(k.second);
		g.erase(k);

		if (found || prof[k.second] >= seen[k.second]) {
			sum += prof[k.second] - 1;
			f.pb(p1);
		} else {
			sum += seen[k.second] - 1;
			f.pb(p2);
		}

	} while(g.size());

	printf("%lld\n", sum);
	for (int i=0;i<n-1;i++) {
		printf("%d %d %d\n", f[i]+1, resp[i]+1, resp[i]+1);
	}
    return 0;
}
