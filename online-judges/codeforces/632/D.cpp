#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

ll z[N];
map<int, ll> cnt;
int v[N];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++) {
		scanf("%d", &v[i]);
		cnt[v[i]]++;
	}
	for (int i=1;i<=m;i++) {
		for (int j=1;i*j<=m;j++) {
			z[i*j] += cnt[i];
		}
	}
	int mx = 0, id = 1;
	for (int i=1;i<=m;i++) {
		if (z[i] > mx) {
			mx = z[i];
			id = i;
		}
	}
	printf("%d %lld\n", id, z[id]);
	for (int i=0;i<n;i++) {
		if (id % v[i] == 0) printf("%d ", i+1);
	} printf("\n");
    return 0;
}

