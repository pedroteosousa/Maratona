#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 2e5 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

struct circle {
	double x, y, r;
	bool operator< (const circle &a) {
		return mp(r, mp(x, y)) < mp(a.r, mp(a.x, a.y));
	}
};

vector<circle> v;
vector<int> adj[N];
set<int> roots;
int resp = 0;

double sq(double x) {
	return x*x;
}

double d(int i, int j) {
	return sqrt(sq(v[i].x - v[j].x) + sq(v[i].y - v[j].y));
}

bool intersect(int i, int j) {
	return abs(v[i].r - v[j].r) < d(i, j);
}

void dfs(int n, int f) {
	if (intersect(n, f)) {
		//printf("found intersection between %d and %d\n", n, f);
		resp += 2;
		for (auto a : adj[n]) {
			dfs(a, f);
		}
	} else {
		if (roots.find(n) != roots.end()) {
			adj[f].pb(n);
			roots.erase(n);
		}
	}
}

int main() {
	int n; scanf("%d", &n);	
	for (int i=0;i<n;i++) {
		double x, y, r; scanf("%lf %lf %lf", &x, &y, &r);
		v.pb({x, y, r});
	}
	sort(v.begin(), v.end());
	for (int i=0;i<n;i++) {
		vector<int> temp;
		for (auto r : roots) {
			temp.pb(r);
		}
		for (auto a : temp) {
			dfs(a, i);
		}
		if (resp > 2*n) break;
		roots.insert(i);
	}
	if (resp > 2*n) printf("greater\n");
	else printf("%d\n", resp);
}

