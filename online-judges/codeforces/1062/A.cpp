#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int dp[N];

int main() {
	vector<int> v; v.pb(0);
	int n; scanf("%d", &n);
	for (int i=0;i<n;i++) {
		int a; scanf("%d", &a);
		v.pb(a);
	}
	v.pb(1001);
	n += 2;
	int resp = 0;
	for (int i=1;i<n;i++) {
		if (v[i] == v[i-1] + 1) {
			dp[i] = dp[i-1] + 1;
			resp = max(resp, dp[i-1]);
		} else dp[i] = 0;
	}
	printf("%d\n", resp);
    return 0;
}

