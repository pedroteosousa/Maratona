#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int v[N], t[N];

int main() {
	srand(time(NULL));
	int n, k, m; scanf("%d %d %d", &n, &m, &k);
	for (int i=0;i<n;i++) {
		v[i] = rand();
	}
	for (int i=0;i<m;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		t[a] ^= v[b];	
		t[b] ^= v[a];
	}
	while (k--) {
		vector<int> g;
		int a; scanf("%d", &a);
		int all = 0;
		while (a--) {
			int b; scanf("%d", &b);
			b--;
			all ^= v[b];
			g.pb(b);
		}
		for (auto b : g) {
			t[b] ^= (v[b]^all); 	
		}
	}
	for (int i=0;i<n;i++) {
		if (t[i] == 0) printf("TAK\n");
		else printf("NIE\n");
	}
    return 0;
}

