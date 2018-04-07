#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int v[50];

int main() {
	int t; scanf("%d", &t);
	for (int i=1;i<=t;i++) {
		long long tot = 0, d;
		string s;
		scanf("%lld", &d);
		cin >> s;
		int cur = 0;
		for (int j=0;j<50;j++) v[j] = 0;
		for (int j=0;j<s.size();j++) {
			if (s[j] == 'S') {
				v[cur]++;
				tot += (1ll << cur);
			}
			else cur++;
		}
		int resp = 0;
		while (cur >= 1 && tot > d) {
			if (v[cur] == 0) {
				cur--;
				continue;
			}
			v[cur-1]++;
			v[cur]--;
			tot -= (1ll << (cur-1));
			resp++;
		}
		printf("Case #%d: ", i);
		if (tot > d) printf("IMPOSSIBLE\n");
		else printf("%d\n", resp);
	}
    return 0;
}

