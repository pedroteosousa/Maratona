#include <bits/stdc++.h>

using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;

struct edge {
	int a, b, c;
};

bool operator<(const struct edge &a, const struct edge &b) {
	return (pair<int, pair<int, int> >){a.a, {a.b, a.c}} <  (pair<int, pair<int, int> >){b.a, {b.b, b.c}};
}

pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b) {
	return {a.first - b.first, a.second - b.second};
}

int cross(pair<int, int> a, pair<int, int> b) {
	return a.first*b.second - a.second*b.first;
}

vector<pair<int, int> > v;
map<struct edge, bool> m;
char s[100];
vector<bool> st;
vector<int> resp;

void print(struct edge a) {
	debug("%d %d %d\n", a.a, a.b, a.c);
}

int dfs(struct edge node, int prof, int n, long long vis) {
	if (m[node] != st[prof]) return 0;
	print(node);
	debug("%d\n", prof);
	if (prof == n-3) return 1;
	for (int i=0;i<n;i++) {
		if ((vis & (1 << i)) == 0) {
			struct edge temp = {node.b, node.c, i};
			if (m[temp] == st[prof+1]) {
				if (dfs(temp, prof+1, n, vis+(1<<i))) {
					resp.pb(i);
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({a, b});
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			for (int k=0;k<n;k++) {
				if (i==j || j==k || i==k) continue;
				int p = cross(v[j]-v[i], v[k]-v[i]); 
				if (p == 0) continue;
				m[{i, j, k}] = (p < 0);
				debug("%d %d %d -> %d\n", i, j, k, m[{i, j, k}]);
			}
		}
	}
	scanf("%s", s);
	for (int i=0;i<n-2;i++) {
		st.pb(s[i] == 'R');
	}
	for (auto a : m) {
		if (dfs(a.first, 0, n, (1<<a.first.c) + (1<<a.first.a) + (1<<a.first.b))) {
			resp.pb(a.first.c);
			resp.pb(a.first.b);
			resp.pb(a.first.a);
			break;
		}
	}
	for (int i=n-1;i>=0;i--) {
		printf("%d ", resp[i]+1);
	}
	printf("\n");
    return 0;
}

