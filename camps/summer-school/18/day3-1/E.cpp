#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 1e2 + 5;
const int T = 1e4 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

struct prob {
	int p, t, i;
	prob (int a = 0, int b = 0, int c = 0) {
		t = a; p = b; i = c;
	}
	bool operator< (const prob &a) {
		return t*a.p < p*a.t;
	}
};

struct prob p[N];
pair<int, int> dp[N][T], rec[N][T];

int main() {
	int n, tot;
	scanf("%d %d", &n, &tot);
	for (int i=1;i<=n;i++) {
		int t, pr;
		scanf("%d %d", &t, &pr);
		p[i] = prob(t, pr, i);
	}
	sort(p+1, p+n+1);
	pair<int, int> mx, id;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=tot;j++) {
			if (i != 0) {
				dp[i][j] = dp[i-1][j];
				rec[i][j] = {i-1, j};
			}
			if (j >= p[i].t) {
				pair<int, int> k = {dp[i-1][j-p[i].t].first + p[i].p, dp[i-1][j-p[i].t].second - j*p[i].p};
				if (dp[i][j] < k) {
					dp[i][j] = k;
					rec[i][j] = {i-1, j-p[i].t};
					if (mx < k) {
						mx = k;
						id = {i, j};
					}
				}
			}
		}
	}
	vector<int> resp;
	while (id != make_pair(0, 0)) {
		pair<int, int> r = rec[id.first][id.second];
		if (id.second != r.second) {
			resp.push_back(p[id.first].i);
		}
		id = r;
	}
	printf("%d\n", resp.size());
	for (int i = resp.size()-1; i >= 0; i--) {
		printf("%d ", resp[i]);
	} printf("\n");
	return 0;
}

