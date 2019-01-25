#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

map<int, int> found;
int resp[N];
int last[N];
int v[N];

int main() {
	int n; scanf("%d", &n);
	int mx = 1; int id = 1;
	for (int i=1;i<=n;i++) {
		scanf("%d", &v[i]);
		resp[i] = max(resp[i], 1);
		if (found[v[i]-1] != 0) {
			int k = found[v[i]-1];
			if (resp[k] + 1 > resp[i]) {
				last[i] = k;
				resp[i] = resp[k] + 1;
				if (mx < resp[i]) {
					mx = resp[i];
					id = i;
				}
				found[v[i]] = i;
			}
		}
		if (found[v[i]] == 0) found[v[i]] = i;
	}
	int cur = id;
	vector<int> t;
	while (cur != 0) {
		t.pb(cur);
		cur = last[cur];
	}
	printf("%d\n", (int)t.size());
	sort(t.begin(), t.end());
	for (auto a : t) {
		printf("%d ", a);
	} printf("\n");
    return 0;
}

