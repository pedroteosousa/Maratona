#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int mk[N];
int a[N];

int check(int n, int l) {
	int used = 0;
	int cur = 0;
	//printf("checking %d %d\n", n, l);
	while (cur < n) {
		//printf("%d\n", cur);
		if (mk[cur] == 0) {
			used++;
			cur += l;
		}
		if (mk[cur] != 0) {
			if (mk[cur] >= l) return 0;
			else cur -= mk[cur];
		}
		if (cur < 0) return 0;
	}
	return used;
}

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	int mx = 0;
	for (int i=0;i<m;i++) {
		int b; scanf("%d", &b);
		mk[b] = 1;
		if (b > 0 && mk[b-1] != 0) mk[b] += mk[b-1];
	}
	for (int i=0;i<n-1;i++) {
		mx = max(mx, mk[i]);
		//printf("%d", mk[i]);
	} mx++;
	//printf("\n");
	ll resp = 1000000000000000;
	for (int i=0;i<k;i++) {
		scanf("%d", &a[i]);
		int used = check(n, i+1);
		if (used > 0) resp = min(resp, (ll)a[i] * used);
	}
	if (resp < 1000000000000000) printf("%lld\n", resp);
	else printf("-1\n");
    return 0;
}

