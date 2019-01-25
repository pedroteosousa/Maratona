#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int p[N], w[N];

int find(int x) {
	return p[x] = (p[x] == x) ? x : find(p[x]);
}

void join(int a, int b) {
	if ((a = find(a)) == (b = find(b))) return;
	if (w[a] < w[b]) swap(a, b);
	p[b] = a;
	w[a] += w[b];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i=0;i<n;i++) {
			w[p[i] = i] = 1;
		}
		for (int i=0;i<m;i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a--; b--;
			join(a, b);
		}
		int resp = 0;
		for (int i=0;i<n;i++) {
			if (find(i) == i) {
				resp += w[i]%2;
				resp %= 2;
			}
		}
		printf("%d\n", resp);
	}
    return 0;
}

