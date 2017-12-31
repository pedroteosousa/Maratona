#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long lli;

const int N = 2e5 + 5;

int seg[4*N][100];

// sum update
void update(int l, int r, int x, int y, int ll = 0, int rl = N-1, int root = 0) {
	if (r < ll || l > rl) return;
	if (ll >= l && rl <= r) {
		seg[root][x] = y;
		return;
	}
	update(l, r, x, y, ll, (ll+rl)/2, 2*root+1);
	update(l, r, x, y, (ll+rl)/2+1, rl, 2*root+2);
	for (int i=0;i<100;i++) {
		seg[root][i] = seg[2*root+2][seg[2*root+1][i]];
	}
}

int a[N];
int main() {
	int n, q;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	scanf("%d", &q);
	for (int i=0;i<4*q;i++) {
		for (int j=0;j<100;j++)
			seg[i][j] = j;
	}
	vector<pair<pair<int, int>, pair<int, pair<int, int> > > > s;
	for (int j=0;j<q;j++) {
		int l, r, x, y;
		scanf("%d %d %d %d", &l, &r, &x, &y);
		l--; r--; x--; y--;
		s.pb(mp(mp(l, 0), mp(x, mp(y, j))));
		s.pb(mp(mp(r, 1), mp(x, mp(x, j))));
	}
	s.pb(mp(mp(n, 0), mp(0, mp(0, 0))));
	sort(s.begin(), s.end());
	int cur = 0;
	for (auto b : s) {
		if (b.first.second == 1) for (;cur <= b.first.first; cur++) {
			printf("%d ", seg[0][a[cur]]+1);
		}
		if (b.first.second == 0) for (;cur < b.first.first; cur++) {
			printf("%d ", seg[0][a[cur]]+1);
		}
		//printf("chaging query %d from %d to %d\n", b.second.second.second, b.second.first, b.second.second.first);
		update(b.second.second.second, b.second.second.second, b.second.first, b.second.second.first, 0, q-1, 0);
	} printf("\n");
	return 0;
}

